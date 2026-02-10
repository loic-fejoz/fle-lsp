package flelsp

import (
	"encoding/json"
	"strings"
	"testing"
)

func TestToGeoJSON(t *testing.T) {
	content := `mycall F4JXQ/P
mygrid JN38qr
date 2026-02-01
40m cw
1200 EA1ABC #JN18du
1205 EA1ABC #JN18du
1210 G4XYZ #JO01aa
mygrid JN39aa
1215 G4XYZ #JO01aa
`
	logbook, _, err := ParseFLE(content)
	if err != nil {
		t.Fatalf("ParseFLE failed: %v", err)
	}

	gjStr, err := ToGeoJSON(logbook)
	if err != nil {
		t.Fatalf("ToGeoJSON failed: %v", err)
	}

	var gj GeoJSON
	if err := json.Unmarshal([]byte(gjStr), &gj); err != nil {
		t.Fatalf("failed to unmarshal GeoJSON: %v", err)
	}

	// Verify Features: 2 QTHs (JN38qr, JN39aa) + 2 unique QSOs (EA1ABC@JN18du, G4XYZ@JO01aa)
	qthCount := 0
	qsoCount := 0
	for _, f := range gj.Features {
		switch f.Properties.Type {
		case "qth":
			qthCount++
		case "qso":
			qsoCount++
		}
	}

	if qthCount != 2 {
		t.Errorf("Expected 2 QTH features, got %d", qthCount)
	}
	if qsoCount != 2 {
		t.Errorf("Expected 2 QSO features, got %d", qsoCount)
	}

	// Verify QTH name (should be F4JXQ/P because it's not a base callsign)
	for _, f := range gj.Features {
		if f.Properties.Type == "qth" {
			if f.Properties.Name != "F4JXQ/P" {
				t.Errorf("Expected QTH name F4JXQ/P, got %q", f.Properties.Name)
			}
		}
	}
}

func TestToGeoJSON_BaseCall(t *testing.T) {
	content := `mycall F4JXQ
mygrid JN38qr
date 2026-02-01
1200 EA1ABC #JN18du
`
	logbook, _, _ := ParseFLE(content)
	gjStr, _ := ToGeoJSON(logbook)

	if !strings.Contains(gjStr, "\"name\": \"QTH\"") {
		t.Error("Expected QTH name to be 'QTH' for base callsign")
	}
}

func TestToGeoJSON_Empty(t *testing.T) {
	logbook := &Logbook{}
	gjStr, err := ToGeoJSON(logbook)
	if err != nil {
		t.Fatalf("ToGeoJSON failed for empty logbook: %v", err)
	}
	if !strings.Contains(gjStr, "\"features\": []") {
		t.Errorf("Expected empty features list, got %s", gjStr)
	}
}
