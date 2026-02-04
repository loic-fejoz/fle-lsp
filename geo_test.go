package flelsp

import (
	"math"
	"testing"
)

func TestGridToLatLon(t *testing.T) {
	tests := []struct {
		grid string
		lat  float64
		lon  float64
	}{
		{"JN38qr", 48.7292, 7.375},
		{"JN18du", 48.8542, 2.2917}, // Calculated center of JN18du
		{"JJ00aa", 0.0208, 0.0417},  // Calculated center of JJ00aa
	}

	for _, tt := range tests {
		lat, lon, err := GridToLatLon(tt.grid)
		if err != nil {
			t.Errorf("GridToLatLon(%q) error: %v", tt.grid, err)
			continue
		}
		if math.Abs(lat-tt.lat) > 0.01 || math.Abs(lon-tt.lon) > 0.01 {
			t.Errorf("GridToLatLon(%q) = (%v, %v), want (%v, %v)", tt.grid, lat, lon, tt.lat, tt.lon)
		}
	}
}

func TestCalculateDistance(t *testing.T) {
	// JN38qr to JN18du (approx Saverne to Paris)
	lat1, lon1, _ := GridToLatLon("JN38qr")
	lat2, lon2, _ := GridToLatLon("JN18du")

	dist := CalculateDistance(lat1, lon1, lat2, lon2)
	// Approx 370 km
	if dist < 360 || dist > 380 {
		t.Errorf("CalculateDistance(JN38qr, JN18du) = %v, want approx 370", dist)
	}
}

func TestCalculateBearing(t *testing.T) {
	// North
	brng := CalculateBearing(0, 0, 10, 0)
	if math.Abs(brng-0) > 0.1 {
		t.Errorf("CalculateBearing(North) = %v, want 0", brng)
	}

	// East
	brng = CalculateBearing(0, 0, 0, 10)
	if math.Abs(brng-90) > 0.1 {
		t.Errorf("CalculateBearing(East) = %v, want 90", brng)
	}
}
