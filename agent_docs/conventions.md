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

## Domain Specifics

### Line Normalization
- All formatting logic should reside in or be accessible from `Handler.normalizeLine`.
- **Headers**: Key-value pairs should be lowercase key followed by a space (e.g., `mycall F4JXQ`).
- **Uppercasing**: `mycall` and `operator` header values MUST be uppercased.
- **Grids**: Use the `formatGrid` helper to ensure correct casing (e.g., `JN38qr`, `JN38`).
- **QSOs**: Time, callsign, and reports should be consistently formatted.

## Examples
- See [handlers.go:L27-48](file:///home/loic/projets/fle-lsp/handlers.go#L27-48) for the implementation of the `Initialize` method using `go.lsp.dev/protocol` types.
