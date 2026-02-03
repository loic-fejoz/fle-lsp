package flelsp

import (
	"bufio"
	"fmt"
	"regexp"
	"strconv"
	"strings"
	"time"
)

var (
	dateRegex   = regexp.MustCompile(`(?i)^date\s+(\d{4}-\d{2}-\d{2})`)
	simpleDate  = regexp.MustCompile(`^(\d{4}-\d{2}-\d{2})$`)
	dayPlus     = regexp.MustCompile(`(?i)^day\s+\+`)
	bandRegex   = regexp.MustCompile(`(?i)^(\d+m|\d+\.\d+)$`)
	modeRegex   = regexp.MustCompile(`(?i)^(CW|SSB|AM|FM|RTTY|FT8|PSK|FT4|DATA|JS8|MFSK)$`)
	headerRegex = regexp.MustCompile(`(?i)^(mycall|mygrid|operator|nickname|qslmsg|mywwff|mysota|mypota)\s+(.+)$`)

	// QSO parts: optional time, mandatory call, optional reports, followed by extras
	qsoLineRegex = regexp.MustCompile(`^(\d{2,4})?\s*([a-zA-Z0-9/]+)\s*(\d{1,3})?\s*(\d{1,3})?\s*(.*)$`)

	extraNameRegex    = regexp.MustCompile(`@([^\s<>\[\]]+)`)
	extraGridRegex    = regexp.MustCompile(`#([a-zA-Z0-9]+)`)
	extraCommentRegex = regexp.MustCompile(`\<([^\>]+)\>`)
	extraQSLRegex     = regexp.MustCompile(`\[([^\]]+)\]`)
)

func ParseFLE(content string) (*Logbook, []Diagnostic, error) {
	logbook := &Logbook{
		QSOs: make([]QSO, 0),
	}
	diagnostics := make([]Diagnostic, 0)
	state := &InternalState{}

	scanner := bufio.NewScanner(strings.NewReader(content))
	lineNumber := 0

	for scanner.Scan() {
		lineNumber++
		rawLine := scanner.Text()
		line := strings.TrimSpace(rawLine)
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}

		// 1. Check for Header keywords
		if loc := headerRegex.FindStringSubmatchIndex(line); loc != nil {
			key := strings.ToLower(line[loc[2]:loc[3]])
			val := line[loc[4]:loc[5]]
			updateHeader(&logbook.Header, key, val)

			// Extract starting position in rawLine for accuracy
			startOfLine := strings.Index(rawLine, line)
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: Range{Start: Pos{lineNumber - 1, startOfLine + loc[2]}, End: Pos{lineNumber - 1, startOfLine + loc[3]}},
				Type:  TokenKeyword,
			})
			continue
		}

		// 2. Check for Dates
		if loc := dateRegex.FindStringSubmatchIndex(line); loc != nil {
			dateStr := line[loc[2]:loc[3]]
			parsedDate, err := time.Parse("2006-01-02", dateStr)
			if err != nil {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  fmt.Sprintf("Invalid date format: %v", err),
					Severity: SeverityError,
				})
			}
			state.Date = parsedDate
			state.LastTime = ""

			startOfLine := strings.Index(rawLine, line)
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: Range{Start: Pos{lineNumber - 1, startOfLine + loc[0]}, End: Pos{lineNumber - 1, startOfLine + loc[1]}},
				Type:  TokenDate,
			})
			continue
		}
		if loc := simpleDate.FindStringSubmatchIndex(line); loc != nil {
			dateStr := line[loc[2]:loc[3]]
			parsedDate, err := time.Parse("2006-01-02", dateStr)
			if err != nil {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  fmt.Sprintf("Invalid date format: %v", err),
					Severity: SeverityError,
				})
			}
			state.Date = parsedDate
			state.LastTime = ""

			startOfLine := strings.Index(rawLine, line)
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: Range{Start: Pos{lineNumber - 1, startOfLine + loc[0]}, End: Pos{lineNumber - 1, startOfLine + loc[1]}},
				Type:  TokenDate,
			})
			continue
		}
		if dayPlus.MatchString(line) {
			if state.Date.IsZero() {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  "day + used before any date was set",
					Severity: SeverityError,
				})
			} else {
				state.Date = state.Date.AddDate(0, 0, strings.Count(line, "+"))
				state.LastTime = ""
			}
			continue
		}

		// 3. Check for Band/Mode standalone lines (can be combined like "40m cw")
		fields := strings.Fields(line)
		foundControl := false
		for _, f := range fields {
			if bandRegex.MatchString(f) {
				state.Band = strings.ToLower(f)
				foundControl = true
			} else if modeRegex.MatchString(strings.ToUpper(f)) {
				state.Mode = strings.ToUpper(f)
				foundControl = true
			}
		}
		if foundControl {
			continue
		}

		// 4. Fallback to QSO entry
		if qso, lineDiags, ok := parseQSOLine(line, state, lineNumber); ok {
			diagnostics = append(diagnostics, lineDiags...)
			// Validate QSO context
			if state.Date.IsZero() {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  "QSO entered before any date was set",
					Severity: SeverityError,
				})
			}
			if state.Band == "" {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  "QSO entered before any band was set",
					Severity: SeverityWarning,
				})
			}
			if state.Mode == "" {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  "QSO entered before any mode was set",
					Severity: SeverityWarning,
				})
			}
			logbook.QSOs = append(logbook.QSOs, qso)
		} else {
			// Unknown line format
			diagnostics = append(diagnostics, Diagnostic{
				Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
				Message:  "Unrecognized line format",
				Severity: SeverityInfo,
			})
		}
	}

	// Final Header Check
	if logbook.Header.MyCall == "" {
		diagnostics = append(diagnostics, Diagnostic{
			Range:    Range{Start: Pos{0, 0}, End: Pos{0, 0}},
			Message:  "Missing mandatory 'mycall' header",
			Severity: SeverityWarning,
		})
	}

	return logbook, diagnostics, nil
}

func updateHeader(h *Header, key, value string) {
	switch key {
	case "mycall":
		h.MyCall = value
	case "mygrid":
		h.MyGrid = value
	case "operator":
		h.Operator = value
	case "nickname":
		h.Nickname = value
	case "qslmsg":
		h.QSLMsg = value
	case "mywwff":
		h.MyWWFF = value
	case "mysota":
		h.MySOTA = value
	case "mypota":
		h.MyPOTA = value
	}
}

func parseQSOLine(line string, state *InternalState, lineNum int) (QSO, []Diagnostic, bool) {
	loc := qsoLineRegex.FindStringSubmatchIndex(line)
	if loc == nil {
		return QSO{}, nil, false
	}

	rawTime := ""
	if loc[2] != -1 {
		rawTime = line[loc[2]:loc[3]]
	}
	callsign := line[loc[4]:loc[5]]
	rstS := ""
	if loc[6] != -1 {
		rstS = line[loc[6]:loc[7]]
	}
	rstR := ""
	if loc[8] != -1 {
		rstR = line[loc[8]:loc[9]]
	}
	extras := ""
	if loc[10] != -1 {
		extras = line[loc[10]:loc[11]]
	}

	var diags []Diagnostic
	var tokens []Token

	// 1. Validate minutes (00-59)
	if rawTime != "" && len(rawTime) >= 2 {
		minsStr := rawTime[len(rawTime)-2:]
		mins, _ := strconv.Atoi(minsStr)
		if mins > 59 {
			diags = append(diags, Diagnostic{
				Range:    Range{Start: Pos{lineNum - 1, loc[2]}, End: Pos{lineNum - 1, loc[3]}},
				Message:  fmt.Sprintf("Invalid minutes: %s", minsStr),
				Severity: SeverityError,
			})
		}
		tokens = append(tokens, Token{
			Range: Range{Start: Pos{lineNum - 1, loc[2]}, End: Pos{lineNum - 1, loc[3]}},
			Type:  TokenTime,
		})
	}

	// Time expansion logic
	expandedTime := expandTime(state.LastTime, rawTime)

	// 2. Check for monotonic time
	if state.LastTime != "" && expandedTime < state.LastTime {
		diags = append(diags, Diagnostic{
			Range:    Range{Start: Pos{lineNum - 1, loc[2]}, End: Pos{lineNum - 1, loc[3]}},
			Message:  fmt.Sprintf("Time goes backwards: %s < %s", expandedTime, state.LastTime),
			Severity: SeverityWarning,
		})
	}

	state.LastTime = expandedTime

	tokens = append(tokens, Token{
		Range: Range{Start: Pos{lineNum - 1, loc[4]}, End: Pos{lineNum - 1, loc[5]}},
		Type:  TokenCallsign,
	})

	if rstS != "" {
		tokens = append(tokens, Token{
			Range: Range{Start: Pos{lineNum - 1, loc[6]}, End: Pos{lineNum - 1, loc[7]}},
			Type:  TokenReport,
		})
	}
	if rstR != "" {
		tokens = append(tokens, Token{
			Range: Range{Start: Pos{lineNum - 1, loc[8]}, End: Pos{lineNum - 1, loc[9]}},
			Type:  TokenReport,
		})
	}

	ts, _ := time.Parse("2006-01-02 1504", state.Date.Format("2006-01-02")+" "+expandedTime)

	qso := QSO{
		Timestamp:      ts,
		Callsign:       strings.ToUpper(callsign),
		Band:           state.Band,
		Mode:           state.Mode,
		ReportSent:     rstS,
		ReportReceived: rstR,
		LineNumber:     lineNum,
	}

	// Default reports if missing
	if qso.ReportSent == "" {
		if qso.Mode == "CW" || isDigital(qso.Mode) {
			qso.ReportSent = "599"
		} else {
			qso.ReportSent = "59"
		}
	}
	if qso.ReportReceived == "" {
		qso.ReportReceived = qso.ReportSent
	}

	// Parse extras
	if extras != "" {
		startExtras := loc[10]
		if n := extraNameRegex.FindStringSubmatchIndex(extras); n != nil {
			qso.Name = extras[n[2]:n[3]]
			tokens = append(tokens, Token{
				Range: Range{Start: Pos{lineNum - 1, startExtras + n[0]}, End: Pos{lineNum - 1, startExtras + n[1]}},
				Type:  TokenName,
			})
		}
		if g := extraGridRegex.FindStringSubmatchIndex(extras); g != nil {
			qso.Grid = extras[g[2]:g[3]]
			tokens = append(tokens, Token{
				Range: Range{Start: Pos{lineNum - 1, startExtras + g[0]}, End: Pos{lineNum - 1, startExtras + g[1]}},
				Type:  TokenGrid,
			})
		}
		if c := extraCommentRegex.FindStringSubmatchIndex(extras); c != nil {
			qso.Comment = extras[c[2]:c[3]]
			tokens = append(tokens, Token{
				Range: Range{Start: Pos{lineNum - 1, startExtras + c[0]}, End: Pos{lineNum - 1, startExtras + c[1]}},
				Type:  TokenComment,
			})
		}
		if q := extraQSLRegex.FindStringSubmatchIndex(extras); q != nil {
			qso.QSLMsg = extras[q[2]:q[3]]
			tokens = append(tokens, Token{
				Range: Range{Start: Pos{lineNum - 1, startExtras + q[0]}, End: Pos{lineNum - 1, startExtras + q[1]}},
				Type:  TokenExtra,
			})
		}
	}

	qso.Tokens = tokens
	return qso, diags, true
}

func expandTime(last, current string) string {
	if current == "" {
		if last == "" {
			return "0000"
		}
		return last
	}
	if len(current) == 4 {
		return current
	}
	if last == "" {
		return strings.Repeat("0000", 1)[:4-len(current)] + current
	}

	// Replace trailing digits of last time
	return last[:4-len(current)] + current
}

func isDigital(mode string) bool {
	switch mode {
	case "FT8", "FT4", "RTTY", "PSK", "JS8", "DATA", "MFSK":
		return true
	}
	return false
}
