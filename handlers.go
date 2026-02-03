package flelsp

import (
	"context"
	"fmt"

	"go.lsp.dev/protocol"
	"go.uber.org/zap"
)

var logger *zap.Logger

type Handler struct {
	protocol.Server
	Logger *zap.Logger
}

func NewHandler(ctx context.Context, server protocol.Server, logger *zap.Logger) (Handler, context.Context, error) {
	// Do initialization logic here, including
	// stuff like setting state variables
	// by returning a new context with
	// context.WithValue(context, ...)
	// instead of just context
	return Handler{Server: server, Logger: logger}, ctx, nil
}

func (h Handler) Initialize(ctx context.Context, params *protocol.InitializeParams) (*protocol.InitializeResult, error) {
	logger = h.Logger
	h.Logger.Debug("Initializing flelsp server")
	return &protocol.InitializeResult{
		Capabilities: protocol.ServerCapabilities{
			DefinitionProvider: false,
			HoverProvider:      false,
			ColorProvider:      true,
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
