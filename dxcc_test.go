package flelsp

import (
	"testing"
)

func TestLookupCountry(t *testing.T) {
	tests := []struct {
		callsign string
		want     string
	}{
		{"F4JXQ", "France"},
		{"f4jxq", "France"}, // Case insensitive
		{"EA1ABC", "Spain"},
		{"GM0ABC", "Scotland"}, // Longest match (GM over G)
		{"G0ABC", "England"},
		{"K1ABC", "USA"},
		{"W6ABC", "USA"},
		{"VE3XYZ", "Canada"},
		{"9A1ABC", "Croatia"},
		{"KH6XYZ", "Hawaii"}, // 3-char prefix match
		{"3A/O3A", "Monaco"},
		{"EA8ABC", "Canary Islands"},
		{"OH0ABC", "Aland Islands"},
		{"TK5KP", "Corsica"},
		{"FJ/O3A", "Saint Barthelemy"},
		{"FS/O3A", "Saint Martin"},
		{"FP/O3A", "Saint Pierre and Miquelon"},
		{"XYZ123", "Unknown"}, // No match
		{"", "Unknown"},       // Empty
		{"EA1ABC/P", "Spain"}, // Suffix
	}

	for _, tt := range tests {
		t.Run(tt.callsign, func(t *testing.T) {
			got := LookupCountry(tt.callsign)
			if got != tt.want {
				t.Errorf("LookupCountry(%q) = %q, want %q", tt.callsign, got, tt.want)
			}
		})
	}
}
