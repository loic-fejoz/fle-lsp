package flelsp

import (
	"context"
	"fmt"
	"sort"
	"strings"
	"sync"
	"time"

	"go.lsp.dev/protocol"
	"go.uber.org/zap"
)

// Handler represents the LSP handler for fle-lsp.
type Handler struct {
	UnimplementedServer
	Client    protocol.Client
	Logger    *zap.Logger
	documents sync.Map // Map[string]*Document
}

// Document represents a managed FLE document.
type Document struct {
	Text    string
	Logbook *Logbook
}

// NewHandler creates a new LSP handler.
func NewHandler(ctx context.Context, client protocol.Client, logger *zap.Logger) (*Handler, context.Context, error) {
	return &Handler{
		Client: client,
		Logger: logger,
	}, ctx, nil
}

// Initialize handles the initialize request.
func (h *Handler) Initialize(_ context.Context, _ *protocol.InitializeParams) (*protocol.InitializeResult, error) {
	h.Logger.Debug("Initializing flelsp server")
	return &protocol.InitializeResult{
		Capabilities: protocol.ServerCapabilities{
			DefinitionProvider:     false,
			HoverProvider:          true,
			DocumentSymbolProvider: true,
			CompletionProvider: &protocol.CompletionOptions{
				TriggerCharacters: []string{" "},
			},
			DocumentFormattingProvider:      true,
			DocumentRangeFormattingProvider: true,
			FoldingRangeProvider:            true,
			ColorProvider:                   false,
			SemanticTokensProvider: map[string]interface{}{
				"legend": protocol.SemanticTokensLegend{
					TokenTypes: []protocol.SemanticTokenTypes{
						protocol.SemanticTokenVariable, // 0: Callsign, Grid
						protocol.SemanticTokenString,   // 1: Comment, Name, Extra
						protocol.SemanticTokenKeyword,  // 2: Keyword, Date
						protocol.SemanticTokenNumber,   // 3: Time, Report
						protocol.SemanticTokenType,     // 4: Band
						protocol.SemanticTokenMacro,    // 5: Mode
						"date",                         // 6: Date value
						"name",                         // 7: Operator name (@)
						"extra",                        // 8: Extra/QSL info ([])
					},
					TokenModifiers: []protocol.SemanticTokenModifiers{},
				},
				"full": true,
			},
			TextDocumentSync: protocol.TextDocumentSyncOptions{
				OpenClose: true,
				Change:    protocol.TextDocumentSyncKindFull,
				Save: &protocol.SaveOptions{
					IncludeText: false,
				},
			},
		},
		ServerInfo: &protocol.ServerInfo{
			Name:    "ortfols",
			Version: fmt.Sprintf("%s (built at %s)", "0.0.0", BuiltAt),
		},
	}, nil
}

// DidOpen handles the textDocument/didOpen notification.
func (h *Handler) DidOpen(ctx context.Context, params *protocol.DidOpenTextDocumentParams) error {
	filename := params.TextDocument.URI.Filename()
	h.Logger.Info("DidOpen", zap.String("uri", filename))

	logbook, diags, err := ParseFLE(params.TextDocument.Text)
	if err != nil {
		h.Logger.Error("failed to parse logbook", zap.Error(err))
	}

	h.documents.Store(filename, &Document{
		Text:    params.TextDocument.Text,
		Logbook: logbook,
	})

	return h.publishDiagnostics(ctx, params.TextDocument.URI, diags)
}

// DidChange handles the textDocument/didChange notification.
func (h *Handler) DidChange(ctx context.Context, params *protocol.DidChangeTextDocumentParams) error {
	filename := params.TextDocument.URI.Filename()
	h.Logger.Info("DidChange", zap.String("uri", filename))

	if len(params.ContentChanges) == 0 {
		return nil
	}

	// With Full sync, the last change contains the full text
	lastChange := params.ContentChanges[len(params.ContentChanges)-1]

	logbook, diags, err := ParseFLE(lastChange.Text)
	if err != nil {
		h.Logger.Error("failed to parse logbook", zap.Error(err))
	}

	h.documents.Store(filename, &Document{
		Text:    lastChange.Text,
		Logbook: logbook,
	})

	return h.publishDiagnostics(ctx, params.TextDocument.URI, diags)
}

// DidClose handles the textDocument/didClose notification.
func (h *Handler) DidClose(_ context.Context, params *protocol.DidCloseTextDocumentParams) error {
	h.Logger.Info("DidClose", zap.String("uri", params.TextDocument.URI.Filename()))
	h.documents.Delete(params.TextDocument.URI.Filename())
	return nil
}

// Initialized handles the initialized notification.
func (h *Handler) Initialized(_ context.Context, _ *protocol.InitializedParams) error {
	h.Logger.Debug("Client initialized")
	return nil
}

// Shutdown handles the shutdown request.
func (h *Handler) Shutdown(_ context.Context) error {
	h.Logger.Debug("Server shutting down")
	return nil
}

// Exit handles the exit notification.
func (h *Handler) Exit(_ context.Context) error {
	h.Logger.Debug("Server exiting")
	return nil
}

// SemanticTokensFull handles the textDocument/semanticTokens/full request.
func (h *Handler) SemanticTokensFull(_ context.Context, params *protocol.SemanticTokensParams) (*protocol.SemanticTokens, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, fmt.Errorf("document not found")
	}
	doc := v.(*Document)
	if doc.Logbook == nil {
		return nil, nil
	}

	// 1. Collect and sort all tokens
	allTokens := append([]Token{}, doc.Logbook.Tokens...)
	for _, qso := range doc.Logbook.QSOs {
		allTokens = append(allTokens, qso.Tokens...)
	}

	// Sort by line then character
	sort.Slice(allTokens, func(i, j int) bool {
		if allTokens[i].Range.Start.Line != allTokens[j].Range.Start.Line {
			return allTokens[i].Range.Start.Line < allTokens[j].Range.Start.Line
		}
		return allTokens[i].Range.Start.Character < allTokens[j].Range.Start.Character
	})

	// Map to legend indices
	typeMap := map[TokenType]uint32{
		TokenCallsign: 0, // SemanticTokenVariable
		TokenComment:  1, // SemanticTokenString
		TokenKeyword:  2, // SemanticTokenKeyword
		TokenDate:     6, // custom "date"
		TokenTime:     3, // SemanticTokenNumber
		TokenBand:     4, // SemanticTokenType
		TokenMode:     5, // SemanticTokenMacro
		TokenName:     7, // custom "name"
		TokenGrid:     0, // Variable
		TokenReport:   3, // Number
		TokenExtra:    8, // custom "extra"
	}
	data := make([]uint32, 0)
	var lastLine, lastChar uint32

	for _, t := range allTokens {
		line := uint32(t.Range.Start.Line)
		char := uint32(t.Range.Start.Character)
		length := uint32(t.Range.End.Character - t.Range.Start.Character)

		deltaLine := line - lastLine
		deltaChar := char
		if deltaLine == 0 {
			deltaChar = char - lastChar
		}

		typeIdx, ok := typeMap[t.Type]
		if !ok {
			typeIdx = 0
		}

		data = append(data, deltaLine, deltaChar, length, typeIdx, 0)

		lastLine = line
		lastChar = char
	}

	return &protocol.SemanticTokens{
		Data: data,
	}, nil
}

// Hover handles the textDocument/hover request.
func (h *Handler) Hover(_ context.Context, params *protocol.HoverParams) (*protocol.Hover, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, nil
	}
	doc := v.(*Document)
	if doc.Logbook == nil {
		return nil, nil
	}

	line := int(params.Position.Line) + 1
	var foundQSO *QSO
	for _, q := range doc.Logbook.QSOs {
		if q.LineNumber == line {
			foundQSO = &q
			break
		}
	}

	if foundQSO == nil {
		return nil, nil
	}

	localTime := foundQSO.Timestamp.Local()
	zone, _ := localTime.Zone()

	content := fmt.Sprintf("**QSO Context**\n\n* **Date (UTC):** %s\n* **Time (UTC):** %s\n* **Local Time:** %s (%s)\n* **Band:** %s\n* **Mode:** %s\n* **Call:** %s",
		foundQSO.Timestamp.Format("2006-01-02"),
		foundQSO.Timestamp.Format("15:04"),
		localTime.Format("15:04"),
		zone,
		foundQSO.Band,
		foundQSO.Mode,
		foundQSO.Callsign,
	)

	return &protocol.Hover{
		Contents: protocol.MarkupContent{
			Kind:  protocol.Markdown,
			Value: content,
		},
	}, nil
}

// DocumentSymbol handles the textDocument/documentSymbol request.
func (h *Handler) DocumentSymbol(_ context.Context, params *protocol.DocumentSymbolParams) ([]interface{}, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, nil
	}
	doc := v.(*Document)
	if doc.Logbook == nil || len(doc.Logbook.QSOs) == 0 {
		return nil, nil
	}

	// 1. Preliminary scan to determine if we should show Year/Month
	years := make(map[int]bool)
	months := make(map[string]bool) // Key: "Year-Month"
	for _, qso := range doc.Logbook.QSOs {
		years[qso.Timestamp.Year()] = true
		months[qso.Timestamp.Format("2006-01")] = true
	}

	showYear := len(years) > 1
	showMonth := len(months) > 1

	// 2. Build Hierarchy
	var finalSymbols []protocol.DocumentSymbol
	var currentYear int
	var currentMonth string
	var currentDate string

	var yearSym *protocol.DocumentSymbol
	var monthSym *protocol.DocumentSymbol
	var daySym *protocol.DocumentSymbol

	for _, qso := range doc.Logbook.QSOs {
		y := qso.Timestamp.Year()
		m := qso.Timestamp.Format("2006-01")
		d := qso.Timestamp.Format("2006-01-02")
		line := uint32(qso.LineNumber - 1)
		qsoRange := protocol.Range{Start: protocol.Position{Line: line}, End: protocol.Position{Line: line}}

		// Handle Year change
		if y != currentYear {
			if yearSym != nil {
				h.appendLevel(&finalSymbols, yearSym, monthSym, daySym, showYear, showMonth)
			}
			currentYear = y
			currentMonth = "" // Reset month/day on year change
			currentDate = ""
			yearSym = &protocol.DocumentSymbol{
				Name:           fmt.Sprintf("%d", y),
				Kind:           protocol.SymbolKindModule,
				Range:          qsoRange,
				SelectionRange: qsoRange,
				Children:       []protocol.DocumentSymbol{},
			}
			monthSym = nil
			daySym = nil
		}

		// Handle Month change
		if m != currentMonth {
			if monthSym != nil {
				h.appendMonthToYear(yearSym, monthSym, daySym, showMonth)
			}
			currentMonth = m
			currentDate = "" // Reset day on month change
			monthSym = &protocol.DocumentSymbol{
				Name:           qso.Timestamp.Format("January"),
				Kind:           protocol.SymbolKindPackage,
				Range:          qsoRange,
				SelectionRange: qsoRange,
				Children:       []protocol.DocumentSymbol{},
			}
			daySym = nil
		}

		// Handle Day change
		if d != currentDate {
			if daySym != nil {
				monthSym.Children = append(monthSym.Children, *daySym)
			}
			currentDate = d
			daySym = &protocol.DocumentSymbol{
				Name:           qso.Timestamp.Format("02 (Mon)"),
				Kind:           protocol.SymbolKindClass,
				Range:          qsoRange,
				SelectionRange: qsoRange,
				Children:       []protocol.DocumentSymbol{},
			}
		}

		// Add QSO to Day
		qsoSym := protocol.DocumentSymbol{
			Name:           fmt.Sprintf("%s - %s", qso.Timestamp.Format("15:04"), qso.Callsign),
			Detail:         fmt.Sprintf("%s %s", qso.Band, qso.Mode),
			Kind:           protocol.SymbolKindEvent,
			Range:          qsoRange,
			SelectionRange: qsoRange,
		}
		daySym.Children = append(daySym.Children, qsoSym)

		// Expand ranges
		daySym.Range.End = qsoRange.End
		monthSym.Range.End = qsoRange.End
		yearSym.Range.End = qsoRange.End
	}

	// Final append
	h.appendLevel(&finalSymbols, yearSym, monthSym, daySym, showYear, showMonth)

	res := make([]interface{}, len(finalSymbols))
	for i, s := range finalSymbols {
		res[i] = s
	}
	return res, nil
}

// FoldingRanges handles the textDocument/foldingRange request.
func (h *Handler) FoldingRanges(_ context.Context, params *protocol.FoldingRangeParams) ([]protocol.FoldingRange, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, nil
	}
	doc := v.(*Document)
	if doc.Logbook == nil || len(doc.Logbook.QSOs) == 0 {
		return nil, nil
	}

	// Logic similar to DocumentSymbol to find ranges
	years := make(map[int]bool)
	months := make(map[string]bool)
	for _, qso := range doc.Logbook.QSOs {
		years[qso.Timestamp.Year()] = true
		months[qso.Timestamp.Format("2006-01")] = true
	}
	showYear := len(years) > 1
	showMonth := len(months) > 1

	var ranges []protocol.FoldingRange
	var currentYear int
	var currentMonth string
	var currentDate string

	var yearStartLine, monthStartLine, dayStartLine uint32
	var lastLine uint32

	// Helper to find the first token line in a range
	getTokenStart := func(startLine, endLine uint32) uint32 {
		minLine := endLine
		for _, t := range doc.Logbook.Tokens {
			l := uint32(t.Range.Start.Line)
			if l >= startLine && l < minLine {
				minLine = l
			}
		}
		return minLine
	}

	var prevQSOLine uint32
	for i, qso := range doc.Logbook.QSOs {
		y := qso.Timestamp.Year()
		m := qso.Timestamp.Format("2006-01")
		d := qso.Timestamp.Format("2006-01-02")
		line := uint32(qso.LineNumber - 1)

		if y != currentYear {
			if i > 0 && showYear && yearStartLine < lastLine {
				ranges = append(ranges, protocol.FoldingRange{
					StartLine: yearStartLine,
					EndLine:   lastLine,
				})
			}
			currentYear = y
			yearStartLine = getTokenStart(prevQSOLine, line)
			currentMonth = ""
			currentDate = ""
		}

		if m != currentMonth {
			if i > 0 && showMonth && monthStartLine < lastLine {
				ranges = append(ranges, protocol.FoldingRange{
					StartLine: monthStartLine,
					EndLine:   lastLine,
				})
			}
			currentMonth = m
			monthStartLine = getTokenStart(prevQSOLine, line)
			currentDate = ""
		}

		if d != currentDate {
			if i > 0 && dayStartLine < lastLine {
				ranges = append(ranges, protocol.FoldingRange{
					StartLine: dayStartLine,
					EndLine:   lastLine,
				})
			}
			currentDate = d
			dayStartLine = getTokenStart(prevQSOLine, line)
		}

		lastLine = line
		prevQSOLine = line + 1
	}

	// Close final ranges
	if showYear && yearStartLine < lastLine {
		ranges = append(ranges, protocol.FoldingRange{StartLine: yearStartLine, EndLine: lastLine})
	}
	if showMonth && monthStartLine < lastLine {
		ranges = append(ranges, protocol.FoldingRange{StartLine: monthStartLine, EndLine: lastLine})
	}
	if dayStartLine < lastLine {
		ranges = append(ranges, protocol.FoldingRange{StartLine: dayStartLine, EndLine: lastLine})
	}

	return ranges, nil
}

func (h *Handler) appendMonthToYear(_ *protocol.DocumentSymbol, month *protocol.DocumentSymbol, day *protocol.DocumentSymbol, _ bool) {
	if day != nil {
		month.Children = append(month.Children, *day)
	}
}

func (h *Handler) appendLevel(root *[]protocol.DocumentSymbol, year *protocol.DocumentSymbol, month *protocol.DocumentSymbol, day *protocol.DocumentSymbol, showYear, showMonth bool) {
	if day != nil {
		month.Children = append(month.Children, *day)
	}

	if showYear {
		if showMonth {
			year.Children = append(year.Children, *month)
		} else {
			// Skip month level, add day children to year directly
			year.Children = append(year.Children, month.Children...)
		}
		*root = append(*root, *year)
	} else if showMonth {
		*root = append(*root, *month)
	} else {
		// Only show days
		*root = append(*root, month.Children...)
	}
}

// Formatting handles the textDocument/formatting request.
func (h *Handler) Formatting(_ context.Context, params *protocol.DocumentFormattingParams) ([]protocol.TextEdit, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, nil
	}
	doc := v.(*Document)

	lines := strings.Split(doc.Text, "\n")
	var edits []protocol.TextEdit

	for i, line := range lines {
		trimmed := strings.TrimSpace(line)
		formatted := h.normalizeLine(trimmed)

		if formatted != "" && formatted != trimmed {
			edits = append(edits, protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{Line: uint32(i), Character: 0},
					End:   protocol.Position{Line: uint32(i), Character: uint32(len(line))},
				},
				NewText: formatted,
			})
		}
	}

	return edits, nil
}

// RangeFormatting handles the textDocument/rangeFormatting request.
func (h *Handler) RangeFormatting(_ context.Context, params *protocol.DocumentRangeFormattingParams) ([]protocol.TextEdit, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, nil
	}
	doc := v.(*Document)

	lines := strings.Split(doc.Text, "\n")
	var edits []protocol.TextEdit

	startLine := params.Range.Start.Line
	endLine := params.Range.End.Line

	for i := int(startLine); i <= int(endLine) && i < len(lines); i++ {
		line := lines[i]
		trimmed := strings.TrimSpace(line)
		formatted := h.normalizeLine(trimmed)

		if formatted != "" && formatted != trimmed {
			edits = append(edits, protocol.TextEdit{
				Range: protocol.Range{
					Start: protocol.Position{Line: uint32(i), Character: 0},
					End:   protocol.Position{Line: uint32(i), Character: uint32(len(line))},
				},
				NewText: formatted,
			})
		}
	}

	return edits, nil
}

func (h *Handler) normalizeLine(trimmed string) string {
	if trimmed == "" || strings.HasPrefix(trimmed, "#") {
		return ""
	}

	// 1. Header keywords
	if loc := headerRegex.FindStringSubmatchIndex(trimmed); loc != nil {
		key := strings.ToLower(trimmed[loc[2]:loc[3]])
		val := trimmed[loc[4]:loc[5]]
		switch key {
		case "mygrid":
			val = formatGrid(val)
		case "mycall", "operator":
			val = strings.ToUpper(val)
		}
		return fmt.Sprintf("%s %s", key, val)
	}

	// 2. Dates "date YYYY-MM-DD"
	if loc := dateRegex.FindStringSubmatchIndex(trimmed); loc != nil {
		dateStr := trimmed[loc[2]:loc[3]]
		return fmt.Sprintf("date %s", dateStr)
	}

	// 3. Simple Dates "YYYY-MM-DD"
	if loc := simpleDate.FindStringSubmatchIndex(trimmed); loc != nil {
		return trimmed[loc[2]:loc[3]]
	}

	// 4. "day +"
	if dayPlus.MatchString(trimmed) {
		return strings.ToLower(trimmed)
	}

	// 5. Band/Mode or QSO
	fields := strings.Fields(trimmed)
	isControl := true
	for _, f := range fields {
		if !bandRegex.MatchString(f) && !modeRegex.MatchString(strings.ToUpper(f)) {
			isControl = false
			break
		}
	}

	if isControl {
		// Normalize Band/Mode line
		var parts []string
		for _, f := range fields {
			if bandRegex.MatchString(f) {
				parts = append(parts, strings.ToLower(f))
			} else {
				parts = append(parts, strings.ToUpper(f))
			}
		}
		return strings.Join(parts, " ")
	}

	// 6. QSO Line Normalization
	if loc := qsoLineRegex.FindStringSubmatchIndex(trimmed); loc != nil {
		rawTime := ""
		if loc[2] != -1 {
			rawTime = trimmed[loc[2]:loc[3]]
		}
		callsign := strings.ToUpper(trimmed[loc[4]:loc[5]])
		rstS := ""
		if loc[6] != -1 {
			rstS = trimmed[loc[6]:loc[7]]
		}
		rstR := ""
		if loc[8] != -1 {
			rstR = trimmed[loc[8]:loc[9]]
		}
		extras := ""
		if loc[10] != -1 {
			extras = trimmed[loc[10]:loc[11]]
			// Normalize grid in extras (e.g., #JN38QR -> #JN38qr)
			extras = extraGridRegex.ReplaceAllStringFunc(extras, func(m string) string {
				return "#" + formatGrid(m[1:])
			})
		}

		// Join with single spaces
		parts := []string{}
		if rawTime != "" {
			parts = append(parts, rawTime)
		}
		parts = append(parts, callsign)
		if rstS != "" {
			parts = append(parts, rstS)
		}
		if rstR != "" {
			parts = append(parts, rstR)
		}
		if extras != "" {
			parts = append(parts, extras)
		}

		return strings.Join(parts, " ")
	}

	return ""
}

// Completion handles the textDocument/completion request.
func (h *Handler) Completion(_ context.Context, params *protocol.CompletionParams) (*protocol.CompletionList, error) {
	filename := params.TextDocument.URI.Filename()
	v, ok := h.documents.Load(filename)
	if !ok {
		return nil, nil
	}
	doc := v.(*Document)

	// 1. Get current UTC time and date for suggestion
	now := time.Now().UTC()
	nowUTC := now.Format("1504")
	dateUTC := now.Format("2006-01-02")

	items := []protocol.CompletionItem{}

	// Determine context
	lineNum := params.Position.Line
	charPos := params.Position.Character
	docLines := strings.Split(doc.Text, "\n")
	currentLine := ""
	if int(lineNum) < len(docLines) {
		currentLine = docLines[lineNum]
	}
	trimmedPrefix := strings.TrimSpace(currentLine[:charPos])

	// Context: Start of line
	if trimmedPrefix == "" {
		items = append(items, protocol.CompletionItem{
			Label:      "Current UTC Time: " + nowUTC,
			InsertText: nowUTC,
			Kind:       protocol.CompletionItemKindSnippet,
			Detail:     "Insert current UTC time",
			SortText:   "00",
		})

		items = append(items, protocol.CompletionItem{
			Label:      "date " + dateUTC,
			InsertText: "date " + dateUTC,
			Kind:       protocol.CompletionItemKindSnippet,
			Detail:     "Suggest current UTC date",
			SortText:   "01",
		})
	}

	// Context: After 'date' keyword
	if strings.ToLower(trimmedPrefix) == "date" {
		items = append(items, protocol.CompletionItem{
			Label:      dateUTC,
			InsertText: dateUTC,
			Kind:       protocol.CompletionItemKindSnippet,
			Detail:     "Current UTC date",
			SortText:   "00",
		})
	}

	// 2. Add Keywords
	keywords := []string{"mycall", "mygrid", "operator", "nickname", "qslmsg", "mywwff", "mysota", "mypota", "date"}
	for _, k := range keywords {
		items = append(items, protocol.CompletionItem{
			Label: k,
			Kind:  protocol.CompletionItemKindKeyword,
		})
	}

	// 3. Add Bands
	bands := []string{"160m", "80m", "60m", "40m", "30m", "20m", "17m", "15m", "12m", "10m", "6m", "4m", "2m", "1.25m", "70cm"}
	for _, b := range bands {
		items = append(items, protocol.CompletionItem{
			Label:  b,
			Kind:   protocol.CompletionItemKindEnumMember,
			Detail: "Band",
		})
	}

	// 4. Add Modes
	modes := []string{"CW", "SSB", "AM", "FM", "RTTY", "FT8", "PSK", "FT4", "DATA", "JS8", "MFSK"}
	for _, m := range modes {
		items = append(items, protocol.CompletionItem{
			Label:  m,
			Kind:   protocol.CompletionItemKindEnumMember,
			Detail: "Mode",
		})
	}

	return &protocol.CompletionList{
		IsIncomplete: false,
		Items:        items,
	}, nil
}

func (h *Handler) publishDiagnostics(ctx context.Context, uri protocol.DocumentURI, diags []Diagnostic) error {
	pDiags := make([]protocol.Diagnostic, len(diags))
	for i, d := range diags {
		pDiags[i] = protocol.Diagnostic{
			Range: protocol.Range{
				Start: protocol.Position{Line: uint32(d.Range.Start.Line), Character: uint32(d.Range.Start.Character)},
				End:   protocol.Position{Line: uint32(d.Range.End.Line), Character: uint32(d.Range.End.Character)},
			},
			Severity: protocol.DiagnosticSeverity(d.Severity + 1), // Mapping Severity
			Message:  d.Message,
			Source:   "fle-lsp",
		}
	}

	return h.Client.PublishDiagnostics(ctx, &protocol.PublishDiagnosticsParams{
		URI:         uri,
		Diagnostics: pDiags,
	})
}

func formatGrid(grid string) string {
	if len(grid) < 2 {
		return strings.ToUpper(grid)
	}
	res := strings.ToUpper(grid)
	if len(res) > 4 {
		res = res[:4] + strings.ToLower(res[4:])
	}
	return res
}
