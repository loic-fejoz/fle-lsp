fle-lsp: cmd/main.go handlers.go models.go  parser.go server.go  unimplemented.go
	go build -o fle-lsp ./cmd/main.go

test:
	go test -v ./...

lint:
	golangci-lint run

coverage:
	go test -coverprofile=coverage.out ./...
	go tool cover -html=coverage.out
