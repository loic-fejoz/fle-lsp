package flelsp

import (
	"strings"
	"testing"
)

func TestParseFLE(t *testing.T) {
	content := `
mycall F4JXQ
mygrid JN38qr

date 2023-10-26
2m FM
1235 F6DCD @Denis <FT8800>
40 F4LAA @Christian

day +
20m ssb
1424 AB1CD 57 58
`
	logbook, diags, err := ParseFLE(content)
	if err != nil {
		t.Fatalf("ParseFLE failed: %v", err)
	}

	if len(diags) > 0 {
		t.Logf("Warnings/Errors found during parsing: %v", diags)
	}

	if logbook.Header.MyCall != "F4JXQ" {
		t.Errorf("Expected MyCall F4JXQ, got %s", logbook.Header.MyCall)
	}

	if len(logbook.QSOs) != 3 {
		t.Fatalf("Expected 3 QSOs, got %d", len(logbook.QSOs))
	}

	// First QSO
	qso1 := logbook.QSOs[0]
	if qso1.Callsign != "F6DCD" || qso1.Mode != "FM" || qso1.Band != "2m" || qso1.Name != "Denis" {
		t.Errorf("QSO1 mismatch: %+v", qso1)
	}
	if qso1.Timestamp.Format("1504") != "1235" {
		t.Errorf("Expected time 1235, got %s", qso1.Timestamp.Format("1504"))
	}

	// Second QSO (time expansion)
	qso2 := logbook.QSOs[1]
	if qso2.Timestamp.Format("1504") != "1240" {
		t.Errorf("Expected time 1240 (expanded from 40), got %s", qso2.Timestamp.Format("1504"))
	}

	// Third QSO (date increment and band/mode change)
	qso3 := logbook.QSOs[2]
	expectedDate := "2023-10-27"
	if qso3.Timestamp.Format("2006-01-02") != expectedDate {
		t.Errorf("Expected date %s, got %s", expectedDate, qso3.Timestamp.Format("2006-01-02"))
	}
	if qso3.Band != "20m" || qso3.Mode != "SSB" || qso3.ReportSent != "57" {
		t.Errorf("QSO3 mismatch: %+v", qso3)
	}
}

func TestTimeExpansion(t *testing.T) {
	tests := []struct {
		last    string
		current string
		want    string
	}{
		{"", "1234", "1234"},
		{"1200", "05", "1205"},
		{"1259", "1301", "1301"},
		{"1234", "", "1234"},
		{"", "5", "0005"},
	}

	for _, tt := range tests {
		got := expandTime(tt.last, tt.current)
		if got != tt.want {
			t.Errorf("expandTime(%q, %q) = %q, want %q", tt.last, tt.current, got, tt.want)
		}
	}
}

func TestDiagnostics(t *testing.T) {
	content := `
# No mycall here
2023-10-26
1235 F6DCD
`
	_, diags, _ := ParseFLE(content)

	foundMyCallWarning := false
	foundNoBandWarning := false

	for _, d := range diags {
		if strings.Contains(d.Message, "mycall") {
			foundMyCallWarning = true
		}
		if strings.Contains(d.Message, "band") {
			foundNoBandWarning = true
		}
	}

	if !foundMyCallWarning {
		t.Error("Expected warning about missing mycall")
	}
	if !foundNoBandWarning {
		t.Error("Expected warning about missing band")
	}
}

func TestTimeDiagnostics(t *testing.T) {
	content := `
mycall F4JXQ
date 2023-10-26
40m CW
1235 F6DCD
1278 F4LAA
1230 AB1CD
`
	_, diags, _ := ParseFLE(content)

	foundMinuteError := false
	foundBackwardsWarning := false

	for _, d := range diags {
		if strings.Contains(d.Message, "Invalid minutes") {
			foundMinuteError = true
		}
		if strings.Contains(d.Message, "goes backwards") {
			foundBackwardsWarning = true
		}
	}

	if !foundMinuteError {
		t.Error("Expected error for invalid minutes (1278)")
	}
	if !foundBackwardsWarning {
		t.Error("Expected warning for time going backwards (1230 after 1278/1235)")
	}
}

func TestDateChangeResetsMonotonicity(t *testing.T) {
	content := `
mycall F4JXQ
date 2024-08-03
1200 F1SLS @Stan

date 2024-09-22
0915 F5NWY/M
`
	_, diags, _ := ParseFLE(content)

	for _, d := range diags {
		if strings.Contains(d.Message, "goes backwards") {
			t.Errorf("Unexpected monotonicity warning across different dates: %s", d.Message)
		}
	}
}
func TestNewBandsAndDayPlus(t *testing.T) {
	content := `
mycall F4JXQ
date 2026-01-01
1.25m fm
1200 W6ABC
70cm ft8
1205 F6ABC
day ++
2m ssb
1000 G0ABC
`
	logbook, diags, err := ParseFLE(content)
	if err != nil {
		t.Fatalf("ParseFLE failed: %v", err)
	}
	if len(diags) > 0 {
		for _, d := range diags {
			if d.Severity == SeverityError {
				t.Errorf("Unexpected error: %s", d.Message)
			}
		}
	}

	if len(logbook.QSOs) != 3 {
		t.Fatalf("Expected 3 QSOs, got %d", len(logbook.QSOs))
	}

	if logbook.QSOs[0].Band != "1.25m" {
		t.Errorf("Expected 1.25m, got %s", logbook.QSOs[0].Band)
	}
	if logbook.QSOs[1].Band != "70cm" {
		t.Errorf("Expected 70cm, got %s", logbook.QSOs[1].Band)
	}

	// day ++ should add 2 days to 2026-01-01
	expectedDate := "2026-01-03"
	if logbook.QSOs[2].Timestamp.Format("2006-01-02") != expectedDate {
		t.Errorf("Expected date %s, got %s", expectedDate, logbook.QSOs[2].Timestamp.Format("2006-01-02"))
	}
}

func TestBaseCallsign(t *testing.T) {
	tests := []struct {
		call string
		want string
	}{
		{"F4JXQ", "F4JXQ"},
		{"DL/F4JXQ", "F4JXQ"},
		{"F4JXQ/P", "F4JXQ"},
		{"DL/F4JXQ/M", "F4JXQ"},
		{"3W/F4JXQ", "F4JXQ"},
		{"F4JXQ/1", "F4JXQ"},
		{"G/F4JXQ/P", "F4JXQ"},
	}

	for _, tt := range tests {
		got := BaseCallsign(tt.call)
		if got != tt.want {
			t.Errorf("BaseCallsign(%q) = %q, want %q", tt.call, got, tt.want)
		}
	}
}

func TestActivatedGrids(t *testing.T) {
	content := `
mycall F4JXQ
mygrid JN38qr
date 2023-10-26
40m CW
1200 F1ABC

mygrid JN39aa
1205 F2ABC

mygrid JN38qr
1210 F3ABC
`
	logbook, _, _ := ParseFLE(content)
	expected := []string{"JN38qr", "JN39aa"}
	if len(logbook.ActivatedGrids) != len(expected) {
		t.Fatalf("Expected %d activated grids, got %d", len(expected), len(logbook.ActivatedGrids))
	}
	for i, g := range logbook.ActivatedGrids {
		if g != expected[i] {
			t.Errorf("At index %d: expected %s, got %s", i, expected[i], g)
		}
	}
}
