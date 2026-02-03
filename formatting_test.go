package flelsp

import (
	"context"
	"testing"

	"go.lsp.dev/protocol"
)

func TestFormatGrid(t *testing.T) {
	tests := []struct {
		input string
		want  string
	}{
		{"jn38qr", "JN38qr"},
		{"JN38QR", "JN38qr"},
		{"jo45", "JO45"},
		{"JO45", "JO45"},
		{"a", "A"},
		{"ab12cd34", "AB12cd34"},
		{"", ""},
	}

	for _, tt := range tests {
		got := formatGrid(tt.input)
		if got != tt.want {
			t.Errorf("formatGrid(%q) = %q, want %q", tt.input, got, tt.want)
		}
	}
}

func TestHandler_Formatting(t *testing.T) {
	h := &Handler{}
	content := "mycall F4JXQ\nmygrid jn38qr\ndate 2026-02-03\n40m cw\n1200 f1sls 599 599 #jo45"
	uri := protocol.DocumentURI("file:///test.fle")
	h.documents.Store(uri.Filename(), &Document{
		Text: content,
	})

	params := &protocol.DocumentFormattingParams{
		TextDocument: protocol.TextDocumentIdentifier{
			URI: uri,
		},
	}

	edits, err := h.Formatting(context.Background(), params)
	if err != nil {
		t.Fatalf("Formatting failed: %v", err)
	}

	// We expect edits for mygrid, callsign, and grid in extras
	expectedEdits := map[uint32]string{
		1: "mygrid JN38qr",
		4: "1200 F1SLS 599 599 #JO45",
	}

	for _, edit := range edits {
		line := edit.Range.Start.Line
		if want, ok := expectedEdits[line]; ok {
			if edit.NewText != want {
				t.Errorf("Line %d: got %q, want %q", line, edit.NewText, want)
			}
		}
	}
}
