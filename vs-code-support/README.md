# FLE LSP Client

An experimental VS Code extension providing rich language support for **Fast Log Entry (FLE)** files using a dedicated Language Server Protocol (LSP) server.

## Features

- **Syntax Highlighting**: Semantic tokens for bands, modes, callsigns, etc.
- **Diagnostics**: Highlights errors in your FLE logs as you type.
- **Auto-completion**: Suggestions for keywords, bands, modes, and current UTC time/date.
- **Hover Support**: View detailed QSO information under the cursor.
- **Document Outline**: Navigate your logbook by Year, Month, and Day.
- **Folding**: Collapse sections of your log to keep it organized.
- **Formatting**: Normalize your log entries automatically.

## Requirements

- `fle-lsp` binary must be installed and available in your PATH.

## Installation

This extension is currently in development. To use it:
1. Clone the repository.
2. Build the `fle-lsp` Go server.
3. Link or sideload the extension into VS Code.

## License

MIT
