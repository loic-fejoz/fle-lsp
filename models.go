package flelsp

import "time"

// Logbook represents the entire parsed FLE document.
type Logbook struct {
	Header Header
	QSOs   []QSO
	Tokens []Token // Global tokens like header keywords, dates, etc.
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

// TokenType represents the type of semantic token for LSP highlighting.
type TokenType string

const (
	// TokenCallsign represents a radio callsign.
	TokenCallsign TokenType = "callsign"
	// TokenDate represents a date keyword or value.
	TokenDate TokenType = "date"
	// TokenTime represents a time value.
	TokenTime TokenType = "time"
	// TokenBand represents a frequency band.
	TokenBand TokenType = "band"
	// TokenMode represents a transmission mode.
	TokenMode TokenType = "mode"
	// TokenName represents a person's name.
	TokenName TokenType = "name"
	// TokenGrid represents a Maidenhead locator.
	TokenGrid TokenType = "grid"
	// TokenComment represents a free-text comment.
	TokenComment TokenType = "comment"
	// TokenKeyword represents a header keyword.
	TokenKeyword TokenType = "keyword"
	// TokenReport represents a signal report.
	TokenReport TokenType = "report"
	// TokenExtra represents extra or QSL information.
	TokenExtra TokenType = "extra"
)

// Token represents a single semantic piece of text.
type Token struct {
	Range Range
	Type  TokenType
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
	LineNumber     int     // For diagnostics mapping
	Tokens         []Token // For semantic highlighting
}

// InternalState tracks the persistent state during parsing.
type InternalState struct {
	Date     time.Time
	Band     string
	Mode     string
	LastTime string
}

// Severity represents the diagnostic severity level.
type Severity int

const (
	// SeverityError indicates a hard error.
	SeverityError Severity = iota
	// SeverityWarning indicates a warning.
	SeverityWarning
	// SeverityInfo indicates informational messages.
	SeverityInfo
)

const (
	// CodeInvalidDate indicates an invalid date format.
	CodeInvalidDate = "invalid_date"
	// CodeLowercaseCallsign indicates a callsign that should be uppercased.
	CodeLowercaseCallsign = "lowercase_callsign"
	// CodeMissingMyCall indicates a missing mycall header.
	CodeMissingMyCall = "missing_mycall"
)

// Diagnostic represents a parsing error or warning.
type Diagnostic struct {
	Range    Range
	Message  string
	Severity Severity
	Code     string // Added for Quick Fixes
}

// Range represents a range in a document.
type Range struct {
	Start Pos
	End   Pos
}

// Pos represents a position in a document.
type Pos struct {
	Line      int
	Character int
}
