#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 31
#define SYMBOL_COUNT 81
#define ALIAS_COUNT 0
#define TOKEN_COUNT 60
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_comment = 1,
  aux_sym_header_token1 = 2,
  aux_sym_header_token2 = 3,
  aux_sym_header_token3 = 4,
  aux_sym_header_token4 = 5,
  aux_sym_header_token5 = 6,
  aux_sym_header_token6 = 7,
  aux_sym_header_token7 = 8,
  aux_sym_header_token8 = 9,
  sym_header_value = 10,
  aux_sym_date_command_token1 = 11,
  sym_date_value = 12,
  aux_sym_day_command_token1 = 13,
  sym_day_value = 14,
  aux_sym_band_token1 = 15,
  aux_sym_band_token2 = 16,
  anon_sym_CW = 17,
  anon_sym_SSB = 18,
  anon_sym_FM = 19,
  anon_sym_AM = 20,
  anon_sym_DIGI = 21,
  anon_sym_FT8 = 22,
  anon_sym_FT4 = 23,
  anon_sym_PSK = 24,
  anon_sym_RTTY = 25,
  anon_sym_VARAC = 26,
  anon_sym_MFSK = 27,
  anon_sym_DATA = 28,
  anon_sym_JS8 = 29,
  anon_sym_cw = 30,
  anon_sym_ssb = 31,
  anon_sym_fm = 32,
  anon_sym_am = 33,
  anon_sym_digi = 34,
  anon_sym_ft8 = 35,
  anon_sym_ft4 = 36,
  anon_sym_psk = 37,
  anon_sym_rtty = 38,
  anon_sym_varac = 39,
  anon_sym_mfsk = 40,
  anon_sym_data = 41,
  anon_sym_js8 = 42,
  sym_time = 43,
  sym_callsign = 44,
  aux_sym_rst_token1 = 45,
  anon_sym_COMMA = 46,
  anon_sym_DOT = 47,
  anon_sym_POUND = 48,
  aux_sym_grid_token1 = 49,
  anon_sym_AT = 50,
  aux_sym_name_token1 = 51,
  anon_sym_LBRACK = 52,
  aux_sym_inline_comment_token1 = 53,
  anon_sym_RBRACK = 54,
  anon_sym_LT = 55,
  aux_sym_qsl_info_token1 = 56,
  anon_sym_GT = 57,
  aux_sym_inline_hash_comment_token1 = 58,
  aux_sym_inline_hash_comment_token2 = 59,
  sym_source_file = 60,
  sym_header = 61,
  sym_date_command = 62,
  sym_day_command = 63,
  sym_band_mode_line = 64,
  sym_band = 65,
  sym_mode = 66,
  sym_qso_line = 67,
  sym_rst = 68,
  sym_serial_sent = 69,
  sym_serial_rcvd = 70,
  sym_qso_extra = 71,
  sym_grid = 72,
  sym_name = 73,
  sym_inline_comment = 74,
  sym_qsl_info = 75,
  sym_inline_hash_comment = 76,
  aux_sym_source_file_repeat1 = 77,
  aux_sym_band_mode_line_repeat1 = 78,
  aux_sym_qso_line_repeat1 = 79,
  aux_sym_qso_line_repeat2 = 80,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_comment] = "comment",
  [aux_sym_header_token1] = "keyword",
  [aux_sym_header_token2] = "keyword",
  [aux_sym_header_token3] = "keyword",
  [aux_sym_header_token4] = "keyword",
  [aux_sym_header_token5] = "keyword",
  [aux_sym_header_token6] = "keyword",
  [aux_sym_header_token7] = "keyword",
  [aux_sym_header_token8] = "keyword",
  [sym_header_value] = "header_value",
  [aux_sym_date_command_token1] = "keyword",
  [sym_date_value] = "date_value",
  [aux_sym_day_command_token1] = "keyword",
  [sym_day_value] = "day_value",
  [aux_sym_band_token1] = "band_token1",
  [aux_sym_band_token2] = "band_token2",
  [anon_sym_CW] = "CW",
  [anon_sym_SSB] = "SSB",
  [anon_sym_FM] = "FM",
  [anon_sym_AM] = "AM",
  [anon_sym_DIGI] = "DIGI",
  [anon_sym_FT8] = "FT8",
  [anon_sym_FT4] = "FT4",
  [anon_sym_PSK] = "PSK",
  [anon_sym_RTTY] = "RTTY",
  [anon_sym_VARAC] = "VARAC",
  [anon_sym_MFSK] = "MFSK",
  [anon_sym_DATA] = "DATA",
  [anon_sym_JS8] = "JS8",
  [anon_sym_cw] = "cw",
  [anon_sym_ssb] = "ssb",
  [anon_sym_fm] = "fm",
  [anon_sym_am] = "am",
  [anon_sym_digi] = "digi",
  [anon_sym_ft8] = "ft8",
  [anon_sym_ft4] = "ft4",
  [anon_sym_psk] = "psk",
  [anon_sym_rtty] = "rtty",
  [anon_sym_varac] = "varac",
  [anon_sym_mfsk] = "mfsk",
  [anon_sym_data] = "data",
  [anon_sym_js8] = "js8",
  [sym_time] = "time",
  [sym_callsign] = "callsign",
  [aux_sym_rst_token1] = "rst_token1",
  [anon_sym_COMMA] = ",",
  [anon_sym_DOT] = ".",
  [anon_sym_POUND] = "#",
  [aux_sym_grid_token1] = "grid_token1",
  [anon_sym_AT] = "@",
  [aux_sym_name_token1] = "name_token1",
  [anon_sym_LBRACK] = "[",
  [aux_sym_inline_comment_token1] = "inline_comment_token1",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LT] = "<",
  [aux_sym_qsl_info_token1] = "qsl_info_token1",
  [anon_sym_GT] = ">",
  [aux_sym_inline_hash_comment_token1] = "inline_hash_comment_token1",
  [aux_sym_inline_hash_comment_token2] = "inline_hash_comment_token2",
  [sym_source_file] = "source_file",
  [sym_header] = "header",
  [sym_date_command] = "date_command",
  [sym_day_command] = "day_command",
  [sym_band_mode_line] = "band_mode_line",
  [sym_band] = "band",
  [sym_mode] = "mode",
  [sym_qso_line] = "qso_line",
  [sym_rst] = "rst",
  [sym_serial_sent] = "serial_sent",
  [sym_serial_rcvd] = "serial_rcvd",
  [sym_qso_extra] = "qso_extra",
  [sym_grid] = "grid",
  [sym_name] = "name",
  [sym_inline_comment] = "inline_comment",
  [sym_qsl_info] = "qsl_info",
  [sym_inline_hash_comment] = "comment",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_band_mode_line_repeat1] = "band_mode_line_repeat1",
  [aux_sym_qso_line_repeat1] = "qso_line_repeat1",
  [aux_sym_qso_line_repeat2] = "qso_line_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_comment] = sym_comment,
  [aux_sym_header_token1] = aux_sym_header_token1,
  [aux_sym_header_token2] = aux_sym_header_token1,
  [aux_sym_header_token3] = aux_sym_header_token1,
  [aux_sym_header_token4] = aux_sym_header_token1,
  [aux_sym_header_token5] = aux_sym_header_token1,
  [aux_sym_header_token6] = aux_sym_header_token1,
  [aux_sym_header_token7] = aux_sym_header_token1,
  [aux_sym_header_token8] = aux_sym_header_token1,
  [sym_header_value] = sym_header_value,
  [aux_sym_date_command_token1] = aux_sym_header_token1,
  [sym_date_value] = sym_date_value,
  [aux_sym_day_command_token1] = aux_sym_header_token1,
  [sym_day_value] = sym_day_value,
  [aux_sym_band_token1] = aux_sym_band_token1,
  [aux_sym_band_token2] = aux_sym_band_token2,
  [anon_sym_CW] = anon_sym_CW,
  [anon_sym_SSB] = anon_sym_SSB,
  [anon_sym_FM] = anon_sym_FM,
  [anon_sym_AM] = anon_sym_AM,
  [anon_sym_DIGI] = anon_sym_DIGI,
  [anon_sym_FT8] = anon_sym_FT8,
  [anon_sym_FT4] = anon_sym_FT4,
  [anon_sym_PSK] = anon_sym_PSK,
  [anon_sym_RTTY] = anon_sym_RTTY,
  [anon_sym_VARAC] = anon_sym_VARAC,
  [anon_sym_MFSK] = anon_sym_MFSK,
  [anon_sym_DATA] = anon_sym_DATA,
  [anon_sym_JS8] = anon_sym_JS8,
  [anon_sym_cw] = anon_sym_cw,
  [anon_sym_ssb] = anon_sym_ssb,
  [anon_sym_fm] = anon_sym_fm,
  [anon_sym_am] = anon_sym_am,
  [anon_sym_digi] = anon_sym_digi,
  [anon_sym_ft8] = anon_sym_ft8,
  [anon_sym_ft4] = anon_sym_ft4,
  [anon_sym_psk] = anon_sym_psk,
  [anon_sym_rtty] = anon_sym_rtty,
  [anon_sym_varac] = anon_sym_varac,
  [anon_sym_mfsk] = anon_sym_mfsk,
  [anon_sym_data] = anon_sym_data,
  [anon_sym_js8] = anon_sym_js8,
  [sym_time] = sym_time,
  [sym_callsign] = sym_callsign,
  [aux_sym_rst_token1] = aux_sym_rst_token1,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym_grid_token1] = aux_sym_grid_token1,
  [anon_sym_AT] = anon_sym_AT,
  [aux_sym_name_token1] = aux_sym_name_token1,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [aux_sym_inline_comment_token1] = aux_sym_inline_comment_token1,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LT] = anon_sym_LT,
  [aux_sym_qsl_info_token1] = aux_sym_qsl_info_token1,
  [anon_sym_GT] = anon_sym_GT,
  [aux_sym_inline_hash_comment_token1] = aux_sym_inline_hash_comment_token1,
  [aux_sym_inline_hash_comment_token2] = aux_sym_inline_hash_comment_token2,
  [sym_source_file] = sym_source_file,
  [sym_header] = sym_header,
  [sym_date_command] = sym_date_command,
  [sym_day_command] = sym_day_command,
  [sym_band_mode_line] = sym_band_mode_line,
  [sym_band] = sym_band,
  [sym_mode] = sym_mode,
  [sym_qso_line] = sym_qso_line,
  [sym_rst] = sym_rst,
  [sym_serial_sent] = sym_serial_sent,
  [sym_serial_rcvd] = sym_serial_rcvd,
  [sym_qso_extra] = sym_qso_extra,
  [sym_grid] = sym_grid,
  [sym_name] = sym_name,
  [sym_inline_comment] = sym_inline_comment,
  [sym_qsl_info] = sym_qsl_info,
  [sym_inline_hash_comment] = sym_comment,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_band_mode_line_repeat1] = aux_sym_band_mode_line_repeat1,
  [aux_sym_qso_line_repeat1] = aux_sym_qso_line_repeat1,
  [aux_sym_qso_line_repeat2] = aux_sym_qso_line_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token1] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token2] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token3] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token4] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token5] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token6] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token7] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_header_token8] = {
    .visible = true,
    .named = true,
  },
  [sym_header_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_date_command_token1] = {
    .visible = true,
    .named = true,
  },
  [sym_date_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_day_command_token1] = {
    .visible = true,
    .named = true,
  },
  [sym_day_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_band_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_band_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_CW] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SSB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DIGI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FT8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FT4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PSK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RTTY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VARAC] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MFSK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DATA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_JS8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ssb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fm] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_am] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_digi] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ft8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ft4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psk] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rtty] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_varac] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mfsk] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_data] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_js8] = {
    .visible = true,
    .named = false,
  },
  [sym_time] = {
    .visible = true,
    .named = true,
  },
  [sym_callsign] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_rst_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_grid_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_name_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_inline_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_qsl_info_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_inline_hash_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_inline_hash_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_header] = {
    .visible = true,
    .named = true,
  },
  [sym_date_command] = {
    .visible = true,
    .named = true,
  },
  [sym_day_command] = {
    .visible = true,
    .named = true,
  },
  [sym_band_mode_line] = {
    .visible = true,
    .named = true,
  },
  [sym_band] = {
    .visible = true,
    .named = true,
  },
  [sym_mode] = {
    .visible = true,
    .named = true,
  },
  [sym_qso_line] = {
    .visible = true,
    .named = true,
  },
  [sym_rst] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_sent] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_rcvd] = {
    .visible = true,
    .named = true,
  },
  [sym_qso_extra] = {
    .visible = true,
    .named = true,
  },
  [sym_grid] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_qsl_info] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_hash_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_band_mode_line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_qso_line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_qso_line_repeat2] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(24);
      if (lookahead == '#') ADVANCE(298);
      if (lookahead == '+') ADVANCE(141);
      if (lookahead == ',') ADVANCE(296);
      if (lookahead == '.') ADVANCE(297);
      if (lookahead == '<') ADVANCE(312);
      if (lookahead == '>') ADVANCE(315);
      if (lookahead == '@') ADVANCE(306);
      if (lookahead == 'A') ADVANCE(222);
      if (lookahead == 'C') ADVANCE(233);
      if (lookahead == 'D') ADVANCE(210);
      if (lookahead == 'F') ADVANCE(223);
      if (lookahead == 'J') ADVANCE(225);
      if (lookahead == 'M') ADVANCE(217);
      if (lookahead == 'P') ADVANCE(226);
      if (lookahead == 'R') ADVANCE(231);
      if (lookahead == 'S') ADVANCE(227);
      if (lookahead == 'V') ADVANCE(212);
      if (lookahead == '[') ADVANCE(308);
      if (lookahead == ']') ADVANCE(311);
      if (lookahead == 'a') ADVANCE(245);
      if (lookahead == 'c') ADVANCE(254);
      if (lookahead == 'd') ADVANCE(211);
      if (lookahead == 'f') ADVANCE(246);
      if (lookahead == 'j') ADVANCE(250);
      if (lookahead == 'm') ADVANCE(240);
      if (lookahead == 'p') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(253);
      if (lookahead == 's') ADVANCE(249);
      if (lookahead == 'v') ADVANCE(235);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(270);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(283);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(287);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(203);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(14);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(15);
      END_STATE();
    case 3:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(316);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 4:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(142);
      END_STATE();
    case 5:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(314);
      END_STATE();
    case 6:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(18);
      END_STATE();
    case 7:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(309);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(310);
      END_STATE();
    case 8:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8)
      if (lookahead != 0) ADVANCE(307);
      END_STATE();
    case 9:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9)
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(295);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(2);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(1);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(305);
      END_STATE();
    case 20:
      if (eof) ADVANCE(24);
      if (lookahead == '#') ADVANCE(298);
      if (lookahead == ',') ADVANCE(296);
      if (lookahead == '.') ADVANCE(297);
      if (lookahead == '<') ADVANCE(312);
      if (lookahead == '@') ADVANCE(306);
      if (lookahead == 'A') ADVANCE(222);
      if (lookahead == 'C') ADVANCE(233);
      if (lookahead == 'D') ADVANCE(210);
      if (lookahead == 'F') ADVANCE(223);
      if (lookahead == 'J') ADVANCE(225);
      if (lookahead == 'M') ADVANCE(217);
      if (lookahead == 'P') ADVANCE(226);
      if (lookahead == 'R') ADVANCE(231);
      if (lookahead == 'S') ADVANCE(227);
      if (lookahead == 'V') ADVANCE(212);
      if (lookahead == '[') ADVANCE(308);
      if (lookahead == 'a') ADVANCE(245);
      if (lookahead == 'c') ADVANCE(254);
      if (lookahead == 'd') ADVANCE(211);
      if (lookahead == 'f') ADVANCE(246);
      if (lookahead == 'j') ADVANCE(250);
      if (lookahead == 'm') ADVANCE(240);
      if (lookahead == 'p') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(253);
      if (lookahead == 's') ADVANCE(249);
      if (lookahead == 'v') ADVANCE(235);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(270);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(283);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(287);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 21:
      if (eof) ADVANCE(24);
      if (lookahead == '#') ADVANCE(298);
      if (lookahead == '<') ADVANCE(312);
      if (lookahead == '@') ADVANCE(306);
      if (lookahead == 'A') ADVANCE(222);
      if (lookahead == 'C') ADVANCE(233);
      if (lookahead == 'D') ADVANCE(210);
      if (lookahead == 'F') ADVANCE(223);
      if (lookahead == 'J') ADVANCE(225);
      if (lookahead == 'M') ADVANCE(217);
      if (lookahead == 'P') ADVANCE(226);
      if (lookahead == 'R') ADVANCE(231);
      if (lookahead == 'S') ADVANCE(227);
      if (lookahead == 'V') ADVANCE(212);
      if (lookahead == '[') ADVANCE(308);
      if (lookahead == 'a') ADVANCE(245);
      if (lookahead == 'c') ADVANCE(254);
      if (lookahead == 'd') ADVANCE(211);
      if (lookahead == 'f') ADVANCE(246);
      if (lookahead == 'j') ADVANCE(250);
      if (lookahead == 'm') ADVANCE(240);
      if (lookahead == 'p') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(253);
      if (lookahead == 's') ADVANCE(249);
      if (lookahead == 'v') ADVANCE(235);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(270);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(283);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(287);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(21)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 22:
      if (eof) ADVANCE(24);
      if (lookahead == '#') ADVANCE(26);
      if (lookahead == 'A') ADVANCE(222);
      if (lookahead == 'C') ADVANCE(233);
      if (lookahead == 'D') ADVANCE(210);
      if (lookahead == 'F') ADVANCE(223);
      if (lookahead == 'J') ADVANCE(225);
      if (lookahead == 'M') ADVANCE(217);
      if (lookahead == 'P') ADVANCE(226);
      if (lookahead == 'R') ADVANCE(231);
      if (lookahead == 'S') ADVANCE(227);
      if (lookahead == 'V') ADVANCE(212);
      if (lookahead == 'a') ADVANCE(245);
      if (lookahead == 'c') ADVANCE(254);
      if (lookahead == 'd') ADVANCE(211);
      if (lookahead == 'f') ADVANCE(246);
      if (lookahead == 'j') ADVANCE(250);
      if (lookahead == 'm') ADVANCE(240);
      if (lookahead == 'p') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(253);
      if (lookahead == 's') ADVANCE(249);
      if (lookahead == 'v') ADVANCE(235);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(270);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(283);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(287);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(22)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(205);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 23:
      if (eof) ADVANCE(24);
      if (lookahead == '#') ADVANCE(25);
      if (lookahead == 'A') ADVANCE(61);
      if (lookahead == 'C') ADVANCE(72);
      if (lookahead == 'D') ADVANCE(49);
      if (lookahead == 'F') ADVANCE(62);
      if (lookahead == 'J') ADVANCE(64);
      if (lookahead == 'M') ADVANCE(56);
      if (lookahead == 'P') ADVANCE(65);
      if (lookahead == 'R') ADVANCE(70);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'V') ADVANCE(51);
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'c') ADVANCE(93);
      if (lookahead == 'd') ADVANCE(50);
      if (lookahead == 'f') ADVANCE(85);
      if (lookahead == 'j') ADVANCE(89);
      if (lookahead == 'm') ADVANCE(79);
      if (lookahead == 'p') ADVANCE(87);
      if (lookahead == 'r') ADVANCE(92);
      if (lookahead == 's') ADVANCE(88);
      if (lookahead == 'v') ADVANCE(74);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(23)
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(110);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(124);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(128);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0) ADVANCE(137);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\r') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_header_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_header_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_header_token2);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_header_token2);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_header_token3);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_header_token3);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_header_token4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_header_token4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_header_token5);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_header_token5);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_header_token6);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_header_token6);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_header_token7);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_header_token7);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_header_token8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_header_token8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '#') ADVANCE(25);
      if (lookahead == 'A') ADVANCE(61);
      if (lookahead == 'C') ADVANCE(72);
      if (lookahead == 'D') ADVANCE(49);
      if (lookahead == 'F') ADVANCE(62);
      if (lookahead == 'J') ADVANCE(64);
      if (lookahead == 'M') ADVANCE(56);
      if (lookahead == 'P') ADVANCE(65);
      if (lookahead == 'R') ADVANCE(70);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'V') ADVANCE(51);
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'c') ADVANCE(93);
      if (lookahead == 'd') ADVANCE(50);
      if (lookahead == 'f') ADVANCE(85);
      if (lookahead == 'j') ADVANCE(89);
      if (lookahead == 'm') ADVANCE(79);
      if (lookahead == 'p') ADVANCE(87);
      if (lookahead == 'r') ADVANCE(92);
      if (lookahead == 's') ADVANCE(88);
      if (lookahead == 'v') ADVANCE(74);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(110);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(124);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(128);
      if (lookahead == '\t' ||
          lookahead == 11 ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          (lookahead < '\n' || '\r' < lookahead)) ADVANCE(137);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '.') ADVANCE(135);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(116);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '4') ADVANCE(158);
      if (lookahead == '8') ADVANCE(156);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '4') ADVANCE(184);
      if (lookahead == '8') ADVANCE(182);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '8') ADVANCE(170);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '8') ADVANCE(196);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(68);
      if (lookahead == 'I') ADVANCE(57);
      if (lookahead == 'a') ADVANCE(130);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(130);
      if (lookahead == 'a') ADVANCE(71);
      if (lookahead == 'i') ADVANCE(80);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(63);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(168);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(55);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'B') ADVANCE(148);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C') ADVANCE(164);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'F') ADVANCE(67);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(100);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'G') ADVANCE(58);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'I') ADVANCE(154);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'K') ADVANCE(160);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'K') ADVANCE(166);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M') ADVANCE(152);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M') ADVANCE(150);
      if (lookahead == 'T') ADVANCE(45);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R') ADVANCE(53);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(47);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(59);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(54);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(60);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(52);
      if (lookahead == 't') ADVANCE(104);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(73);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(69);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(104);
      if (lookahead == 't') ADVANCE(75);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'W') ADVANCE(146);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'Y') ADVANCE(162);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'a') ADVANCE(86);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'a') ADVANCE(194);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'a') ADVANCE(78);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'b') ADVANCE(174);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'c') ADVANCE(190);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'f') ADVANCE(90);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(100);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'g') ADVANCE(81);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'i') ADVANCE(180);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'k') ADVANCE(186);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'k') ADVANCE(192);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'm') ADVANCE(178);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'm') ADVANCE(176);
      if (lookahead == 't') ADVANCE(46);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'r') ADVANCE(76);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(82);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(77);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(48);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(83);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 't') ADVANCE(94);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 't') ADVANCE(91);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'w') ADVANCE(172);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'y') ADVANCE(188);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(42);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(40);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(115);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(131);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(119);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(97);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(126);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(121);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(123);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(112);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(117);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(30);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(34);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(107);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(36);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(101);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(103);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(120);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(118);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(113);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(129);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(105);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(99);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(132);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(125);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(133);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(32);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(111);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(98);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(114);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(109);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(104);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(122);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(95);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(96);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(108);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_header_value);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_header_value);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_date_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_date_value);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_day_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_day_value);
      if (lookahead == '+') ADVANCE(141);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_band_token1);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_band_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_band_token2);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(4);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_CW);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_CW);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_SSB);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_SSB);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_FM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_FM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_AM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_AM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_DIGI);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_DIGI);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_FT8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_FT8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_FT4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_FT4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_PSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_PSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_RTTY);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_RTTY);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_VARAC);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_VARAC);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_MFSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_MFSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_DATA);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_DATA);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_JS8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_JS8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_cw);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_cw);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_ssb);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_ssb);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_fm);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_fm);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_am);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_am);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_digi);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_digi);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_ft8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_ft8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_ft4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_ft4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_psk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_psk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_rtty);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_rtty);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_varac);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_varac);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_mfsk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_mfsk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_data);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_data);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_js8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_js8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(137);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '-') ADVANCE(14);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(204);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(197);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(204);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(198);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(199);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(201);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(200);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(204);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(276);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(202);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(157);
      if (lookahead == '8') ADVANCE(155);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(183);
      if (lookahead == '8') ADVANCE(181);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(169);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(195);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(229);
      if (lookahead == 'I') ADVANCE(218);
      if (lookahead == 'a') ADVANCE(289);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(289);
      if (lookahead == 'a') ADVANCE(232);
      if (lookahead == 'i') ADVANCE(241);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(224);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(167);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(216);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'B') ADVANCE(147);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C') ADVANCE(163);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F') ADVANCE(228);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(261);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G') ADVANCE(219);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I') ADVANCE(153);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(159);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(165);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(151);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(149);
      if (lookahead == 'T') ADVANCE(206);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R') ADVANCE(214);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(208);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(220);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(215);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(221);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 't') ADVANCE(264);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(140);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(234);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(230);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(264);
      if (lookahead == 't') ADVANCE(236);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(140);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W') ADVANCE(145);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'Y') ADVANCE(161);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(247);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(193);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(239);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'b') ADVANCE(173);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'c') ADVANCE(189);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'f') ADVANCE(251);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(261);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'g') ADVANCE(242);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'i') ADVANCE(179);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(185);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(191);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(177);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(175);
      if (lookahead == 't') ADVANCE(207);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'r') ADVANCE(237);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(243);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(238);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(209);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(244);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(255);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(252);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'w') ADVANCE(171);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'y') ADVANCE(187);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(41);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(39);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(275);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(290);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(278);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(258);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(285);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(280);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(282);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(293);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(272);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(29);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(33);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(286);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(37);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(267);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(35);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(262);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(263);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(279);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(27);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(277);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(273);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(143);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(288);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(265);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(260);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(291);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(284);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(292);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(266);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(271);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(259);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(274);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(269);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(264);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(140);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(281);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(256);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(257);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(268);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_callsign);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_rst_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(295);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(26);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(300);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(301);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(302);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(303);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(304);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(aux_sym_name_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(307);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(309);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(310);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(310);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(313);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(314);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(314);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(aux_sym_inline_hash_comment_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(316);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(aux_sym_inline_hash_comment_token2);
      if (lookahead == '\t' ||
          (11 <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(317);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(318);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(aux_sym_inline_hash_comment_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(318);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 22},
  [2] = {.lex_state = 20},
  [3] = {.lex_state = 20},
  [4] = {.lex_state = 20},
  [5] = {.lex_state = 20},
  [6] = {.lex_state = 21},
  [7] = {.lex_state = 21},
  [8] = {.lex_state = 21},
  [9] = {.lex_state = 21},
  [10] = {.lex_state = 20},
  [11] = {.lex_state = 22},
  [12] = {.lex_state = 22},
  [13] = {.lex_state = 20},
  [14] = {.lex_state = 20},
  [15] = {.lex_state = 20},
  [16] = {.lex_state = 21},
  [17] = {.lex_state = 21},
  [18] = {.lex_state = 21},
  [19] = {.lex_state = 21},
  [20] = {.lex_state = 21},
  [21] = {.lex_state = 21},
  [22] = {.lex_state = 22},
  [23] = {.lex_state = 22},
  [24] = {.lex_state = 22},
  [25] = {.lex_state = 23},
  [26] = {.lex_state = 22},
  [27] = {.lex_state = 22},
  [28] = {.lex_state = 22},
  [29] = {.lex_state = 22},
  [30] = {.lex_state = 22},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 317},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 7},
  [38] = {.lex_state = 8},
  [39] = {.lex_state = 10},
  [40] = {.lex_state = 10},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 9},
  [43] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [aux_sym_header_token1] = ACTIONS(1),
    [aux_sym_header_token2] = ACTIONS(1),
    [aux_sym_header_token3] = ACTIONS(1),
    [aux_sym_header_token4] = ACTIONS(1),
    [aux_sym_header_token5] = ACTIONS(1),
    [aux_sym_header_token6] = ACTIONS(1),
    [aux_sym_header_token7] = ACTIONS(1),
    [aux_sym_header_token8] = ACTIONS(1),
    [aux_sym_date_command_token1] = ACTIONS(1),
    [sym_date_value] = ACTIONS(1),
    [aux_sym_day_command_token1] = ACTIONS(1),
    [sym_day_value] = ACTIONS(1),
    [aux_sym_band_token1] = ACTIONS(1),
    [aux_sym_band_token2] = ACTIONS(1),
    [anon_sym_CW] = ACTIONS(1),
    [anon_sym_SSB] = ACTIONS(1),
    [anon_sym_FM] = ACTIONS(1),
    [anon_sym_AM] = ACTIONS(1),
    [anon_sym_DIGI] = ACTIONS(1),
    [anon_sym_FT8] = ACTIONS(1),
    [anon_sym_FT4] = ACTIONS(1),
    [anon_sym_PSK] = ACTIONS(1),
    [anon_sym_RTTY] = ACTIONS(1),
    [anon_sym_VARAC] = ACTIONS(1),
    [anon_sym_MFSK] = ACTIONS(1),
    [anon_sym_DATA] = ACTIONS(1),
    [anon_sym_JS8] = ACTIONS(1),
    [anon_sym_cw] = ACTIONS(1),
    [anon_sym_ssb] = ACTIONS(1),
    [anon_sym_fm] = ACTIONS(1),
    [anon_sym_am] = ACTIONS(1),
    [anon_sym_digi] = ACTIONS(1),
    [anon_sym_ft8] = ACTIONS(1),
    [anon_sym_ft4] = ACTIONS(1),
    [anon_sym_psk] = ACTIONS(1),
    [anon_sym_rtty] = ACTIONS(1),
    [anon_sym_varac] = ACTIONS(1),
    [anon_sym_mfsk] = ACTIONS(1),
    [anon_sym_data] = ACTIONS(1),
    [anon_sym_js8] = ACTIONS(1),
    [sym_time] = ACTIONS(1),
    [sym_callsign] = ACTIONS(1),
    [aux_sym_rst_token1] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(41),
    [sym_header] = STATE(11),
    [sym_date_command] = STATE(11),
    [sym_day_command] = STATE(11),
    [sym_band_mode_line] = STATE(11),
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [sym_qso_line] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [aux_sym_header_token1] = ACTIONS(7),
    [aux_sym_header_token2] = ACTIONS(7),
    [aux_sym_header_token3] = ACTIONS(7),
    [aux_sym_header_token4] = ACTIONS(7),
    [aux_sym_header_token5] = ACTIONS(7),
    [aux_sym_header_token6] = ACTIONS(7),
    [aux_sym_header_token7] = ACTIONS(7),
    [aux_sym_header_token8] = ACTIONS(7),
    [aux_sym_date_command_token1] = ACTIONS(9),
    [aux_sym_day_command_token1] = ACTIONS(11),
    [aux_sym_band_token1] = ACTIONS(13),
    [aux_sym_band_token2] = ACTIONS(13),
    [anon_sym_CW] = ACTIONS(15),
    [anon_sym_SSB] = ACTIONS(15),
    [anon_sym_FM] = ACTIONS(15),
    [anon_sym_AM] = ACTIONS(15),
    [anon_sym_DIGI] = ACTIONS(15),
    [anon_sym_FT8] = ACTIONS(15),
    [anon_sym_FT4] = ACTIONS(15),
    [anon_sym_PSK] = ACTIONS(15),
    [anon_sym_RTTY] = ACTIONS(15),
    [anon_sym_VARAC] = ACTIONS(15),
    [anon_sym_MFSK] = ACTIONS(15),
    [anon_sym_DATA] = ACTIONS(15),
    [anon_sym_JS8] = ACTIONS(15),
    [anon_sym_cw] = ACTIONS(15),
    [anon_sym_ssb] = ACTIONS(15),
    [anon_sym_fm] = ACTIONS(15),
    [anon_sym_am] = ACTIONS(15),
    [anon_sym_digi] = ACTIONS(15),
    [anon_sym_ft8] = ACTIONS(15),
    [anon_sym_ft4] = ACTIONS(15),
    [anon_sym_psk] = ACTIONS(15),
    [anon_sym_rtty] = ACTIONS(15),
    [anon_sym_varac] = ACTIONS(15),
    [anon_sym_mfsk] = ACTIONS(15),
    [anon_sym_data] = ACTIONS(15),
    [anon_sym_js8] = ACTIONS(15),
    [sym_time] = ACTIONS(17),
    [sym_callsign] = ACTIONS(19),
  },
  [2] = {
    [sym_rst] = STATE(10),
    [sym_serial_sent] = STATE(10),
    [sym_serial_rcvd] = STATE(10),
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(10),
    [aux_sym_qso_line_repeat2] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_comment] = ACTIONS(23),
    [aux_sym_header_token1] = ACTIONS(23),
    [aux_sym_header_token2] = ACTIONS(23),
    [aux_sym_header_token3] = ACTIONS(23),
    [aux_sym_header_token4] = ACTIONS(23),
    [aux_sym_header_token5] = ACTIONS(23),
    [aux_sym_header_token6] = ACTIONS(23),
    [aux_sym_header_token7] = ACTIONS(23),
    [aux_sym_header_token8] = ACTIONS(23),
    [aux_sym_date_command_token1] = ACTIONS(23),
    [aux_sym_day_command_token1] = ACTIONS(23),
    [aux_sym_band_token1] = ACTIONS(23),
    [aux_sym_band_token2] = ACTIONS(23),
    [anon_sym_CW] = ACTIONS(23),
    [anon_sym_SSB] = ACTIONS(23),
    [anon_sym_FM] = ACTIONS(23),
    [anon_sym_AM] = ACTIONS(23),
    [anon_sym_DIGI] = ACTIONS(23),
    [anon_sym_FT8] = ACTIONS(23),
    [anon_sym_FT4] = ACTIONS(23),
    [anon_sym_PSK] = ACTIONS(23),
    [anon_sym_RTTY] = ACTIONS(23),
    [anon_sym_VARAC] = ACTIONS(23),
    [anon_sym_MFSK] = ACTIONS(23),
    [anon_sym_DATA] = ACTIONS(23),
    [anon_sym_JS8] = ACTIONS(23),
    [anon_sym_cw] = ACTIONS(23),
    [anon_sym_ssb] = ACTIONS(23),
    [anon_sym_fm] = ACTIONS(23),
    [anon_sym_am] = ACTIONS(23),
    [anon_sym_digi] = ACTIONS(23),
    [anon_sym_ft8] = ACTIONS(23),
    [anon_sym_ft4] = ACTIONS(23),
    [anon_sym_psk] = ACTIONS(23),
    [anon_sym_rtty] = ACTIONS(23),
    [anon_sym_varac] = ACTIONS(23),
    [anon_sym_mfsk] = ACTIONS(23),
    [anon_sym_data] = ACTIONS(23),
    [anon_sym_js8] = ACTIONS(23),
    [sym_time] = ACTIONS(23),
    [sym_callsign] = ACTIONS(23),
    [aux_sym_rst_token1] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_DOT] = ACTIONS(29),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [3] = {
    [sym_rst] = STATE(2),
    [sym_serial_sent] = STATE(2),
    [sym_serial_rcvd] = STATE(2),
    [sym_qso_extra] = STATE(9),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(2),
    [aux_sym_qso_line_repeat2] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(39),
    [sym_comment] = ACTIONS(41),
    [aux_sym_header_token1] = ACTIONS(41),
    [aux_sym_header_token2] = ACTIONS(41),
    [aux_sym_header_token3] = ACTIONS(41),
    [aux_sym_header_token4] = ACTIONS(41),
    [aux_sym_header_token5] = ACTIONS(41),
    [aux_sym_header_token6] = ACTIONS(41),
    [aux_sym_header_token7] = ACTIONS(41),
    [aux_sym_header_token8] = ACTIONS(41),
    [aux_sym_date_command_token1] = ACTIONS(41),
    [aux_sym_day_command_token1] = ACTIONS(41),
    [aux_sym_band_token1] = ACTIONS(41),
    [aux_sym_band_token2] = ACTIONS(41),
    [anon_sym_CW] = ACTIONS(41),
    [anon_sym_SSB] = ACTIONS(41),
    [anon_sym_FM] = ACTIONS(41),
    [anon_sym_AM] = ACTIONS(41),
    [anon_sym_DIGI] = ACTIONS(41),
    [anon_sym_FT8] = ACTIONS(41),
    [anon_sym_FT4] = ACTIONS(41),
    [anon_sym_PSK] = ACTIONS(41),
    [anon_sym_RTTY] = ACTIONS(41),
    [anon_sym_VARAC] = ACTIONS(41),
    [anon_sym_MFSK] = ACTIONS(41),
    [anon_sym_DATA] = ACTIONS(41),
    [anon_sym_JS8] = ACTIONS(41),
    [anon_sym_cw] = ACTIONS(41),
    [anon_sym_ssb] = ACTIONS(41),
    [anon_sym_fm] = ACTIONS(41),
    [anon_sym_am] = ACTIONS(41),
    [anon_sym_digi] = ACTIONS(41),
    [anon_sym_ft8] = ACTIONS(41),
    [anon_sym_ft4] = ACTIONS(41),
    [anon_sym_psk] = ACTIONS(41),
    [anon_sym_rtty] = ACTIONS(41),
    [anon_sym_varac] = ACTIONS(41),
    [anon_sym_mfsk] = ACTIONS(41),
    [anon_sym_data] = ACTIONS(41),
    [anon_sym_js8] = ACTIONS(41),
    [sym_time] = ACTIONS(41),
    [sym_callsign] = ACTIONS(41),
    [aux_sym_rst_token1] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_DOT] = ACTIONS(29),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [4] = {
    [sym_rst] = STATE(10),
    [sym_serial_sent] = STATE(10),
    [sym_serial_rcvd] = STATE(10),
    [sym_qso_extra] = STATE(7),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(10),
    [aux_sym_qso_line_repeat2] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(45),
    [aux_sym_header_token1] = ACTIONS(45),
    [aux_sym_header_token2] = ACTIONS(45),
    [aux_sym_header_token3] = ACTIONS(45),
    [aux_sym_header_token4] = ACTIONS(45),
    [aux_sym_header_token5] = ACTIONS(45),
    [aux_sym_header_token6] = ACTIONS(45),
    [aux_sym_header_token7] = ACTIONS(45),
    [aux_sym_header_token8] = ACTIONS(45),
    [aux_sym_date_command_token1] = ACTIONS(45),
    [aux_sym_day_command_token1] = ACTIONS(45),
    [aux_sym_band_token1] = ACTIONS(45),
    [aux_sym_band_token2] = ACTIONS(45),
    [anon_sym_CW] = ACTIONS(45),
    [anon_sym_SSB] = ACTIONS(45),
    [anon_sym_FM] = ACTIONS(45),
    [anon_sym_AM] = ACTIONS(45),
    [anon_sym_DIGI] = ACTIONS(45),
    [anon_sym_FT8] = ACTIONS(45),
    [anon_sym_FT4] = ACTIONS(45),
    [anon_sym_PSK] = ACTIONS(45),
    [anon_sym_RTTY] = ACTIONS(45),
    [anon_sym_VARAC] = ACTIONS(45),
    [anon_sym_MFSK] = ACTIONS(45),
    [anon_sym_DATA] = ACTIONS(45),
    [anon_sym_JS8] = ACTIONS(45),
    [anon_sym_cw] = ACTIONS(45),
    [anon_sym_ssb] = ACTIONS(45),
    [anon_sym_fm] = ACTIONS(45),
    [anon_sym_am] = ACTIONS(45),
    [anon_sym_digi] = ACTIONS(45),
    [anon_sym_ft8] = ACTIONS(45),
    [anon_sym_ft4] = ACTIONS(45),
    [anon_sym_psk] = ACTIONS(45),
    [anon_sym_rtty] = ACTIONS(45),
    [anon_sym_varac] = ACTIONS(45),
    [anon_sym_mfsk] = ACTIONS(45),
    [anon_sym_data] = ACTIONS(45),
    [anon_sym_js8] = ACTIONS(45),
    [sym_time] = ACTIONS(45),
    [sym_callsign] = ACTIONS(45),
    [aux_sym_rst_token1] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_DOT] = ACTIONS(29),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [5] = {
    [sym_rst] = STATE(4),
    [sym_serial_sent] = STATE(4),
    [sym_serial_rcvd] = STATE(4),
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(4),
    [aux_sym_qso_line_repeat2] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_comment] = ACTIONS(23),
    [aux_sym_header_token1] = ACTIONS(23),
    [aux_sym_header_token2] = ACTIONS(23),
    [aux_sym_header_token3] = ACTIONS(23),
    [aux_sym_header_token4] = ACTIONS(23),
    [aux_sym_header_token5] = ACTIONS(23),
    [aux_sym_header_token6] = ACTIONS(23),
    [aux_sym_header_token7] = ACTIONS(23),
    [aux_sym_header_token8] = ACTIONS(23),
    [aux_sym_date_command_token1] = ACTIONS(23),
    [aux_sym_day_command_token1] = ACTIONS(23),
    [aux_sym_band_token1] = ACTIONS(23),
    [aux_sym_band_token2] = ACTIONS(23),
    [anon_sym_CW] = ACTIONS(23),
    [anon_sym_SSB] = ACTIONS(23),
    [anon_sym_FM] = ACTIONS(23),
    [anon_sym_AM] = ACTIONS(23),
    [anon_sym_DIGI] = ACTIONS(23),
    [anon_sym_FT8] = ACTIONS(23),
    [anon_sym_FT4] = ACTIONS(23),
    [anon_sym_PSK] = ACTIONS(23),
    [anon_sym_RTTY] = ACTIONS(23),
    [anon_sym_VARAC] = ACTIONS(23),
    [anon_sym_MFSK] = ACTIONS(23),
    [anon_sym_DATA] = ACTIONS(23),
    [anon_sym_JS8] = ACTIONS(23),
    [anon_sym_cw] = ACTIONS(23),
    [anon_sym_ssb] = ACTIONS(23),
    [anon_sym_fm] = ACTIONS(23),
    [anon_sym_am] = ACTIONS(23),
    [anon_sym_digi] = ACTIONS(23),
    [anon_sym_ft8] = ACTIONS(23),
    [anon_sym_ft4] = ACTIONS(23),
    [anon_sym_psk] = ACTIONS(23),
    [anon_sym_rtty] = ACTIONS(23),
    [anon_sym_varac] = ACTIONS(23),
    [anon_sym_mfsk] = ACTIONS(23),
    [anon_sym_data] = ACTIONS(23),
    [anon_sym_js8] = ACTIONS(23),
    [sym_time] = ACTIONS(23),
    [sym_callsign] = ACTIONS(23),
    [aux_sym_rst_token1] = ACTIONS(25),
    [anon_sym_COMMA] = ACTIONS(27),
    [anon_sym_DOT] = ACTIONS(29),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [6] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat2] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_comment] = ACTIONS(49),
    [aux_sym_header_token1] = ACTIONS(49),
    [aux_sym_header_token2] = ACTIONS(49),
    [aux_sym_header_token3] = ACTIONS(49),
    [aux_sym_header_token4] = ACTIONS(49),
    [aux_sym_header_token5] = ACTIONS(49),
    [aux_sym_header_token6] = ACTIONS(49),
    [aux_sym_header_token7] = ACTIONS(49),
    [aux_sym_header_token8] = ACTIONS(49),
    [aux_sym_date_command_token1] = ACTIONS(49),
    [aux_sym_day_command_token1] = ACTIONS(49),
    [aux_sym_band_token1] = ACTIONS(49),
    [aux_sym_band_token2] = ACTIONS(49),
    [anon_sym_CW] = ACTIONS(49),
    [anon_sym_SSB] = ACTIONS(49),
    [anon_sym_FM] = ACTIONS(49),
    [anon_sym_AM] = ACTIONS(49),
    [anon_sym_DIGI] = ACTIONS(49),
    [anon_sym_FT8] = ACTIONS(49),
    [anon_sym_FT4] = ACTIONS(49),
    [anon_sym_PSK] = ACTIONS(49),
    [anon_sym_RTTY] = ACTIONS(49),
    [anon_sym_VARAC] = ACTIONS(49),
    [anon_sym_MFSK] = ACTIONS(49),
    [anon_sym_DATA] = ACTIONS(49),
    [anon_sym_JS8] = ACTIONS(49),
    [anon_sym_cw] = ACTIONS(49),
    [anon_sym_ssb] = ACTIONS(49),
    [anon_sym_fm] = ACTIONS(49),
    [anon_sym_am] = ACTIONS(49),
    [anon_sym_digi] = ACTIONS(49),
    [anon_sym_ft8] = ACTIONS(49),
    [anon_sym_ft4] = ACTIONS(49),
    [anon_sym_psk] = ACTIONS(49),
    [anon_sym_rtty] = ACTIONS(49),
    [anon_sym_varac] = ACTIONS(49),
    [anon_sym_mfsk] = ACTIONS(49),
    [anon_sym_data] = ACTIONS(49),
    [anon_sym_js8] = ACTIONS(49),
    [sym_time] = ACTIONS(49),
    [sym_callsign] = ACTIONS(49),
    [anon_sym_POUND] = ACTIONS(51),
    [anon_sym_AT] = ACTIONS(54),
    [anon_sym_LBRACK] = ACTIONS(57),
    [anon_sym_LT] = ACTIONS(60),
  },
  [7] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat2] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(63),
    [sym_comment] = ACTIONS(65),
    [aux_sym_header_token1] = ACTIONS(65),
    [aux_sym_header_token2] = ACTIONS(65),
    [aux_sym_header_token3] = ACTIONS(65),
    [aux_sym_header_token4] = ACTIONS(65),
    [aux_sym_header_token5] = ACTIONS(65),
    [aux_sym_header_token6] = ACTIONS(65),
    [aux_sym_header_token7] = ACTIONS(65),
    [aux_sym_header_token8] = ACTIONS(65),
    [aux_sym_date_command_token1] = ACTIONS(65),
    [aux_sym_day_command_token1] = ACTIONS(65),
    [aux_sym_band_token1] = ACTIONS(65),
    [aux_sym_band_token2] = ACTIONS(65),
    [anon_sym_CW] = ACTIONS(65),
    [anon_sym_SSB] = ACTIONS(65),
    [anon_sym_FM] = ACTIONS(65),
    [anon_sym_AM] = ACTIONS(65),
    [anon_sym_DIGI] = ACTIONS(65),
    [anon_sym_FT8] = ACTIONS(65),
    [anon_sym_FT4] = ACTIONS(65),
    [anon_sym_PSK] = ACTIONS(65),
    [anon_sym_RTTY] = ACTIONS(65),
    [anon_sym_VARAC] = ACTIONS(65),
    [anon_sym_MFSK] = ACTIONS(65),
    [anon_sym_DATA] = ACTIONS(65),
    [anon_sym_JS8] = ACTIONS(65),
    [anon_sym_cw] = ACTIONS(65),
    [anon_sym_ssb] = ACTIONS(65),
    [anon_sym_fm] = ACTIONS(65),
    [anon_sym_am] = ACTIONS(65),
    [anon_sym_digi] = ACTIONS(65),
    [anon_sym_ft8] = ACTIONS(65),
    [anon_sym_ft4] = ACTIONS(65),
    [anon_sym_psk] = ACTIONS(65),
    [anon_sym_rtty] = ACTIONS(65),
    [anon_sym_varac] = ACTIONS(65),
    [anon_sym_mfsk] = ACTIONS(65),
    [anon_sym_data] = ACTIONS(65),
    [anon_sym_js8] = ACTIONS(65),
    [sym_time] = ACTIONS(65),
    [sym_callsign] = ACTIONS(65),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [8] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat2] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(45),
    [aux_sym_header_token1] = ACTIONS(45),
    [aux_sym_header_token2] = ACTIONS(45),
    [aux_sym_header_token3] = ACTIONS(45),
    [aux_sym_header_token4] = ACTIONS(45),
    [aux_sym_header_token5] = ACTIONS(45),
    [aux_sym_header_token6] = ACTIONS(45),
    [aux_sym_header_token7] = ACTIONS(45),
    [aux_sym_header_token8] = ACTIONS(45),
    [aux_sym_date_command_token1] = ACTIONS(45),
    [aux_sym_day_command_token1] = ACTIONS(45),
    [aux_sym_band_token1] = ACTIONS(45),
    [aux_sym_band_token2] = ACTIONS(45),
    [anon_sym_CW] = ACTIONS(45),
    [anon_sym_SSB] = ACTIONS(45),
    [anon_sym_FM] = ACTIONS(45),
    [anon_sym_AM] = ACTIONS(45),
    [anon_sym_DIGI] = ACTIONS(45),
    [anon_sym_FT8] = ACTIONS(45),
    [anon_sym_FT4] = ACTIONS(45),
    [anon_sym_PSK] = ACTIONS(45),
    [anon_sym_RTTY] = ACTIONS(45),
    [anon_sym_VARAC] = ACTIONS(45),
    [anon_sym_MFSK] = ACTIONS(45),
    [anon_sym_DATA] = ACTIONS(45),
    [anon_sym_JS8] = ACTIONS(45),
    [anon_sym_cw] = ACTIONS(45),
    [anon_sym_ssb] = ACTIONS(45),
    [anon_sym_fm] = ACTIONS(45),
    [anon_sym_am] = ACTIONS(45),
    [anon_sym_digi] = ACTIONS(45),
    [anon_sym_ft8] = ACTIONS(45),
    [anon_sym_ft4] = ACTIONS(45),
    [anon_sym_psk] = ACTIONS(45),
    [anon_sym_rtty] = ACTIONS(45),
    [anon_sym_varac] = ACTIONS(45),
    [anon_sym_mfsk] = ACTIONS(45),
    [anon_sym_data] = ACTIONS(45),
    [anon_sym_js8] = ACTIONS(45),
    [sym_time] = ACTIONS(45),
    [sym_callsign] = ACTIONS(45),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [9] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [sym_inline_hash_comment] = STATE(21),
    [aux_sym_qso_line_repeat2] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_comment] = ACTIONS(23),
    [aux_sym_header_token1] = ACTIONS(23),
    [aux_sym_header_token2] = ACTIONS(23),
    [aux_sym_header_token3] = ACTIONS(23),
    [aux_sym_header_token4] = ACTIONS(23),
    [aux_sym_header_token5] = ACTIONS(23),
    [aux_sym_header_token6] = ACTIONS(23),
    [aux_sym_header_token7] = ACTIONS(23),
    [aux_sym_header_token8] = ACTIONS(23),
    [aux_sym_date_command_token1] = ACTIONS(23),
    [aux_sym_day_command_token1] = ACTIONS(23),
    [aux_sym_band_token1] = ACTIONS(23),
    [aux_sym_band_token2] = ACTIONS(23),
    [anon_sym_CW] = ACTIONS(23),
    [anon_sym_SSB] = ACTIONS(23),
    [anon_sym_FM] = ACTIONS(23),
    [anon_sym_AM] = ACTIONS(23),
    [anon_sym_DIGI] = ACTIONS(23),
    [anon_sym_FT8] = ACTIONS(23),
    [anon_sym_FT4] = ACTIONS(23),
    [anon_sym_PSK] = ACTIONS(23),
    [anon_sym_RTTY] = ACTIONS(23),
    [anon_sym_VARAC] = ACTIONS(23),
    [anon_sym_MFSK] = ACTIONS(23),
    [anon_sym_DATA] = ACTIONS(23),
    [anon_sym_JS8] = ACTIONS(23),
    [anon_sym_cw] = ACTIONS(23),
    [anon_sym_ssb] = ACTIONS(23),
    [anon_sym_fm] = ACTIONS(23),
    [anon_sym_am] = ACTIONS(23),
    [anon_sym_digi] = ACTIONS(23),
    [anon_sym_ft8] = ACTIONS(23),
    [anon_sym_ft4] = ACTIONS(23),
    [anon_sym_psk] = ACTIONS(23),
    [anon_sym_rtty] = ACTIONS(23),
    [anon_sym_varac] = ACTIONS(23),
    [anon_sym_mfsk] = ACTIONS(23),
    [anon_sym_data] = ACTIONS(23),
    [anon_sym_js8] = ACTIONS(23),
    [sym_time] = ACTIONS(23),
    [sym_callsign] = ACTIONS(23),
    [anon_sym_POUND] = ACTIONS(31),
    [anon_sym_AT] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_LT] = ACTIONS(37),
  },
  [10] = {
    [sym_rst] = STATE(10),
    [sym_serial_sent] = STATE(10),
    [sym_serial_rcvd] = STATE(10),
    [aux_sym_qso_line_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(67),
    [sym_comment] = ACTIONS(69),
    [aux_sym_header_token1] = ACTIONS(69),
    [aux_sym_header_token2] = ACTIONS(69),
    [aux_sym_header_token3] = ACTIONS(69),
    [aux_sym_header_token4] = ACTIONS(69),
    [aux_sym_header_token5] = ACTIONS(69),
    [aux_sym_header_token6] = ACTIONS(69),
    [aux_sym_header_token7] = ACTIONS(69),
    [aux_sym_header_token8] = ACTIONS(69),
    [aux_sym_date_command_token1] = ACTIONS(69),
    [aux_sym_day_command_token1] = ACTIONS(69),
    [aux_sym_band_token1] = ACTIONS(69),
    [aux_sym_band_token2] = ACTIONS(69),
    [anon_sym_CW] = ACTIONS(69),
    [anon_sym_SSB] = ACTIONS(69),
    [anon_sym_FM] = ACTIONS(69),
    [anon_sym_AM] = ACTIONS(69),
    [anon_sym_DIGI] = ACTIONS(69),
    [anon_sym_FT8] = ACTIONS(69),
    [anon_sym_FT4] = ACTIONS(69),
    [anon_sym_PSK] = ACTIONS(69),
    [anon_sym_RTTY] = ACTIONS(69),
    [anon_sym_VARAC] = ACTIONS(69),
    [anon_sym_MFSK] = ACTIONS(69),
    [anon_sym_DATA] = ACTIONS(69),
    [anon_sym_JS8] = ACTIONS(69),
    [anon_sym_cw] = ACTIONS(69),
    [anon_sym_ssb] = ACTIONS(69),
    [anon_sym_fm] = ACTIONS(69),
    [anon_sym_am] = ACTIONS(69),
    [anon_sym_digi] = ACTIONS(69),
    [anon_sym_ft8] = ACTIONS(69),
    [anon_sym_ft4] = ACTIONS(69),
    [anon_sym_psk] = ACTIONS(69),
    [anon_sym_rtty] = ACTIONS(69),
    [anon_sym_varac] = ACTIONS(69),
    [anon_sym_mfsk] = ACTIONS(69),
    [anon_sym_data] = ACTIONS(69),
    [anon_sym_js8] = ACTIONS(69),
    [sym_time] = ACTIONS(69),
    [sym_callsign] = ACTIONS(69),
    [aux_sym_rst_token1] = ACTIONS(71),
    [anon_sym_COMMA] = ACTIONS(74),
    [anon_sym_DOT] = ACTIONS(77),
    [anon_sym_POUND] = ACTIONS(69),
    [anon_sym_AT] = ACTIONS(67),
    [anon_sym_LBRACK] = ACTIONS(67),
    [anon_sym_LT] = ACTIONS(67),
  },
  [11] = {
    [sym_header] = STATE(12),
    [sym_date_command] = STATE(12),
    [sym_day_command] = STATE(12),
    [sym_band_mode_line] = STATE(12),
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [sym_qso_line] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(80),
    [sym_comment] = ACTIONS(82),
    [aux_sym_header_token1] = ACTIONS(7),
    [aux_sym_header_token2] = ACTIONS(7),
    [aux_sym_header_token3] = ACTIONS(7),
    [aux_sym_header_token4] = ACTIONS(7),
    [aux_sym_header_token5] = ACTIONS(7),
    [aux_sym_header_token6] = ACTIONS(7),
    [aux_sym_header_token7] = ACTIONS(7),
    [aux_sym_header_token8] = ACTIONS(7),
    [aux_sym_date_command_token1] = ACTIONS(9),
    [aux_sym_day_command_token1] = ACTIONS(11),
    [aux_sym_band_token1] = ACTIONS(13),
    [aux_sym_band_token2] = ACTIONS(13),
    [anon_sym_CW] = ACTIONS(15),
    [anon_sym_SSB] = ACTIONS(15),
    [anon_sym_FM] = ACTIONS(15),
    [anon_sym_AM] = ACTIONS(15),
    [anon_sym_DIGI] = ACTIONS(15),
    [anon_sym_FT8] = ACTIONS(15),
    [anon_sym_FT4] = ACTIONS(15),
    [anon_sym_PSK] = ACTIONS(15),
    [anon_sym_RTTY] = ACTIONS(15),
    [anon_sym_VARAC] = ACTIONS(15),
    [anon_sym_MFSK] = ACTIONS(15),
    [anon_sym_DATA] = ACTIONS(15),
    [anon_sym_JS8] = ACTIONS(15),
    [anon_sym_cw] = ACTIONS(15),
    [anon_sym_ssb] = ACTIONS(15),
    [anon_sym_fm] = ACTIONS(15),
    [anon_sym_am] = ACTIONS(15),
    [anon_sym_digi] = ACTIONS(15),
    [anon_sym_ft8] = ACTIONS(15),
    [anon_sym_ft4] = ACTIONS(15),
    [anon_sym_psk] = ACTIONS(15),
    [anon_sym_rtty] = ACTIONS(15),
    [anon_sym_varac] = ACTIONS(15),
    [anon_sym_mfsk] = ACTIONS(15),
    [anon_sym_data] = ACTIONS(15),
    [anon_sym_js8] = ACTIONS(15),
    [sym_time] = ACTIONS(17),
    [sym_callsign] = ACTIONS(19),
  },
  [12] = {
    [sym_header] = STATE(12),
    [sym_date_command] = STATE(12),
    [sym_day_command] = STATE(12),
    [sym_band_mode_line] = STATE(12),
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [sym_qso_line] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(84),
    [sym_comment] = ACTIONS(86),
    [aux_sym_header_token1] = ACTIONS(89),
    [aux_sym_header_token2] = ACTIONS(89),
    [aux_sym_header_token3] = ACTIONS(89),
    [aux_sym_header_token4] = ACTIONS(89),
    [aux_sym_header_token5] = ACTIONS(89),
    [aux_sym_header_token6] = ACTIONS(89),
    [aux_sym_header_token7] = ACTIONS(89),
    [aux_sym_header_token8] = ACTIONS(89),
    [aux_sym_date_command_token1] = ACTIONS(92),
    [aux_sym_day_command_token1] = ACTIONS(95),
    [aux_sym_band_token1] = ACTIONS(98),
    [aux_sym_band_token2] = ACTIONS(98),
    [anon_sym_CW] = ACTIONS(101),
    [anon_sym_SSB] = ACTIONS(101),
    [anon_sym_FM] = ACTIONS(101),
    [anon_sym_AM] = ACTIONS(101),
    [anon_sym_DIGI] = ACTIONS(101),
    [anon_sym_FT8] = ACTIONS(101),
    [anon_sym_FT4] = ACTIONS(101),
    [anon_sym_PSK] = ACTIONS(101),
    [anon_sym_RTTY] = ACTIONS(101),
    [anon_sym_VARAC] = ACTIONS(101),
    [anon_sym_MFSK] = ACTIONS(101),
    [anon_sym_DATA] = ACTIONS(101),
    [anon_sym_JS8] = ACTIONS(101),
    [anon_sym_cw] = ACTIONS(101),
    [anon_sym_ssb] = ACTIONS(101),
    [anon_sym_fm] = ACTIONS(101),
    [anon_sym_am] = ACTIONS(101),
    [anon_sym_digi] = ACTIONS(101),
    [anon_sym_ft8] = ACTIONS(101),
    [anon_sym_ft4] = ACTIONS(101),
    [anon_sym_psk] = ACTIONS(101),
    [anon_sym_rtty] = ACTIONS(101),
    [anon_sym_varac] = ACTIONS(101),
    [anon_sym_mfsk] = ACTIONS(101),
    [anon_sym_data] = ACTIONS(101),
    [anon_sym_js8] = ACTIONS(101),
    [sym_time] = ACTIONS(104),
    [sym_callsign] = ACTIONS(107),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(110),
    [sym_comment] = ACTIONS(112),
    [aux_sym_header_token1] = ACTIONS(112),
    [aux_sym_header_token2] = ACTIONS(112),
    [aux_sym_header_token3] = ACTIONS(112),
    [aux_sym_header_token4] = ACTIONS(112),
    [aux_sym_header_token5] = ACTIONS(112),
    [aux_sym_header_token6] = ACTIONS(112),
    [aux_sym_header_token7] = ACTIONS(112),
    [aux_sym_header_token8] = ACTIONS(112),
    [aux_sym_date_command_token1] = ACTIONS(112),
    [aux_sym_day_command_token1] = ACTIONS(112),
    [aux_sym_band_token1] = ACTIONS(112),
    [aux_sym_band_token2] = ACTIONS(112),
    [anon_sym_CW] = ACTIONS(112),
    [anon_sym_SSB] = ACTIONS(112),
    [anon_sym_FM] = ACTIONS(112),
    [anon_sym_AM] = ACTIONS(112),
    [anon_sym_DIGI] = ACTIONS(112),
    [anon_sym_FT8] = ACTIONS(112),
    [anon_sym_FT4] = ACTIONS(112),
    [anon_sym_PSK] = ACTIONS(112),
    [anon_sym_RTTY] = ACTIONS(112),
    [anon_sym_VARAC] = ACTIONS(112),
    [anon_sym_MFSK] = ACTIONS(112),
    [anon_sym_DATA] = ACTIONS(112),
    [anon_sym_JS8] = ACTIONS(112),
    [anon_sym_cw] = ACTIONS(112),
    [anon_sym_ssb] = ACTIONS(112),
    [anon_sym_fm] = ACTIONS(112),
    [anon_sym_am] = ACTIONS(112),
    [anon_sym_digi] = ACTIONS(112),
    [anon_sym_ft8] = ACTIONS(112),
    [anon_sym_ft4] = ACTIONS(112),
    [anon_sym_psk] = ACTIONS(112),
    [anon_sym_rtty] = ACTIONS(112),
    [anon_sym_varac] = ACTIONS(112),
    [anon_sym_mfsk] = ACTIONS(112),
    [anon_sym_data] = ACTIONS(112),
    [anon_sym_js8] = ACTIONS(112),
    [sym_time] = ACTIONS(112),
    [sym_callsign] = ACTIONS(112),
    [aux_sym_rst_token1] = ACTIONS(112),
    [anon_sym_COMMA] = ACTIONS(110),
    [anon_sym_DOT] = ACTIONS(110),
    [anon_sym_POUND] = ACTIONS(112),
    [anon_sym_AT] = ACTIONS(110),
    [anon_sym_LBRACK] = ACTIONS(110),
    [anon_sym_LT] = ACTIONS(110),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(114),
    [sym_comment] = ACTIONS(116),
    [aux_sym_header_token1] = ACTIONS(116),
    [aux_sym_header_token2] = ACTIONS(116),
    [aux_sym_header_token3] = ACTIONS(116),
    [aux_sym_header_token4] = ACTIONS(116),
    [aux_sym_header_token5] = ACTIONS(116),
    [aux_sym_header_token6] = ACTIONS(116),
    [aux_sym_header_token7] = ACTIONS(116),
    [aux_sym_header_token8] = ACTIONS(116),
    [aux_sym_date_command_token1] = ACTIONS(116),
    [aux_sym_day_command_token1] = ACTIONS(116),
    [aux_sym_band_token1] = ACTIONS(116),
    [aux_sym_band_token2] = ACTIONS(116),
    [anon_sym_CW] = ACTIONS(116),
    [anon_sym_SSB] = ACTIONS(116),
    [anon_sym_FM] = ACTIONS(116),
    [anon_sym_AM] = ACTIONS(116),
    [anon_sym_DIGI] = ACTIONS(116),
    [anon_sym_FT8] = ACTIONS(116),
    [anon_sym_FT4] = ACTIONS(116),
    [anon_sym_PSK] = ACTIONS(116),
    [anon_sym_RTTY] = ACTIONS(116),
    [anon_sym_VARAC] = ACTIONS(116),
    [anon_sym_MFSK] = ACTIONS(116),
    [anon_sym_DATA] = ACTIONS(116),
    [anon_sym_JS8] = ACTIONS(116),
    [anon_sym_cw] = ACTIONS(116),
    [anon_sym_ssb] = ACTIONS(116),
    [anon_sym_fm] = ACTIONS(116),
    [anon_sym_am] = ACTIONS(116),
    [anon_sym_digi] = ACTIONS(116),
    [anon_sym_ft8] = ACTIONS(116),
    [anon_sym_ft4] = ACTIONS(116),
    [anon_sym_psk] = ACTIONS(116),
    [anon_sym_rtty] = ACTIONS(116),
    [anon_sym_varac] = ACTIONS(116),
    [anon_sym_mfsk] = ACTIONS(116),
    [anon_sym_data] = ACTIONS(116),
    [anon_sym_js8] = ACTIONS(116),
    [sym_time] = ACTIONS(116),
    [sym_callsign] = ACTIONS(116),
    [aux_sym_rst_token1] = ACTIONS(116),
    [anon_sym_COMMA] = ACTIONS(114),
    [anon_sym_DOT] = ACTIONS(114),
    [anon_sym_POUND] = ACTIONS(116),
    [anon_sym_AT] = ACTIONS(114),
    [anon_sym_LBRACK] = ACTIONS(114),
    [anon_sym_LT] = ACTIONS(114),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(118),
    [sym_comment] = ACTIONS(120),
    [aux_sym_header_token1] = ACTIONS(120),
    [aux_sym_header_token2] = ACTIONS(120),
    [aux_sym_header_token3] = ACTIONS(120),
    [aux_sym_header_token4] = ACTIONS(120),
    [aux_sym_header_token5] = ACTIONS(120),
    [aux_sym_header_token6] = ACTIONS(120),
    [aux_sym_header_token7] = ACTIONS(120),
    [aux_sym_header_token8] = ACTIONS(120),
    [aux_sym_date_command_token1] = ACTIONS(120),
    [aux_sym_day_command_token1] = ACTIONS(120),
    [aux_sym_band_token1] = ACTIONS(120),
    [aux_sym_band_token2] = ACTIONS(120),
    [anon_sym_CW] = ACTIONS(120),
    [anon_sym_SSB] = ACTIONS(120),
    [anon_sym_FM] = ACTIONS(120),
    [anon_sym_AM] = ACTIONS(120),
    [anon_sym_DIGI] = ACTIONS(120),
    [anon_sym_FT8] = ACTIONS(120),
    [anon_sym_FT4] = ACTIONS(120),
    [anon_sym_PSK] = ACTIONS(120),
    [anon_sym_RTTY] = ACTIONS(120),
    [anon_sym_VARAC] = ACTIONS(120),
    [anon_sym_MFSK] = ACTIONS(120),
    [anon_sym_DATA] = ACTIONS(120),
    [anon_sym_JS8] = ACTIONS(120),
    [anon_sym_cw] = ACTIONS(120),
    [anon_sym_ssb] = ACTIONS(120),
    [anon_sym_fm] = ACTIONS(120),
    [anon_sym_am] = ACTIONS(120),
    [anon_sym_digi] = ACTIONS(120),
    [anon_sym_ft8] = ACTIONS(120),
    [anon_sym_ft4] = ACTIONS(120),
    [anon_sym_psk] = ACTIONS(120),
    [anon_sym_rtty] = ACTIONS(120),
    [anon_sym_varac] = ACTIONS(120),
    [anon_sym_mfsk] = ACTIONS(120),
    [anon_sym_data] = ACTIONS(120),
    [anon_sym_js8] = ACTIONS(120),
    [sym_time] = ACTIONS(120),
    [sym_callsign] = ACTIONS(120),
    [aux_sym_rst_token1] = ACTIONS(120),
    [anon_sym_COMMA] = ACTIONS(118),
    [anon_sym_DOT] = ACTIONS(118),
    [anon_sym_POUND] = ACTIONS(120),
    [anon_sym_AT] = ACTIONS(118),
    [anon_sym_LBRACK] = ACTIONS(118),
    [anon_sym_LT] = ACTIONS(118),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(122),
    [sym_comment] = ACTIONS(124),
    [aux_sym_header_token1] = ACTIONS(124),
    [aux_sym_header_token2] = ACTIONS(124),
    [aux_sym_header_token3] = ACTIONS(124),
    [aux_sym_header_token4] = ACTIONS(124),
    [aux_sym_header_token5] = ACTIONS(124),
    [aux_sym_header_token6] = ACTIONS(124),
    [aux_sym_header_token7] = ACTIONS(124),
    [aux_sym_header_token8] = ACTIONS(124),
    [aux_sym_date_command_token1] = ACTIONS(124),
    [aux_sym_day_command_token1] = ACTIONS(124),
    [aux_sym_band_token1] = ACTIONS(124),
    [aux_sym_band_token2] = ACTIONS(124),
    [anon_sym_CW] = ACTIONS(124),
    [anon_sym_SSB] = ACTIONS(124),
    [anon_sym_FM] = ACTIONS(124),
    [anon_sym_AM] = ACTIONS(124),
    [anon_sym_DIGI] = ACTIONS(124),
    [anon_sym_FT8] = ACTIONS(124),
    [anon_sym_FT4] = ACTIONS(124),
    [anon_sym_PSK] = ACTIONS(124),
    [anon_sym_RTTY] = ACTIONS(124),
    [anon_sym_VARAC] = ACTIONS(124),
    [anon_sym_MFSK] = ACTIONS(124),
    [anon_sym_DATA] = ACTIONS(124),
    [anon_sym_JS8] = ACTIONS(124),
    [anon_sym_cw] = ACTIONS(124),
    [anon_sym_ssb] = ACTIONS(124),
    [anon_sym_fm] = ACTIONS(124),
    [anon_sym_am] = ACTIONS(124),
    [anon_sym_digi] = ACTIONS(124),
    [anon_sym_ft8] = ACTIONS(124),
    [anon_sym_ft4] = ACTIONS(124),
    [anon_sym_psk] = ACTIONS(124),
    [anon_sym_rtty] = ACTIONS(124),
    [anon_sym_varac] = ACTIONS(124),
    [anon_sym_mfsk] = ACTIONS(124),
    [anon_sym_data] = ACTIONS(124),
    [anon_sym_js8] = ACTIONS(124),
    [sym_time] = ACTIONS(124),
    [sym_callsign] = ACTIONS(124),
    [anon_sym_POUND] = ACTIONS(124),
    [anon_sym_AT] = ACTIONS(122),
    [anon_sym_LBRACK] = ACTIONS(122),
    [anon_sym_LT] = ACTIONS(122),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(126),
    [sym_comment] = ACTIONS(128),
    [aux_sym_header_token1] = ACTIONS(128),
    [aux_sym_header_token2] = ACTIONS(128),
    [aux_sym_header_token3] = ACTIONS(128),
    [aux_sym_header_token4] = ACTIONS(128),
    [aux_sym_header_token5] = ACTIONS(128),
    [aux_sym_header_token6] = ACTIONS(128),
    [aux_sym_header_token7] = ACTIONS(128),
    [aux_sym_header_token8] = ACTIONS(128),
    [aux_sym_date_command_token1] = ACTIONS(128),
    [aux_sym_day_command_token1] = ACTIONS(128),
    [aux_sym_band_token1] = ACTIONS(128),
    [aux_sym_band_token2] = ACTIONS(128),
    [anon_sym_CW] = ACTIONS(128),
    [anon_sym_SSB] = ACTIONS(128),
    [anon_sym_FM] = ACTIONS(128),
    [anon_sym_AM] = ACTIONS(128),
    [anon_sym_DIGI] = ACTIONS(128),
    [anon_sym_FT8] = ACTIONS(128),
    [anon_sym_FT4] = ACTIONS(128),
    [anon_sym_PSK] = ACTIONS(128),
    [anon_sym_RTTY] = ACTIONS(128),
    [anon_sym_VARAC] = ACTIONS(128),
    [anon_sym_MFSK] = ACTIONS(128),
    [anon_sym_DATA] = ACTIONS(128),
    [anon_sym_JS8] = ACTIONS(128),
    [anon_sym_cw] = ACTIONS(128),
    [anon_sym_ssb] = ACTIONS(128),
    [anon_sym_fm] = ACTIONS(128),
    [anon_sym_am] = ACTIONS(128),
    [anon_sym_digi] = ACTIONS(128),
    [anon_sym_ft8] = ACTIONS(128),
    [anon_sym_ft4] = ACTIONS(128),
    [anon_sym_psk] = ACTIONS(128),
    [anon_sym_rtty] = ACTIONS(128),
    [anon_sym_varac] = ACTIONS(128),
    [anon_sym_mfsk] = ACTIONS(128),
    [anon_sym_data] = ACTIONS(128),
    [anon_sym_js8] = ACTIONS(128),
    [sym_time] = ACTIONS(128),
    [sym_callsign] = ACTIONS(128),
    [anon_sym_POUND] = ACTIONS(128),
    [anon_sym_AT] = ACTIONS(126),
    [anon_sym_LBRACK] = ACTIONS(126),
    [anon_sym_LT] = ACTIONS(126),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(130),
    [sym_comment] = ACTIONS(132),
    [aux_sym_header_token1] = ACTIONS(132),
    [aux_sym_header_token2] = ACTIONS(132),
    [aux_sym_header_token3] = ACTIONS(132),
    [aux_sym_header_token4] = ACTIONS(132),
    [aux_sym_header_token5] = ACTIONS(132),
    [aux_sym_header_token6] = ACTIONS(132),
    [aux_sym_header_token7] = ACTIONS(132),
    [aux_sym_header_token8] = ACTIONS(132),
    [aux_sym_date_command_token1] = ACTIONS(132),
    [aux_sym_day_command_token1] = ACTIONS(132),
    [aux_sym_band_token1] = ACTIONS(132),
    [aux_sym_band_token2] = ACTIONS(132),
    [anon_sym_CW] = ACTIONS(132),
    [anon_sym_SSB] = ACTIONS(132),
    [anon_sym_FM] = ACTIONS(132),
    [anon_sym_AM] = ACTIONS(132),
    [anon_sym_DIGI] = ACTIONS(132),
    [anon_sym_FT8] = ACTIONS(132),
    [anon_sym_FT4] = ACTIONS(132),
    [anon_sym_PSK] = ACTIONS(132),
    [anon_sym_RTTY] = ACTIONS(132),
    [anon_sym_VARAC] = ACTIONS(132),
    [anon_sym_MFSK] = ACTIONS(132),
    [anon_sym_DATA] = ACTIONS(132),
    [anon_sym_JS8] = ACTIONS(132),
    [anon_sym_cw] = ACTIONS(132),
    [anon_sym_ssb] = ACTIONS(132),
    [anon_sym_fm] = ACTIONS(132),
    [anon_sym_am] = ACTIONS(132),
    [anon_sym_digi] = ACTIONS(132),
    [anon_sym_ft8] = ACTIONS(132),
    [anon_sym_ft4] = ACTIONS(132),
    [anon_sym_psk] = ACTIONS(132),
    [anon_sym_rtty] = ACTIONS(132),
    [anon_sym_varac] = ACTIONS(132),
    [anon_sym_mfsk] = ACTIONS(132),
    [anon_sym_data] = ACTIONS(132),
    [anon_sym_js8] = ACTIONS(132),
    [sym_time] = ACTIONS(132),
    [sym_callsign] = ACTIONS(132),
    [anon_sym_POUND] = ACTIONS(132),
    [anon_sym_AT] = ACTIONS(130),
    [anon_sym_LBRACK] = ACTIONS(130),
    [anon_sym_LT] = ACTIONS(130),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(134),
    [sym_comment] = ACTIONS(136),
    [aux_sym_header_token1] = ACTIONS(136),
    [aux_sym_header_token2] = ACTIONS(136),
    [aux_sym_header_token3] = ACTIONS(136),
    [aux_sym_header_token4] = ACTIONS(136),
    [aux_sym_header_token5] = ACTIONS(136),
    [aux_sym_header_token6] = ACTIONS(136),
    [aux_sym_header_token7] = ACTIONS(136),
    [aux_sym_header_token8] = ACTIONS(136),
    [aux_sym_date_command_token1] = ACTIONS(136),
    [aux_sym_day_command_token1] = ACTIONS(136),
    [aux_sym_band_token1] = ACTIONS(136),
    [aux_sym_band_token2] = ACTIONS(136),
    [anon_sym_CW] = ACTIONS(136),
    [anon_sym_SSB] = ACTIONS(136),
    [anon_sym_FM] = ACTIONS(136),
    [anon_sym_AM] = ACTIONS(136),
    [anon_sym_DIGI] = ACTIONS(136),
    [anon_sym_FT8] = ACTIONS(136),
    [anon_sym_FT4] = ACTIONS(136),
    [anon_sym_PSK] = ACTIONS(136),
    [anon_sym_RTTY] = ACTIONS(136),
    [anon_sym_VARAC] = ACTIONS(136),
    [anon_sym_MFSK] = ACTIONS(136),
    [anon_sym_DATA] = ACTIONS(136),
    [anon_sym_JS8] = ACTIONS(136),
    [anon_sym_cw] = ACTIONS(136),
    [anon_sym_ssb] = ACTIONS(136),
    [anon_sym_fm] = ACTIONS(136),
    [anon_sym_am] = ACTIONS(136),
    [anon_sym_digi] = ACTIONS(136),
    [anon_sym_ft8] = ACTIONS(136),
    [anon_sym_ft4] = ACTIONS(136),
    [anon_sym_psk] = ACTIONS(136),
    [anon_sym_rtty] = ACTIONS(136),
    [anon_sym_varac] = ACTIONS(136),
    [anon_sym_mfsk] = ACTIONS(136),
    [anon_sym_data] = ACTIONS(136),
    [anon_sym_js8] = ACTIONS(136),
    [sym_time] = ACTIONS(136),
    [sym_callsign] = ACTIONS(136),
    [anon_sym_POUND] = ACTIONS(136),
    [anon_sym_AT] = ACTIONS(134),
    [anon_sym_LBRACK] = ACTIONS(134),
    [anon_sym_LT] = ACTIONS(134),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(138),
    [sym_comment] = ACTIONS(140),
    [aux_sym_header_token1] = ACTIONS(140),
    [aux_sym_header_token2] = ACTIONS(140),
    [aux_sym_header_token3] = ACTIONS(140),
    [aux_sym_header_token4] = ACTIONS(140),
    [aux_sym_header_token5] = ACTIONS(140),
    [aux_sym_header_token6] = ACTIONS(140),
    [aux_sym_header_token7] = ACTIONS(140),
    [aux_sym_header_token8] = ACTIONS(140),
    [aux_sym_date_command_token1] = ACTIONS(140),
    [aux_sym_day_command_token1] = ACTIONS(140),
    [aux_sym_band_token1] = ACTIONS(140),
    [aux_sym_band_token2] = ACTIONS(140),
    [anon_sym_CW] = ACTIONS(140),
    [anon_sym_SSB] = ACTIONS(140),
    [anon_sym_FM] = ACTIONS(140),
    [anon_sym_AM] = ACTIONS(140),
    [anon_sym_DIGI] = ACTIONS(140),
    [anon_sym_FT8] = ACTIONS(140),
    [anon_sym_FT4] = ACTIONS(140),
    [anon_sym_PSK] = ACTIONS(140),
    [anon_sym_RTTY] = ACTIONS(140),
    [anon_sym_VARAC] = ACTIONS(140),
    [anon_sym_MFSK] = ACTIONS(140),
    [anon_sym_DATA] = ACTIONS(140),
    [anon_sym_JS8] = ACTIONS(140),
    [anon_sym_cw] = ACTIONS(140),
    [anon_sym_ssb] = ACTIONS(140),
    [anon_sym_fm] = ACTIONS(140),
    [anon_sym_am] = ACTIONS(140),
    [anon_sym_digi] = ACTIONS(140),
    [anon_sym_ft8] = ACTIONS(140),
    [anon_sym_ft4] = ACTIONS(140),
    [anon_sym_psk] = ACTIONS(140),
    [anon_sym_rtty] = ACTIONS(140),
    [anon_sym_varac] = ACTIONS(140),
    [anon_sym_mfsk] = ACTIONS(140),
    [anon_sym_data] = ACTIONS(140),
    [anon_sym_js8] = ACTIONS(140),
    [sym_time] = ACTIONS(140),
    [sym_callsign] = ACTIONS(140),
    [anon_sym_POUND] = ACTIONS(140),
    [anon_sym_AT] = ACTIONS(138),
    [anon_sym_LBRACK] = ACTIONS(138),
    [anon_sym_LT] = ACTIONS(138),
  },
  [21] = {
    [ts_builtin_sym_end] = ACTIONS(142),
    [sym_comment] = ACTIONS(144),
    [aux_sym_header_token1] = ACTIONS(144),
    [aux_sym_header_token2] = ACTIONS(144),
    [aux_sym_header_token3] = ACTIONS(144),
    [aux_sym_header_token4] = ACTIONS(144),
    [aux_sym_header_token5] = ACTIONS(144),
    [aux_sym_header_token6] = ACTIONS(144),
    [aux_sym_header_token7] = ACTIONS(144),
    [aux_sym_header_token8] = ACTIONS(144),
    [aux_sym_date_command_token1] = ACTIONS(144),
    [aux_sym_day_command_token1] = ACTIONS(144),
    [aux_sym_band_token1] = ACTIONS(144),
    [aux_sym_band_token2] = ACTIONS(144),
    [anon_sym_CW] = ACTIONS(144),
    [anon_sym_SSB] = ACTIONS(144),
    [anon_sym_FM] = ACTIONS(144),
    [anon_sym_AM] = ACTIONS(144),
    [anon_sym_DIGI] = ACTIONS(144),
    [anon_sym_FT8] = ACTIONS(144),
    [anon_sym_FT4] = ACTIONS(144),
    [anon_sym_PSK] = ACTIONS(144),
    [anon_sym_RTTY] = ACTIONS(144),
    [anon_sym_VARAC] = ACTIONS(144),
    [anon_sym_MFSK] = ACTIONS(144),
    [anon_sym_DATA] = ACTIONS(144),
    [anon_sym_JS8] = ACTIONS(144),
    [anon_sym_cw] = ACTIONS(144),
    [anon_sym_ssb] = ACTIONS(144),
    [anon_sym_fm] = ACTIONS(144),
    [anon_sym_am] = ACTIONS(144),
    [anon_sym_digi] = ACTIONS(144),
    [anon_sym_ft8] = ACTIONS(144),
    [anon_sym_ft4] = ACTIONS(144),
    [anon_sym_psk] = ACTIONS(144),
    [anon_sym_rtty] = ACTIONS(144),
    [anon_sym_varac] = ACTIONS(144),
    [anon_sym_mfsk] = ACTIONS(144),
    [anon_sym_data] = ACTIONS(144),
    [anon_sym_js8] = ACTIONS(144),
    [sym_time] = ACTIONS(144),
    [sym_callsign] = ACTIONS(144),
    [anon_sym_POUND] = ACTIONS(144),
    [anon_sym_AT] = ACTIONS(142),
    [anon_sym_LBRACK] = ACTIONS(142),
    [anon_sym_LT] = ACTIONS(142),
  },
  [22] = {
    [sym_band] = STATE(24),
    [sym_mode] = STATE(24),
    [aux_sym_band_mode_line_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(146),
    [sym_comment] = ACTIONS(146),
    [aux_sym_header_token1] = ACTIONS(148),
    [aux_sym_header_token2] = ACTIONS(148),
    [aux_sym_header_token3] = ACTIONS(148),
    [aux_sym_header_token4] = ACTIONS(148),
    [aux_sym_header_token5] = ACTIONS(148),
    [aux_sym_header_token6] = ACTIONS(148),
    [aux_sym_header_token7] = ACTIONS(148),
    [aux_sym_header_token8] = ACTIONS(148),
    [aux_sym_date_command_token1] = ACTIONS(148),
    [aux_sym_day_command_token1] = ACTIONS(148),
    [aux_sym_band_token1] = ACTIONS(150),
    [aux_sym_band_token2] = ACTIONS(150),
    [anon_sym_CW] = ACTIONS(153),
    [anon_sym_SSB] = ACTIONS(153),
    [anon_sym_FM] = ACTIONS(153),
    [anon_sym_AM] = ACTIONS(153),
    [anon_sym_DIGI] = ACTIONS(153),
    [anon_sym_FT8] = ACTIONS(153),
    [anon_sym_FT4] = ACTIONS(153),
    [anon_sym_PSK] = ACTIONS(153),
    [anon_sym_RTTY] = ACTIONS(153),
    [anon_sym_VARAC] = ACTIONS(153),
    [anon_sym_MFSK] = ACTIONS(153),
    [anon_sym_DATA] = ACTIONS(153),
    [anon_sym_JS8] = ACTIONS(153),
    [anon_sym_cw] = ACTIONS(153),
    [anon_sym_ssb] = ACTIONS(153),
    [anon_sym_fm] = ACTIONS(153),
    [anon_sym_am] = ACTIONS(153),
    [anon_sym_digi] = ACTIONS(153),
    [anon_sym_ft8] = ACTIONS(153),
    [anon_sym_ft4] = ACTIONS(153),
    [anon_sym_psk] = ACTIONS(153),
    [anon_sym_rtty] = ACTIONS(153),
    [anon_sym_varac] = ACTIONS(153),
    [anon_sym_mfsk] = ACTIONS(153),
    [anon_sym_data] = ACTIONS(153),
    [anon_sym_js8] = ACTIONS(153),
    [sym_time] = ACTIONS(148),
    [sym_callsign] = ACTIONS(148),
  },
  [23] = {
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
    [aux_sym_band_mode_line_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(156),
    [sym_comment] = ACTIONS(156),
    [aux_sym_header_token1] = ACTIONS(158),
    [aux_sym_header_token2] = ACTIONS(158),
    [aux_sym_header_token3] = ACTIONS(158),
    [aux_sym_header_token4] = ACTIONS(158),
    [aux_sym_header_token5] = ACTIONS(158),
    [aux_sym_header_token6] = ACTIONS(158),
    [aux_sym_header_token7] = ACTIONS(158),
    [aux_sym_header_token8] = ACTIONS(158),
    [aux_sym_date_command_token1] = ACTIONS(158),
    [aux_sym_day_command_token1] = ACTIONS(158),
    [aux_sym_band_token1] = ACTIONS(160),
    [aux_sym_band_token2] = ACTIONS(160),
    [anon_sym_CW] = ACTIONS(163),
    [anon_sym_SSB] = ACTIONS(163),
    [anon_sym_FM] = ACTIONS(163),
    [anon_sym_AM] = ACTIONS(163),
    [anon_sym_DIGI] = ACTIONS(163),
    [anon_sym_FT8] = ACTIONS(163),
    [anon_sym_FT4] = ACTIONS(163),
    [anon_sym_PSK] = ACTIONS(163),
    [anon_sym_RTTY] = ACTIONS(163),
    [anon_sym_VARAC] = ACTIONS(163),
    [anon_sym_MFSK] = ACTIONS(163),
    [anon_sym_DATA] = ACTIONS(163),
    [anon_sym_JS8] = ACTIONS(163),
    [anon_sym_cw] = ACTIONS(163),
    [anon_sym_ssb] = ACTIONS(163),
    [anon_sym_fm] = ACTIONS(163),
    [anon_sym_am] = ACTIONS(163),
    [anon_sym_digi] = ACTIONS(163),
    [anon_sym_ft8] = ACTIONS(163),
    [anon_sym_ft4] = ACTIONS(163),
    [anon_sym_psk] = ACTIONS(163),
    [anon_sym_rtty] = ACTIONS(163),
    [anon_sym_varac] = ACTIONS(163),
    [anon_sym_mfsk] = ACTIONS(163),
    [anon_sym_data] = ACTIONS(163),
    [anon_sym_js8] = ACTIONS(163),
    [sym_time] = ACTIONS(158),
    [sym_callsign] = ACTIONS(158),
  },
  [24] = {
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
    [aux_sym_band_mode_line_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(166),
    [sym_comment] = ACTIONS(166),
    [aux_sym_header_token1] = ACTIONS(168),
    [aux_sym_header_token2] = ACTIONS(168),
    [aux_sym_header_token3] = ACTIONS(168),
    [aux_sym_header_token4] = ACTIONS(168),
    [aux_sym_header_token5] = ACTIONS(168),
    [aux_sym_header_token6] = ACTIONS(168),
    [aux_sym_header_token7] = ACTIONS(168),
    [aux_sym_header_token8] = ACTIONS(168),
    [aux_sym_date_command_token1] = ACTIONS(168),
    [aux_sym_day_command_token1] = ACTIONS(168),
    [aux_sym_band_token1] = ACTIONS(170),
    [aux_sym_band_token2] = ACTIONS(170),
    [anon_sym_CW] = ACTIONS(173),
    [anon_sym_SSB] = ACTIONS(173),
    [anon_sym_FM] = ACTIONS(173),
    [anon_sym_AM] = ACTIONS(173),
    [anon_sym_DIGI] = ACTIONS(173),
    [anon_sym_FT8] = ACTIONS(173),
    [anon_sym_FT4] = ACTIONS(173),
    [anon_sym_PSK] = ACTIONS(173),
    [anon_sym_RTTY] = ACTIONS(173),
    [anon_sym_VARAC] = ACTIONS(173),
    [anon_sym_MFSK] = ACTIONS(173),
    [anon_sym_DATA] = ACTIONS(173),
    [anon_sym_JS8] = ACTIONS(173),
    [anon_sym_cw] = ACTIONS(173),
    [anon_sym_ssb] = ACTIONS(173),
    [anon_sym_fm] = ACTIONS(173),
    [anon_sym_am] = ACTIONS(173),
    [anon_sym_digi] = ACTIONS(173),
    [anon_sym_ft8] = ACTIONS(173),
    [anon_sym_ft4] = ACTIONS(173),
    [anon_sym_psk] = ACTIONS(173),
    [anon_sym_rtty] = ACTIONS(173),
    [anon_sym_varac] = ACTIONS(173),
    [anon_sym_mfsk] = ACTIONS(173),
    [anon_sym_data] = ACTIONS(173),
    [anon_sym_js8] = ACTIONS(173),
    [sym_time] = ACTIONS(168),
    [sym_callsign] = ACTIONS(168),
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(176),
    [sym_comment] = ACTIONS(178),
    [aux_sym_header_token1] = ACTIONS(178),
    [aux_sym_header_token2] = ACTIONS(178),
    [aux_sym_header_token3] = ACTIONS(178),
    [aux_sym_header_token4] = ACTIONS(178),
    [aux_sym_header_token5] = ACTIONS(178),
    [aux_sym_header_token6] = ACTIONS(178),
    [aux_sym_header_token7] = ACTIONS(178),
    [aux_sym_header_token8] = ACTIONS(178),
    [sym_header_value] = ACTIONS(180),
    [aux_sym_date_command_token1] = ACTIONS(178),
    [aux_sym_day_command_token1] = ACTIONS(178),
    [aux_sym_band_token1] = ACTIONS(178),
    [aux_sym_band_token2] = ACTIONS(178),
    [anon_sym_CW] = ACTIONS(178),
    [anon_sym_SSB] = ACTIONS(178),
    [anon_sym_FM] = ACTIONS(178),
    [anon_sym_AM] = ACTIONS(178),
    [anon_sym_DIGI] = ACTIONS(178),
    [anon_sym_FT8] = ACTIONS(178),
    [anon_sym_FT4] = ACTIONS(178),
    [anon_sym_PSK] = ACTIONS(178),
    [anon_sym_RTTY] = ACTIONS(178),
    [anon_sym_VARAC] = ACTIONS(178),
    [anon_sym_MFSK] = ACTIONS(178),
    [anon_sym_DATA] = ACTIONS(178),
    [anon_sym_JS8] = ACTIONS(178),
    [anon_sym_cw] = ACTIONS(178),
    [anon_sym_ssb] = ACTIONS(178),
    [anon_sym_fm] = ACTIONS(178),
    [anon_sym_am] = ACTIONS(178),
    [anon_sym_digi] = ACTIONS(178),
    [anon_sym_ft8] = ACTIONS(178),
    [anon_sym_ft4] = ACTIONS(178),
    [anon_sym_psk] = ACTIONS(178),
    [anon_sym_rtty] = ACTIONS(178),
    [anon_sym_varac] = ACTIONS(178),
    [anon_sym_mfsk] = ACTIONS(178),
    [anon_sym_data] = ACTIONS(178),
    [anon_sym_js8] = ACTIONS(178),
    [sym_time] = ACTIONS(178),
    [sym_callsign] = ACTIONS(178),
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(182),
    [sym_comment] = ACTIONS(182),
    [aux_sym_header_token1] = ACTIONS(184),
    [aux_sym_header_token2] = ACTIONS(184),
    [aux_sym_header_token3] = ACTIONS(184),
    [aux_sym_header_token4] = ACTIONS(184),
    [aux_sym_header_token5] = ACTIONS(184),
    [aux_sym_header_token6] = ACTIONS(184),
    [aux_sym_header_token7] = ACTIONS(184),
    [aux_sym_header_token8] = ACTIONS(184),
    [aux_sym_date_command_token1] = ACTIONS(184),
    [aux_sym_day_command_token1] = ACTIONS(184),
    [aux_sym_band_token1] = ACTIONS(184),
    [aux_sym_band_token2] = ACTIONS(184),
    [anon_sym_CW] = ACTIONS(184),
    [anon_sym_SSB] = ACTIONS(184),
    [anon_sym_FM] = ACTIONS(184),
    [anon_sym_AM] = ACTIONS(184),
    [anon_sym_DIGI] = ACTIONS(184),
    [anon_sym_FT8] = ACTIONS(184),
    [anon_sym_FT4] = ACTIONS(184),
    [anon_sym_PSK] = ACTIONS(184),
    [anon_sym_RTTY] = ACTIONS(184),
    [anon_sym_VARAC] = ACTIONS(184),
    [anon_sym_MFSK] = ACTIONS(184),
    [anon_sym_DATA] = ACTIONS(184),
    [anon_sym_JS8] = ACTIONS(184),
    [anon_sym_cw] = ACTIONS(184),
    [anon_sym_ssb] = ACTIONS(184),
    [anon_sym_fm] = ACTIONS(184),
    [anon_sym_am] = ACTIONS(184),
    [anon_sym_digi] = ACTIONS(184),
    [anon_sym_ft8] = ACTIONS(184),
    [anon_sym_ft4] = ACTIONS(184),
    [anon_sym_psk] = ACTIONS(184),
    [anon_sym_rtty] = ACTIONS(184),
    [anon_sym_varac] = ACTIONS(184),
    [anon_sym_mfsk] = ACTIONS(184),
    [anon_sym_data] = ACTIONS(184),
    [anon_sym_js8] = ACTIONS(184),
    [sym_time] = ACTIONS(184),
    [sym_callsign] = ACTIONS(184),
  },
  [27] = {
    [ts_builtin_sym_end] = ACTIONS(186),
    [sym_comment] = ACTIONS(186),
    [aux_sym_header_token1] = ACTIONS(188),
    [aux_sym_header_token2] = ACTIONS(188),
    [aux_sym_header_token3] = ACTIONS(188),
    [aux_sym_header_token4] = ACTIONS(188),
    [aux_sym_header_token5] = ACTIONS(188),
    [aux_sym_header_token6] = ACTIONS(188),
    [aux_sym_header_token7] = ACTIONS(188),
    [aux_sym_header_token8] = ACTIONS(188),
    [aux_sym_date_command_token1] = ACTIONS(188),
    [aux_sym_day_command_token1] = ACTIONS(188),
    [aux_sym_band_token1] = ACTIONS(188),
    [aux_sym_band_token2] = ACTIONS(188),
    [anon_sym_CW] = ACTIONS(188),
    [anon_sym_SSB] = ACTIONS(188),
    [anon_sym_FM] = ACTIONS(188),
    [anon_sym_AM] = ACTIONS(188),
    [anon_sym_DIGI] = ACTIONS(188),
    [anon_sym_FT8] = ACTIONS(188),
    [anon_sym_FT4] = ACTIONS(188),
    [anon_sym_PSK] = ACTIONS(188),
    [anon_sym_RTTY] = ACTIONS(188),
    [anon_sym_VARAC] = ACTIONS(188),
    [anon_sym_MFSK] = ACTIONS(188),
    [anon_sym_DATA] = ACTIONS(188),
    [anon_sym_JS8] = ACTIONS(188),
    [anon_sym_cw] = ACTIONS(188),
    [anon_sym_ssb] = ACTIONS(188),
    [anon_sym_fm] = ACTIONS(188),
    [anon_sym_am] = ACTIONS(188),
    [anon_sym_digi] = ACTIONS(188),
    [anon_sym_ft8] = ACTIONS(188),
    [anon_sym_ft4] = ACTIONS(188),
    [anon_sym_psk] = ACTIONS(188),
    [anon_sym_rtty] = ACTIONS(188),
    [anon_sym_varac] = ACTIONS(188),
    [anon_sym_mfsk] = ACTIONS(188),
    [anon_sym_data] = ACTIONS(188),
    [anon_sym_js8] = ACTIONS(188),
    [sym_time] = ACTIONS(188),
    [sym_callsign] = ACTIONS(188),
  },
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(190),
    [sym_comment] = ACTIONS(190),
    [aux_sym_header_token1] = ACTIONS(192),
    [aux_sym_header_token2] = ACTIONS(192),
    [aux_sym_header_token3] = ACTIONS(192),
    [aux_sym_header_token4] = ACTIONS(192),
    [aux_sym_header_token5] = ACTIONS(192),
    [aux_sym_header_token6] = ACTIONS(192),
    [aux_sym_header_token7] = ACTIONS(192),
    [aux_sym_header_token8] = ACTIONS(192),
    [aux_sym_date_command_token1] = ACTIONS(192),
    [aux_sym_day_command_token1] = ACTIONS(192),
    [aux_sym_band_token1] = ACTIONS(192),
    [aux_sym_band_token2] = ACTIONS(192),
    [anon_sym_CW] = ACTIONS(192),
    [anon_sym_SSB] = ACTIONS(192),
    [anon_sym_FM] = ACTIONS(192),
    [anon_sym_AM] = ACTIONS(192),
    [anon_sym_DIGI] = ACTIONS(192),
    [anon_sym_FT8] = ACTIONS(192),
    [anon_sym_FT4] = ACTIONS(192),
    [anon_sym_PSK] = ACTIONS(192),
    [anon_sym_RTTY] = ACTIONS(192),
    [anon_sym_VARAC] = ACTIONS(192),
    [anon_sym_MFSK] = ACTIONS(192),
    [anon_sym_DATA] = ACTIONS(192),
    [anon_sym_JS8] = ACTIONS(192),
    [anon_sym_cw] = ACTIONS(192),
    [anon_sym_ssb] = ACTIONS(192),
    [anon_sym_fm] = ACTIONS(192),
    [anon_sym_am] = ACTIONS(192),
    [anon_sym_digi] = ACTIONS(192),
    [anon_sym_ft8] = ACTIONS(192),
    [anon_sym_ft4] = ACTIONS(192),
    [anon_sym_psk] = ACTIONS(192),
    [anon_sym_rtty] = ACTIONS(192),
    [anon_sym_varac] = ACTIONS(192),
    [anon_sym_mfsk] = ACTIONS(192),
    [anon_sym_data] = ACTIONS(192),
    [anon_sym_js8] = ACTIONS(192),
    [sym_time] = ACTIONS(192),
    [sym_callsign] = ACTIONS(192),
  },
  [29] = {
    [ts_builtin_sym_end] = ACTIONS(194),
    [sym_comment] = ACTIONS(194),
    [aux_sym_header_token1] = ACTIONS(196),
    [aux_sym_header_token2] = ACTIONS(196),
    [aux_sym_header_token3] = ACTIONS(196),
    [aux_sym_header_token4] = ACTIONS(196),
    [aux_sym_header_token5] = ACTIONS(196),
    [aux_sym_header_token6] = ACTIONS(196),
    [aux_sym_header_token7] = ACTIONS(196),
    [aux_sym_header_token8] = ACTIONS(196),
    [aux_sym_date_command_token1] = ACTIONS(196),
    [aux_sym_day_command_token1] = ACTIONS(196),
    [aux_sym_band_token1] = ACTIONS(196),
    [aux_sym_band_token2] = ACTIONS(196),
    [anon_sym_CW] = ACTIONS(196),
    [anon_sym_SSB] = ACTIONS(196),
    [anon_sym_FM] = ACTIONS(196),
    [anon_sym_AM] = ACTIONS(196),
    [anon_sym_DIGI] = ACTIONS(196),
    [anon_sym_FT8] = ACTIONS(196),
    [anon_sym_FT4] = ACTIONS(196),
    [anon_sym_PSK] = ACTIONS(196),
    [anon_sym_RTTY] = ACTIONS(196),
    [anon_sym_VARAC] = ACTIONS(196),
    [anon_sym_MFSK] = ACTIONS(196),
    [anon_sym_DATA] = ACTIONS(196),
    [anon_sym_JS8] = ACTIONS(196),
    [anon_sym_cw] = ACTIONS(196),
    [anon_sym_ssb] = ACTIONS(196),
    [anon_sym_fm] = ACTIONS(196),
    [anon_sym_am] = ACTIONS(196),
    [anon_sym_digi] = ACTIONS(196),
    [anon_sym_ft8] = ACTIONS(196),
    [anon_sym_ft4] = ACTIONS(196),
    [anon_sym_psk] = ACTIONS(196),
    [anon_sym_rtty] = ACTIONS(196),
    [anon_sym_varac] = ACTIONS(196),
    [anon_sym_mfsk] = ACTIONS(196),
    [anon_sym_data] = ACTIONS(196),
    [anon_sym_js8] = ACTIONS(196),
    [sym_time] = ACTIONS(196),
    [sym_callsign] = ACTIONS(196),
  },
  [30] = {
    [ts_builtin_sym_end] = ACTIONS(198),
    [sym_comment] = ACTIONS(198),
    [aux_sym_header_token1] = ACTIONS(200),
    [aux_sym_header_token2] = ACTIONS(200),
    [aux_sym_header_token3] = ACTIONS(200),
    [aux_sym_header_token4] = ACTIONS(200),
    [aux_sym_header_token5] = ACTIONS(200),
    [aux_sym_header_token6] = ACTIONS(200),
    [aux_sym_header_token7] = ACTIONS(200),
    [aux_sym_header_token8] = ACTIONS(200),
    [aux_sym_date_command_token1] = ACTIONS(200),
    [aux_sym_day_command_token1] = ACTIONS(200),
    [aux_sym_band_token1] = ACTIONS(200),
    [aux_sym_band_token2] = ACTIONS(200),
    [anon_sym_CW] = ACTIONS(200),
    [anon_sym_SSB] = ACTIONS(200),
    [anon_sym_FM] = ACTIONS(200),
    [anon_sym_AM] = ACTIONS(200),
    [anon_sym_DIGI] = ACTIONS(200),
    [anon_sym_FT8] = ACTIONS(200),
    [anon_sym_FT4] = ACTIONS(200),
    [anon_sym_PSK] = ACTIONS(200),
    [anon_sym_RTTY] = ACTIONS(200),
    [anon_sym_VARAC] = ACTIONS(200),
    [anon_sym_MFSK] = ACTIONS(200),
    [anon_sym_DATA] = ACTIONS(200),
    [anon_sym_JS8] = ACTIONS(200),
    [anon_sym_cw] = ACTIONS(200),
    [anon_sym_ssb] = ACTIONS(200),
    [anon_sym_fm] = ACTIONS(200),
    [anon_sym_am] = ACTIONS(200),
    [anon_sym_digi] = ACTIONS(200),
    [anon_sym_ft8] = ACTIONS(200),
    [anon_sym_ft4] = ACTIONS(200),
    [anon_sym_psk] = ACTIONS(200),
    [anon_sym_rtty] = ACTIONS(200),
    [anon_sym_varac] = ACTIONS(200),
    [anon_sym_mfsk] = ACTIONS(200),
    [anon_sym_data] = ACTIONS(200),
    [anon_sym_js8] = ACTIONS(200),
    [sym_time] = ACTIONS(200),
    [sym_callsign] = ACTIONS(200),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(202), 1,
      aux_sym_grid_token1,
    ACTIONS(204), 1,
      aux_sym_inline_hash_comment_token1,
  [7] = 1,
    ACTIONS(206), 1,
      aux_sym_qsl_info_token1,
  [11] = 1,
    ACTIONS(208), 1,
      aux_sym_inline_hash_comment_token2,
  [15] = 1,
    ACTIONS(210), 1,
      sym_date_value,
  [19] = 1,
    ACTIONS(212), 1,
      anon_sym_RBRACK,
  [23] = 1,
    ACTIONS(214), 1,
      anon_sym_GT,
  [27] = 1,
    ACTIONS(216), 1,
      aux_sym_inline_comment_token1,
  [31] = 1,
    ACTIONS(218), 1,
      aux_sym_name_token1,
  [35] = 1,
    ACTIONS(220), 1,
      aux_sym_rst_token1,
  [39] = 1,
    ACTIONS(222), 1,
      aux_sym_rst_token1,
  [43] = 1,
    ACTIONS(224), 1,
      ts_builtin_sym_end,
  [47] = 1,
    ACTIONS(226), 1,
      sym_callsign,
  [51] = 1,
    ACTIONS(228), 1,
      sym_day_value,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(31)] = 0,
  [SMALL_STATE(32)] = 7,
  [SMALL_STATE(33)] = 11,
  [SMALL_STATE(34)] = 15,
  [SMALL_STATE(35)] = 19,
  [SMALL_STATE(36)] = 23,
  [SMALL_STATE(37)] = 27,
  [SMALL_STATE(38)] = 31,
  [SMALL_STATE(39)] = 35,
  [SMALL_STATE(40)] = 39,
  [SMALL_STATE(41)] = 43,
  [SMALL_STATE(42)] = 47,
  [SMALL_STATE(43)] = 51,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 2),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 2),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 1),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 3),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 3),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat2, 2),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat2, 2),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat2, 2), SHIFT_REPEAT(31),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat2, 2), SHIFT_REPEAT(38),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat2, 2), SHIFT_REPEAT(37),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat2, 2), SHIFT_REPEAT(32),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 4),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 4),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(15),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(40),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(39),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(25),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(34),
  [95] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(43),
  [98] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(30),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(42),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_rcvd, 2),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_rcvd, 2),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_sent, 2),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_sent, 2),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst, 1),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst, 1),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_comment, 3),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_comment, 3),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_hash_comment, 3),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_hash_comment, 3),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qsl_info, 3),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qsl_info, 3),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid, 2),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid, 2),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 2),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_extra, 1),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_extra, 1),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 1),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 1),
  [150] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 1), SHIFT(26),
  [153] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 1), SHIFT(30),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(26),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(30),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 2),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 2),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 2), SHIFT(26),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 2), SHIFT(30),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 1),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 1),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band, 1),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band, 1),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day_command, 2),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_day_command, 2),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_command, 2),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_command, 2),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 2),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 2),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mode, 1),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mode, 1),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [224] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_fle(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
