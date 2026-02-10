package flelsp

import (
	"encoding/json"
	"time"
)

// GeoJSON represents a GeoJSON FeatureCollection.
type GeoJSON struct {
	Type     string    `json:"type"`
	Features []Feature `json:"features"`
}

// Feature represents a GeoJSON Feature.
type Feature struct {
	Type       string     `json:"type"`
	Geometry   Geometry   `json:"geometry"`
	Properties Properties `json:"properties"`
}

// Geometry represents a GeoJSON Point geometry.
type Geometry struct {
	Type        string    `json:"type"`
	Coordinates []float64 `json:"coordinates"` // [lon, lat]
}

// Properties represents GeoJSON properties for QTH or QSO points.
type Properties struct {
	Name         string `json:"name,omitempty"`
	Callsign     string `json:"callsign,omitempty"`
	Date         string `json:"date,omitempty"`
	Time         string `json:"time,omitempty"`
	Band         string `json:"band,omitempty"`
	Mode         string `json:"mode,omitempty"`
	RSTSent      string `json:"rst_sent,omitempty"`
	RSTRcvd      string `json:"rst_rcvd,omitempty"`
	Comment      string `json:"comment,omitempty"`
	MarkerColor  string `json:"marker-color,omitempty"`
	MarkerSymbol string `json:"marker-symbol,omitempty"`
	Type         string `json:"type,omitempty"`
}

// ToGeoJSON converts a Logbook to a GeoJSON string.
func ToGeoJSON(logbook *Logbook) (string, error) {
	gj := GeoJSON{
		Type:     "FeatureCollection",
		Features: []Feature{},
	}

	// 1. QTH Points
	// Use "QTH" if no prefix/suffix, else use the full mycall.
	qthName := "QTH"
	if logbook.Header.MyCall != "" && logbook.Header.MyCall != BaseCallsign(logbook.Header.MyCall) {
		qthName = logbook.Header.MyCall
	}

	for _, grid := range logbook.ActivatedGrids {
		lat, lon, err := GridToLatLon(grid)
		if err != nil {
			continue
		}
		gj.Features = append(gj.Features, Feature{
			Type: "Feature",
			Geometry: Geometry{
				Type:        "Point",
				Coordinates: []float64{lon, lat},
			},
			Properties: Properties{
				Name:         qthName,
				MarkerColor:  "#00ff00",
				MarkerSymbol: "star",
				Type:         "qth",
			},
		})
	}

	// 2. QSO Points
	type qsoKey struct {
		callsign string
		grid     string
	}
	seenQSOs := make(map[qsoKey]bool)

	for _, qso := range logbook.QSOs {
		if qso.Grid == "" {
			continue
		}
		key := qsoKey{qso.Callsign, qso.Grid}
		if seenQSOs[key] {
			continue
		}
		seenQSOs[key] = true

		lat, lon, err := GridToLatLon(qso.Grid)
		if err != nil {
			continue
		}

		gj.Features = append(gj.Features, Feature{
			Type: "Feature",
			Geometry: Geometry{
				Type:        "Point",
				Coordinates: []float64{lon, lat},
			},
			Properties: Properties{
				Callsign:     qso.Callsign,
				Date:         qso.Timestamp.Format(time.DateOnly),
				Time:         qso.Timestamp.Format("15:04"),
				Band:         qso.Band,
				Mode:         qso.Mode,
				RSTSent:      qso.ReportSent,
				RSTRcvd:      qso.ReportReceived,
				Comment:      qso.Comment,
				MarkerColor:  "#0000ff",
				MarkerSymbol: "circle",
				Type:         "qso",
			},
		})
	}

	data, err := json.MarshalIndent(gj, "", "  ")
	if err != nil {
		return "", err
	}
	return string(data), nil
}
