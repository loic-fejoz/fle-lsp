package flelsp

import (
	"os"
	"testing"
)

func BenchmarkParseFLE_Big(b *testing.B) {
	content, err := os.ReadFile("big.fle")
	if err != nil {
		b.Fatalf("failed to read big.fle: %v", err)
	}
	sContent := string(content)

	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		_, _, err := ParseFLE(sContent)
		if err != nil {
			b.Fatal(err)
		}
	}
}

func BenchmarkParseFLE_Large(b *testing.B) {
	content, err := os.ReadFile("test_large.fle")
	if err != nil {
		b.Fatalf("failed to read test_large.fle: %v", err)
	}
	sContent := string(content)
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		lb, _, err := ParseFLE(sContent)
		if err != nil {
			b.Fatal(err)
		}
		CalculateStatistics(lb)
	}
}
