# Editor Integration Guide

This document outlines the setup and configuration for various editors supporting `fle-lsp`.

## 1. Zed
The Zed extension is a hybrid solution providing both Tree-sitter highlighting and LSP services.

### Installation
- Build the LSP: `go build -o fle-lsp ./cmd/main.go`
- Install the extension as a "Dev Extension" by dragging the `zed-support` folder into Zed.

### Configuration
Update your `settings.json`:
```json
{
  "lsp": {
    "fle": {
      "binary": { "path": "/path/to/fle-lsp" }
    }
  }
}
```

## 2. Helix (`hx`)
Helix uses Tree-sitter for highlighting and `languages.toml` for LSP.

### Configuration
Add to `~/.config/helix/languages.toml`:
```toml
[[language]]
name = "fle"
scope = "source.fle"
file-types = ["fle"]
language-servers = [ "fle-lsp" ]

[language-server.fle-lsp]
command = "fle-lsp"
```

### Queries
Copy `zed-support/languages/fle/highlights.scm` to your Helix runtime:
`cp zed-support/languages/fle/highlights.scm ~/.config/helix/runtime/queries/fle/highlights.scm`

## 3. Neovim
Use the built-in LSP client.

### Setup
```lua
vim.filetype.add({ extension = { fle = "fle" } })
vim.api.nvim_create_autocmd("FileType", {
  pattern = "fle",
  callback = function()
    vim.lsp.start({
      name = "fle-lsp",
      cmd = { "fle-lsp" },
      root_dir = vim.fn.getcwd(),
    })
  end,
})
```

## 4. VS Code
The extension is available in the `vs-code-support` directory for local side-loading.
