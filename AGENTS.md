# Agent Guidance (fle-lsp)

## Mission
To provide a high-performance Language Server for Fast Log Entry (FLE) files, enabling features like syntax highlighting, diagnostics, and completions in modern editors.

## Critical Commands
- **Build**: `go build -o fle-lsp ./cmd/main.go`
- **Test**: `go test ./...`
- **Coverage**: `go test -cover ./...`
- **Lint**: `go vet ./...`

## Directory Map
- `root/`: Core library logic (`server.go`, `handlers.go`, `parser.go`, `models.go`).
- `cmd/`: CLI entry point for the server.
- `vs-code-support/`: Extension metadata and bundling logic.
- `agent_docs/`: Technical deep-dives (Architecture, Conventions, Testing).
- `.github/workflows/`: CI/CD pipelines (Go CI, Extension Release).

## Documentation Index
Read these files in `agent_docs/` to understand specific areas before contributing:
1. [Architecture](file:///home/loic/projets/fle-lsp/agent_docs/architecture.md): LSP lifecycle, **FoldingRanges**, and **RangeFormatting**.
2. [Testing Guidelines](file:///home/loic/projets/fle-lsp/agent_docs/testing_guidelines.md): CI/CD, coverage thresholds, and golden-file tests.
3. [Conventions](file:///home/loic/projets/fle-lsp/agent_docs/conventions.md): Code style, domain models, and **Line Normalization**.
4. [Publishing](file:///home/loic/projets/fle-lsp/agent_docs/publishing.md): **Platform-Specific Bundling** for VS Code.

## Linter Guidelines
- We use **golangci-lint v2**.
- Configuration is in `.golangci.yml` (requires `version: "2"`).
- **Mandatory**: Always run `make lint` and ensure it passes before building your walkthrough or finalizing a task.

> [!IMPORTANT]
> Always run the build/test commands before finishing a task to ensure the server remains functional.
