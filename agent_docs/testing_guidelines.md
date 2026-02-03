# Testing Guidelines

## Current State
The project currently has a minimal set of tests. Establishing robust test coverage is a priority.

## Running Tests
Use the standard Go toolchain:
```bash
go test ./...
```

## Adding Tests
- **Unit Tests**: Place tests in the same package as the code they test (e.g., `handlers_test.go`).
- **Mocking**: Leverage the `protocol.Server` and `protocol.Client` interfaces from `go.lsp.dev/protocol` to mock LSP interactions.
- **Integration Tests**: Consider using a mock JSON-RPC connection to test the full lifecycle of a request through the `Handler`.

## Performance
Tests should be fast. Use `testing.Short()` to skip long-running simulations if applicable.
