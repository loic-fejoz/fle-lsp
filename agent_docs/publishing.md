# VS Code Extension Publishing & Bundling

The `fle-lsp` project uses a zero-configuration bundling strategy to simplify the user experience.

## Bundling Strategy: Platform-Specific VSIX

We do not expect the user to have Go installed. Instead, we bundle the compiled `fle-lsp` binary directly into the extension for their specific platform.

### Structure
- **Binary Location**: All binaries are placed in `vs-code-support/bin/`.
- **Naming**: 
  - Windows: `fle-lsp.exe`
  - Others: `fle-lsp`

### Client Resolution (`client.js`)
The VS Code client dynamically detects the operating system using `os.platform()` and points the language server to the correct file within the extension's `bin/` directory.

## Automated Workflow (GitHub Actions)

The `.github/workflows/extension-release.yml` uses a matrix build to produce optimized `.vsix` files for:
- `linux-x64`
- `win32-x64`
- `darwin-x64` (Intel Macs)
- `darwin-arm64` (Apple Silicon)

### Release Steps
1.  **Trigger**: Push a tag starting with `v*`.
2.  **Matrix Build**: Cross-compile the Go server for each target.
3.  **Package**: Run `npx vsce package --target <target>`.
4.  **Release**: All four `.vsix` packages are attached to the GitHub Release.

> [!TIP]
> This strategy ensures that when a user installs the extension, the Correct Binary for their machine is already included.
