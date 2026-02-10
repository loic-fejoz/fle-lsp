package flelsp

import (
	"testing"
	"time"
)

func TestHandler_CalculateStatistics(t *testing.T) {
	h := &Handler{}

	t.Run("EmptyLogbook", func(t *testing.T) {
		lb := &Logbook{}
		qsoCount, uniqueCalls, activatedGrids, collectedGrids, odx := h.CalculateStatistics(lb)
		if qsoCount != 0 || uniqueCalls != 0 || activatedGrids != 0 || collectedGrids != 0 || odx != 0 {
			t.Errorf("Expected zeros, got %d, %d, %d, %d, %d", qsoCount, uniqueCalls, activatedGrids, collectedGrids, odx)
		}
	})

	t.Run("OneQSONoGrid", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "F4JXQ", Timestamp: time.Now()},
			},
		}
		qsoCount, uniqueCalls, _, _, odx := h.CalculateStatistics(lb)
		if qsoCount != 1 || uniqueCalls != 1 || odx != 0 {
			t.Errorf("Unexpected stats: count=%d, unique=%d, odx=%d", qsoCount, uniqueCalls, odx)
		}
	})

	t.Run("OneQSOWithGrid", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "EA1ABC", Grid: "JN18du", MyGrid: "JN38qr", Timestamp: time.Now()},
			},
		}
		_, _, _, collectedGrids, odx := h.CalculateStatistics(lb)
		if collectedGrids != 1 {
			t.Errorf("Expected 1 collected grid, got %d", collectedGrids)
		}
		if odx == 0 {
			t.Error("Expected non-zero ODX distance")
		}
	})

	t.Run("MultipleQSOsGlobalODX", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "EA1ABC", Grid: "JN18du", MyGrid: "JN38qr", Timestamp: time.Now()}, // ~275km
				{Callsign: "K1ABC", Grid: "FN42aa", MyGrid: "JN38qr", Timestamp: time.Now()},  // Much further
			},
		}
		_, _, _, _, odx := h.CalculateStatistics(lb)
		if odx < 5000 {
			t.Errorf("Expected significant ODX distance, got %d", odx)
		}
	})

	t.Run("InvalidGrids", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "EA1ABC", Grid: "INVALID", MyGrid: "JN38qr", Timestamp: time.Now()},
			},
		}
		_, _, _, collectedGrids, odx := h.CalculateStatistics(lb)
		// "INVALID" is not a valid grid, formatGrid might still return something or it might fail GridToLatLon
		// We want to ensure it doesn't crash and odx is 0 if calculation fails
		if odx != 0 {
			t.Errorf("Expected 0 ODX for invalid grid, got %d", odx)
		}
		if collectedGrids != 1 {
			t.Errorf("Expected 1 collected grid (even if invalid format), got %d", collectedGrids)
		}
	})
}
