# Testing Guidelines

## Current State
The project has robust test coverage (~74%) including unit tests for handlers and golden-file tests for the parser.

## Running Tests
Standard Go toolchain:
```bash
go test ./...
```

## Coverage
Summary report:
```bash
go test -cover ./...
```
Detailed HTML report:
```bash
go test -coverprofile=coverage.out ./...
go tool cover -html=coverage.out
```

## Adding Tests
- **Unit Tests**: Place in `*_test.go` files (e.g., `handlers_test.go`).
- **Mocking**: Use the `mockClient` pattern in `handlers_test.go` to simulate LSP client interactions.
- **Golden-File Tests**: Use `parser_golden_test.go` to test parser behavior against complex `.fle` files.

## CI/CD Enforcement
The CI/CD pipeline (`.github/workflows/go.yml`) enforces the following:
- **Linting**: All code must pass `golangci-lint` with the rules defined in `.golangci.yml`.
- **Coverage**: A minimum statement coverage of **70%** is required.
- **Reporting**: Coverage reports are automatically uploaded to Codecov.

## Performance
Tests should be fast. Use `testing.Short()` to skip long-running simulations if applicable.
