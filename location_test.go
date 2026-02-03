package flelsp

import (
	"fmt"
	"net"
	"os"
	"path/filepath"
	"testing"
	"time"
)

func TestLatLonToGrid(t *testing.T) {
	tests := []struct {
		lat, lon float64
		want     string
	}{
		{48.74708840, 7.35792930, "JN38qr"}, // Saverne, France
		{48.8583, 2.2945, "JN18du"},         // Paris (Eiffel Tower)
		{40.7128, -74.0060, "FN20xr"},       // New York
		{-33.8688, 151.2093, "QF56od"},      // Sydney
		{0, 0, "JJ00aa"},                    // Origin
	}

	for _, tt := range tests {
		t.Run(tt.want, func(t *testing.T) {
			got := LatLonToGrid(tt.lat, tt.lon)
			if got != tt.want {
				t.Errorf("LatLonToGrid(%f, %f) = %q, want %q", tt.lat, tt.lon, got, tt.want)
			}
		})
	}
}

func TestGetGPredictGrids(t *testing.T) {
	tmpDir, err := os.MkdirTemp("", "gpredict_test")
	if err != nil {
		t.Fatal(err)
	}
	defer func() { _ = os.RemoveAll(tmpDir) }()

	qthFile := filepath.Join(tmpDir, "TestStation.qth")
	content := "[QTH]\nLAT=48.8583\nLON=2.2945\nALT=35\n"
	if err := os.WriteFile(qthFile, []byte(content), 0644); err != nil {
		t.Fatal(err)
	}

	name, grid := GetGPredictGrids(qthFile)
	if name != "TestStation" {
		t.Errorf("Got name %q, want %q", name, "TestStation")
	}
	if grid != "JN18du" {
		t.Errorf("Got grid %q, want %q", grid, "JN18du")
	}
}

func TestGetXastirGrid(t *testing.T) {
	tmpDir, err := os.MkdirTemp("", "xastir_test")
	if err != nil {
		t.Fatal(err)
	}
	defer func() { _ = os.RemoveAll(tmpDir) }()

	cnfFile := filepath.Join(tmpDir, "xastir.cnf")
	content := "STATION_LAT:4851.498N\nSTATION_LONG:00217.670E\n"
	// 48 deg 51.498 min = 48.8583
	// 2 deg 17.670 min = 2.2945
	if err := os.WriteFile(cnfFile, []byte(content), 0644); err != nil {
		t.Fatal(err)
	}

	grid := GetXastirGrid(cnfFile)
	if grid != "JN18du" {
		t.Errorf("Got grid %q, want %q", grid, "JN18du")
	}
}

func TestGetGPSDGrid(t *testing.T) {
	// Start a mock GPSD server
	l, err := net.Listen("tcp", "127.0.0.1:2947")
	if err != nil {
		t.Skip("Skipping TestGetGPSDGrid: gpsd port 2947 already in use or unavailable")
	}
	defer func() { _ = l.Close() }()

	go func() {
		conn, err := l.Accept()
		if err != nil {
			return
		}
		defer func() { _ = conn.Close() }()

		// Read the WATCH command
		buf := make([]byte, 1024)
		_, _ = conn.Read(buf)

		// Send version and TPV
		_, _ = fmt.Fprintf(conn, "{\"class\":\"VERSION\",\"release\":\"3.22\",\"rev\":\"3.22\",\"proto_major\":3,\"proto_minor\":14}\n")
		time.Sleep(50 * time.Millisecond)
		// Send a TPV response (mode 3 = 3D fix)
		// 48.8583, 2.2945 -> "JN18du"
		_, _ = fmt.Fprintf(conn, "{\"class\":\"TPV\",\"device\":\"/dev/pts/1\",\"mode\":3,\"time\":\"2026-02-03T21:40:00.000Z\",\"lat\":48.8583,\"lon\":2.2945,\"alt\":35.0}\n")
	}()

	grid := GetGPSDGrid()
	if grid != "JN18du" {
		t.Errorf("Got grid %q, want %q", grid, "JN18du")
	}
}
