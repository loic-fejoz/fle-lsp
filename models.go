package flelsp

import (
	"time"

	"go.lsp.dev/protocol"
)

// Logbook represents the entire parsed FLE document.
type Logbook struct {
	Header         Header
	QSOs           []QSO
	Tokens         []Token  // Global tokens like header keywords, dates, etc.
	ActivatedGrids []string // All unique mygrid values encountered
	SeenHeaders    map[string]bool
	BaseMyCall     string
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
type TokenType uint8

const (
	// TokenCallsign represents a radio callsign.
	TokenCallsign TokenType = iota
	// TokenDate represents a date keyword or value.
	TokenDate
	// TokenTime represents a time value.
	TokenTime
	// TokenBand represents a frequency band.
	TokenBand
	// TokenMode represents a transmission mode.
	TokenMode
	// TokenName represents a person's name.
	TokenName
	// TokenGrid represents a Maidenhead locator.
	TokenGrid
	// TokenComment represents a free-text comment.
	TokenComment
	// TokenKeyword represents a header keyword.
	TokenKeyword
	// TokenReport represents a signal report.
	TokenReport
	// TokenExtra represents extra or QSL information.
	TokenExtra
)

// Token represents a single semantic piece of text.
type Token struct {
	Range Range
	Type  TokenType
}

// QSO represents a single amateur radio contact.
type QSO struct {
	Timestamp      time.Time
	Callsign       string // Not interned (usually unique)
	Band           string // Interned (highly repetitive)
	Mode           string // Interned (highly repetitive)
	ReportSent     string // Interned (highly repetitive)
	ReportReceived string // Interned (highly repetitive)
	Name           string // Interned
	Grid           string // Interned
	Comment        string // Not interned (long, unique)
	QSLMsg         string // Not interned (long, unique)
	LineNumber     int    // For diagnostics mapping
	TokenStart     int32  // Index into Logbook.Tokens
	TokenCount     int32  // Number of tokens in Logbook.Tokens
	MyGrid         string // Interned (highly repetitive)
}

// InternalState tracks the persistent state during parsing.
type InternalState struct {
	Date       time.Time
	Band       string
	Mode       string
	LastTime   string
	MyGrid     string
	BaseMyCall string
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
	Line      int32
	Character int32
}

// InlayHintParams represents textDocument/inlayHint parameters.
type InlayHintParams struct {
	TextDocument protocol.TextDocumentIdentifier `json:"textDocument"`
	Range        protocol.Range                  `json:"range"`
}

// InlayHint represents a single inlay hint.
type InlayHint struct {
	Position     protocol.Position `json:"position"`
	Label        string            `json:"label"`
	Kind         uint32            `json:"kind,omitempty"`
	PaddingLeft  bool              `json:"paddingLeft,omitempty"`
	PaddingRight bool              `json:"paddingRight,omitempty"`
}

// GlobalStats represents overall logbook statistics.
type GlobalStats struct {
	QSOCount       int
	UniqueCalls    int
	ActivatedGrids int
	CollectedGrids int
	ODX            int
}

// DailyStats represents statistics for a single day.
type DailyStats struct {
	QSOCount    int
	UniqueCalls int
	Grids       int
	ODX         int
}
