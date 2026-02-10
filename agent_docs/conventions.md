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

## Security Best Practices
- **ReDoS Immunity**: Always use the standard `regexp` package (RE2 based). **DO NOT** use backtracking regex libraries (e.g., `regexp2`) without explicit justification and vulnerability analysis.
- **Network I/O**: When reading from network connections (especially `net.Conn`), **ALWAYS** wrap the reader in `io.LimitReader` to prevent memory exhaustion DoS.
- **Path Parsing**: Sanitize and validate all file paths used in `os.Open` or `exec.Command`. Ensure they reside within expected directories.

## Code Safe-Guards
- **Bounds Checking**: **ALWAYS** check `len()` or indices before slicing strings or arrays/slices.
  ```go
  // Bad
  val := line[start:end]
  // Good
  if end <= len(line) { val := line[start:end] }
  ```
- **Nil Safety**: Add defensive checks for optional pointers before dereferencing, especially in deep struct hierarchies (e.g., LSP `DocumentSymbol` trees).
- **Error Checking**: explicitly handle errors from conversion functions like `strconv.Atoi` or `strconv.ParseFloat`. Do not blindly ignore them with `_`.

## Coding Convention Refinements

### Naming Patterns
- **Acronyms**: Prefer all-caps for acronyms in variable names (e.g., `geoJSONPath` instead of `geoJsonPath`). This aligns with Go's style guide and is enforced by many linters.

### Linting & Static Analysis
- **Unchecked Errors**: Always check the return value of client methods like `h.Client.ShowMessage`. Linters (e.g., `errcheck`) will flag unchecked errors even on notifications.
- **Unused Parameters**: In callback functions (e.g., `sync.Map.Range`), use `_` for unused parameters to satisfy `revive`.

## Examples
- See [handlers.go:L27-55](file:///home/loic/projets/fle-lsp/handlers.go#L27-55) for initialization and capability detection.
- See [handlers.go:L160-178](file:///home/loic/projets/fle-lsp/handlers.go#L160-178) for the `showDocument` fallback pattern.
