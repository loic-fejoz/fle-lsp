package flelsp

import (
	"context"
	"encoding/json"
	"fmt"
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
		conn,
		logger,
	)

	if err != nil {
		logger.Sugar().Fatalf("while initializing handler: %v", err)
	}

	serverHandler := protocol.ServerHandler(handler, jsonrpc2.MethodNotFoundHandler)
	conn.Go(ctx, func(ctx context.Context, reply jsonrpc2.Replier, req jsonrpc2.Request) (err error) {
		logger.Debug("Handling request", zap.String("method", req.Method()))
		defer func() {
			if r := recover(); r != nil {
				logger.Error("panic in request handler", zap.Any("panic", r), zap.String("method", req.Method()))
				// We can't easily return the error to the client here if reply was already used,
				// but jsonrpc2 handles the return value of this func.
				err = jsonrpc2.NewError(jsonrpc2.InternalError, fmt.Sprintf("panic: %v", r))
			}
		}()

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
			m, err := json.Marshal(resp)
			if err != nil {
				return reply(ctx, resp, nil)
			}
			var customResp map[string]interface{}
			if err := json.Unmarshal(m, &customResp); err != nil || customResp == nil {
				return reply(ctx, resp, nil)
			}
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

		case "workspace/executeCommand":
			var params protocol.ExecuteCommandParams
			if err := json.Unmarshal(req.Params(), &params); err != nil {
				return reply(ctx, nil, jsonrpc2.NewError(jsonrpc2.InvalidParams, err.Error()))
			}
			resp, err := handler.ExecuteCommand(ctx, &params)
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
	return r.reader.Read(b)
}

func (r *readWriteCloser) Write(b []byte) (int, error) {
	return r.writer.Write(b)
}

func (r *readWriteCloser) Close() error {
	return multierr.Append(r.reader.Close(), r.writer.Close())
}
