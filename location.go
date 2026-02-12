package flelsp

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"net"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"strconv"
	"strings"
	"time"
)

// LocationSourceType represents the type of location source.
type LocationSourceType string

const (
	// SourceGPSD represents a location from a running gpsd instance.
	SourceGPSD LocationSourceType = "GPSD"
	// SourceGPredict represents a location from GPredict config.
	SourceGPredict LocationSourceType = "GPredict"
	// SourceXastir represents a location from Xastir config.
	SourceXastir LocationSourceType = "Xastir"
)

// LocationSource represents a detected source of geographical coordinates.
type LocationSource struct {
	Name string
	Path string
	Type LocationSourceType
}

// LatLonToGrid converts latitude and longitude to a 6-character Maidenhead locator (Grid Square).
// Latitude: North is positive, South is negative (WGS84).
// Longitude: East is positive, West is negative (WGS84).
func LatLonToGrid(lat, lon float64) string {
	if lat < -90 || lat > 90 || lon < -180 || lon > 180 {
		return ""
	}

	lon += 180
	lat += 90

	// Field (1st pair): 20 deg Lon x 10 deg Lat
	fieldLon := int(lon / 20)
	fieldLat := int(lat / 10)
	lon -= float64(fieldLon * 20)
	lat -= float64(fieldLat * 10)

	// Square (2nd pair): 2 deg Lon x 1 deg Lat
	squareLon := int(lon / 2)
	squareLat := int(lat / 1)
	lon -= float64(squareLon * 2)
	lat -= float64(squareLat * 1)

	// Subsquare (3rd pair): 5 min Lon x 2.5 min Lat
	subLon := int(lon * 60 / 5)
	subLat := int(lat * 60 / 2.5)

	// Bounds check for safety
	fieldLon = max(0, min(fieldLon, 17))
	fieldLat = max(0, min(fieldLat, 17))
	squareLon = max(0, min(squareLon, 9))
	squareLat = max(0, min(squareLat, 9))
	subLon = max(0, min(subLon, 23))
	subLat = max(0, min(subLat, 23))

	return fmt.Sprintf("%c%c%01d%01d%c%c",
		'A'+fieldLon, 'A'+fieldLat,
		squareLon, squareLat,
		'a'+subLon, 'a'+subLat)
}

// GetGPSDGrid attempts to get the current grid from a local gpsd instance via TCP.
func GetGPSDGrid() string {
	conn, err := net.DialTimeout("tcp", "127.0.0.1:2947", 100*time.Millisecond)
	if err != nil {
		return ""
	}
	defer func() { _ = conn.Close() }()

	// Enable JSON output
	_, err = fmt.Fprintf(conn, "?WATCH={\"enable\":true,\"json\":true};")
	if err != nil {
		return ""
	}

	// Use a LimitedReader to prevent unbounded memory usage if gpsd goes rogue
	// 4096 bytes should be enough for any TPV or VERSION message.
	limitReader := io.LimitReader(conn, 4096)
	decoder := json.NewDecoder(limitReader)

	for {
		// GPSD sends various message types (VERSION, DEVICES, WATCH, TPV).
		// We use json.RawMessage to first capture the message and inspect its "class".

		var raw json.RawMessage
		if err := decoder.Decode(&raw); err != nil {
			// standard io.EOF or error
			break
		}

		// First, check the class roughly
		var envelope struct {
			Class string `json:"class"`
			// We don't strictly check envelope fields here, just look for class
		}
		if err := json.Unmarshal(raw, &envelope); err != nil {
			continue
		}

		if envelope.Class == "TPV" {
			// Now decode into generic struct.
			// We removed DisallowUnknownFields() because it caused regressions with various gpsd versions
			// that send extra fields. We still benefit from LimitReader preventing DoS.
			var data struct {
				Class  string  `json:"class"`
				Device string  `json:"device"`
				Mode   int     `json:"mode"`
				Lat    float64 `json:"lat"`
				Lon    float64 `json:"lon"`
			}

			if err := json.Unmarshal(raw, &data); err == nil {
				if data.Mode >= 2 {
					return LatLonToGrid(data.Lat, data.Lon)
				}
			}
		}
	}
	return ""
}

// GetGPredictGrids returns grids found in GPredict .qth files.
func GetGPredictGrids(qthPath string) (name string, grid string) {
	file, err := os.Open(filepath.Clean(qthPath))
	if err != nil {
		return "", ""
	}
	defer func() { _ = file.Close() }()

	name = filepath.Base(qthPath)
	name = strings.TrimSuffix(name, ".qth")

	var lat, lon float64
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.SplitN(line, "=", 2)
		if len(parts) != 2 {
			continue
		}
		val := strings.TrimSpace(parts[1])
		switch strings.ToUpper(parts[0]) {
		case "LAT":
			var err error
			lat, err = strconv.ParseFloat(val, 64)
			if err != nil {
				continue
			}
		case "LON":
			// GPredict uses East positive, North positive in its .qth files
			// based on internal consistency check with user's Saverne file.
			var err error
			lon, err = strconv.ParseFloat(val, 64)
			if err != nil {
				continue
			}
		}
	}

	if lat != 0 || lon != 0 {
		return name, LatLonToGrid(lat, lon)
	}
	return "", ""
}

// GetXastirGrid returns the grid found in Xastir configuration.
func GetXastirGrid(cnfPath string) string {
	file, err := os.Open(filepath.Clean(cnfPath))
	if err != nil {
		return ""
	}
	defer func() { _ = file.Close() }()

	var lat, lon float64
	scanner := bufio.NewScanner(file)
	// STATION_LAT:4844.826N
	// STATION_LONG:00721.480E
	reLat := regexp.MustCompile(`^STATION_LAT:(\d{2})(\d{2}\.\d+)([NS])`)
	reLon := regexp.MustCompile(`^STATION_LONG:(\d{3})(\d{2}\.\d+)([EW])`)

	for scanner.Scan() {
		line := scanner.Text()
		if matches := reLat.FindStringSubmatch(line); matches != nil {
			deg, err1 := strconv.ParseFloat(matches[1], 64)
			minutes, err2 := strconv.ParseFloat(matches[2], 64)
			if err1 != nil || err2 != nil {
				continue
			}
			lat = deg + minutes/60
			if matches[3] == "S" {
				lat = -lat
			}
		} else if matches := reLon.FindStringSubmatch(line); matches != nil {
			deg, err1 := strconv.ParseFloat(matches[1], 64)
			minutes, err2 := strconv.ParseFloat(matches[2], 64)
			if err1 != nil || err2 != nil {
				continue
			}
			lon = deg + minutes/60
			if matches[3] == "W" {
				lon = -lon
			}
		}
	}

	if lat != 0 || lon != 0 {
		return LatLonToGrid(lat, lon)
	}
	return ""
}

// DetectLocationSources probes the system for GPredict and Xastir configurations.
func DetectLocationSources() []LocationSource {
	var sources []LocationSource

	home, err := os.UserHomeDir()
	if err != nil {
		return sources
	}

	// GPredict
	gpredictPath := filepath.Join(home, ".config", "Gpredict")
	if files, err := filepath.Glob(filepath.Join(gpredictPath, "*.qth")); err == nil {
		for _, f := range files {
			name := filepath.Base(f)
			sources = append(sources, LocationSource{
				Name: "GPredict: " + strings.TrimSuffix(name, ".qth"),
				Path: f,
				Type: SourceGPredict,
			})
		}
	}

	// Xastir
	xastirCnf := filepath.Join(home, ".xastir", "config", "xastir.cnf")
	if _, err := os.Stat(xastirCnf); err == nil {
		sources = append(sources, LocationSource{
			Name: "Xastir",
			Path: xastirCnf,
			Type: SourceXastir,
		})
	}

	// GPSD (check if tools exist, assuming gpsd presence)
	gpsTools := []string{"gpspipe", "cgps", "gpsmon"}
	foundGPS := false
	for _, tool := range gpsTools {
		if _, err := exec.LookPath(tool); err == nil {
			foundGPS = true
			break
		}
	}
	if foundGPS {
		sources = append(sources, LocationSource{
			Name: "GPS (gpsd)",
			Type: SourceGPSD,
		})
	}

	return sources
}
