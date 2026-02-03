package flelsp

import (
	"context"
	"fmt"
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
			DefinitionProvider: false,
			HoverProvider:      false,
			ColorProvider:      false,
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
