package flelsp

import (
	"math"
	"testing"
)

func TestGridToLatLon(t *testing.T) {
	tests := []struct {
		grid    string
		lat     float64
		lon     float64
		wantErr bool
	}{
		{"JN38qr", 48.7292, 7.375, false},
		{"JN18du", 48.8542, 2.2917, false},
		{"JJ00aa", 0.0208, 0.0417, false},
		{"JN", 0, 0, true},                     // Too short
		{"JN38", 48.5, 7.0, false},             // 4-character
		{"RR99xx", 89.9792, 179.9583, false},   // Polar/Date Line
		{"AA00aa", -89.9792, -179.9583, false}, // Bottom left
	}

	for _, tt := range tests {
		lat, lon, err := GridToLatLon(tt.grid)
		if (err != nil) != tt.wantErr {
			t.Errorf("GridToLatLon(%q) error = %v, wantErr %v", tt.grid, err, tt.wantErr)
			continue
		}
		if tt.wantErr {
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

	// Same point
	dist = CalculateDistance(lat1, lon1, lat1, lon1)
	if dist != 0 {
		t.Errorf("CalculateDistance(same point) = %v, want 0", dist)
	}

	// Antipodes (approx)
	dist = CalculateDistance(0, 0, 0, 180)
	if math.Abs(dist-20015) > 100 {
		t.Errorf("CalculateDistance(antipodes) = %v, want approx 20015", dist)
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
