package flelsp

import (
	"context"
	"os"
	"path/filepath"
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
	h, _, _ := NewHandler(context.Background(), client, nil, logger)

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
	content := "mycall F4JXQ\ndate 2026-02-01\n40m cw\n1200 EA1ABC 599 599\n1205 EA1ABC 579 589"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// Hover over the first QSO line (line 3, 0-indexed)
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

	wantCountry := "**Country:** Spain"
	if !strings.Contains(hover.Contents.Value, wantCountry) {
		t.Errorf("Hover content %q does not contain %q", hover.Contents.Value, wantCountry)
	}

	wantCount := "**Times Contacted:** 2"
	if !strings.Contains(hover.Contents.Value, wantCount) {
		t.Errorf("Hover content %q does not contain %q", hover.Contents.Value, wantCount)
	}

	wantQRZ := "[QRZ](https://www.qrz.com/db/EA1ABC)"
	if !strings.Contains(hover.Contents.Value, wantQRZ) {
		t.Errorf("Hover content %q does not contain %q", hover.Contents.Value, wantQRZ)
	}

	wantHamQTH := "[HamQTH](https://www.hamqth.com/EA1ABC)"
	if !strings.Contains(hover.Contents.Value, wantHamQTH) {
		t.Errorf("Hover content %q does not contain %q", hover.Contents.Value, wantHamQTH)
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

func TestHandler_Completion_MyGrid(t *testing.T) {
	tmpDir, err := os.MkdirTemp("", "gpredict_test_completion")
	if err != nil {
		t.Fatal(err)
	}
	defer func() { _ = os.RemoveAll(tmpDir) }()

	qthFile := filepath.Join(tmpDir, "Home.qth")
	contentFile := "[QTH]\nLAT=48.8583\nLON=2.2945\n"
	if err := os.WriteFile(qthFile, []byte(contentFile), 0600); err != nil {
		t.Fatal(err)
	}

	content := "mygrid "
	h, _ := setupTestHandler(t, content)
	h.locationSources = []LocationSource{{
		Name: "GPredict: Home",
		Path: qthFile,
		Type: SourceGPredict,
	}}
	uri := protocol.DocumentURI("file:///test.fle")

	params := &protocol.CompletionParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
			Position:     protocol.Position{Line: 0, Character: 7},
		},
	}

	list, err := h.Completion(context.Background(), params)
	if err != nil {
		t.Fatalf("Completion failed: %v", err)
	}

	found := false
	for _, item := range list.Items {
		if strings.Contains(item.Label, "JN18du") {
			found = true
			break
		}
	}
	if !found {
		t.Error("Expected grid 'JN18du' in completion items for mygrid")
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

func TestHandler_RangeFormatting(t *testing.T) {
	content := `mycall f4jxq
date 2026-02-01
40m cw
1200 ea1abc #jn38qr`
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// Format only the first line (mycall) and last line (QSO)
	// We'll do two separate range requests or one that covers a middle part but we want to see it NOT format the middle if excluded.
	// Actually, let's just test a single range.
	params := &protocol.DocumentRangeFormattingParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
		Range: protocol.Range{
			Start: protocol.Position{Line: 0, Character: 0},
			End:   protocol.Position{Line: 0, Character: 12},
		},
	}

	edits, err := h.RangeFormatting(context.Background(), params)
	if err != nil {
		t.Fatalf("RangeFormatting failed: %v", err)
	}

	if len(edits) != 1 {
		t.Fatalf("Expected 1 edit for the first line, got %d", len(edits))
	}

	if edits[0].NewText != "mycall F4JXQ" {
		t.Errorf("Expected formatted mycall 'mycall F4JXQ', got %q", edits[0].NewText)
	}

	// Test formatting the last line
	params.Range = protocol.Range{
		Start: protocol.Position{Line: 3, Character: 0},
		End:   protocol.Position{Line: 3, Character: 20},
	}

	edits, err = h.RangeFormatting(context.Background(), params)
	if err != nil {
		t.Fatalf("RangeFormatting failed: %v", err)
	}

	if len(edits) != 1 {
		t.Fatalf("Expected 1 edit for the last line, got %d", len(edits))
	}

	// ea1abc -> EA1ABC, jn38qr -> JN38qr
	if edits[0].NewText != "1200 EA1ABC #JN38qr" {
		t.Errorf("Expected formatted QSO '1200 EA1ABC #JN38qr', got %q", edits[0].NewText)
	}
}

func TestHandler_CodeAction(t *testing.T) {
	// 1. Missing mycall header & Lowercase callsign
	content := "date 2026-02-01\n40m cw\n1200 ea1abc"
	h, client := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// Verify diagnostics are present
	diags := client.diagnostics[uri]
	var missingMyCallDiag *protocol.Diagnostic
	var lowercaseCallDiag *protocol.Diagnostic
	for _, d := range diags {
		if d.Code == CodeMissingMyCall {
			missingMyCallDiag = &d
		}
		if d.Code == CodeLowercaseCallsign {
			lowercaseCallDiag = &d
		}
	}
	if missingMyCallDiag == nil {
		t.Fatal("Expected CodeMissingMyCall diagnostic")
	}
	if lowercaseCallDiag == nil {
		t.Fatal("Expected CodeLowercaseCallsign diagnostic")
	}

	params := &protocol.CodeActionParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
		Context: protocol.CodeActionContext{
			Diagnostics: []protocol.Diagnostic{*missingMyCallDiag},
		},
	}

	actions, err := h.CodeAction(context.Background(), params)
	if err != nil {
		t.Fatalf("CodeAction failed: %v", err)
	}

	found := false
	for _, a := range actions {
		if a.Title == "Insert missing 'mycall' header" {
			found = true
			if len(a.Edit.Changes[uri]) != 1 {
				t.Errorf("Expected 1 edit, got %d", len(a.Edit.Changes[uri]))
			}
			if a.Edit.Changes[uri][0].NewText != "mycall MYCALL\n" {
				t.Errorf("Expected 'mycall MYCALL\\n', got %q", a.Edit.Changes[uri][0].NewText)
			}
			break
		}
	}
	if !found {
		t.Error("Quick fix for missing mycall not found")
	}

	// Test Lowercase callsign
	params.Context.Diagnostics = []protocol.Diagnostic{*lowercaseCallDiag}
	actions, err = h.CodeAction(context.Background(), params)
	if err != nil {
		t.Fatalf("CodeAction failed: %v", err)
	}

	found = false
	for _, a := range actions {
		if strings.Contains(a.Title, "Uppercase callsign") {
			found = true
			if a.Edit.Changes[uri][0].NewText != "EA1ABC" {
				t.Errorf("Expected 'EA1ABC', got %q", a.Edit.Changes[uri][0].NewText)
			}
			break
		}
	}
	if !found {
		t.Error("Quick fix for lowercase callsign not found")
	}

	// 2. Fix date format
	content = "mycall F4JXQ\ndate 2026/02/01\n40m cw\n1200 EA1ABC"
	h, client = setupTestHandler(t, content)
	diags = client.diagnostics[uri]
	var invalidDateDiag *protocol.Diagnostic
	for _, d := range diags {
		if d.Code == CodeInvalidDate {
			invalidDateDiag = &d
			break
		}
	}
	if invalidDateDiag == nil {
		t.Fatal("Expected CodeInvalidDate diagnostic")
	}

	params.Context.Diagnostics = []protocol.Diagnostic{*invalidDateDiag}
	actions, err = h.CodeAction(context.Background(), params)
	if err != nil {
		t.Fatalf("CodeAction failed: %v", err)
	}

	found = false
	for _, a := range actions {
		if a.Title == "Fix date format to YYYY-MM-DD" {
			found = true
			if a.Edit.Changes[uri][0].NewText != "2026-02-01" {
				t.Errorf("Expected '2026-02-01', got %q", a.Edit.Changes[uri][0].NewText)
			}
			break
		}
	}
	if !found {
		t.Error("Quick fix for invalid date format not found")
	}

	// 3. Fix European date format
	content = "mycall F4JXQ\ndate 31/12/2026\n40m cw\n1200 EA1ABC"
	h, client = setupTestHandler(t, content)
	diags = client.diagnostics[uri]
	invalidDateDiag = nil
	for _, d := range diags {
		if d.Code == CodeInvalidDate {
			invalidDateDiag = &d
			break
		}
	}
	if invalidDateDiag == nil {
		t.Fatal("Expected CodeInvalidDate diagnostic for European date")
	}

	params.Context.Diagnostics = []protocol.Diagnostic{*invalidDateDiag}
	actions, err = h.CodeAction(context.Background(), params)
	if err != nil {
		t.Fatalf("CodeAction failed: %v", err)
	}

	found = false
	for _, a := range actions {
		if a.Title == "Fix European date format to YYYY-MM-DD" {
			found = true
			if a.Edit.Changes[uri][0].NewText != "2026-12-31" {
				t.Errorf("Expected '2026-12-31', got %q", a.Edit.Changes[uri][0].NewText)
			}
			break
		}
	}
	if !found {
		t.Error("Quick fix for European date format not found")
	}
}

func TestHandler_InlayHint(t *testing.T) {
	content := `mycall F4JXQ
mygrid JN38qr
date 2026-02-01
40m cw
1200 EA1ABC 59 55
1205 DL/F4JXQ/P
mygrid JN39aa
1210 G4XYZ 599 #JN18du`
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	params := &InlayHintParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
		Range:        protocol.Range{}, // Range is often ignored for this specific hint
	}

	hints, err := h.InlayHint(context.Background(), params)
	if err != nil {
		t.Fatalf("InlayHint failed: %v", err)
	}

	// 1 (summary) + 1 (daily stats) + 2 (RST for EA1ABC) + 1 (distance/bearing for G4XYZ) + 1 (RST for G4XYZ) = 6
	if len(hints) != 6 {
		t.Fatalf("Expected 6 inlay hints, got %d", len(hints))
	}

	summaryHint := hints[0]
	wantSummary := "Total QSOs: 3 | Callsigns: 3 | Activated Grids: 2 | Collected Grids: 1 | ODX: 275km"
	if summaryHint.Label != wantSummary {
		t.Errorf("Expected summary label %q, got %q", wantSummary, summaryHint.Label)
	}

	// Second inlay hint should be the Daily Statistics for 2026-02-01
	dailyHint := hints[1]
	if !strings.Contains(dailyHint.Label, "Daily QSOs: 3") || !strings.Contains(dailyHint.Label, "Callsigns: 3") {
		t.Errorf("Expected daily statistics hint, got %q", dailyHint.Label)
	}

	// First QSO: EA1ABC 59 55 -> Should have Sent: and Received: hints
	sentHint := hints[2]
	if sentHint.Label != "Sent: " {
		t.Errorf("Expected 'Sent: ', got %q", sentHint.Label)
	}
	receivedHint := hints[3]
	if receivedHint.Label != "Received: " {
		t.Errorf("Expected 'Received: ', got %q", receivedHint.Label)
	}

	// Third QSO: G4XYZ #JN18du 599 -> Should have Sent: and distance/bearing
	gridHint := hints[4] // order might depend on implementation, but let's check
	// JN39aa to JN18du is approx 374km 258°
	if !strings.Contains(gridHint.Label, "km") || !strings.Contains(gridHint.Label, "°") {
		// Maybe it's the other way around?
		gridHint = hints[5]
	}
	if !strings.Contains(gridHint.Label, "km") || !strings.Contains(gridHint.Label, "°") {
		t.Errorf("Expected grid hint to contain distance and bearing, got %q", gridHint.Label)
	}
}
func TestHandler_Completion_SmartFiltering(t *testing.T) {
	content := "mycall F4JXQ/P\nmysota HU-001\n"
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

	hasMySota := false
	hasMyWWFF := false
	hasMyCall := false
	hasMyGrid := false

	for _, item := range list.Items {
		if item.Label == "mysota" {
			hasMySota = true
		}
		if item.Label == "mywwff" {
			hasMyWWFF = true
		}
		if item.Label == "mycall" {
			hasMyCall = true
		}
		if item.Label == "mygrid" {
			hasMyGrid = true
		}
	}

	if hasMySota {
		t.Error("Did not expect 'mysota' in completion (already used)")
	}
	if !hasMyWWFF {
		t.Error("Expected 'mywwff' in completion (not yet used)")
	}
	if !hasMyCall {
		t.Error("Expected 'mycall' keyword in completion (relaxed for variations)")
	}
	if !hasMyGrid {
		t.Error("Expected 'mygrid' in completion (relaxed)")
	}

	// Now check 'mycall ' context
	h2, _ := setupTestHandler(t, "mycall F4JXQ/P\nmycall ")
	params2 := &protocol.CompletionParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
			Position:     protocol.Position{Line: 1, Character: 7},
		},
	}
	list2, err := h2.Completion(context.Background(), params2)
	if err != nil {
		t.Fatalf("Completion failed: %v", err)
	}

	foundF4JXQ := false
	for _, item := range list2.Items {
		if item.Label == "F4JXQ" {
			foundF4JXQ = true
		}
	}
	if !foundF4JXQ {
		t.Error("Expected variation 'F4JXQ' when completing after 'mycall '")
	}
}

func TestHandler_Hover_References(t *testing.T) {
	content := "mysota W4G/CE-003\nmypota US-1611\nmywwff ONFF-0001\n"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	// 1. Hover over 'mysota' keyword
	params := &protocol.HoverParams{
		TextDocumentPositionParams: protocol.TextDocumentPositionParams{
			TextDocument: protocol.TextDocumentIdentifier{URI: uri},
			Position:     protocol.Position{Line: 0, Character: 2},
		},
	}
	hover, _ := h.Hover(context.Background(), params)
	if hover == nil || !strings.Contains(hover.Contents.Value, "sotl.as/summits/W4G/CE-003") {
		t.Errorf("Expected SOTA link in hover, got %v", hover)
	}

	// 2. Hover over 'mypota' value
	params.Position = protocol.Position{Line: 1, Character: 8}
	hover, _ = h.Hover(context.Background(), params)
	if hover == nil || !strings.Contains(hover.Contents.Value, "pota.app/#/park/US-1611") {
		t.Errorf("Expected POTA link in hover, got %v", hover)
	}

	// 3. Hover over 'mywwff' value
	params.Position = protocol.Position{Line: 2, Character: 8}
	hover, _ = h.Hover(context.Background(), params)
	if hover == nil || !strings.Contains(hover.Contents.Value, "wwff.co/directory/?showRef=ONFF-0001") {
		t.Errorf("Expected WWFF link in hover, got %v", hover)
	}
}

func TestHandler_InlayHint_DailyStats(t *testing.T) {
	content := "mycall F4JXQ\ndate 2026-02-01\n40m ssb\n1200 EA1ABC\n1205 EA2ABC\nday +\n20m cw\n1300 G3XYZ\n1305 G4XYZ\n"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	params := &InlayHintParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
	}

	hints, _ := h.InlayHint(context.Background(), params)

	foundDate1 := false
	foundDayPlus := false

	for _, hint := range hints {
		if hint.Position.Line == 1 { // date 2026-02-01
			if strings.Contains(hint.Label, "Daily QSOs: 2") && strings.Contains(hint.Label, "Callsigns: 2") && strings.Contains(hint.Label, "ODX: 0km") {
				foundDate1 = true
			}
		}
		if hint.Position.Line == 5 { // day + (2026-02-02)
			if strings.Contains(hint.Label, "Daily QSOs: 2") && strings.Contains(hint.Label, "Callsigns: 2") && strings.Contains(hint.Label, "ODX: 0km") {
				foundDayPlus = true
			}
		}
	}

	if !foundDate1 {
		t.Errorf("Did not find expected inlay hint on date 2026-02-01 line, hints: %v", hints)
	}
	if !foundDayPlus {
		t.Errorf("Did not find expected inlay hint on day + line, hints: %v", hints)
	}
}

func TestHandler_ExecuteCommand_GeoJSON(t *testing.T) {
	tmpDir := t.TempDir()
	flePath := filepath.Join(tmpDir, "test.fle")
	content := "mycall F4JXQ\ndate 2026-02-01\n40m cw\n1200 EA1ABC #JN18du"
	if err := os.WriteFile(flePath, []byte(content), 0600); err != nil {
		t.Fatalf("Failed to write test file: %v", err)
	}

	h, _ := setupTestHandler(t, "")
	uri := "file://" + flePath
	if err := h.DidOpen(context.Background(), &protocol.DidOpenTextDocumentParams{
		TextDocument: protocol.TextDocumentItem{
			URI:  protocol.DocumentURI(uri),
			Text: content,
		},
	}); err != nil {
		t.Fatalf("DidOpen failed: %v", err)
	}

	params := &protocol.ExecuteCommandParams{
		Command:   "fle.convertGeoJson",
		Arguments: []interface{}{uri},
	}

	res, err := h.ExecuteCommand(context.Background(), params)
	if err != nil {
		t.Fatalf("ExecuteCommand failed: %v", err)
	}

	gj, ok := res.(string)
	if !ok {
		t.Fatalf("Expected string result, got %T", res)
	}

	if !strings.Contains(gj, "EA1ABC") {
		t.Errorf("GeoJSON does not contain EA1ABC: %s", gj)
	}

	// Verify file was created
	geoJSONPath := filepath.Join(tmpDir, "test.geojson")
	if _, err := os.Stat(geoJSONPath); os.IsNotExist(err) {
		t.Errorf("GeoJSON file was not created at %s", geoJSONPath)
	}
}
func TestHandler_DidChange(t *testing.T) {
	content := "mycall F4JXQ\n"
	h, _ := setupTestHandler(t, content)
	uri := protocol.DocumentURI("file:///test.fle")

	newContent := "mycall F4JXQ\ndate 2026-02-01\n"
	err := h.DidChange(context.Background(), &protocol.DidChangeTextDocumentParams{
		TextDocument: protocol.VersionedTextDocumentIdentifier{
			TextDocumentIdentifier: protocol.TextDocumentIdentifier{URI: uri},
			Version:                1,
		},
		ContentChanges: []protocol.TextDocumentContentChangeEvent{
			{Text: newContent},
		},
	})
	if err != nil {
		t.Fatalf("DidChange failed: %v", err)
	}

	v, ok := h.documents.Load(uri.Filename())
	if !ok {
		t.Fatal("Document not found after DidChange")
	}
	doc := v.(*Document)
	if doc.Text != newContent {
		t.Errorf("Expected content %q, got %q", newContent, doc.Text)
	}
}

func TestHandler_DidSave(t *testing.T) {
	h, _ := setupTestHandler(t, "mycall F4JXQ\n")
	uri := protocol.DocumentURI("file:///test.fle")

	err := h.DidSave(context.Background(), &protocol.DidSaveTextDocumentParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
	})
	if err != nil {
		t.Errorf("DidSave failed: %v", err)
	}
}

func TestHandler_DidClose(t *testing.T) {
	h, _ := setupTestHandler(t, "mycall F4JXQ\n")
	uri := protocol.DocumentURI("file:///test.fle")

	err := h.DidClose(context.Background(), &protocol.DidCloseTextDocumentParams{
		TextDocument: protocol.TextDocumentIdentifier{URI: uri},
	})
	if err != nil {
		t.Fatalf("DidClose failed: %v", err)
	}

	_, ok := h.documents.Load(uri.Filename())
	if ok {
		t.Error("Document still exists after DidClose")
	}
}
