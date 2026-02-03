# LSP for FLE

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) implementation for hamradio logbook in [Fast Log Entry](https://df3cb.com/fle/documentation/) format.

## Development

### Building
```bash
go build -o fle-lsp ./cmd/main.go
```

### Testing with VSCode

1. Build the server binary in the root directory:
   ```bash
   go build -o fle-lsp ./cmd/main.go
   ```
2. Navigate to `vs-code-support/`:
   ```bash
   cd vs-code-support
   npm install
   ```
3. Open the `vs-code-support` folder in a new VSCode window.
4. Press `F5` to start a new "Extension Development Host" window.
5. In the new window, open any `.fle` file (or create one).
6. You should see the LSP status and real-time diagnostics!
7. **Syntax Highlighting**: To get the original FLE look, press `Ctrl+K Ctrl+T` and select the **FLE Original** theme.

## Resources

* [Fast Log Entry Documentation](https://df3cb.com/fle/documentation/)
* [Making an LSP server in Go](https://en.ewen.works/blog/making-an-lsp-server-in-go)