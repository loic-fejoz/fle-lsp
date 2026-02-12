package flelsp

import (
	"testing"
	"time"
)

func TestCalculateStatistics(t *testing.T) {

	t.Run("EmptyLogbook", func(t *testing.T) {
		lb := &Logbook{}
		global, _ := CalculateStatistics(lb)
		if global.QSOCount != 0 || global.UniqueCalls != 0 || global.ActivatedGrids != 0 || global.CollectedGrids != 0 || global.ODX != 0 {
			t.Errorf("Expected zeros, got %+v", global)
		}
	})

	t.Run("OneQSONoGrid", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "F4JXQ", Timestamp: time.Now()},
			},
		}
		global, _ := CalculateStatistics(lb)
		if global.QSOCount != 1 || global.UniqueCalls != 1 || global.ODX != 0 {
			t.Errorf("Unexpected stats: count=%d, unique=%d, odx=%d", global.QSOCount, global.UniqueCalls, global.ODX)
		}
	})

	t.Run("OneQSOWithGrid", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "EA1ABC", Grid: "JN18du", MyGrid: "JN38qr", Timestamp: time.Now()},
			},
		}
		global, _ := CalculateStatistics(lb)
		if global.CollectedGrids != 1 {
			t.Errorf("Expected 1 collected grid, got %d", global.CollectedGrids)
		}
		if global.ODX == 0 {
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
		global, _ := CalculateStatistics(lb)
		if global.ODX < 5000 {
			t.Errorf("Expected significant ODX distance, got %d", global.ODX)
		}
	})

	t.Run("InvalidGrids", func(t *testing.T) {
		lb := &Logbook{
			QSOs: []QSO{
				{Callsign: "EA1ABC", Grid: "INVALID", MyGrid: "JN38qr", Timestamp: time.Now()},
			},
		}
		global, _ := CalculateStatistics(lb)
		// "INVALID" is not a valid grid, formatGrid might still return something or it might fail GridToLatLon
		// We want to ensure it doesn't crash and odx is 0 if calculation fails
		if global.ODX != 0 {
			t.Errorf("Expected 0 ODX for invalid grid, got %d", global.ODX)
		}
		if global.CollectedGrids != 1 {
			t.Errorf("Expected 1 collected grid (even if invalid format), got %d", global.CollectedGrids)
		}
	})
}
