# FLE LSP Client

An experimental VS Code extension providing rich language support for **Fast Log Entry (FLE)** files using a dedicated Language Server Protocol (LSP) server.

## Features

- **Syntax Highlighting**: Semantic tokens for bands, modes, callsigns, etc.
- **Diagnostics**: Highlights errors in your FLE logs as you type.
- **Auto-completion**:
    - Suggestions for keywords, bands, modes, and current UTC time/date.
    - **MyGrid**: Type `mygrid ` to auto-suggest your current Maidenhead locator from **GPSD** (direct TCP), **GPredict**, or **Xastir** configs.
- **Contextual Hover**: View detailed information including:
    - Persistent state (Date, Band, Mode).
    - **Contact Statistics**: See how many times you've worked a callsign.
    - **DXCC Info**: Instant country/entity lookup (supports all countries, European microstates & French territories).
- **Code Actions**: Quick Fixes for common issues like correcting date formats (`DD/MM/YYYY` -> `YYYY-MM-DD`).
- **Document Outline**: Navigate your logbook by Year, Month, and Day.
- **Folding**: Collapse sections of your log to keep it organized.
- **Formatting**: Normalize your log entries automatically.
- **Export to GeoJSON**: Command Palette (`FLE: Convert to GeoJSON`) or Code Action to visualize your QSOs. Auto-opens the resulting file.

## Requirements

- `fle-lsp` binary must be installed and available in your PATH.

## Installation

This extension is currently in development. To use it:
1. Clone the repository.
2. Build the `fle-lsp` Go server.
3. Link or sideload the extension into VS Code.

## License

MIT
