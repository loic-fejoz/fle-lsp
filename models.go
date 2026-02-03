package flelsp

import "time"

// Logbook represents the entire parsed FLE document.
type Logbook struct {
	Header Header
	QSOs   []QSO
}

// Header contains station and operator information.
type Header struct {
	MyCall   string
	MyGrid   string
	Operator string
	Nickname string
	QSLMsg   string
	MyWWFF   string
	MySOTA   string
	MyPOTA   string
}

// QSO represents a single amateur radio contact.
type QSO struct {
	Timestamp      time.Time
	Callsign       string
	Band           string
	Mode           string
	ReportSent     string
	ReportReceived string
	Name           string
	Grid           string
	Comment        string
	QSLMsg         string
	LineNumber     int // For diagnostics mapping
}

// InternalState tracks the persistent state during parsing.
type InternalState struct {
	Date     time.Time
	Band     string
	Mode     string
	LastTime string
}

type Severity int

const (
	SeverityError Severity = iota
	SeverityWarning
	SeverityInfo
)

type Diagnostic struct {
	Range    Range
	Message  string
	Severity Severity
}

type Range struct {
	Start Pos
	End   Pos
}

type Pos struct {
	Line      int
	Character int
}
