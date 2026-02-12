package flelsp

import (
	"bufio"
	"fmt"
	"math"
	"regexp"
	"strconv"
	"strings"
	"time"
)

func toInt32(i int) int32 {
	return int32(max(math.MinInt32, min(i, math.MaxInt32))) // #nosec G115
}

func toPos(line, char int) Pos {
	return Pos{Line: toInt32(line), Character: toInt32(char)}
}

func toRange(line, start, end int) Range {
	return Range{
		Start: toPos(line, start),
		End:   toPos(line, end),
	}
}

var (
	simpleDate       = regexp.MustCompile(`^(\d{4}-\d{2}-\d{2})$`)
	invalidDateRegex = regexp.MustCompile(`(?i)^date\s+(\d{4}[/. ]\d{2}[/. ]\d{2})`)
	eurDateRegex     = regexp.MustCompile(`(?i)^date\s+(\d{2}[/. ]\d{2}[/. ]\d{4})`)
	dayPlus          = regexp.MustCompile(`(?i)^day\s+\+`)
	bandRegex        = regexp.MustCompile(`(?i)^(\d+(\.\d+)?(m|cm)|\d+\.\d+)$`)
	modeRegex        = regexp.MustCompile(`^(CW|SSB|FM|AM|DIGI|FT8|FT4|PSK|RTTY|VARAC)$`)
	headerRegex      = regexp.MustCompile(`^(?i)(mycall|mygrid|operator|nickname|qslmsg|mywwff|mysota|mypota)\s+(.+)$`)
	dateRegex        = regexp.MustCompile(`^date\s+(\d{4}-\d{2}-\d{2})$`)
	qsoLineRegex     = regexp.MustCompile(`^(\d{2,4})?\s*([a-zA-Z0-9/]+)\s*(\d{1,3})?\s*(\d{1,3})?\s*(.*)$`)

	reISODate      = regexp.MustCompile(`(\d{4})[/. ](\d{2})[/. ](\d{2})`)
	reEurDate      = regexp.MustCompile(`(\d{2})[/. ](\d{2})[/. ](\d{4})`)
	extraGridRegex = regexp.MustCompile(`#([a-zA-Z0-9]+)`)

	suffixesToIgnore = map[string]bool{
		// ITU Authorized
		"P":  true, // Portable
		"M":  true, // Mobile
		"MM": true, // Maritime Mobile
		// Common conventions / Special events
		"AM":  true, // Aeronautical Mobile
		"QRP": true, // Low Power
		"LH":  true, // Lighthouse
		"R":   true, // Repeater/Remote
		"B":   true, // Beacon
		"J":   true, // Jamboree
	}
)

// ParseFLE parses the content of an FLE document and returns a Logbook, diagnostics, and any error.
type stringInterner struct {
	pool map[string]string
}

func newStringInterner() *stringInterner {
	return &stringInterner{pool: make(map[string]string)}
}

func (si *stringInterner) intern(s string) string {
	if s == "" {
		return ""
	}
	if v, ok := si.pool[s]; ok {
		return v
	}
	si.pool[s] = s
	return s
}

// ParseFLE parses the content of an FLE document and returns a Logbook, diagnostics, and any error.
func ParseFLE(content string) (*Logbook, []Diagnostic, error) {
	// Heuristic: ~40 characters per line, roughly 1 QSO per line
	estimatedQSOs := len(content) / 40
	if estimatedQSOs < 50 {
		estimatedQSOs = 50
	}
	logbook := &Logbook{
		QSOs:        make([]QSO, 0, estimatedQSOs),
		Tokens:      make([]Token, 0, estimatedQSOs*5), // ~5 tokens per QSO
		SeenHeaders: make(map[string]bool),
	}
	diagnostics := make([]Diagnostic, 0, 32)
	state := &InternalState{}
	interner := newStringInterner()

	scanner := bufio.NewScanner(strings.NewReader(content))
	lineNumber := 0

	for scanner.Scan() {
		lineNumber++
		rawLine := scanner.Text()

		// Handle comments (including EOL comments deviation)
		processedLine := rawLine
		commentStart := -1

		trimmedRaw := strings.TrimLeft(rawLine, " \t")
		if strings.HasPrefix(trimmedRaw, "#") {
			// Whole line is a comment
			commentStart = strings.Index(rawLine, "#")
			processedLine = ""
		} else if idx := strings.LastIndex(rawLine, "# "); idx != -1 {
			// End of line comment
			commentStart = idx
			processedLine = rawLine[:idx]
		}

		if commentStart != -1 {
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: toRange(lineNumber-1, commentStart, len(rawLine)),
				Type:  TokenComment,
			})
		}

		line := strings.TrimSpace(processedLine)
		if line == "" {
			continue
		}

		// 1. Check for Header keywords
		if loc := headerRegex.FindStringSubmatchIndex(line); loc != nil {
			key := interner.intern(strings.ToLower(line[loc[2]:loc[3]]))
			val := line[loc[4]:loc[5]]

			// Protocol Enforcement: Some headers must be unique per file
			isUniqueHeader := false
			switch key {
			case "mycall", "mysota", "mywwff", "mypota", "nickname", "qslmsg":
				isUniqueHeader = true
			}

			if isUniqueHeader {
				if key == "mycall" {
					base := BaseCallsign(val)
					if state.BaseMyCall == "" {
						state.BaseMyCall = base
					} else if state.BaseMyCall != base {
						diagnostics = append(diagnostics, Diagnostic{
							Range:    toRange(lineNumber-1, loc[2], loc[3]),
							Message:  fmt.Sprintf("Keyword 'mycall' redefined with a different base callsign ('%s' vs '%s') is not allowed.", base, state.BaseMyCall),
							Severity: SeverityError,
						})
						continue
					}
				} else if logbook.SeenHeaders[key] {
					diagnostics = append(diagnostics, Diagnostic{
						Range:    toRange(lineNumber-1, loc[2], loc[3]),
						Message:  fmt.Sprintf("Keyword '%s' already defined. Only one is allowed per file.", key),
						Severity: SeverityError,
					})
					continue
				}
				logbook.SeenHeaders[key] = true
			}

			updateHeader(&logbook.Header, key, val)

			if key == "mygrid" {
				val = interner.intern(formatGrid(val))
				state.MyGrid = val
				found := false
				for _, g := range logbook.ActivatedGrids {
					if g == val {
						found = true
						break
					}
				}
				if !found {
					logbook.ActivatedGrids = append(logbook.ActivatedGrids, val)
				}
			}

			// Extract starting position in rawLine for accuracy
			startOfLine := strings.Index(rawLine, line)
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: toRange(lineNumber-1, startOfLine+loc[2], startOfLine+loc[3]),
				Type:  TokenKeyword,
			})
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: toRange(lineNumber-1, startOfLine+loc[4], startOfLine+loc[5]),
				Type:  TokenExtra,
			})
			continue
		}

		// 2. Check for Dates
		if loc := dateRegex.FindStringSubmatchIndex(line); loc != nil {
			dateStr := line[loc[2]:loc[3]]
			parsedDate, err := time.Parse("2006-01-02", dateStr)
			if err != nil {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    toRange(lineNumber-1, 0, len(rawLine)),
					Message:  fmt.Sprintf("Invalid date format: %v", err),
					Severity: SeverityError,
					Code:     CodeInvalidDate,
				})
			}
			state.Date = parsedDate
			state.LastTime = ""

			startOfLine := strings.Index(rawLine, line)
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: toRange(lineNumber-1, startOfLine+loc[0], startOfLine+loc[1]),
				Type:  TokenDate,
			})
			continue
		}
		if loc := simpleDate.FindStringSubmatchIndex(line); loc != nil {
			dateStr := line[loc[2]:loc[3]]
			parsedDate, err := time.Parse("2006-01-02", dateStr)
			if err != nil {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    toRange(lineNumber-1, 0, len(rawLine)),
					Message:  fmt.Sprintf("Invalid date format: %v", err),
					Severity: SeverityError,
					Code:     CodeInvalidDate,
				})
			}
			state.Date = parsedDate
			state.LastTime = ""

			startOfLine := strings.Index(rawLine, line)
			logbook.Tokens = append(logbook.Tokens, Token{
				Range: toRange(lineNumber-1, startOfLine+loc[0], startOfLine+loc[1]),
				Type:  TokenDate,
			})
			continue
		}
		// Handle almost-correct dates for Quick Fix
		if loc := invalidDateRegex.FindStringSubmatchIndex(line); loc != nil {
			diagnostics = append(diagnostics, Diagnostic{
				Range:    toRange(lineNumber-1, 0, len(rawLine)),
				Message:  "Invalid date format: use YYYY-MM-DD",
				Severity: SeverityError,
				Code:     CodeInvalidDate,
			})
			continue
		}
		if loc := eurDateRegex.FindStringSubmatchIndex(line); loc != nil {
			diagnostics = append(diagnostics, Diagnostic{
				Range:    toRange(lineNumber-1, 0, len(rawLine)),
				Message:  "Invalid date format: use YYYY-MM-DD",
				Severity: SeverityError,
				Code:     CodeInvalidDate,
			})
			continue
		}
		if dayPlus.MatchString(line) {
			if state.Date.IsZero() {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    toRange(lineNumber-1, 0, len(rawLine)),
					Message:  "day + used before any date was set",
					Severity: SeverityError,
				})
			} else {
				state.Date = state.Date.AddDate(0, 0, strings.Count(line, "+"))
				state.LastTime = ""

				startOfLine := strings.Index(rawLine, line)
				logbook.Tokens = append(logbook.Tokens, Token{
					Range: toRange(lineNumber-1, startOfLine, startOfLine+len(line)),
					Type:  TokenDate,
				})
			}
			continue
		}

		// 3. Check for Band/Mode standalone lines (can be combined like "40m cw")
		fields := strings.Fields(line)
		foundControl := false
		for _, f := range fields {
			if bandRegex.MatchString(f) {
				state.Band = interner.intern(strings.ToLower(f))
				foundControl = true
			} else if modeRegex.MatchString(strings.ToUpper(f)) {
				state.Mode = interner.intern(strings.ToUpper(f))
				foundControl = true
			}
		}
		if foundControl {
			startOfLine := strings.Index(rawLine, line)
			for _, f := range fields {
				start := strings.Index(line, f)
				tokenType := TokenKeyword
				if bandRegex.MatchString(f) {
					tokenType = TokenBand
				} else if modeRegex.MatchString(strings.ToUpper(f)) {
					tokenType = TokenMode
				}
				logbook.Tokens = append(logbook.Tokens, Token{
					Range: toRange(lineNumber-1, startOfLine+start, startOfLine+start+len(f)),
					Type:  tokenType,
				})
			}
			continue
		}
		// 4. Fallback to QSO entry
		if qso, lineDiags, ok := parseQSOLine(logbook, line, state, lineNumber, interner); ok {
			diagnostics = append(diagnostics, lineDiags...)
			// Validate QSO context
			if state.Date.IsZero() {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    toRange(lineNumber-1, 0, len(rawLine)),
					Message:  "QSO entered before any date was set",
					Severity: SeverityError,
				})
			}
			if state.Band == "" {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    toRange(lineNumber-1, 0, len(rawLine)),
					Message:  "QSO entered before any band was set",
					Severity: SeverityWarning,
				})
			}
			if state.Mode == "" {
				diagnostics = append(diagnostics, Diagnostic{
					Range:    toRange(lineNumber-1, 0, len(rawLine)),
					Message:  "QSO entered before any mode was set",
					Severity: SeverityWarning,
				})
			}
			logbook.QSOs = append(logbook.QSOs, qso)
		} else {
			// Unknown line format
			diagnostics = append(diagnostics, Diagnostic{
				Range:    toRange(lineNumber-1, 0, len(rawLine)),
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
			Code:     CodeMissingMyCall,
		})
	}

	logbook.BaseMyCall = state.BaseMyCall
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

func parseQSOLine(lb *Logbook, line string, state *InternalState, lineNum int, si *stringInterner) (QSO, []Diagnostic, bool) {
	trimmed := strings.TrimLeft(line, " \t")
	if trimmed == "" {
		return QSO{}, nil, false
	}
	startOfTrimmed := len(line) - len(trimmed)

	// Regex equivalent: ^(\d{2,4})?\s*([a-zA-Z0-9/]+)\s*(\d{1,3})?\s*(\d{1,3})?\s*(.*)$
	i := 0
	// 1. Time (optional digits 0 at the start)
	rawTime := ""
	timeStart := -1
	if i < len(trimmed) && trimmed[i] >= '0' && trimmed[i] <= '9' {
		timeStart = i
		for i < len(trimmed) && trimmed[i] >= '0' && trimmed[i] <= '9' && i-timeStart < 4 {
			i++
		}
		rawTime = trimmed[timeStart:i]
	}

	// Skip space
	for i < len(trimmed) && (trimmed[i] == ' ' || trimmed[i] == '\t') {
		i++
	}

	// 2. Callsign (required alpha-numeric/slash)
	callStart := i
	for i < len(trimmed) && trimmed[i] != ' ' && trimmed[i] != '\t' {
		i++
	}
	callsign := trimmed[callStart:i]
	if callsign == "" {
		return QSO{}, nil, false
	}
	callEnd := i

	// Skip space
	for i < len(trimmed) && (trimmed[i] == ' ' || trimmed[i] == '\t') {
		i++
	}

	// 3. RST Sent (optional digits)
	rstS := ""
	rstSStart := -1
	rstSEnd := -1
	if i < len(trimmed) && trimmed[i] >= '0' && trimmed[i] <= '9' {
		rstSStart = i
		for i < len(trimmed) && trimmed[i] >= '0' && trimmed[i] <= '9' && i-rstSStart < 3 {
			i++
		}
		rstSEnd = i
		rstS = si.intern(trimmed[rstSStart:rstSEnd])
	}

	// Skip space
	for i < len(trimmed) && (trimmed[i] == ' ' || trimmed[i] == '\t') {
		i++
	}

	// 4. RST Received (optional digits)
	rstR := ""
	rstRStart := -1
	rstREnd := -1
	if i < len(trimmed) && trimmed[i] >= '0' && trimmed[i] <= '9' {
		rstRStart = i
		for i < len(trimmed) && trimmed[i] >= '0' && trimmed[i] <= '9' && i-rstRStart < 3 {
			i++
		}
		rstREnd = i
		rstR = si.intern(trimmed[rstRStart:rstREnd])
	}

	// Skip space
	for i < len(trimmed) && (trimmed[i] == ' ' || trimmed[i] == '\t') {
		i++
	}

	// 5. Extras (remaining)
	extras := ""
	extrasStart := -1
	if i < len(trimmed) {
		extrasStart = i
		extras = trimmed[extrasStart:]
	}

	var diags []Diagnostic
	tokenStart := len(lb.Tokens)

	// 1. Validate minutes (00-59)
	if rawTime != "" {
		if len(rawTime) >= 2 {
			minsStr := rawTime[len(rawTime)-2:]
			mins, _ := strconv.Atoi(minsStr)
			if mins > 59 {
				diags = append(diags, Diagnostic{
					Range:    toRange(lineNum-1, startOfTrimmed+timeStart, startOfTrimmed+timeStart+len(rawTime)),
					Message:  fmt.Sprintf("Invalid minutes: %s", minsStr),
					Severity: SeverityError,
				})
			}
		}
		lb.Tokens = append(lb.Tokens, Token{
			Range: toRange(lineNum-1, startOfTrimmed+timeStart, startOfTrimmed+timeStart+len(rawTime)),
			Type:  TokenTime,
		})
	}

	// Time expansion logic
	expandedTime := si.intern(expandTime(state.LastTime, rawTime))

	// 2. Check for monotonic time
	if state.LastTime != "" && expandedTime < state.LastTime {
		diags = append(diags, Diagnostic{
			Range:    toRange(lineNum-1, startOfTrimmed+timeStart, startOfTrimmed+timeStart+len(rawTime)),
			Message:  fmt.Sprintf("Time goes backwards: %s < %s", expandedTime, state.LastTime),
			Severity: SeverityWarning,
		})
	}

	state.LastTime = expandedTime

	lb.Tokens = append(lb.Tokens, Token{
		Range: toRange(lineNum-1, startOfTrimmed+callStart, startOfTrimmed+callEnd),
		Type:  TokenCallsign,
	})

	// Add warning for lowercase callsign
	if strings.ToUpper(callsign) != callsign {
		diags = append(diags, Diagnostic{
			Range:    toRange(lineNum-1, startOfTrimmed+callStart, startOfTrimmed+callEnd),
			Message:  fmt.Sprintf("Callsign should be uppercased: %s", callsign),
			Severity: SeverityWarning,
			Code:     CodeLowercaseCallsign,
		})
	}

	if rstS != "" {
		lb.Tokens = append(lb.Tokens, Token{
			Range: toRange(lineNum-1, startOfTrimmed+rstSStart, startOfTrimmed+rstSEnd),
			Type:  TokenReport,
		})
	}
	if rstR != "" {
		lb.Tokens = append(lb.Tokens, Token{
			Range: toRange(lineNum-1, startOfTrimmed+rstRStart, startOfTrimmed+rstREnd),
			Type:  TokenReport,
		})
	}

	hour, _ := strconv.Atoi(expandedTime[:2])
	minute, _ := strconv.Atoi(expandedTime[2:])
	ts := time.Date(state.Date.Year(), state.Date.Month(), state.Date.Day(), hour, minute, 0, 0, time.UTC)

	qso := QSO{
		Timestamp:      ts,
		Callsign:       ensureUpper(callsign),
		Band:           si.intern(state.Band),
		Mode:           si.intern(state.Mode),
		ReportSent:     rstS,
		ReportReceived: rstR,
		LineNumber:     lineNum,
		MyGrid:         si.intern(state.MyGrid),
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

	// Parse extras manually to avoid regex allocations
	if extras != "" {
		start := startOfTrimmed + extrasStart
		l := len(extras)
		for i := 0; i < l; i++ {
			c := extras[i]
			switch c {
			case '@':
				j := i + 1
				for j < l && !isSpaceOrSpecial(extras[j]) {
					j++
				}
				qso.Name = si.intern(extras[i+1 : j])
				lb.Tokens = append(lb.Tokens, Token{
					Range: toRange(lineNum-1, start+i, start+j),
					Type:  TokenName,
				})
				i = j - 1
			case '#':
				j := i + 1
				for j < l && !isSpaceOrSpecial(extras[j]) {
					j++
				}
				qso.Grid = si.intern(formatGrid(extras[i+1 : j]))
				lb.Tokens = append(lb.Tokens, Token{
					Range: toRange(lineNum-1, start+i, start+j),
					Type:  TokenGrid,
				})
				i = j - 1
			case '<':
				j := i + 1
				for j < l && extras[j] != '>' {
					j++
				}
				if j < l {
					qso.QSLMsg = extras[i+1 : j]
					lb.Tokens = append(lb.Tokens, Token{
						Range: toRange(lineNum-1, start+i, start+j+1),
						Type:  TokenExtra,
					})
					i = j
				}
			case '[':
				j := i + 1
				for j < l && extras[j] != ']' {
					j++
				}
				if j < l {
					qso.Comment = extras[i+1 : j]
					lb.Tokens = append(lb.Tokens, Token{
						Range: toRange(lineNum-1, start+i, start+j+1),
						Type:  TokenComment,
					})
					i = j
				}
			case ' ':
				// Skip
			case '\t':
				// Skip
			default:
				// If it looks like a grid (4 chars, LLNN)
				if !isDigit(c) && i+3 < l && isLetter(extras[i]) && isLetter(extras[i+1]) && isDigit(extras[i+2]) && isDigit(extras[i+3]) && (i+4 == l || isSpaceOrSpecial(extras[i+4])) {
					qso.Grid = si.intern(formatGrid(extras[i : i+4]))
					lb.Tokens = append(lb.Tokens, Token{
						Range: toRange(lineNum-1, start+i, start+i+4),
						Type:  TokenGrid,
					})
					i += 3
				}
			}
		}
	}

	qso.TokenStart = toInt32(tokenStart)
	qso.TokenCount = toInt32(len(lb.Tokens) - tokenStart)

	return qso, diags, true
}

func isSpaceOrSpecial(c byte) bool {
	return c == ' ' || c == '\t' || c == '<' || c == '>' || c == '[' || c == ']'
}

func isDigit(c byte) bool {
	return c >= '0' && c <= '9'
}

func isLetter(c byte) bool {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
}

func ensureUpper(s string) string {
	for i := 0; i < len(s); i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			return strings.ToUpper(s)
		}
	}
	return s
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
	if last == "" || len(last) < 4 {
		// Defensive fallback: if last time context is missing or invalid,
		// and we have a partial current time, we can't reliably expand it.
		// Pad current with zeros is a safe best-effort (though likely wrong context).
		return fmt.Sprintf("%04s", current)
	}

	// Double check bounds before slicing (safe based on logic above, but explicit is better)
	if 4-len(current) < 0 || 4-len(current) > len(last) {
		return current
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

// BaseCallsign extracts the core callsign, removing prefixes and suffixes.
// E.g., DL/F4JXQ/M -> F4JXQ
func BaseCallsign(call string) string {
	idx := strings.IndexByte(call, '/')
	if idx == -1 {
		return call
	}
	parts := strings.Split(call, "/")

	bestPart := ""
	for _, part := range parts {
		// Ignore standard suffixes/prefixes
		if isSuffixOrPrefixToIgnore(part) {
			continue
		}
		// Pick the "most complex" part: usually the longest or one with a digit
		if bestPart == "" || compareCallsignComplexity(part, bestPart) > 0 {
			bestPart = part
		}
	}

	if bestPart == "" {
		// Fallback to the longest part if everything was filtered
		for _, part := range parts {
			if len(part) > len(bestPart) {
				bestPart = part
			}
		}
	}

	if bestPart == "" {
		return parts[0]
	}

	return bestPart
}

func isSuffixOrPrefixToIgnore(part string) bool {
	if suffixesToIgnore[part] {
		return true
	}
	// Ignore single digits (e.g., F4JXQ/1)
	if len(part) == 1 && part >= "0" && part <= "9" {
		return true
	}
	return false
}

func compareCallsignComplexity(a, b string) int {
	// A part with a digit is usually more "callsign-like" than one without
	aHasDigit := strings.ContainsAny(a, "0123456789")
	bHasDigit := strings.ContainsAny(b, "0123456789")

	if aHasDigit && !bHasDigit {
		return 1
	}
	if !aHasDigit && bHasDigit {
		return -1
	}

	// Longer is often better for the base call
	if len(a) != len(b) {
		return len(a) - len(b)
	}

	return 0
}
