package flelsp

import (
	"context"
	"strings"
	"testing"
	"time"

	"go.lsp.dev/protocol"
	"go.uber.org/zap"
)

// mockClient implements protocol.Client for testing
type mockClient struct {
	diagnostics map[protocol.DocumentURI][]protocol.Diagnostic
}

func (m *mockClient) Progress(_ context.Context, _ *protocol.ProgressParams) error { return nil }
func (m *mockClient) WorkDoneProgressCreate(_ context.Context, _ *protocol.WorkDoneProgressCreateParams) error {
	return nil
}
func (m *mockClient) LogMessage(_ context.Context, _ *protocol.LogMessageParams) error {
	return nil
}
func (m *mockClient) PublishDiagnostics(_ context.Context, params *protocol.PublishDiagnosticsParams) error {
	if m.diagnostics == nil {
		m.diagnostics = make(map[protocol.DocumentURI][]protocol.Diagnostic)
	}
	m.diagnostics[params.URI] = params.Diagnostics
	return nil
}
func (m *mockClient) ShowMessage(_ context.Context, _ *protocol.ShowMessageParams) error {
	return nil
}
func (m *mockClient) ShowMessageRequest(_ context.Context, _ *protocol.ShowMessageRequestParams) (*protocol.MessageActionItem, error) {
	return nil, nil
}
func (m *mockClient) Telemetry(_ context.Context, _ interface{}) error { return nil }
func (m *mockClient) RegisterCapability(_ context.Context, _ *protocol.RegistrationParams) error {
	return nil
}
func (m *mockClient) UnregisterCapability(_ context.Context, _ *protocol.UnregistrationParams) error {
	return nil
}
func (m *mockClient) ApplyEdit(_ context.Context, _ *protocol.ApplyWorkspaceEditParams) (bool, error) {
	return true, nil
}
func (m *mockClient) Configuration(_ context.Context, _ *protocol.ConfigurationParams) ([]interface{}, error) {
	return nil, nil
}
func (m *mockClient) WorkspaceFolders(_ context.Context) ([]protocol.WorkspaceFolder, error) {
	return nil, nil
}

func setupTestHandler(t *testing.T, content string) (*Handler, *mockClient) {
	logger := zap.NewNop()
	client := &mockClient{}
	h, _, _ := NewHandler(context.Background(), client, logger)

	if content != "" {
		uri := protocol.DocumentURI("file:///test.fle")
		if err := h.DidOpen(context.Background(), &protocol.DidOpenTextDocumentParams{
			TextDocument: protocol.TextDocumentItem{
				URI:  uri,
				Text: content,
			},
		}); err != nil {
			t.Fatalf("setupTestHandler: DidOpen failed: %v", err)
		}
	}

	return h, client
}

func TestHandler_Hover(t *testing.T) {
	content := "mycall F4JXQ\ndate 2026-02-01\n40m cw\n1200 EA1ABC 599 599"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// Hover over the QSO line (line 3, 0-indexed)
	params := &protocol.HoverParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
			Position:     protocol.Position{Line: 3, Character: 5},
		},
	}

	hover, err := h.Hover(context.Background(), params)
	if err != nil {
		t.Fatalf("Hover failed: %v", err)
	}
	if hover == nil {
		t.Fatal("Expected hover result, got nil")
	}

	wantSub := "EA1ABC"
	if !strings.Contains(hover.Contents.Value, wantSub) {
		t.Errorf("Hover content %q does not contain %q", hover.Contents.Value, wantSub)
	}
}

func TestHandler_Completion(t *testing.T) {
	content := "mycall F4JXQ\ndate 2026-02-01\n40m "
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// Complete after '40m '
	params := &protocol.CompletionParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
			Position:     protocol.Position{Line: 2, Character: 4},
		},
	}

	list, err := h.Completion(context.Background(), params)
	if err != nil {
		t.Fatalf("Completion failed: %v", err)
	}

	found := false
	for _, item := range list.Items {
		if item.Label == "CW" {
			found = true
			break
		}
	}
	if !found {
		t.Error("Expected 'CW' in completion items")
	}
}

func TestHandler_DocumentSymbol(t *testing.T) {
	content := "mycall F4JXQ\ndate 2026-02-01\n40m cw\n1200 EA1ABC"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	params := &protocol.DocumentSymbolParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
	}

	symbols, err := h.DocumentSymbol(context.Background(), params)
	if err != nil {
		t.Fatalf("DocumentSymbol failed: %v", err)
	}

	// Because there is only one day/month/year, it should return the day level directly or QSOs depending on implementation
	// Looking at handlers.go, if showYear and showMonth are false (one year/month only), it returns month.Children (days)
	if len(symbols) == 0 {
		t.Fatal("Expected symbols, got 0")
	}
}

func TestHandler_SemanticTokensFull(t *testing.T) {
	content := "mycall F4JXQ\ndate 2026-02-01\n40m cw\n1200 EA1ABC"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	params := &protocol.SemanticTokensParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
	}

	tokens, err := h.SemanticTokensFull(context.Background(), params)
	if err != nil {
		t.Fatalf("SemanticTokensFull failed: %v", err)
	}

	if tokens == nil || len(tokens.Data) == 0 {
		t.Fatal("Expected semantic tokens, got none")
	}
}

func TestHandler_ErrorCases(t *testing.T) {
	h, _ := setupTestHandler(t, "")

	t.Run("MissingDocument", func(t *testing.T) {
		uri := protocol.DocumentURI("file:///nonexistent.fle")
		params := &protocol.HoverParams{
			TextDocumentPositionParams: protocol.TextDocumentPositionParams{
				TextDocument: protocol.TextDocumentIdentifier{URI: uri},
				Position:     protocol.Position{Line: 0, Character: 0},
			},
		}
		res, err := h.Hover(context.Background(), params)
		if err != nil {
			t.Errorf("Expected no error for missing document in Hover, got %v", err)
		}
		if res != nil {
			t.Error("Expected nil result for missing document in Hover")
		}
	})

	t.Run("SemanticTokensMissingDoc", func(t *testing.T) {
		uri := protocol.DocumentURI("file:///nonexistent.fle")
		params := &protocol.SemanticTokensParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
		}
		_, err := h.SemanticTokensFull(context.Background(), params)
		if err == nil {
			t.Error("Expected error for missing document in SemanticTokensFull")
		}
	})
}

func TestHandler_FoldingRange(t *testing.T) {
	content := `mycall F4JXQ
date 2026-02-01
40m cw
1200 EA1ABC
date 2026-02-02
1300 G4XYZ`
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	params := &protocol.FoldingRangeParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
		},
	}

	ranges, err := h.FoldingRanges(context.Background(), params)
	if err != nil {
		t.Fatalf("FoldingRanges failed: %v", err)
	}

	// We expect one range for the first day (lines 1-3, 0-indexed)
	// and one range for the second day (line 5... wait, 1300 G4XYZ is line 5)
	// Actually, day 1 is lines 1, 2, 3. Day 2 is lines 4, 5.
	// But first day starts at line 1 (date 2026-02-01) and ends at line 3 (1200 EA1ABC).
	// Second day starts at line 4 (date 2026-02-02) and ends at line 5 (1300 G4XYZ).
	if len(ranges) == 0 {
		t.Fatal("Expected folding ranges, got 0")
	}

	// Verify at least one range exists
	found := false
	for _, r := range ranges {
		if (r.StartLine == 0 || r.StartLine == 1) && r.EndLine == 3 {
			found = true
			break
		}
	}
	if !found {
		t.Errorf("Expected range for first day (covering 1-3), got %v", ranges)
	}
}

func TestHandler_Completion_DateToday(t *testing.T) {
	// Content already has a date
	content := "mycall F4JXQ\ndate 2026-02-01\n"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// Trigger completion at start of 3rd line
	params := &protocol.CompletionParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
			Position:     protocol.Position{Line: 2, Character: 0},
		},
	}

	list, err := h.Completion(context.Background(), params)
	if err != nil {
		t.Fatalf("Completion failed: %v", err)
	}

	dateToday := time.Now().UTC().Format("2006-01-02")
	wantLabel := "date " + dateToday
	found := false
	for _, item := range list.Items {
		if item.Label == wantLabel {
			found = true
			break
		}
	}

	if !found {
		t.Errorf("Expected completion item %q not found in %v", wantLabel, list.Items)
	}
}
