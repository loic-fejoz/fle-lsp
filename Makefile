SRCS := $(shell find . -type f -name "*.go" -not -name "*_test.go")

fle-lsp: $(SRCS)
	go build -o fle-lsp ./cmd/main.go

test:
	go test -v ./...

lint:
	golangci-lint run

coverage:
	go test -coverprofile=coverage.out ./...
	go tool cover -html=coverage.out
