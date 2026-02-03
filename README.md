# LSP for FLE

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) implementation for hamradio logbook in [Fast Log Entry](https://df3cb.com/fle/documentation/) format.

## Features

- **Real-time Diagnostics**: Immediate feedback on syntax errors, invalid dates, and time monotonicity.
- **Semantic Highlighting**: Rich coloring for callsigns, bands, modes, times, and operator comments (requires **FLE Original** theme).
- **Smart Autocompletion**:
  - Context-aware suggestions for **Bands** and **Modes**.
  - **Current UTC time** suggestions at the start of a line for real-time logging.
  - **Current UTC date** suggestions (e.g., `date 2026-02-03`) if no date is present.
  - Header keywords suggestions.
- **Document Formatting**:
  - Automatic normalization of **Maidenhead grids** (e.g., `jn38qr` -> `JN38qr`).
  - Normalization of casing for callsigns and modes.
  - Clean whitespace management for QSO lines.
- **Outline & Navigation**: Full support for the VSCode Outline view, allowing navigation by year, month, and day.
- **Enhanced Hover Info**: Hover over any QSO to see its persistent context (Date, Band, Mode).

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

### Testing with Vim (Neovim)

For Neovim users using the built-in LSP client, you can test the server by adding this to your `init.lua` (usually located at `~/.config/nvim/init.lua` on Linux/macOS):

```lua
-- 1. Ensure .fle files are recognized
vim.filetype.add({
  extension = {
    fle = "fle",
  },
})

-- 2. Start the LSP server for 'fle' files
vim.api.nvim_create_autocmd("FileType", {
  pattern = "fle",
  callback = function()
    vim.lsp.start({
      name = "fle-lsp",
      cmd = { "/home/loic/projets/fle-lsp/fle-lsp" }, -- Absolute path to binary
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
#### Verifying Neovim Setup

1.  **Check LSP Status**: Open a `.fle` file in Neovim and run `:LspInfo`. You should see `fle-lsp` listed as an active client.
2.  **Inspect Logs**: If it's not working, run `:LspLog` to see the communication between Neovim and the server.
3.  **Validate Path**: Ensure the `cmd` path in your `init.lua` is the **absolute path** to the compiled `fle-lsp` binary.
4.  **Test Diagnostics**: Type an invalid date (e.g., `date 2026-13-45`) and save. You should see a diagnostic message.

If you use `coc.nvim`, add this to your `coc-settings.json`:

```json
{
  "languageserver": {
    "fle": {
      "command": "/absolute/path/to/fle-lsp",
      "filetypes": ["fle", "fastlogentry"],
      "rootPatterns": [".git/"]
    }
  }
}
```

## Resources

* [Fast Log Entry Documentation](https://df3cb.com/fle/documentation/)
* [Making an LSP server in Go](https://en.ewen.works/blog/making-an-lsp-server-in-go)