package flelsp

import (
	"fmt"
	"math"
	"strings"
)

const earthRadiusKm = 6371.0

// GridToLatLon converts a 4 or 6 character Maidenhead locator to latitude and longitude.
// It returns the coordinates of the center of the grid square.
func GridToLatLon(grid string) (lat, lon float64, err error) {
	grid = strings.ToUpper(grid)
	if len(grid) < 4 {
		return 0, 0, fmt.Errorf("grid too short")
	}

	// Validate Field (A-R)
	if grid[0] < 'A' || grid[0] > 'R' || grid[1] < 'A' || grid[1] > 'R' {
		return 0, 0, fmt.Errorf("invalid grid field")
	}

	// Validate Square (0-9)
	if grid[2] < '0' || grid[2] > '9' || grid[3] < '0' || grid[3] > '9' {
		return 0, 0, fmt.Errorf("invalid grid square")
	}

	lon = float64(grid[0]-'A')*20 - 180
	lat = float64(grid[1]-'A')*10 - 90
	lon += float64(grid[2]-'0') * 2
	lat += float64(grid[3]-'0') * 1

	if len(grid) >= 6 {
		// Validate Subsquare (A-X)
		s4 := strings.ToUpper(string(grid[4]))[0]
		s5 := strings.ToUpper(string(grid[5]))[0]
		if s4 < 'A' || s4 > 'X' || s5 < 'A' || s5 > 'X' {
			return 0, 0, fmt.Errorf("invalid grid subsquare")
		}
		lon += (float64(s4-'A') + 0.5) * (5.0 / 60.0)
		lat += (float64(s5-'A') + 0.5) * (2.5 / 60.0)
	} else {
		lon += 1.0
		lat += 0.5
	}

	return lat, lon, nil
}

// CalculateDistance returns the distance between two points in kilometers using the Haversine formula.
func CalculateDistance(lat1, lon1, lat2, lon2 float64) float64 {
	dLat := (lat2 - lat1) * math.Pi / 180.0
	dLon := (lon2 - lon1) * math.Pi / 180.0

	rLat1 := lat1 * math.Pi / 180.0
	rLat2 := lat2 * math.Pi / 180.0

	a := math.Sin(dLat/2)*math.Sin(dLat/2) +
		math.Sin(dLon/2)*math.Sin(dLon/2)*math.Cos(rLat1)*math.Cos(rLat2)
	c := 2 * math.Atan2(math.Sqrt(a), math.Sqrt(1-a))

	return earthRadiusKm * c
}

// CalculateBearing returns the initial bearing from point 1 to point 2 in degrees.
func CalculateBearing(lat1, lon1, lat2, lon2 float64) float64 {
	rLat1 := lat1 * math.Pi / 180.0
	rLat2 := lat2 * math.Pi / 180.0
	dLon := (lon2 - lon1) * math.Pi / 180.0

	y := math.Sin(dLon) * math.Cos(rLat2)
	x := math.Cos(rLat1)*math.Sin(rLat2) -
		math.Sin(rLat1)*math.Cos(rLat2)*math.Cos(dLon)
	brng := math.Atan2(y, x)

	return math.Mod(brng*180.0/math.Pi+360.0, 360.0)
}
