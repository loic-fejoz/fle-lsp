# Contributing

Thank you for considering contributing to the FLE LSP Client!

## Development Setup

1.  **Clone the repository**:
    ```bash
    git clone https://github.com/loic-fejoz/fle-lsp.git
    cd fle-lsp/vs-code-support
    ```

2.  **Install dependencies**:
    ```bash
    npm install
    ```

3.  **Build the LSP Server**:
    Ensure you have Go installed and build the server from the root directory:
    ```bash
    go build -o fle-lsp ./cmd/main.go
    ```
    The extension expects the `fle-lsp` binary to be available in your PATH or in the root of the project (configure `client.js` if needed).

## Running the Extension

1.  Open the `vs-code-support` folder in VS Code.
2.  Press `F5` to open a "Extension Development Host" window.
3.  Open an `.fle` file to see the extension in action.

## Testing

- Unit tests for the LSP server are located in the root directory.
- Run them with: `go test ./...`
