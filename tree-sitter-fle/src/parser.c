#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 40
#define LARGE_STATE_COUNT 29
#define SYMBOL_COUNT 74
#define ALIAS_COUNT 0
#define TOKEN_COUNT 56
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
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
  aux_sym_rst_sent_token1 = 45,
  anon_sym_POUND = 46,
  aux_sym_grid_token1 = 47,
  anon_sym_AT = 48,
  aux_sym_name_token1 = 49,
  anon_sym_LBRACK = 50,
  aux_sym_inline_comment_token1 = 51,
  anon_sym_RBRACK = 52,
  anon_sym_LT = 53,
  aux_sym_qsl_info_token1 = 54,
  anon_sym_GT = 55,
  sym_source_file = 56,
  sym_header = 57,
  sym_date_command = 58,
  sym_day_command = 59,
  sym_band_mode_line = 60,
  sym_band = 61,
  sym_mode = 62,
  sym_qso_line = 63,
  sym_rst_sent = 64,
  sym_rst_rcvd = 65,
  sym_qso_extra = 66,
  sym_grid = 67,
  sym_name = 68,
  sym_inline_comment = 69,
  sym_qsl_info = 70,
  aux_sym_source_file_repeat1 = 71,
  aux_sym_band_mode_line_repeat1 = 72,
  aux_sym_qso_line_repeat1 = 73,
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
  [aux_sym_rst_sent_token1] = "rst_sent_token1",
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
  [sym_source_file] = "source_file",
  [sym_header] = "header",
  [sym_date_command] = "date_command",
  [sym_day_command] = "day_command",
  [sym_band_mode_line] = "band_mode_line",
  [sym_band] = "band",
  [sym_mode] = "mode",
  [sym_qso_line] = "qso_line",
  [sym_rst_sent] = "rst_sent",
  [sym_rst_rcvd] = "rst_rcvd",
  [sym_qso_extra] = "qso_extra",
  [sym_grid] = "grid",
  [sym_name] = "name",
  [sym_inline_comment] = "inline_comment",
  [sym_qsl_info] = "qsl_info",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_band_mode_line_repeat1] = "band_mode_line_repeat1",
  [aux_sym_qso_line_repeat1] = "qso_line_repeat1",
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
  [aux_sym_rst_sent_token1] = aux_sym_rst_sent_token1,
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
  [sym_source_file] = sym_source_file,
  [sym_header] = sym_header,
  [sym_date_command] = sym_date_command,
  [sym_day_command] = sym_day_command,
  [sym_band_mode_line] = sym_band_mode_line,
  [sym_band] = sym_band,
  [sym_mode] = sym_mode,
  [sym_qso_line] = sym_qso_line,
  [sym_rst_sent] = sym_rst_sent,
  [sym_rst_rcvd] = sym_rst_rcvd,
  [sym_qso_extra] = sym_qso_extra,
  [sym_grid] = sym_grid,
  [sym_name] = sym_name,
  [sym_inline_comment] = sym_inline_comment,
  [sym_qsl_info] = sym_qsl_info,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_band_mode_line_repeat1] = aux_sym_band_mode_line_repeat1,
  [aux_sym_qso_line_repeat1] = aux_sym_qso_line_repeat1,
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
  [aux_sym_rst_sent_token1] = {
    .visible = false,
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
  [sym_rst_sent] = {
    .visible = true,
    .named = true,
  },
  [sym_rst_rcvd] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(20);
      if (lookahead == '#') ADVANCE(163);
      if (lookahead == '+') ADVANCE(39);
      if (lookahead == '<') ADVANCE(171);
      if (lookahead == '>') ADVANCE(174);
      if (lookahead == '@') ADVANCE(165);
      if (lookahead == 'A') ADVANCE(90);
      if (lookahead == 'C') ADVANCE(101);
      if (lookahead == 'D') ADVANCE(78);
      if (lookahead == 'F') ADVANCE(91);
      if (lookahead == 'J') ADVANCE(93);
      if (lookahead == 'M') ADVANCE(85);
      if (lookahead == 'P') ADVANCE(94);
      if (lookahead == 'R') ADVANCE(99);
      if (lookahead == 'S') ADVANCE(95);
      if (lookahead == 'V') ADVANCE(80);
      if (lookahead == '[') ADVANCE(167);
      if (lookahead == ']') ADVANCE(170);
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'c') ADVANCE(122);
      if (lookahead == 'd') ADVANCE(79);
      if (lookahead == 'f') ADVANCE(114);
      if (lookahead == 'j') ADVANCE(118);
      if (lookahead == 'm') ADVANCE(108);
      if (lookahead == 'p') ADVANCE(116);
      if (lookahead == 'r') ADVANCE(121);
      if (lookahead == 's') ADVANCE(117);
      if (lookahead == 'v') ADVANCE(103);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(138);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(151);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(164);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(173);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(5)
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(34);
      if (lookahead != 0) ADVANCE(35);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(169);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(24);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (lookahead != 0) ADVANCE(166);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(40);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(8);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 19:
      if (eof) ADVANCE(20);
      if (lookahead == '#') ADVANCE(25);
      if (lookahead == '+') ADVANCE(39);
      if (lookahead == '>') ADVANCE(174);
      if (lookahead == 'A') ADVANCE(90);
      if (lookahead == 'C') ADVANCE(101);
      if (lookahead == 'D') ADVANCE(78);
      if (lookahead == 'F') ADVANCE(91);
      if (lookahead == 'J') ADVANCE(93);
      if (lookahead == 'M') ADVANCE(85);
      if (lookahead == 'P') ADVANCE(94);
      if (lookahead == 'R') ADVANCE(99);
      if (lookahead == 'S') ADVANCE(95);
      if (lookahead == 'V') ADVANCE(80);
      if (lookahead == ']') ADVANCE(170);
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'c') ADVANCE(122);
      if (lookahead == 'd') ADVANCE(79);
      if (lookahead == 'f') ADVANCE(114);
      if (lookahead == 'j') ADVANCE(118);
      if (lookahead == 'm') ADVANCE(108);
      if (lookahead == 'p') ADVANCE(116);
      if (lookahead == 'r') ADVANCE(121);
      if (lookahead == 's') ADVANCE(117);
      if (lookahead == 'v') ADVANCE(103);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(138);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(151);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(173);
      if (lookahead == '>') ADVANCE(25);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(169);
      if (lookahead == ']') ADVANCE(25);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\r') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\t' ||
          (11 <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_header_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_header_token2);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_header_token3);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_header_token4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_header_token5);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_header_token6);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_header_token7);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_header_token8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == 11 ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(34);
      if (lookahead != 0 &&
          (lookahead < '\n' || '\r' < lookahead)) ADVANCE(35);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_date_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_date_value);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_day_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_day_value);
      if (lookahead == '+') ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_band_token1);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_band_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_band_token2);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(10);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_CW);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_SSB);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_FM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_AM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_DIGI);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_FT8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_FT4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_PSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_RTTY);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_VARAC);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_MFSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DATA);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_JS8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_cw);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_ssb);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_fm);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_am);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_digi);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_ft8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_ft4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_psk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_rtty);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_varac);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_mfsk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_data);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_js8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(144);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(144);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(144);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(144);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(144);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(49);
      if (lookahead == '8') ADVANCE(48);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(62);
      if (lookahead == '8') ADVANCE(61);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(55);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(68);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(97);
      if (lookahead == 'I') ADVANCE(86);
      if (lookahead == 'a') ADVANCE(157);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(157);
      if (lookahead == 'a') ADVANCE(100);
      if (lookahead == 'i') ADVANCE(109);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(92);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(54);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(36);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(84);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'B') ADVANCE(44);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C') ADVANCE(52);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F') ADVANCE(96);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(129);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G') ADVANCE(87);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I') ADVANCE(47);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(50);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(53);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(46);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(45);
      if (lookahead == 'T') ADVANCE(74);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R') ADVANCE(82);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(76);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(88);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(83);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(89);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(81);
      if (lookahead == 't') ADVANCE(132);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(102);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(98);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(132);
      if (lookahead == 't') ADVANCE(104);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W') ADVANCE(43);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'Y') ADVANCE(51);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(115);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(67);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(36);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(107);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'b') ADVANCE(57);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'c') ADVANCE(65);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'f') ADVANCE(119);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(129);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'g') ADVANCE(110);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'i') ADVANCE(60);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(63);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(66);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(59);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(58);
      if (lookahead == 't') ADVANCE(75);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'r') ADVANCE(105);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(111);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(106);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(77);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(112);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(123);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(120);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'w') ADVANCE(56);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'y') ADVANCE(64);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(33);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(32);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(143);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(158);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(146);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(126);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(153);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(148);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(150);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(161);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(140);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(27);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(36);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(154);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(135);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(30);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(130);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(131);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(147);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(26);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(145);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(141);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(41);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(156);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(133);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(128);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(159);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(152);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(160);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(139);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(127);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(142);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(137);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(132);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(149);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(124);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(125);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_callsign);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(162);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(25);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(164);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_name_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(166);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (lookahead == '#') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(169);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (lookahead == '#') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(173);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(173);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 19},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 19},
  [14] = {.lex_state = 19},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 19},
  [23] = {.lex_state = 19},
  [24] = {.lex_state = 19},
  [25] = {.lex_state = 19},
  [26] = {.lex_state = 19},
  [27] = {.lex_state = 19},
  [28] = {.lex_state = 19},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 19},
  [31] = {.lex_state = 19},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 6},
  [34] = {.lex_state = 7},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 19},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 19},
  [39] = {.lex_state = 3},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(1),
    [aux_sym_header_token2] = ACTIONS(1),
    [aux_sym_header_token3] = ACTIONS(1),
    [aux_sym_header_token4] = ACTIONS(1),
    [aux_sym_header_token5] = ACTIONS(1),
    [aux_sym_header_token6] = ACTIONS(1),
    [aux_sym_header_token7] = ACTIONS(1),
    [aux_sym_header_token8] = ACTIONS(1),
    [aux_sym_date_command_token1] = ACTIONS(1),
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
    [aux_sym_rst_sent_token1] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(36),
    [sym_header] = STATE(13),
    [sym_date_command] = STATE(13),
    [sym_day_command] = STATE(13),
    [sym_band_mode_line] = STATE(13),
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
    [sym_qso_line] = STATE(13),
    [aux_sym_source_file_repeat1] = STATE(13),
    [aux_sym_band_mode_line_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
    [aux_sym_header_token1] = ACTIONS(9),
    [aux_sym_header_token2] = ACTIONS(9),
    [aux_sym_header_token3] = ACTIONS(9),
    [aux_sym_header_token4] = ACTIONS(9),
    [aux_sym_header_token5] = ACTIONS(9),
    [aux_sym_header_token6] = ACTIONS(9),
    [aux_sym_header_token7] = ACTIONS(9),
    [aux_sym_header_token8] = ACTIONS(9),
    [aux_sym_date_command_token1] = ACTIONS(11),
    [aux_sym_day_command_token1] = ACTIONS(13),
    [aux_sym_band_token1] = ACTIONS(15),
    [aux_sym_band_token2] = ACTIONS(15),
    [anon_sym_CW] = ACTIONS(17),
    [anon_sym_SSB] = ACTIONS(17),
    [anon_sym_FM] = ACTIONS(17),
    [anon_sym_AM] = ACTIONS(17),
    [anon_sym_DIGI] = ACTIONS(17),
    [anon_sym_FT8] = ACTIONS(17),
    [anon_sym_FT4] = ACTIONS(17),
    [anon_sym_PSK] = ACTIONS(17),
    [anon_sym_RTTY] = ACTIONS(17),
    [anon_sym_VARAC] = ACTIONS(17),
    [anon_sym_MFSK] = ACTIONS(17),
    [anon_sym_DATA] = ACTIONS(17),
    [anon_sym_JS8] = ACTIONS(17),
    [anon_sym_cw] = ACTIONS(17),
    [anon_sym_ssb] = ACTIONS(17),
    [anon_sym_fm] = ACTIONS(17),
    [anon_sym_am] = ACTIONS(17),
    [anon_sym_digi] = ACTIONS(17),
    [anon_sym_ft8] = ACTIONS(17),
    [anon_sym_ft4] = ACTIONS(17),
    [anon_sym_psk] = ACTIONS(17),
    [anon_sym_rtty] = ACTIONS(17),
    [anon_sym_varac] = ACTIONS(17),
    [anon_sym_mfsk] = ACTIONS(17),
    [anon_sym_data] = ACTIONS(17),
    [anon_sym_js8] = ACTIONS(17),
    [sym_time] = ACTIONS(19),
    [sym_callsign] = ACTIONS(21),
  },
  [2] = {
    [sym_rst_sent] = STATE(4),
    [sym_qso_extra] = STATE(9),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(25),
    [aux_sym_header_token2] = ACTIONS(25),
    [aux_sym_header_token3] = ACTIONS(25),
    [aux_sym_header_token4] = ACTIONS(25),
    [aux_sym_header_token5] = ACTIONS(25),
    [aux_sym_header_token6] = ACTIONS(25),
    [aux_sym_header_token7] = ACTIONS(25),
    [aux_sym_header_token8] = ACTIONS(25),
    [aux_sym_date_command_token1] = ACTIONS(25),
    [aux_sym_day_command_token1] = ACTIONS(25),
    [aux_sym_band_token1] = ACTIONS(25),
    [aux_sym_band_token2] = ACTIONS(25),
    [anon_sym_CW] = ACTIONS(25),
    [anon_sym_SSB] = ACTIONS(25),
    [anon_sym_FM] = ACTIONS(25),
    [anon_sym_AM] = ACTIONS(25),
    [anon_sym_DIGI] = ACTIONS(25),
    [anon_sym_FT8] = ACTIONS(25),
    [anon_sym_FT4] = ACTIONS(25),
    [anon_sym_PSK] = ACTIONS(25),
    [anon_sym_RTTY] = ACTIONS(25),
    [anon_sym_VARAC] = ACTIONS(25),
    [anon_sym_MFSK] = ACTIONS(25),
    [anon_sym_DATA] = ACTIONS(25),
    [anon_sym_JS8] = ACTIONS(25),
    [anon_sym_cw] = ACTIONS(25),
    [anon_sym_ssb] = ACTIONS(25),
    [anon_sym_fm] = ACTIONS(25),
    [anon_sym_am] = ACTIONS(25),
    [anon_sym_digi] = ACTIONS(25),
    [anon_sym_ft8] = ACTIONS(25),
    [anon_sym_ft4] = ACTIONS(25),
    [anon_sym_psk] = ACTIONS(25),
    [anon_sym_rtty] = ACTIONS(25),
    [anon_sym_varac] = ACTIONS(25),
    [anon_sym_mfsk] = ACTIONS(25),
    [anon_sym_data] = ACTIONS(25),
    [anon_sym_js8] = ACTIONS(25),
    [sym_time] = ACTIONS(25),
    [sym_callsign] = ACTIONS(25),
    [aux_sym_rst_sent_token1] = ACTIONS(27),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [3] = {
    [sym_rst_rcvd] = STATE(8),
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(39),
    [aux_sym_header_token2] = ACTIONS(39),
    [aux_sym_header_token3] = ACTIONS(39),
    [aux_sym_header_token4] = ACTIONS(39),
    [aux_sym_header_token5] = ACTIONS(39),
    [aux_sym_header_token6] = ACTIONS(39),
    [aux_sym_header_token7] = ACTIONS(39),
    [aux_sym_header_token8] = ACTIONS(39),
    [aux_sym_date_command_token1] = ACTIONS(39),
    [aux_sym_day_command_token1] = ACTIONS(39),
    [aux_sym_band_token1] = ACTIONS(39),
    [aux_sym_band_token2] = ACTIONS(39),
    [anon_sym_CW] = ACTIONS(39),
    [anon_sym_SSB] = ACTIONS(39),
    [anon_sym_FM] = ACTIONS(39),
    [anon_sym_AM] = ACTIONS(39),
    [anon_sym_DIGI] = ACTIONS(39),
    [anon_sym_FT8] = ACTIONS(39),
    [anon_sym_FT4] = ACTIONS(39),
    [anon_sym_PSK] = ACTIONS(39),
    [anon_sym_RTTY] = ACTIONS(39),
    [anon_sym_VARAC] = ACTIONS(39),
    [anon_sym_MFSK] = ACTIONS(39),
    [anon_sym_DATA] = ACTIONS(39),
    [anon_sym_JS8] = ACTIONS(39),
    [anon_sym_cw] = ACTIONS(39),
    [anon_sym_ssb] = ACTIONS(39),
    [anon_sym_fm] = ACTIONS(39),
    [anon_sym_am] = ACTIONS(39),
    [anon_sym_digi] = ACTIONS(39),
    [anon_sym_ft8] = ACTIONS(39),
    [anon_sym_ft4] = ACTIONS(39),
    [anon_sym_psk] = ACTIONS(39),
    [anon_sym_rtty] = ACTIONS(39),
    [anon_sym_varac] = ACTIONS(39),
    [anon_sym_mfsk] = ACTIONS(39),
    [anon_sym_data] = ACTIONS(39),
    [anon_sym_js8] = ACTIONS(39),
    [sym_time] = ACTIONS(39),
    [sym_callsign] = ACTIONS(39),
    [aux_sym_rst_sent_token1] = ACTIONS(41),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [4] = {
    [sym_rst_rcvd] = STATE(10),
    [sym_qso_extra] = STATE(7),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(3),
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
    [aux_sym_rst_sent_token1] = ACTIONS(41),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [5] = {
    [sym_rst_sent] = STATE(3),
    [sym_qso_extra] = STATE(7),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(3),
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
    [aux_sym_rst_sent_token1] = ACTIONS(27),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [6] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_comment] = ACTIONS(3),
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
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [7] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(39),
    [aux_sym_header_token2] = ACTIONS(39),
    [aux_sym_header_token3] = ACTIONS(39),
    [aux_sym_header_token4] = ACTIONS(39),
    [aux_sym_header_token5] = ACTIONS(39),
    [aux_sym_header_token6] = ACTIONS(39),
    [aux_sym_header_token7] = ACTIONS(39),
    [aux_sym_header_token8] = ACTIONS(39),
    [aux_sym_date_command_token1] = ACTIONS(39),
    [aux_sym_day_command_token1] = ACTIONS(39),
    [aux_sym_band_token1] = ACTIONS(39),
    [aux_sym_band_token2] = ACTIONS(39),
    [anon_sym_CW] = ACTIONS(39),
    [anon_sym_SSB] = ACTIONS(39),
    [anon_sym_FM] = ACTIONS(39),
    [anon_sym_AM] = ACTIONS(39),
    [anon_sym_DIGI] = ACTIONS(39),
    [anon_sym_FT8] = ACTIONS(39),
    [anon_sym_FT4] = ACTIONS(39),
    [anon_sym_PSK] = ACTIONS(39),
    [anon_sym_RTTY] = ACTIONS(39),
    [anon_sym_VARAC] = ACTIONS(39),
    [anon_sym_MFSK] = ACTIONS(39),
    [anon_sym_DATA] = ACTIONS(39),
    [anon_sym_JS8] = ACTIONS(39),
    [anon_sym_cw] = ACTIONS(39),
    [anon_sym_ssb] = ACTIONS(39),
    [anon_sym_fm] = ACTIONS(39),
    [anon_sym_am] = ACTIONS(39),
    [anon_sym_digi] = ACTIONS(39),
    [anon_sym_ft8] = ACTIONS(39),
    [anon_sym_ft4] = ACTIONS(39),
    [anon_sym_psk] = ACTIONS(39),
    [anon_sym_rtty] = ACTIONS(39),
    [anon_sym_varac] = ACTIONS(39),
    [anon_sym_mfsk] = ACTIONS(39),
    [anon_sym_data] = ACTIONS(39),
    [anon_sym_js8] = ACTIONS(39),
    [sym_time] = ACTIONS(39),
    [sym_callsign] = ACTIONS(39),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [8] = {
    [sym_qso_extra] = STATE(12),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_comment] = ACTIONS(3),
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
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [9] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_comment] = ACTIONS(3),
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
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [10] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(37),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(39),
    [aux_sym_header_token2] = ACTIONS(39),
    [aux_sym_header_token3] = ACTIONS(39),
    [aux_sym_header_token4] = ACTIONS(39),
    [aux_sym_header_token5] = ACTIONS(39),
    [aux_sym_header_token6] = ACTIONS(39),
    [aux_sym_header_token7] = ACTIONS(39),
    [aux_sym_header_token8] = ACTIONS(39),
    [aux_sym_date_command_token1] = ACTIONS(39),
    [aux_sym_day_command_token1] = ACTIONS(39),
    [aux_sym_band_token1] = ACTIONS(39),
    [aux_sym_band_token2] = ACTIONS(39),
    [anon_sym_CW] = ACTIONS(39),
    [anon_sym_SSB] = ACTIONS(39),
    [anon_sym_FM] = ACTIONS(39),
    [anon_sym_AM] = ACTIONS(39),
    [anon_sym_DIGI] = ACTIONS(39),
    [anon_sym_FT8] = ACTIONS(39),
    [anon_sym_FT4] = ACTIONS(39),
    [anon_sym_PSK] = ACTIONS(39),
    [anon_sym_RTTY] = ACTIONS(39),
    [anon_sym_VARAC] = ACTIONS(39),
    [anon_sym_MFSK] = ACTIONS(39),
    [anon_sym_DATA] = ACTIONS(39),
    [anon_sym_JS8] = ACTIONS(39),
    [anon_sym_cw] = ACTIONS(39),
    [anon_sym_ssb] = ACTIONS(39),
    [anon_sym_fm] = ACTIONS(39),
    [anon_sym_am] = ACTIONS(39),
    [anon_sym_digi] = ACTIONS(39),
    [anon_sym_ft8] = ACTIONS(39),
    [anon_sym_ft4] = ACTIONS(39),
    [anon_sym_psk] = ACTIONS(39),
    [anon_sym_rtty] = ACTIONS(39),
    [anon_sym_varac] = ACTIONS(39),
    [anon_sym_mfsk] = ACTIONS(39),
    [anon_sym_data] = ACTIONS(39),
    [anon_sym_js8] = ACTIONS(39),
    [sym_time] = ACTIONS(39),
    [sym_callsign] = ACTIONS(39),
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [11] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(51),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(53),
    [aux_sym_header_token2] = ACTIONS(53),
    [aux_sym_header_token3] = ACTIONS(53),
    [aux_sym_header_token4] = ACTIONS(53),
    [aux_sym_header_token5] = ACTIONS(53),
    [aux_sym_header_token6] = ACTIONS(53),
    [aux_sym_header_token7] = ACTIONS(53),
    [aux_sym_header_token8] = ACTIONS(53),
    [aux_sym_date_command_token1] = ACTIONS(53),
    [aux_sym_day_command_token1] = ACTIONS(53),
    [aux_sym_band_token1] = ACTIONS(53),
    [aux_sym_band_token2] = ACTIONS(53),
    [anon_sym_CW] = ACTIONS(53),
    [anon_sym_SSB] = ACTIONS(53),
    [anon_sym_FM] = ACTIONS(53),
    [anon_sym_AM] = ACTIONS(53),
    [anon_sym_DIGI] = ACTIONS(53),
    [anon_sym_FT8] = ACTIONS(53),
    [anon_sym_FT4] = ACTIONS(53),
    [anon_sym_PSK] = ACTIONS(53),
    [anon_sym_RTTY] = ACTIONS(53),
    [anon_sym_VARAC] = ACTIONS(53),
    [anon_sym_MFSK] = ACTIONS(53),
    [anon_sym_DATA] = ACTIONS(53),
    [anon_sym_JS8] = ACTIONS(53),
    [anon_sym_cw] = ACTIONS(53),
    [anon_sym_ssb] = ACTIONS(53),
    [anon_sym_fm] = ACTIONS(53),
    [anon_sym_am] = ACTIONS(53),
    [anon_sym_digi] = ACTIONS(53),
    [anon_sym_ft8] = ACTIONS(53),
    [anon_sym_ft4] = ACTIONS(53),
    [anon_sym_psk] = ACTIONS(53),
    [anon_sym_rtty] = ACTIONS(53),
    [anon_sym_varac] = ACTIONS(53),
    [anon_sym_mfsk] = ACTIONS(53),
    [anon_sym_data] = ACTIONS(53),
    [anon_sym_js8] = ACTIONS(53),
    [sym_time] = ACTIONS(53),
    [sym_callsign] = ACTIONS(53),
    [anon_sym_POUND] = ACTIONS(55),
    [anon_sym_AT] = ACTIONS(58),
    [anon_sym_LBRACK] = ACTIONS(61),
    [anon_sym_LT] = ACTIONS(64),
  },
  [12] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(16),
    [sym_name] = STATE(16),
    [sym_inline_comment] = STATE(16),
    [sym_qsl_info] = STATE(16),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(67),
    [sym_comment] = ACTIONS(3),
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
    [anon_sym_POUND] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(31),
    [anon_sym_LBRACK] = ACTIONS(33),
    [anon_sym_LT] = ACTIONS(35),
  },
  [13] = {
    [sym_header] = STATE(14),
    [sym_date_command] = STATE(14),
    [sym_day_command] = STATE(14),
    [sym_band_mode_line] = STATE(14),
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
    [sym_qso_line] = STATE(14),
    [aux_sym_source_file_repeat1] = STATE(14),
    [aux_sym_band_mode_line_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(71),
    [sym_comment] = ACTIONS(7),
    [aux_sym_header_token1] = ACTIONS(9),
    [aux_sym_header_token2] = ACTIONS(9),
    [aux_sym_header_token3] = ACTIONS(9),
    [aux_sym_header_token4] = ACTIONS(9),
    [aux_sym_header_token5] = ACTIONS(9),
    [aux_sym_header_token6] = ACTIONS(9),
    [aux_sym_header_token7] = ACTIONS(9),
    [aux_sym_header_token8] = ACTIONS(9),
    [aux_sym_date_command_token1] = ACTIONS(11),
    [aux_sym_day_command_token1] = ACTIONS(13),
    [aux_sym_band_token1] = ACTIONS(15),
    [aux_sym_band_token2] = ACTIONS(15),
    [anon_sym_CW] = ACTIONS(17),
    [anon_sym_SSB] = ACTIONS(17),
    [anon_sym_FM] = ACTIONS(17),
    [anon_sym_AM] = ACTIONS(17),
    [anon_sym_DIGI] = ACTIONS(17),
    [anon_sym_FT8] = ACTIONS(17),
    [anon_sym_FT4] = ACTIONS(17),
    [anon_sym_PSK] = ACTIONS(17),
    [anon_sym_RTTY] = ACTIONS(17),
    [anon_sym_VARAC] = ACTIONS(17),
    [anon_sym_MFSK] = ACTIONS(17),
    [anon_sym_DATA] = ACTIONS(17),
    [anon_sym_JS8] = ACTIONS(17),
    [anon_sym_cw] = ACTIONS(17),
    [anon_sym_ssb] = ACTIONS(17),
    [anon_sym_fm] = ACTIONS(17),
    [anon_sym_am] = ACTIONS(17),
    [anon_sym_digi] = ACTIONS(17),
    [anon_sym_ft8] = ACTIONS(17),
    [anon_sym_ft4] = ACTIONS(17),
    [anon_sym_psk] = ACTIONS(17),
    [anon_sym_rtty] = ACTIONS(17),
    [anon_sym_varac] = ACTIONS(17),
    [anon_sym_mfsk] = ACTIONS(17),
    [anon_sym_data] = ACTIONS(17),
    [anon_sym_js8] = ACTIONS(17),
    [sym_time] = ACTIONS(19),
    [sym_callsign] = ACTIONS(21),
  },
  [14] = {
    [sym_header] = STATE(14),
    [sym_date_command] = STATE(14),
    [sym_day_command] = STATE(14),
    [sym_band_mode_line] = STATE(14),
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
    [sym_qso_line] = STATE(14),
    [aux_sym_source_file_repeat1] = STATE(14),
    [aux_sym_band_mode_line_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(73),
    [sym_comment] = ACTIONS(7),
    [aux_sym_header_token1] = ACTIONS(75),
    [aux_sym_header_token2] = ACTIONS(75),
    [aux_sym_header_token3] = ACTIONS(75),
    [aux_sym_header_token4] = ACTIONS(75),
    [aux_sym_header_token5] = ACTIONS(75),
    [aux_sym_header_token6] = ACTIONS(75),
    [aux_sym_header_token7] = ACTIONS(75),
    [aux_sym_header_token8] = ACTIONS(75),
    [aux_sym_date_command_token1] = ACTIONS(78),
    [aux_sym_day_command_token1] = ACTIONS(81),
    [aux_sym_band_token1] = ACTIONS(84),
    [aux_sym_band_token2] = ACTIONS(84),
    [anon_sym_CW] = ACTIONS(87),
    [anon_sym_SSB] = ACTIONS(87),
    [anon_sym_FM] = ACTIONS(87),
    [anon_sym_AM] = ACTIONS(87),
    [anon_sym_DIGI] = ACTIONS(87),
    [anon_sym_FT8] = ACTIONS(87),
    [anon_sym_FT4] = ACTIONS(87),
    [anon_sym_PSK] = ACTIONS(87),
    [anon_sym_RTTY] = ACTIONS(87),
    [anon_sym_VARAC] = ACTIONS(87),
    [anon_sym_MFSK] = ACTIONS(87),
    [anon_sym_DATA] = ACTIONS(87),
    [anon_sym_JS8] = ACTIONS(87),
    [anon_sym_cw] = ACTIONS(87),
    [anon_sym_ssb] = ACTIONS(87),
    [anon_sym_fm] = ACTIONS(87),
    [anon_sym_am] = ACTIONS(87),
    [anon_sym_digi] = ACTIONS(87),
    [anon_sym_ft8] = ACTIONS(87),
    [anon_sym_ft4] = ACTIONS(87),
    [anon_sym_psk] = ACTIONS(87),
    [anon_sym_rtty] = ACTIONS(87),
    [anon_sym_varac] = ACTIONS(87),
    [anon_sym_mfsk] = ACTIONS(87),
    [anon_sym_data] = ACTIONS(87),
    [anon_sym_js8] = ACTIONS(87),
    [sym_time] = ACTIONS(90),
    [sym_callsign] = ACTIONS(93),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(96),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(98),
    [aux_sym_header_token2] = ACTIONS(98),
    [aux_sym_header_token3] = ACTIONS(98),
    [aux_sym_header_token4] = ACTIONS(98),
    [aux_sym_header_token5] = ACTIONS(98),
    [aux_sym_header_token6] = ACTIONS(98),
    [aux_sym_header_token7] = ACTIONS(98),
    [aux_sym_header_token8] = ACTIONS(98),
    [aux_sym_date_command_token1] = ACTIONS(98),
    [aux_sym_day_command_token1] = ACTIONS(98),
    [aux_sym_band_token1] = ACTIONS(98),
    [aux_sym_band_token2] = ACTIONS(98),
    [anon_sym_CW] = ACTIONS(98),
    [anon_sym_SSB] = ACTIONS(98),
    [anon_sym_FM] = ACTIONS(98),
    [anon_sym_AM] = ACTIONS(98),
    [anon_sym_DIGI] = ACTIONS(98),
    [anon_sym_FT8] = ACTIONS(98),
    [anon_sym_FT4] = ACTIONS(98),
    [anon_sym_PSK] = ACTIONS(98),
    [anon_sym_RTTY] = ACTIONS(98),
    [anon_sym_VARAC] = ACTIONS(98),
    [anon_sym_MFSK] = ACTIONS(98),
    [anon_sym_DATA] = ACTIONS(98),
    [anon_sym_JS8] = ACTIONS(98),
    [anon_sym_cw] = ACTIONS(98),
    [anon_sym_ssb] = ACTIONS(98),
    [anon_sym_fm] = ACTIONS(98),
    [anon_sym_am] = ACTIONS(98),
    [anon_sym_digi] = ACTIONS(98),
    [anon_sym_ft8] = ACTIONS(98),
    [anon_sym_ft4] = ACTIONS(98),
    [anon_sym_psk] = ACTIONS(98),
    [anon_sym_rtty] = ACTIONS(98),
    [anon_sym_varac] = ACTIONS(98),
    [anon_sym_mfsk] = ACTIONS(98),
    [anon_sym_data] = ACTIONS(98),
    [anon_sym_js8] = ACTIONS(98),
    [sym_time] = ACTIONS(98),
    [sym_callsign] = ACTIONS(98),
    [aux_sym_rst_sent_token1] = ACTIONS(98),
    [anon_sym_POUND] = ACTIONS(98),
    [anon_sym_AT] = ACTIONS(96),
    [anon_sym_LBRACK] = ACTIONS(96),
    [anon_sym_LT] = ACTIONS(96),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(100),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(102),
    [aux_sym_header_token2] = ACTIONS(102),
    [aux_sym_header_token3] = ACTIONS(102),
    [aux_sym_header_token4] = ACTIONS(102),
    [aux_sym_header_token5] = ACTIONS(102),
    [aux_sym_header_token6] = ACTIONS(102),
    [aux_sym_header_token7] = ACTIONS(102),
    [aux_sym_header_token8] = ACTIONS(102),
    [aux_sym_date_command_token1] = ACTIONS(102),
    [aux_sym_day_command_token1] = ACTIONS(102),
    [aux_sym_band_token1] = ACTIONS(102),
    [aux_sym_band_token2] = ACTIONS(102),
    [anon_sym_CW] = ACTIONS(102),
    [anon_sym_SSB] = ACTIONS(102),
    [anon_sym_FM] = ACTIONS(102),
    [anon_sym_AM] = ACTIONS(102),
    [anon_sym_DIGI] = ACTIONS(102),
    [anon_sym_FT8] = ACTIONS(102),
    [anon_sym_FT4] = ACTIONS(102),
    [anon_sym_PSK] = ACTIONS(102),
    [anon_sym_RTTY] = ACTIONS(102),
    [anon_sym_VARAC] = ACTIONS(102),
    [anon_sym_MFSK] = ACTIONS(102),
    [anon_sym_DATA] = ACTIONS(102),
    [anon_sym_JS8] = ACTIONS(102),
    [anon_sym_cw] = ACTIONS(102),
    [anon_sym_ssb] = ACTIONS(102),
    [anon_sym_fm] = ACTIONS(102),
    [anon_sym_am] = ACTIONS(102),
    [anon_sym_digi] = ACTIONS(102),
    [anon_sym_ft8] = ACTIONS(102),
    [anon_sym_ft4] = ACTIONS(102),
    [anon_sym_psk] = ACTIONS(102),
    [anon_sym_rtty] = ACTIONS(102),
    [anon_sym_varac] = ACTIONS(102),
    [anon_sym_mfsk] = ACTIONS(102),
    [anon_sym_data] = ACTIONS(102),
    [anon_sym_js8] = ACTIONS(102),
    [sym_time] = ACTIONS(102),
    [sym_callsign] = ACTIONS(102),
    [anon_sym_POUND] = ACTIONS(102),
    [anon_sym_AT] = ACTIONS(100),
    [anon_sym_LBRACK] = ACTIONS(100),
    [anon_sym_LT] = ACTIONS(100),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(104),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(106),
    [aux_sym_header_token2] = ACTIONS(106),
    [aux_sym_header_token3] = ACTIONS(106),
    [aux_sym_header_token4] = ACTIONS(106),
    [aux_sym_header_token5] = ACTIONS(106),
    [aux_sym_header_token6] = ACTIONS(106),
    [aux_sym_header_token7] = ACTIONS(106),
    [aux_sym_header_token8] = ACTIONS(106),
    [aux_sym_date_command_token1] = ACTIONS(106),
    [aux_sym_day_command_token1] = ACTIONS(106),
    [aux_sym_band_token1] = ACTIONS(106),
    [aux_sym_band_token2] = ACTIONS(106),
    [anon_sym_CW] = ACTIONS(106),
    [anon_sym_SSB] = ACTIONS(106),
    [anon_sym_FM] = ACTIONS(106),
    [anon_sym_AM] = ACTIONS(106),
    [anon_sym_DIGI] = ACTIONS(106),
    [anon_sym_FT8] = ACTIONS(106),
    [anon_sym_FT4] = ACTIONS(106),
    [anon_sym_PSK] = ACTIONS(106),
    [anon_sym_RTTY] = ACTIONS(106),
    [anon_sym_VARAC] = ACTIONS(106),
    [anon_sym_MFSK] = ACTIONS(106),
    [anon_sym_DATA] = ACTIONS(106),
    [anon_sym_JS8] = ACTIONS(106),
    [anon_sym_cw] = ACTIONS(106),
    [anon_sym_ssb] = ACTIONS(106),
    [anon_sym_fm] = ACTIONS(106),
    [anon_sym_am] = ACTIONS(106),
    [anon_sym_digi] = ACTIONS(106),
    [anon_sym_ft8] = ACTIONS(106),
    [anon_sym_ft4] = ACTIONS(106),
    [anon_sym_psk] = ACTIONS(106),
    [anon_sym_rtty] = ACTIONS(106),
    [anon_sym_varac] = ACTIONS(106),
    [anon_sym_mfsk] = ACTIONS(106),
    [anon_sym_data] = ACTIONS(106),
    [anon_sym_js8] = ACTIONS(106),
    [sym_time] = ACTIONS(106),
    [sym_callsign] = ACTIONS(106),
    [anon_sym_POUND] = ACTIONS(106),
    [anon_sym_AT] = ACTIONS(104),
    [anon_sym_LBRACK] = ACTIONS(104),
    [anon_sym_LT] = ACTIONS(104),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(108),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(110),
    [aux_sym_header_token2] = ACTIONS(110),
    [aux_sym_header_token3] = ACTIONS(110),
    [aux_sym_header_token4] = ACTIONS(110),
    [aux_sym_header_token5] = ACTIONS(110),
    [aux_sym_header_token6] = ACTIONS(110),
    [aux_sym_header_token7] = ACTIONS(110),
    [aux_sym_header_token8] = ACTIONS(110),
    [aux_sym_date_command_token1] = ACTIONS(110),
    [aux_sym_day_command_token1] = ACTIONS(110),
    [aux_sym_band_token1] = ACTIONS(110),
    [aux_sym_band_token2] = ACTIONS(110),
    [anon_sym_CW] = ACTIONS(110),
    [anon_sym_SSB] = ACTIONS(110),
    [anon_sym_FM] = ACTIONS(110),
    [anon_sym_AM] = ACTIONS(110),
    [anon_sym_DIGI] = ACTIONS(110),
    [anon_sym_FT8] = ACTIONS(110),
    [anon_sym_FT4] = ACTIONS(110),
    [anon_sym_PSK] = ACTIONS(110),
    [anon_sym_RTTY] = ACTIONS(110),
    [anon_sym_VARAC] = ACTIONS(110),
    [anon_sym_MFSK] = ACTIONS(110),
    [anon_sym_DATA] = ACTIONS(110),
    [anon_sym_JS8] = ACTIONS(110),
    [anon_sym_cw] = ACTIONS(110),
    [anon_sym_ssb] = ACTIONS(110),
    [anon_sym_fm] = ACTIONS(110),
    [anon_sym_am] = ACTIONS(110),
    [anon_sym_digi] = ACTIONS(110),
    [anon_sym_ft8] = ACTIONS(110),
    [anon_sym_ft4] = ACTIONS(110),
    [anon_sym_psk] = ACTIONS(110),
    [anon_sym_rtty] = ACTIONS(110),
    [anon_sym_varac] = ACTIONS(110),
    [anon_sym_mfsk] = ACTIONS(110),
    [anon_sym_data] = ACTIONS(110),
    [anon_sym_js8] = ACTIONS(110),
    [sym_time] = ACTIONS(110),
    [sym_callsign] = ACTIONS(110),
    [anon_sym_POUND] = ACTIONS(110),
    [anon_sym_AT] = ACTIONS(108),
    [anon_sym_LBRACK] = ACTIONS(108),
    [anon_sym_LT] = ACTIONS(108),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(112),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(114),
    [aux_sym_header_token2] = ACTIONS(114),
    [aux_sym_header_token3] = ACTIONS(114),
    [aux_sym_header_token4] = ACTIONS(114),
    [aux_sym_header_token5] = ACTIONS(114),
    [aux_sym_header_token6] = ACTIONS(114),
    [aux_sym_header_token7] = ACTIONS(114),
    [aux_sym_header_token8] = ACTIONS(114),
    [aux_sym_date_command_token1] = ACTIONS(114),
    [aux_sym_day_command_token1] = ACTIONS(114),
    [aux_sym_band_token1] = ACTIONS(114),
    [aux_sym_band_token2] = ACTIONS(114),
    [anon_sym_CW] = ACTIONS(114),
    [anon_sym_SSB] = ACTIONS(114),
    [anon_sym_FM] = ACTIONS(114),
    [anon_sym_AM] = ACTIONS(114),
    [anon_sym_DIGI] = ACTIONS(114),
    [anon_sym_FT8] = ACTIONS(114),
    [anon_sym_FT4] = ACTIONS(114),
    [anon_sym_PSK] = ACTIONS(114),
    [anon_sym_RTTY] = ACTIONS(114),
    [anon_sym_VARAC] = ACTIONS(114),
    [anon_sym_MFSK] = ACTIONS(114),
    [anon_sym_DATA] = ACTIONS(114),
    [anon_sym_JS8] = ACTIONS(114),
    [anon_sym_cw] = ACTIONS(114),
    [anon_sym_ssb] = ACTIONS(114),
    [anon_sym_fm] = ACTIONS(114),
    [anon_sym_am] = ACTIONS(114),
    [anon_sym_digi] = ACTIONS(114),
    [anon_sym_ft8] = ACTIONS(114),
    [anon_sym_ft4] = ACTIONS(114),
    [anon_sym_psk] = ACTIONS(114),
    [anon_sym_rtty] = ACTIONS(114),
    [anon_sym_varac] = ACTIONS(114),
    [anon_sym_mfsk] = ACTIONS(114),
    [anon_sym_data] = ACTIONS(114),
    [anon_sym_js8] = ACTIONS(114),
    [sym_time] = ACTIONS(114),
    [sym_callsign] = ACTIONS(114),
    [anon_sym_POUND] = ACTIONS(114),
    [anon_sym_AT] = ACTIONS(112),
    [anon_sym_LBRACK] = ACTIONS(112),
    [anon_sym_LT] = ACTIONS(112),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(116),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(118),
    [aux_sym_header_token2] = ACTIONS(118),
    [aux_sym_header_token3] = ACTIONS(118),
    [aux_sym_header_token4] = ACTIONS(118),
    [aux_sym_header_token5] = ACTIONS(118),
    [aux_sym_header_token6] = ACTIONS(118),
    [aux_sym_header_token7] = ACTIONS(118),
    [aux_sym_header_token8] = ACTIONS(118),
    [aux_sym_date_command_token1] = ACTIONS(118),
    [aux_sym_day_command_token1] = ACTIONS(118),
    [aux_sym_band_token1] = ACTIONS(118),
    [aux_sym_band_token2] = ACTIONS(118),
    [anon_sym_CW] = ACTIONS(118),
    [anon_sym_SSB] = ACTIONS(118),
    [anon_sym_FM] = ACTIONS(118),
    [anon_sym_AM] = ACTIONS(118),
    [anon_sym_DIGI] = ACTIONS(118),
    [anon_sym_FT8] = ACTIONS(118),
    [anon_sym_FT4] = ACTIONS(118),
    [anon_sym_PSK] = ACTIONS(118),
    [anon_sym_RTTY] = ACTIONS(118),
    [anon_sym_VARAC] = ACTIONS(118),
    [anon_sym_MFSK] = ACTIONS(118),
    [anon_sym_DATA] = ACTIONS(118),
    [anon_sym_JS8] = ACTIONS(118),
    [anon_sym_cw] = ACTIONS(118),
    [anon_sym_ssb] = ACTIONS(118),
    [anon_sym_fm] = ACTIONS(118),
    [anon_sym_am] = ACTIONS(118),
    [anon_sym_digi] = ACTIONS(118),
    [anon_sym_ft8] = ACTIONS(118),
    [anon_sym_ft4] = ACTIONS(118),
    [anon_sym_psk] = ACTIONS(118),
    [anon_sym_rtty] = ACTIONS(118),
    [anon_sym_varac] = ACTIONS(118),
    [anon_sym_mfsk] = ACTIONS(118),
    [anon_sym_data] = ACTIONS(118),
    [anon_sym_js8] = ACTIONS(118),
    [sym_time] = ACTIONS(118),
    [sym_callsign] = ACTIONS(118),
    [anon_sym_POUND] = ACTIONS(118),
    [anon_sym_AT] = ACTIONS(116),
    [anon_sym_LBRACK] = ACTIONS(116),
    [anon_sym_LT] = ACTIONS(116),
  },
  [21] = {
    [ts_builtin_sym_end] = ACTIONS(120),
    [sym_comment] = ACTIONS(3),
    [aux_sym_header_token1] = ACTIONS(122),
    [aux_sym_header_token2] = ACTIONS(122),
    [aux_sym_header_token3] = ACTIONS(122),
    [aux_sym_header_token4] = ACTIONS(122),
    [aux_sym_header_token5] = ACTIONS(122),
    [aux_sym_header_token6] = ACTIONS(122),
    [aux_sym_header_token7] = ACTIONS(122),
    [aux_sym_header_token8] = ACTIONS(122),
    [aux_sym_date_command_token1] = ACTIONS(122),
    [aux_sym_day_command_token1] = ACTIONS(122),
    [aux_sym_band_token1] = ACTIONS(122),
    [aux_sym_band_token2] = ACTIONS(122),
    [anon_sym_CW] = ACTIONS(122),
    [anon_sym_SSB] = ACTIONS(122),
    [anon_sym_FM] = ACTIONS(122),
    [anon_sym_AM] = ACTIONS(122),
    [anon_sym_DIGI] = ACTIONS(122),
    [anon_sym_FT8] = ACTIONS(122),
    [anon_sym_FT4] = ACTIONS(122),
    [anon_sym_PSK] = ACTIONS(122),
    [anon_sym_RTTY] = ACTIONS(122),
    [anon_sym_VARAC] = ACTIONS(122),
    [anon_sym_MFSK] = ACTIONS(122),
    [anon_sym_DATA] = ACTIONS(122),
    [anon_sym_JS8] = ACTIONS(122),
    [anon_sym_cw] = ACTIONS(122),
    [anon_sym_ssb] = ACTIONS(122),
    [anon_sym_fm] = ACTIONS(122),
    [anon_sym_am] = ACTIONS(122),
    [anon_sym_digi] = ACTIONS(122),
    [anon_sym_ft8] = ACTIONS(122),
    [anon_sym_ft4] = ACTIONS(122),
    [anon_sym_psk] = ACTIONS(122),
    [anon_sym_rtty] = ACTIONS(122),
    [anon_sym_varac] = ACTIONS(122),
    [anon_sym_mfsk] = ACTIONS(122),
    [anon_sym_data] = ACTIONS(122),
    [anon_sym_js8] = ACTIONS(122),
    [sym_time] = ACTIONS(122),
    [sym_callsign] = ACTIONS(122),
    [anon_sym_POUND] = ACTIONS(122),
    [anon_sym_AT] = ACTIONS(120),
    [anon_sym_LBRACK] = ACTIONS(120),
    [anon_sym_LT] = ACTIONS(120),
  },
  [22] = {
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [aux_sym_band_mode_line_repeat1] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(124),
    [sym_comment] = ACTIONS(7),
    [aux_sym_header_token1] = ACTIONS(126),
    [aux_sym_header_token2] = ACTIONS(126),
    [aux_sym_header_token3] = ACTIONS(126),
    [aux_sym_header_token4] = ACTIONS(126),
    [aux_sym_header_token5] = ACTIONS(126),
    [aux_sym_header_token6] = ACTIONS(126),
    [aux_sym_header_token7] = ACTIONS(126),
    [aux_sym_header_token8] = ACTIONS(126),
    [aux_sym_date_command_token1] = ACTIONS(126),
    [aux_sym_day_command_token1] = ACTIONS(126),
    [aux_sym_band_token1] = ACTIONS(128),
    [aux_sym_band_token2] = ACTIONS(128),
    [anon_sym_CW] = ACTIONS(131),
    [anon_sym_SSB] = ACTIONS(131),
    [anon_sym_FM] = ACTIONS(131),
    [anon_sym_AM] = ACTIONS(131),
    [anon_sym_DIGI] = ACTIONS(131),
    [anon_sym_FT8] = ACTIONS(131),
    [anon_sym_FT4] = ACTIONS(131),
    [anon_sym_PSK] = ACTIONS(131),
    [anon_sym_RTTY] = ACTIONS(131),
    [anon_sym_VARAC] = ACTIONS(131),
    [anon_sym_MFSK] = ACTIONS(131),
    [anon_sym_DATA] = ACTIONS(131),
    [anon_sym_JS8] = ACTIONS(131),
    [anon_sym_cw] = ACTIONS(131),
    [anon_sym_ssb] = ACTIONS(131),
    [anon_sym_fm] = ACTIONS(131),
    [anon_sym_am] = ACTIONS(131),
    [anon_sym_digi] = ACTIONS(131),
    [anon_sym_ft8] = ACTIONS(131),
    [anon_sym_ft4] = ACTIONS(131),
    [anon_sym_psk] = ACTIONS(131),
    [anon_sym_rtty] = ACTIONS(131),
    [anon_sym_varac] = ACTIONS(131),
    [anon_sym_mfsk] = ACTIONS(131),
    [anon_sym_data] = ACTIONS(131),
    [anon_sym_js8] = ACTIONS(131),
    [sym_time] = ACTIONS(126),
    [sym_callsign] = ACTIONS(126),
  },
  [23] = {
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [aux_sym_band_mode_line_repeat1] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(134),
    [sym_comment] = ACTIONS(7),
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
  },
  [24] = {
    [ts_builtin_sym_end] = ACTIONS(138),
    [sym_comment] = ACTIONS(7),
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
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(142),
    [sym_comment] = ACTIONS(7),
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
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(146),
    [sym_comment] = ACTIONS(7),
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
    [aux_sym_band_token1] = ACTIONS(148),
    [aux_sym_band_token2] = ACTIONS(148),
    [anon_sym_CW] = ACTIONS(148),
    [anon_sym_SSB] = ACTIONS(148),
    [anon_sym_FM] = ACTIONS(148),
    [anon_sym_AM] = ACTIONS(148),
    [anon_sym_DIGI] = ACTIONS(148),
    [anon_sym_FT8] = ACTIONS(148),
    [anon_sym_FT4] = ACTIONS(148),
    [anon_sym_PSK] = ACTIONS(148),
    [anon_sym_RTTY] = ACTIONS(148),
    [anon_sym_VARAC] = ACTIONS(148),
    [anon_sym_MFSK] = ACTIONS(148),
    [anon_sym_DATA] = ACTIONS(148),
    [anon_sym_JS8] = ACTIONS(148),
    [anon_sym_cw] = ACTIONS(148),
    [anon_sym_ssb] = ACTIONS(148),
    [anon_sym_fm] = ACTIONS(148),
    [anon_sym_am] = ACTIONS(148),
    [anon_sym_digi] = ACTIONS(148),
    [anon_sym_ft8] = ACTIONS(148),
    [anon_sym_ft4] = ACTIONS(148),
    [anon_sym_psk] = ACTIONS(148),
    [anon_sym_rtty] = ACTIONS(148),
    [anon_sym_varac] = ACTIONS(148),
    [anon_sym_mfsk] = ACTIONS(148),
    [anon_sym_data] = ACTIONS(148),
    [anon_sym_js8] = ACTIONS(148),
    [sym_time] = ACTIONS(148),
    [sym_callsign] = ACTIONS(148),
  },
  [27] = {
    [ts_builtin_sym_end] = ACTIONS(150),
    [sym_comment] = ACTIONS(7),
    [aux_sym_header_token1] = ACTIONS(152),
    [aux_sym_header_token2] = ACTIONS(152),
    [aux_sym_header_token3] = ACTIONS(152),
    [aux_sym_header_token4] = ACTIONS(152),
    [aux_sym_header_token5] = ACTIONS(152),
    [aux_sym_header_token6] = ACTIONS(152),
    [aux_sym_header_token7] = ACTIONS(152),
    [aux_sym_header_token8] = ACTIONS(152),
    [aux_sym_date_command_token1] = ACTIONS(152),
    [aux_sym_day_command_token1] = ACTIONS(152),
    [aux_sym_band_token1] = ACTIONS(152),
    [aux_sym_band_token2] = ACTIONS(152),
    [anon_sym_CW] = ACTIONS(152),
    [anon_sym_SSB] = ACTIONS(152),
    [anon_sym_FM] = ACTIONS(152),
    [anon_sym_AM] = ACTIONS(152),
    [anon_sym_DIGI] = ACTIONS(152),
    [anon_sym_FT8] = ACTIONS(152),
    [anon_sym_FT4] = ACTIONS(152),
    [anon_sym_PSK] = ACTIONS(152),
    [anon_sym_RTTY] = ACTIONS(152),
    [anon_sym_VARAC] = ACTIONS(152),
    [anon_sym_MFSK] = ACTIONS(152),
    [anon_sym_DATA] = ACTIONS(152),
    [anon_sym_JS8] = ACTIONS(152),
    [anon_sym_cw] = ACTIONS(152),
    [anon_sym_ssb] = ACTIONS(152),
    [anon_sym_fm] = ACTIONS(152),
    [anon_sym_am] = ACTIONS(152),
    [anon_sym_digi] = ACTIONS(152),
    [anon_sym_ft8] = ACTIONS(152),
    [anon_sym_ft4] = ACTIONS(152),
    [anon_sym_psk] = ACTIONS(152),
    [anon_sym_rtty] = ACTIONS(152),
    [anon_sym_varac] = ACTIONS(152),
    [anon_sym_mfsk] = ACTIONS(152),
    [anon_sym_data] = ACTIONS(152),
    [anon_sym_js8] = ACTIONS(152),
    [sym_time] = ACTIONS(152),
    [sym_callsign] = ACTIONS(152),
  },
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(154),
    [sym_comment] = ACTIONS(7),
    [aux_sym_header_token1] = ACTIONS(156),
    [aux_sym_header_token2] = ACTIONS(156),
    [aux_sym_header_token3] = ACTIONS(156),
    [aux_sym_header_token4] = ACTIONS(156),
    [aux_sym_header_token5] = ACTIONS(156),
    [aux_sym_header_token6] = ACTIONS(156),
    [aux_sym_header_token7] = ACTIONS(156),
    [aux_sym_header_token8] = ACTIONS(156),
    [aux_sym_date_command_token1] = ACTIONS(156),
    [aux_sym_day_command_token1] = ACTIONS(156),
    [aux_sym_band_token1] = ACTIONS(156),
    [aux_sym_band_token2] = ACTIONS(156),
    [anon_sym_CW] = ACTIONS(156),
    [anon_sym_SSB] = ACTIONS(156),
    [anon_sym_FM] = ACTIONS(156),
    [anon_sym_AM] = ACTIONS(156),
    [anon_sym_DIGI] = ACTIONS(156),
    [anon_sym_FT8] = ACTIONS(156),
    [anon_sym_FT4] = ACTIONS(156),
    [anon_sym_PSK] = ACTIONS(156),
    [anon_sym_RTTY] = ACTIONS(156),
    [anon_sym_VARAC] = ACTIONS(156),
    [anon_sym_MFSK] = ACTIONS(156),
    [anon_sym_DATA] = ACTIONS(156),
    [anon_sym_JS8] = ACTIONS(156),
    [anon_sym_cw] = ACTIONS(156),
    [anon_sym_ssb] = ACTIONS(156),
    [anon_sym_fm] = ACTIONS(156),
    [anon_sym_am] = ACTIONS(156),
    [anon_sym_digi] = ACTIONS(156),
    [anon_sym_ft8] = ACTIONS(156),
    [anon_sym_ft4] = ACTIONS(156),
    [anon_sym_psk] = ACTIONS(156),
    [anon_sym_rtty] = ACTIONS(156),
    [anon_sym_varac] = ACTIONS(156),
    [anon_sym_mfsk] = ACTIONS(156),
    [anon_sym_data] = ACTIONS(156),
    [anon_sym_js8] = ACTIONS(156),
    [sym_time] = ACTIONS(156),
    [sym_callsign] = ACTIONS(156),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 1,
      aux_sym_qsl_info_token1,
  [7] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(160), 1,
      anon_sym_RBRACK,
  [14] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(162), 1,
      anon_sym_GT,
  [21] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(164), 1,
      sym_header_value,
  [28] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(166), 1,
      aux_sym_inline_comment_token1,
  [35] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(168), 1,
      aux_sym_name_token1,
  [42] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(170), 1,
      aux_sym_grid_token1,
  [49] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(172), 1,
      ts_builtin_sym_end,
  [56] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_callsign,
  [63] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(176), 1,
      sym_day_value,
  [70] = 2,
    ACTIONS(7), 1,
      sym_comment,
    ACTIONS(178), 1,
      sym_date_value,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(29)] = 0,
  [SMALL_STATE(30)] = 7,
  [SMALL_STATE(31)] = 14,
  [SMALL_STATE(32)] = 21,
  [SMALL_STATE(33)] = 28,
  [SMALL_STATE(34)] = 35,
  [SMALL_STATE(35)] = 42,
  [SMALL_STATE(36)] = 49,
  [SMALL_STATE(37)] = 56,
  [SMALL_STATE(38)] = 63,
  [SMALL_STATE(39)] = 70,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 1),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 3),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 2),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 2),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 4),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 4),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(35),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(34),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(33),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(29),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 5),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 5),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(32),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(39),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(38),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(25),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(37),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst_sent, 1),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst_sent, 1),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_extra, 1),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_extra, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 2),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name, 2),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst_rcvd, 1),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst_rcvd, 1),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_comment, 3),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_comment, 3),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qsl_info, 3),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qsl_info, 3),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid, 2),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid, 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(25),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(26),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 1),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 1),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day_command, 2),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_day_command, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band, 1),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band, 1),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mode, 1),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mode, 1),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_command, 2),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_command, 2),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 2),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 2),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [172] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
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
