# Coding Conventions

## Language Style
- Follow standard Go idioms as defined in **Effective Go**.
- Run `gofmt` (or `goimports`) before committing.
- Use `go vet` to catch common mistakes.

## Project Patterns
- **Logging**: Use the `zap` logger provided in the `Handler` struct. Avoid naked `fmt.Print` calls.
- **Error Handling**: Bubble errors up to the handler methods where they can be logged or returned as LSP error codes.
- **LSP Methods**: Maintain a clean `Handler` struct.
- **FLE Models**: Use domain-driven naming for FLE concepts (e.g., `QSO`, `Header`, `LogEvent`, `Band`, `Mode`).

## Examples
- See [handlers.go:L27-48](file:///home/loic/projets/fle-lsp/handlers.go#L27-48) for the implementation of the `Initialize` method using `go.lsp.dev/protocol` types.
