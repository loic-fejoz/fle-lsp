package flelsp

import (
	"os"
	"testing"
)

func TestParseErrorsFile(t *testing.T) {
	content, err := os.ReadFile("errors_test.fle")
	if err != nil {
		t.Fatalf("Failed to read errors_test.fle: %v", err)
	}

	_, diags, err := ParseFLE(string(content))
	if err != nil {
		t.Errorf("ParseFLE returned unexpected error: %v", err)
	}

	// Based on manual inspection, we expect at least 12 diagnostics
	expectedMinDiags := 12
	if len(diags) < expectedMinDiags {
		t.Errorf("Expected at least %d diagnostics, got %d", expectedMinDiags, len(diags))
	}
}

func TestParseValidExhaustiveFile(t *testing.T) {
	content, err := os.ReadFile("valid_exhaustive.fle")
	if err != nil {
		t.Fatalf("Failed to read valid_exhaustive.fle: %v", err)
	}

	logbook, diags, err := ParseFLE(string(content))
	if err != nil {
		t.Errorf("ParseFLE returned unexpected error: %v", err)
	}

	if len(diags) > 0 {
		t.Errorf("Expected 0 diagnostics for valid_exhaustive.fle, got %d", len(diags))
		for _, d := range diags {
			t.Logf("Diagnostic: %s at line %d", d.Message, d.Range.Start.Line)
		}
	}

	// Based on manual inspection, we expect 26 QSOs
	expectedQSOs := 26
	if len(logbook.QSOs) != expectedQSOs {
		t.Errorf("Expected %d QSOs, got %d", expectedQSOs, len(logbook.QSOs))
	}
}
