package flelsp

import (
	"context"
	"encoding/json"
	"io"
	"os"

	"go.lsp.dev/jsonrpc2"
	"go.lsp.dev/protocol"
	"go.uber.org/multierr"
	"go.uber.org/zap"
)

// BuiltAt holds the timestamp of when the binary was built.
var BuiltAt string

// StartServer starts the language server.
// It reads from stdin and writes to stdout.
func StartServer(logger *zap.Logger) {
	conn := jsonrpc2.NewConn(jsonrpc2.NewStream(&readWriteCloser{
		reader: os.Stdin,
		writer: os.Stdout,
	}))

	client := protocol.ClientDispatcher(conn, logger)
	handler, ctx, err := NewHandler(
		context.Background(),
		client,
		logger,
	)

	if err != nil {
		logger.Sugar().Fatalf("while initializing handler: %v", err)
	}

	serverHandler := protocol.ServerHandler(handler, jsonrpc2.MethodNotFoundHandler)
	conn.Go(ctx, func(ctx context.Context, reply jsonrpc2.Replier, req jsonrpc2.Request) error {
		switch req.Method() {
		case "initialize":
			var params protocol.InitializeParams
			if err := json.Unmarshal(req.Params(), &params); err != nil {
				return reply(ctx, nil, jsonrpc2.NewError(jsonrpc2.InvalidParams, err.Error()))
			}
			resp, err := handler.Initialize(ctx, &params)
			if err != nil {
				return reply(ctx, nil, err)
			}
			// Add inlayHintProvider support to the response
			m, _ := json.Marshal(resp)
			var customResp map[string]interface{}
			_ = json.Unmarshal(m, &customResp)
			if caps, ok := customResp["capabilities"].(map[string]interface{}); ok {
				caps["inlayHintProvider"] = true
			}
			return reply(ctx, customResp, nil)

		case "textDocument/inlayHint":
			var params InlayHintParams
			if err := json.Unmarshal(req.Params(), &params); err != nil {
				return reply(ctx, nil, jsonrpc2.NewError(jsonrpc2.InvalidParams, err.Error()))
			}
			resp, err := handler.InlayHint(ctx, &params)
			return reply(ctx, resp, err)
		}
		return serverHandler(ctx, reply, req)
	})
	<-conn.Done()
}

type readWriteCloser struct {
	reader io.ReadCloser
	writer io.WriteCloser
}

func (r *readWriteCloser) Read(b []byte) (int, error) {
	n, err := r.reader.Read(b)
	return n, err
}

func (r *readWriteCloser) Write(b []byte) (int, error) {
	return r.writer.Write(b)
}

func (r *readWriteCloser) Close() error {
	return multierr.Append(r.reader.Close(), r.writer.Close())
}
