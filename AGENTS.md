# Agent Guidance (fle-lsp)

## Mission
To provide a high-performance Language Server for Fast Log Entry (FLE) files, enabling features like syntax highlighting, diagnostics, and completions in modern editors.

## Critical Commands
- **Build**: `go build -o fle-lsp ./cmd/main.go`
- **Test**: `go test ./...`
- **Lint**: `go vet ./...`

## Directory Map
- `root/`: Core library logic (`server.go`, `handlers.go`).
- `cmd/`: CLI entry point for the server.
- `vs-code-support/`: Extension metadata for VS Code integration.

## Documentation Index
Read these files in `agent_docs/` to understand specific areas before contributing:
1. [Architecture](file:///home/loic/projets/fle-lsp/agent_docs/architecture.md): LSP lifecycle, transport, and **Parsing Strategy**.
2. [Testing Guidelines](file:///home/loic/projets/fle-lsp/agent_docs/testing_guidelines.md): How to verify changes.
3. [Conventions](file:///home/loic/projets/fle-lsp/agent_docs/conventions.md): Code style and **FLE Domain Models**.

> [!IMPORTANT]
> Always run the build/vet commands before finishing a task to ensure the server remains functional.
