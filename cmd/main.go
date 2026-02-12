// Package main is the entry point for the fle-lsp server.
package main

import (
	flelsp "github.com/loic-fejoz/fle-lsp"
	"go.uber.org/zap"
)

func main() {
	logger, err := zap.NewDevelopmentConfig().Build()
	if err != nil {
		panic("failed to initialize logger: " + err.Error())
	}
	defer func() {
		_ = logger.Sync()
	}()

	// Start the server
	logger.Sugar().Info("Starting the server...")
	flelsp.StartServer(logger)
}
