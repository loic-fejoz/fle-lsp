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

	content := fmt.Sprintf("**QSO Context**\n\n* **Date:** %s\n* **Time:** %s\n* **Band:** %s\n* **Mode:** %s\n* **Call:** %s",
		foundQSO.Timestamp.Format("2006-01-02"),
		foundQSO.Timestamp.Format("15:04"),
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
	if doc.Logbook == nil {
		return nil, nil
	}

	var symbols []protocol.DocumentSymbol
	var currentDate string
	var currentDaySymbol *protocol.DocumentSymbol

	for _, qso := range doc.Logbook.QSOs {
		dateStr := qso.Timestamp.Format("2006-01-02")
		if dateStr != currentDate {
			if currentDaySymbol != nil {
				symbols = append(symbols, *currentDaySymbol)
			}
			currentDate = dateStr
			currentDaySymbol = &protocol.DocumentSymbol{
				Name:           dateStr,
				Kind:           protocol.SymbolKindModule,
				Range:          protocol.Range{Start: protocol.Position{Line: uint32(qso.LineNumber - 1)}, End: protocol.Position{Line: uint32(qso.LineNumber - 1)}},
				SelectionRange: protocol.Range{Start: protocol.Position{Line: uint32(qso.LineNumber - 1)}, End: protocol.Position{Line: uint32(qso.LineNumber - 1)}},
				Children:       []protocol.DocumentSymbol{},
			}
		}

		qsoSymbol := protocol.DocumentSymbol{
			Name:           fmt.Sprintf("%s - %s", qso.Timestamp.Format("15:04"), qso.Callsign),
			Detail:         fmt.Sprintf("%s %s", qso.Band, qso.Mode),
			Kind:           protocol.SymbolKindClass,
			Range:          protocol.Range{Start: protocol.Position{Line: uint32(qso.LineNumber - 1)}, End: protocol.Position{Line: uint32(qso.LineNumber - 1)}},
			SelectionRange: protocol.Range{Start: protocol.Position{Line: uint32(qso.LineNumber - 1)}, End: protocol.Position{Line: uint32(qso.LineNumber - 1)}},
		}
		currentDaySymbol.Children = append(currentDaySymbol.Children, qsoSymbol)
		// Update parent range to include this child
		currentDaySymbol.Range.End.Line = uint32(qso.LineNumber - 1)
	}

	if currentDaySymbol != nil {
		symbols = append(symbols, *currentDaySymbol)
	}

	// Convert to []interface{} as required by the protocol package
	res := make([]interface{}, len(symbols))
	for i, s := range symbols {
		res[i] = s
	}
	return res, nil
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
