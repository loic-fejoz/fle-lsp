package flelsp

import (
	"bufio"
	"fmt"
	"regexp"
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
		if m := headerRegex.FindStringSubmatch(line); m != nil {
			updateHeader(&logbook.Header, strings.ToLower(m[1]), m[2])
			continue
		}

		// 2. Check for Dates
		if m := dateRegex.FindStringSubmatch(line); m != nil {
			parsedDate, err := time.Parse("2006-01-02", m[1])
			if err != nil {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  fmt.Sprintf("Invalid date format: %v", err),
					Severity: SeverityError,
				})
			}
			state.Date = parsedDate
			continue
		}
		if m := simpleDate.FindStringSubmatch(line); m != nil {
			parsedDate, err := time.Parse("2006-01-02", m[1])
			if err != nil {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    Range{Start: Pos{lineNumber - 1, 0}, End: Pos{lineNumber - 1, len(rawLine)}},
					Message:  fmt.Sprintf("Invalid date format: %v", err),
					Severity: SeverityError,
				})
			}
			state.Date = parsedDate
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
		if qso, ok := parseQSOLine(line, state, lineNumber); ok {
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

func parseQSOLine(line string, state *InternalState, lineNum int) (QSO, bool) {
	m := qsoLineRegex.FindStringSubmatch(line)
	if m == nil {
		return QSO{}, false
	}

	rawTime := m[1]
	callsign := m[2]
	rstS := m[3]
	rstR := m[4]
	extras := m[5]

	// Time expansion logic
	expandedTime := expandTime(state.LastTime, rawTime)
	state.LastTime = expandedTime

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
	if n := extraNameRegex.FindStringSubmatch(extras); n != nil {
		qso.Name = n[1]
	}
	if g := extraGridRegex.FindStringSubmatch(extras); g != nil {
		qso.Grid = g[1]
	}
	if c := extraCommentRegex.FindStringSubmatch(extras); c != nil {
		qso.Comment = c[1]
	}
	if q := extraQSLRegex.FindStringSubmatch(extras); q != nil {
		qso.QSLMsg = q[1]
	}

	return qso, true
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
