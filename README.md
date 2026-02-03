# FLE LSP 📡

[![Go Report Card](https://goreportcard.com/badge/github.com/loic-fejoz/fle-lsp)](https://goreportcard.com/report/github.com/loic-fejoz/fle-lsp)
[![CI](https://github.com/loic-fejoz/fle-lsp/actions/workflows/go.yml/badge.svg)](https://github.com/loic-fejoz/fle-lsp/actions/workflows/go.yml)
[![codecov](https://codecov.io/gh/loic-fejoz/fle-lsp/branch/master/graph/badge.svg)](https://codecov.io/gh/loic-fejoz/fle-lsp)

A high-performance [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) implementation for [Fast Log Entry (FLE)](https://df3cb.com/fle/documentation/) ham radio logbooks.

---

### ⚡ TL;DR: Quick Start

**What is it?** A tool that adds IDE-like features (errors, completions, formatting) to your FLE logging workflow.  
**Why use it?** Catch logging errors instantly, automate formatting, and navigate thousands of QSOs with ease.  
**How to start?**

1.  **Build**: `go build -o fle-lsp ./cmd/main.go`
2.  **Configure**: Add the binary to your PATH and point your favorite LSP client (VS Code, Neovim, etc.) to it.

---

## ✨ Features

FLE LSP transforms your text editor into a powerful radio logging workstation:

### 🔍 Real-time Intelligence
-   **Instant Diagnostics**: Catches syntax errors, invalid dates, and out-of-order timestamps as you type.
-   **Smart Autocomplete**:
    -   Bands (160m - 70cm) and Modes (CW, SSB, FT8, etc.).
    -   Dynamic **current UTC time** and **date** suggestions.
    -   Header keywords (`mycall`, `mygrid`, `operator`, etc.).
    -   **MyGrid**: Type `mygrid ` to auto-suggest your current Maidenhead locator from:
        -   **GPS**: Direct TCP link to local `gpsd` (supports `cgps`/`gpsmon`).
        -   **GPredict**: Configured ground stations in `~/.config/Gpredict/`.
        -   **Xastir**: Station location from `~/.xastir/config/xastir.cnf`.
-   **Contextual Hover**: Hover over any QSO to reveal:
    -   Persistent state (Date, Band, Mode).
    -   **Contact Statistics**: Number of times you've worked this callsign.
    -   **DXCC Info**: Country and entity details (supports all countries + European microstates & French territories).
-   **Quick Fixes**: Automatically correct date formats (e.g., `DD/MM/YYYY` → `YYYY-MM-DD`).

### 🛠️ Professional Layout & Formatting
-   **Auto-Formatting**: Automatically normalizes Maidenhead grids (e.g., `jn38qr` → `JN38qr`), callsigns, and modes.
-   **Document Hierarchy**: Navigate complex logs via a structured outline (Year > Month > Day > QSO).
-   **Smart Folding**: Collapse entire years or months to focus on your current session.
-   **Semantic Highlighting**: Rich, context-aware coloring for all FLE elements.

> [!TIP]
> Use the included **FLE Original** theme in VS Code for the best semantic highlighting experience.

---

## 🚀 Development Setup Guides

### VS Code
1.  Navigate to `vs-code-support/` and run `npm install`.
2.  Open the folder in VS Code and press `F5` to launch.
3.  Set your color theme to **FLE Original** (`Ctrl+K Ctrl+T`).

### Neovim (Built-in LSP)
Add this snippet to your `init.lua`:

```lua
-- 1. Register .fle filetype
vim.filetype.add({ extension = { fle = "fle" } })

-- 2. Attach LSP
vim.api.nvim_create_autocmd("FileType", {
  pattern = "fle",
  callback = function()
    vim.lsp.start({
      name = "fle-lsp",
      cmd = { "fle-lsp" }, -- Ensure fle-lsp is in your PATH
      root_dir = vim.fn.getcwd(),
    })
  end,
})

-- 3. Map LSP semantic tokens to colors
vim.api.nvim_set_hl(0, "@lsp.type.keyword.fle", { link = "Keyword" })
vim.api.nvim_set_hl(0, "@lsp.type.variable.fle", { bold = true })
vim.api.nvim_set_hl(0, "@lsp.type.string.fle", { link = "String" })
vim.api.nvim_set_hl(0, "@lsp.type.number.fle", { link = "Number", bold = true })
vim.api.nvim_set_hl(0, "@lsp.type.type.fle", { link = "Keyword" })
vim.api.nvim_set_hl(0, "@lsp.type.macro.fle", { link = "Keyword" })
vim.api.nvim_set_hl(0, "@lsp.type.date.fle", { link = "Function" })
vim.api.nvim_set_hl(0, "@lsp.type.name.fle", { foreground = "#8b4513" })
vim.api.nvim_set_hl(0, "@lsp.type.extra.fle", { foreground = "#8b4513" })
```

> [!IMPORTANT]
> Ensure the `fle-lsp` binary is in your system PATH or provide the absolute path in the `cmd` table.

---

## 🛠️ Development

### Local Build
```bash
go build -o fle-lsp ./cmd/main.go
```

### Quality Control
```bash
make lint    # Run golangci-lint
go test ./... # Run full test suite
```

---

## 📚 Resources
*   [Official FLE Documentation](https://df3cb.com/fle/documentation/)
*   [LSP Specification](https://microsoft.github.io/language-server-protocol/)

---
*Maintained by [F4JXQ](https://github.com/loic-fejoz)*