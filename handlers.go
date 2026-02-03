package flelsp

import (
	"context"
	"fmt"
	"sort"
	"sync"

	"go.lsp.dev/protocol"
	"go.uber.org/zap"
)

var logger *zap.Logger

type Handler struct {
	UnimplementedServer
	Client    protocol.Client
	Logger    *zap.Logger
	documents sync.Map // Map[string]*Document
}

type Document struct {
	Text    string
	Logbook *Logbook
}

func NewHandler(ctx context.Context, client protocol.Client, logger *zap.Logger) (*Handler, context.Context, error) {
	return &Handler{
		Client: client,
		Logger: logger,
	}, ctx, nil
}

func (h *Handler) Initialize(ctx context.Context, params *protocol.InitializeParams) (*protocol.InitializeResult, error) {
	logger = h.Logger
	h.Logger.Debug("Initializing flelsp server")
	return &protocol.InitializeResult{
		Capabilities: protocol.ServerCapabilities{
			DefinitionProvider:     false,
			HoverProvider:          true,
			DocumentSymbolProvider: true,
			ColorProvider:          false,
			SemanticTokensProvider: map[string]interface{}{
				"legend": protocol.SemanticTokensLegend{
					TokenTypes: []protocol.SemanticTokenTypes{
						protocol.SemanticTokenVariable, // Callsign
						protocol.SemanticTokenString,   // Comment
						protocol.SemanticTokenKeyword,  // Keyword
						protocol.SemanticTokenNumber,   // Time
						protocol.SemanticTokenType,     // Band/Mode (mapped later)
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

func (h *Handler) DidClose(ctx context.Context, params *protocol.DidCloseTextDocumentParams) error {
	h.Logger.Info("DidClose", zap.String("uri", params.TextDocument.URI.Filename()))
	h.documents.Delete(params.TextDocument.URI.Filename())
	return nil
}

func (h *Handler) Initialized(ctx context.Context, params *protocol.InitializedParams) error {
	h.Logger.Debug("Client initialized")
	return nil
}

func (h *Handler) Shutdown(ctx context.Context) error {
	h.Logger.Debug("Server shutting down")
	return nil
}

func (h *Handler) Exit(ctx context.Context) error {
	h.Logger.Debug("Server exiting")
	return nil
}

func (h *Handler) SemanticTokensFull(ctx context.Context, params *protocol.SemanticTokensParams) (*protocol.SemanticTokens, error) {
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
		TokenTime:     3, // SemanticTokenNumber
		TokenBand:     4, // SemanticTokenType
		TokenMode:     4, // SemanticTokenType
		TokenName:     1, // String
		TokenGrid:     0, // Variable
		TokenReport:   3, // Number
		TokenExtra:    1, // String
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

func (h *Handler) Hover(ctx context.Context, params *protocol.HoverParams) (*protocol.Hover, error) {
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

func (h *Handler) DocumentSymbol(ctx context.Context, params *protocol.DocumentSymbolParams) ([]interface{}, error) {
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

func (h *Handler) appendMonthToYear(year *protocol.DocumentSymbol, month *protocol.DocumentSymbol, day *protocol.DocumentSymbol, showMonth bool) {
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
