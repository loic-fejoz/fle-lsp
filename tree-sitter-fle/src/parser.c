#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 41
#define LARGE_STATE_COUNT 30
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
  [40] = 40,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      if (lookahead == '#') ADVANCE(158);
      if (lookahead == '+') ADVANCE(34);
      if (lookahead == '<') ADVANCE(166);
      if (lookahead == '>') ADVANCE(169);
      if (lookahead == '@') ADVANCE(160);
      if (lookahead == 'A') ADVANCE(85);
      if (lookahead == 'C') ADVANCE(96);
      if (lookahead == 'D') ADVANCE(73);
      if (lookahead == 'F') ADVANCE(86);
      if (lookahead == 'J') ADVANCE(88);
      if (lookahead == 'M') ADVANCE(80);
      if (lookahead == 'P') ADVANCE(89);
      if (lookahead == 'R') ADVANCE(94);
      if (lookahead == 'S') ADVANCE(90);
      if (lookahead == 'V') ADVANCE(75);
      if (lookahead == '[') ADVANCE(162);
      if (lookahead == ']') ADVANCE(165);
      if (lookahead == 'a') ADVANCE(108);
      if (lookahead == 'c') ADVANCE(117);
      if (lookahead == 'd') ADVANCE(74);
      if (lookahead == 'f') ADVANCE(109);
      if (lookahead == 'j') ADVANCE(113);
      if (lookahead == 'm') ADVANCE(103);
      if (lookahead == 'p') ADVANCE(111);
      if (lookahead == 'r') ADVANCE(116);
      if (lookahead == 's') ADVANCE(112);
      if (lookahead == 'v') ADVANCE(98);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(133);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(146);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(150);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(18);
      END_STATE();
    case 3:
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(3)
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 4:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(35);
      END_STATE();
    case 5:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(168);
      END_STATE();
    case 6:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(164);
      END_STATE();
    case 7:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (lookahead != 0) ADVANCE(161);
      END_STATE();
    case 8:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 9:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9)
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 10:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(2);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(1);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_header_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_header_token2);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_header_token3);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_header_token4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_header_token5);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_header_token6);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_header_token7);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_header_token8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '\t' ||
          lookahead == 11 ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          (lookahead < '\n' || '\r' < lookahead)) ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_date_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_date_value);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_day_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_day_value);
      if (lookahead == '+') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_band_token1);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_band_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_band_token2);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(4);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_CW);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_SSB);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_FM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_AM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_DIGI);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_FT8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_FT4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_PSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_RTTY);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_VARAC);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_MFSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_DATA);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_JS8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_cw);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_ssb);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_fm);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_am);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_digi);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_ft8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_ft4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_psk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_rtty);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_varac);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_mfsk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_data);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_js8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(44);
      if (lookahead == '8') ADVANCE(43);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(57);
      if (lookahead == '8') ADVANCE(56);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(50);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(63);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(92);
      if (lookahead == 'I') ADVANCE(81);
      if (lookahead == 'a') ADVANCE(152);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(152);
      if (lookahead == 'a') ADVANCE(95);
      if (lookahead == 'i') ADVANCE(104);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(87);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(49);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(79);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'B') ADVANCE(39);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C') ADVANCE(47);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F') ADVANCE(91);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(124);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G') ADVANCE(82);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I') ADVANCE(42);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(45);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(48);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(41);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(40);
      if (lookahead == 'T') ADVANCE(69);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R') ADVANCE(77);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(71);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(83);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(78);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(84);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(76);
      if (lookahead == 't') ADVANCE(127);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(33);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(97);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(93);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(127);
      if (lookahead == 't') ADVANCE(99);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(33);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'Y') ADVANCE(46);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(110);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(62);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(102);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'b') ADVANCE(52);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'c') ADVANCE(60);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'f') ADVANCE(114);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(124);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'g') ADVANCE(105);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'i') ADVANCE(55);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(58);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(61);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(54);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(53);
      if (lookahead == 't') ADVANCE(70);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'r') ADVANCE(100);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(106);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(101);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(72);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(107);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(118);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(115);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'w') ADVANCE(51);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'y') ADVANCE(59);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(27);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(153);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(141);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(121);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(148);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(143);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(145);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(156);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(135);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(22);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(24);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(149);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(26);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(130);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(25);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(125);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(126);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(142);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(21);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(140);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(36);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(151);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(128);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(123);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(154);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(147);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(155);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(129);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(23);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(122);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(137);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(132);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(127);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(33);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(144);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(119);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(120);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(131);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_callsign);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(20);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_name_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(161);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(164);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(164);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(168);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(168);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
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
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 5},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 9},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 10},
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
    [sym_source_file] = STATE(37),
    [sym_header] = STATE(13),
    [sym_date_command] = STATE(13),
    [sym_day_command] = STATE(13),
    [sym_band_mode_line] = STATE(13),
    [sym_band] = STATE(24),
    [sym_mode] = STATE(24),
    [sym_qso_line] = STATE(13),
    [aux_sym_source_file_repeat1] = STATE(13),
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
    [sym_rst_sent] = STATE(4),
    [sym_qso_extra] = STATE(7),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_comment] = ACTIONS(21),
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
    [aux_sym_rst_sent_token1] = ACTIONS(25),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [3] = {
    [sym_rst_rcvd] = STATE(8),
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(35),
    [aux_sym_header_token1] = ACTIONS(37),
    [aux_sym_header_token2] = ACTIONS(37),
    [aux_sym_header_token3] = ACTIONS(37),
    [aux_sym_header_token4] = ACTIONS(37),
    [aux_sym_header_token5] = ACTIONS(37),
    [aux_sym_header_token6] = ACTIONS(37),
    [aux_sym_header_token7] = ACTIONS(37),
    [aux_sym_header_token8] = ACTIONS(37),
    [aux_sym_date_command_token1] = ACTIONS(37),
    [aux_sym_day_command_token1] = ACTIONS(37),
    [aux_sym_band_token1] = ACTIONS(37),
    [aux_sym_band_token2] = ACTIONS(37),
    [anon_sym_CW] = ACTIONS(37),
    [anon_sym_SSB] = ACTIONS(37),
    [anon_sym_FM] = ACTIONS(37),
    [anon_sym_AM] = ACTIONS(37),
    [anon_sym_DIGI] = ACTIONS(37),
    [anon_sym_FT8] = ACTIONS(37),
    [anon_sym_FT4] = ACTIONS(37),
    [anon_sym_PSK] = ACTIONS(37),
    [anon_sym_RTTY] = ACTIONS(37),
    [anon_sym_VARAC] = ACTIONS(37),
    [anon_sym_MFSK] = ACTIONS(37),
    [anon_sym_DATA] = ACTIONS(37),
    [anon_sym_JS8] = ACTIONS(37),
    [anon_sym_cw] = ACTIONS(37),
    [anon_sym_ssb] = ACTIONS(37),
    [anon_sym_fm] = ACTIONS(37),
    [anon_sym_am] = ACTIONS(37),
    [anon_sym_digi] = ACTIONS(37),
    [anon_sym_ft8] = ACTIONS(37),
    [anon_sym_ft4] = ACTIONS(37),
    [anon_sym_psk] = ACTIONS(37),
    [anon_sym_rtty] = ACTIONS(37),
    [anon_sym_varac] = ACTIONS(37),
    [anon_sym_mfsk] = ACTIONS(37),
    [anon_sym_data] = ACTIONS(37),
    [anon_sym_js8] = ACTIONS(37),
    [sym_time] = ACTIONS(37),
    [sym_callsign] = ACTIONS(37),
    [aux_sym_rst_sent_token1] = ACTIONS(39),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [4] = {
    [sym_rst_rcvd] = STATE(12),
    [sym_qso_extra] = STATE(9),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_comment] = ACTIONS(41),
    [aux_sym_header_token1] = ACTIONS(43),
    [aux_sym_header_token2] = ACTIONS(43),
    [aux_sym_header_token3] = ACTIONS(43),
    [aux_sym_header_token4] = ACTIONS(43),
    [aux_sym_header_token5] = ACTIONS(43),
    [aux_sym_header_token6] = ACTIONS(43),
    [aux_sym_header_token7] = ACTIONS(43),
    [aux_sym_header_token8] = ACTIONS(43),
    [aux_sym_date_command_token1] = ACTIONS(43),
    [aux_sym_day_command_token1] = ACTIONS(43),
    [aux_sym_band_token1] = ACTIONS(43),
    [aux_sym_band_token2] = ACTIONS(43),
    [anon_sym_CW] = ACTIONS(43),
    [anon_sym_SSB] = ACTIONS(43),
    [anon_sym_FM] = ACTIONS(43),
    [anon_sym_AM] = ACTIONS(43),
    [anon_sym_DIGI] = ACTIONS(43),
    [anon_sym_FT8] = ACTIONS(43),
    [anon_sym_FT4] = ACTIONS(43),
    [anon_sym_PSK] = ACTIONS(43),
    [anon_sym_RTTY] = ACTIONS(43),
    [anon_sym_VARAC] = ACTIONS(43),
    [anon_sym_MFSK] = ACTIONS(43),
    [anon_sym_DATA] = ACTIONS(43),
    [anon_sym_JS8] = ACTIONS(43),
    [anon_sym_cw] = ACTIONS(43),
    [anon_sym_ssb] = ACTIONS(43),
    [anon_sym_fm] = ACTIONS(43),
    [anon_sym_am] = ACTIONS(43),
    [anon_sym_digi] = ACTIONS(43),
    [anon_sym_ft8] = ACTIONS(43),
    [anon_sym_ft4] = ACTIONS(43),
    [anon_sym_psk] = ACTIONS(43),
    [anon_sym_rtty] = ACTIONS(43),
    [anon_sym_varac] = ACTIONS(43),
    [anon_sym_mfsk] = ACTIONS(43),
    [anon_sym_data] = ACTIONS(43),
    [anon_sym_js8] = ACTIONS(43),
    [sym_time] = ACTIONS(43),
    [sym_callsign] = ACTIONS(43),
    [aux_sym_rst_sent_token1] = ACTIONS(39),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [5] = {
    [sym_rst_sent] = STATE(3),
    [sym_qso_extra] = STATE(9),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_comment] = ACTIONS(41),
    [aux_sym_header_token1] = ACTIONS(43),
    [aux_sym_header_token2] = ACTIONS(43),
    [aux_sym_header_token3] = ACTIONS(43),
    [aux_sym_header_token4] = ACTIONS(43),
    [aux_sym_header_token5] = ACTIONS(43),
    [aux_sym_header_token6] = ACTIONS(43),
    [aux_sym_header_token7] = ACTIONS(43),
    [aux_sym_header_token8] = ACTIONS(43),
    [aux_sym_date_command_token1] = ACTIONS(43),
    [aux_sym_day_command_token1] = ACTIONS(43),
    [aux_sym_band_token1] = ACTIONS(43),
    [aux_sym_band_token2] = ACTIONS(43),
    [anon_sym_CW] = ACTIONS(43),
    [anon_sym_SSB] = ACTIONS(43),
    [anon_sym_FM] = ACTIONS(43),
    [anon_sym_AM] = ACTIONS(43),
    [anon_sym_DIGI] = ACTIONS(43),
    [anon_sym_FT8] = ACTIONS(43),
    [anon_sym_FT4] = ACTIONS(43),
    [anon_sym_PSK] = ACTIONS(43),
    [anon_sym_RTTY] = ACTIONS(43),
    [anon_sym_VARAC] = ACTIONS(43),
    [anon_sym_MFSK] = ACTIONS(43),
    [anon_sym_DATA] = ACTIONS(43),
    [anon_sym_JS8] = ACTIONS(43),
    [anon_sym_cw] = ACTIONS(43),
    [anon_sym_ssb] = ACTIONS(43),
    [anon_sym_fm] = ACTIONS(43),
    [anon_sym_am] = ACTIONS(43),
    [anon_sym_digi] = ACTIONS(43),
    [anon_sym_ft8] = ACTIONS(43),
    [anon_sym_ft4] = ACTIONS(43),
    [anon_sym_psk] = ACTIONS(43),
    [anon_sym_rtty] = ACTIONS(43),
    [anon_sym_varac] = ACTIONS(43),
    [anon_sym_mfsk] = ACTIONS(43),
    [anon_sym_data] = ACTIONS(43),
    [anon_sym_js8] = ACTIONS(43),
    [sym_time] = ACTIONS(43),
    [sym_callsign] = ACTIONS(43),
    [aux_sym_rst_sent_token1] = ACTIONS(25),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [6] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_comment] = ACTIONS(45),
    [aux_sym_header_token1] = ACTIONS(47),
    [aux_sym_header_token2] = ACTIONS(47),
    [aux_sym_header_token3] = ACTIONS(47),
    [aux_sym_header_token4] = ACTIONS(47),
    [aux_sym_header_token5] = ACTIONS(47),
    [aux_sym_header_token6] = ACTIONS(47),
    [aux_sym_header_token7] = ACTIONS(47),
    [aux_sym_header_token8] = ACTIONS(47),
    [aux_sym_date_command_token1] = ACTIONS(47),
    [aux_sym_day_command_token1] = ACTIONS(47),
    [aux_sym_band_token1] = ACTIONS(47),
    [aux_sym_band_token2] = ACTIONS(47),
    [anon_sym_CW] = ACTIONS(47),
    [anon_sym_SSB] = ACTIONS(47),
    [anon_sym_FM] = ACTIONS(47),
    [anon_sym_AM] = ACTIONS(47),
    [anon_sym_DIGI] = ACTIONS(47),
    [anon_sym_FT8] = ACTIONS(47),
    [anon_sym_FT4] = ACTIONS(47),
    [anon_sym_PSK] = ACTIONS(47),
    [anon_sym_RTTY] = ACTIONS(47),
    [anon_sym_VARAC] = ACTIONS(47),
    [anon_sym_MFSK] = ACTIONS(47),
    [anon_sym_DATA] = ACTIONS(47),
    [anon_sym_JS8] = ACTIONS(47),
    [anon_sym_cw] = ACTIONS(47),
    [anon_sym_ssb] = ACTIONS(47),
    [anon_sym_fm] = ACTIONS(47),
    [anon_sym_am] = ACTIONS(47),
    [anon_sym_digi] = ACTIONS(47),
    [anon_sym_ft8] = ACTIONS(47),
    [anon_sym_ft4] = ACTIONS(47),
    [anon_sym_psk] = ACTIONS(47),
    [anon_sym_rtty] = ACTIONS(47),
    [anon_sym_varac] = ACTIONS(47),
    [anon_sym_mfsk] = ACTIONS(47),
    [anon_sym_data] = ACTIONS(47),
    [anon_sym_js8] = ACTIONS(47),
    [sym_time] = ACTIONS(47),
    [sym_callsign] = ACTIONS(47),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [7] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_comment] = ACTIONS(41),
    [aux_sym_header_token1] = ACTIONS(43),
    [aux_sym_header_token2] = ACTIONS(43),
    [aux_sym_header_token3] = ACTIONS(43),
    [aux_sym_header_token4] = ACTIONS(43),
    [aux_sym_header_token5] = ACTIONS(43),
    [aux_sym_header_token6] = ACTIONS(43),
    [aux_sym_header_token7] = ACTIONS(43),
    [aux_sym_header_token8] = ACTIONS(43),
    [aux_sym_date_command_token1] = ACTIONS(43),
    [aux_sym_day_command_token1] = ACTIONS(43),
    [aux_sym_band_token1] = ACTIONS(43),
    [aux_sym_band_token2] = ACTIONS(43),
    [anon_sym_CW] = ACTIONS(43),
    [anon_sym_SSB] = ACTIONS(43),
    [anon_sym_FM] = ACTIONS(43),
    [anon_sym_AM] = ACTIONS(43),
    [anon_sym_DIGI] = ACTIONS(43),
    [anon_sym_FT8] = ACTIONS(43),
    [anon_sym_FT4] = ACTIONS(43),
    [anon_sym_PSK] = ACTIONS(43),
    [anon_sym_RTTY] = ACTIONS(43),
    [anon_sym_VARAC] = ACTIONS(43),
    [anon_sym_MFSK] = ACTIONS(43),
    [anon_sym_DATA] = ACTIONS(43),
    [anon_sym_JS8] = ACTIONS(43),
    [anon_sym_cw] = ACTIONS(43),
    [anon_sym_ssb] = ACTIONS(43),
    [anon_sym_fm] = ACTIONS(43),
    [anon_sym_am] = ACTIONS(43),
    [anon_sym_digi] = ACTIONS(43),
    [anon_sym_ft8] = ACTIONS(43),
    [anon_sym_ft4] = ACTIONS(43),
    [anon_sym_psk] = ACTIONS(43),
    [anon_sym_rtty] = ACTIONS(43),
    [anon_sym_varac] = ACTIONS(43),
    [anon_sym_mfsk] = ACTIONS(43),
    [anon_sym_data] = ACTIONS(43),
    [anon_sym_js8] = ACTIONS(43),
    [sym_time] = ACTIONS(43),
    [sym_callsign] = ACTIONS(43),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [8] = {
    [sym_qso_extra] = STATE(10),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_comment] = ACTIONS(45),
    [aux_sym_header_token1] = ACTIONS(47),
    [aux_sym_header_token2] = ACTIONS(47),
    [aux_sym_header_token3] = ACTIONS(47),
    [aux_sym_header_token4] = ACTIONS(47),
    [aux_sym_header_token5] = ACTIONS(47),
    [aux_sym_header_token6] = ACTIONS(47),
    [aux_sym_header_token7] = ACTIONS(47),
    [aux_sym_header_token8] = ACTIONS(47),
    [aux_sym_date_command_token1] = ACTIONS(47),
    [aux_sym_day_command_token1] = ACTIONS(47),
    [aux_sym_band_token1] = ACTIONS(47),
    [aux_sym_band_token2] = ACTIONS(47),
    [anon_sym_CW] = ACTIONS(47),
    [anon_sym_SSB] = ACTIONS(47),
    [anon_sym_FM] = ACTIONS(47),
    [anon_sym_AM] = ACTIONS(47),
    [anon_sym_DIGI] = ACTIONS(47),
    [anon_sym_FT8] = ACTIONS(47),
    [anon_sym_FT4] = ACTIONS(47),
    [anon_sym_PSK] = ACTIONS(47),
    [anon_sym_RTTY] = ACTIONS(47),
    [anon_sym_VARAC] = ACTIONS(47),
    [anon_sym_MFSK] = ACTIONS(47),
    [anon_sym_DATA] = ACTIONS(47),
    [anon_sym_JS8] = ACTIONS(47),
    [anon_sym_cw] = ACTIONS(47),
    [anon_sym_ssb] = ACTIONS(47),
    [anon_sym_fm] = ACTIONS(47),
    [anon_sym_am] = ACTIONS(47),
    [anon_sym_digi] = ACTIONS(47),
    [anon_sym_ft8] = ACTIONS(47),
    [anon_sym_ft4] = ACTIONS(47),
    [anon_sym_psk] = ACTIONS(47),
    [anon_sym_rtty] = ACTIONS(47),
    [anon_sym_varac] = ACTIONS(47),
    [anon_sym_mfsk] = ACTIONS(47),
    [anon_sym_data] = ACTIONS(47),
    [anon_sym_js8] = ACTIONS(47),
    [sym_time] = ACTIONS(47),
    [sym_callsign] = ACTIONS(47),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [9] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(35),
    [aux_sym_header_token1] = ACTIONS(37),
    [aux_sym_header_token2] = ACTIONS(37),
    [aux_sym_header_token3] = ACTIONS(37),
    [aux_sym_header_token4] = ACTIONS(37),
    [aux_sym_header_token5] = ACTIONS(37),
    [aux_sym_header_token6] = ACTIONS(37),
    [aux_sym_header_token7] = ACTIONS(37),
    [aux_sym_header_token8] = ACTIONS(37),
    [aux_sym_date_command_token1] = ACTIONS(37),
    [aux_sym_day_command_token1] = ACTIONS(37),
    [aux_sym_band_token1] = ACTIONS(37),
    [aux_sym_band_token2] = ACTIONS(37),
    [anon_sym_CW] = ACTIONS(37),
    [anon_sym_SSB] = ACTIONS(37),
    [anon_sym_FM] = ACTIONS(37),
    [anon_sym_AM] = ACTIONS(37),
    [anon_sym_DIGI] = ACTIONS(37),
    [anon_sym_FT8] = ACTIONS(37),
    [anon_sym_FT4] = ACTIONS(37),
    [anon_sym_PSK] = ACTIONS(37),
    [anon_sym_RTTY] = ACTIONS(37),
    [anon_sym_VARAC] = ACTIONS(37),
    [anon_sym_MFSK] = ACTIONS(37),
    [anon_sym_DATA] = ACTIONS(37),
    [anon_sym_JS8] = ACTIONS(37),
    [anon_sym_cw] = ACTIONS(37),
    [anon_sym_ssb] = ACTIONS(37),
    [anon_sym_fm] = ACTIONS(37),
    [anon_sym_am] = ACTIONS(37),
    [anon_sym_digi] = ACTIONS(37),
    [anon_sym_ft8] = ACTIONS(37),
    [anon_sym_ft4] = ACTIONS(37),
    [anon_sym_psk] = ACTIONS(37),
    [anon_sym_rtty] = ACTIONS(37),
    [anon_sym_varac] = ACTIONS(37),
    [anon_sym_mfsk] = ACTIONS(37),
    [anon_sym_data] = ACTIONS(37),
    [anon_sym_js8] = ACTIONS(37),
    [sym_time] = ACTIONS(37),
    [sym_callsign] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [10] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_comment] = ACTIONS(49),
    [aux_sym_header_token1] = ACTIONS(51),
    [aux_sym_header_token2] = ACTIONS(51),
    [aux_sym_header_token3] = ACTIONS(51),
    [aux_sym_header_token4] = ACTIONS(51),
    [aux_sym_header_token5] = ACTIONS(51),
    [aux_sym_header_token6] = ACTIONS(51),
    [aux_sym_header_token7] = ACTIONS(51),
    [aux_sym_header_token8] = ACTIONS(51),
    [aux_sym_date_command_token1] = ACTIONS(51),
    [aux_sym_day_command_token1] = ACTIONS(51),
    [aux_sym_band_token1] = ACTIONS(51),
    [aux_sym_band_token2] = ACTIONS(51),
    [anon_sym_CW] = ACTIONS(51),
    [anon_sym_SSB] = ACTIONS(51),
    [anon_sym_FM] = ACTIONS(51),
    [anon_sym_AM] = ACTIONS(51),
    [anon_sym_DIGI] = ACTIONS(51),
    [anon_sym_FT8] = ACTIONS(51),
    [anon_sym_FT4] = ACTIONS(51),
    [anon_sym_PSK] = ACTIONS(51),
    [anon_sym_RTTY] = ACTIONS(51),
    [anon_sym_VARAC] = ACTIONS(51),
    [anon_sym_MFSK] = ACTIONS(51),
    [anon_sym_DATA] = ACTIONS(51),
    [anon_sym_JS8] = ACTIONS(51),
    [anon_sym_cw] = ACTIONS(51),
    [anon_sym_ssb] = ACTIONS(51),
    [anon_sym_fm] = ACTIONS(51),
    [anon_sym_am] = ACTIONS(51),
    [anon_sym_digi] = ACTIONS(51),
    [anon_sym_ft8] = ACTIONS(51),
    [anon_sym_ft4] = ACTIONS(51),
    [anon_sym_psk] = ACTIONS(51),
    [anon_sym_rtty] = ACTIONS(51),
    [anon_sym_varac] = ACTIONS(51),
    [anon_sym_mfsk] = ACTIONS(51),
    [anon_sym_data] = ACTIONS(51),
    [anon_sym_js8] = ACTIONS(51),
    [sym_time] = ACTIONS(51),
    [sym_callsign] = ACTIONS(51),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [11] = {
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(53),
    [sym_comment] = ACTIONS(53),
    [aux_sym_header_token1] = ACTIONS(55),
    [aux_sym_header_token2] = ACTIONS(55),
    [aux_sym_header_token3] = ACTIONS(55),
    [aux_sym_header_token4] = ACTIONS(55),
    [aux_sym_header_token5] = ACTIONS(55),
    [aux_sym_header_token6] = ACTIONS(55),
    [aux_sym_header_token7] = ACTIONS(55),
    [aux_sym_header_token8] = ACTIONS(55),
    [aux_sym_date_command_token1] = ACTIONS(55),
    [aux_sym_day_command_token1] = ACTIONS(55),
    [aux_sym_band_token1] = ACTIONS(55),
    [aux_sym_band_token2] = ACTIONS(55),
    [anon_sym_CW] = ACTIONS(55),
    [anon_sym_SSB] = ACTIONS(55),
    [anon_sym_FM] = ACTIONS(55),
    [anon_sym_AM] = ACTIONS(55),
    [anon_sym_DIGI] = ACTIONS(55),
    [anon_sym_FT8] = ACTIONS(55),
    [anon_sym_FT4] = ACTIONS(55),
    [anon_sym_PSK] = ACTIONS(55),
    [anon_sym_RTTY] = ACTIONS(55),
    [anon_sym_VARAC] = ACTIONS(55),
    [anon_sym_MFSK] = ACTIONS(55),
    [anon_sym_DATA] = ACTIONS(55),
    [anon_sym_JS8] = ACTIONS(55),
    [anon_sym_cw] = ACTIONS(55),
    [anon_sym_ssb] = ACTIONS(55),
    [anon_sym_fm] = ACTIONS(55),
    [anon_sym_am] = ACTIONS(55),
    [anon_sym_digi] = ACTIONS(55),
    [anon_sym_ft8] = ACTIONS(55),
    [anon_sym_ft4] = ACTIONS(55),
    [anon_sym_psk] = ACTIONS(55),
    [anon_sym_rtty] = ACTIONS(55),
    [anon_sym_varac] = ACTIONS(55),
    [anon_sym_mfsk] = ACTIONS(55),
    [anon_sym_data] = ACTIONS(55),
    [anon_sym_js8] = ACTIONS(55),
    [sym_time] = ACTIONS(55),
    [sym_callsign] = ACTIONS(55),
    [anon_sym_POUND] = ACTIONS(57),
    [anon_sym_AT] = ACTIONS(60),
    [anon_sym_LBRACK] = ACTIONS(63),
    [anon_sym_LT] = ACTIONS(66),
  },
  [12] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(21),
    [sym_name] = STATE(21),
    [sym_inline_comment] = STATE(21),
    [sym_qsl_info] = STATE(21),
    [aux_sym_qso_line_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(35),
    [aux_sym_header_token1] = ACTIONS(37),
    [aux_sym_header_token2] = ACTIONS(37),
    [aux_sym_header_token3] = ACTIONS(37),
    [aux_sym_header_token4] = ACTIONS(37),
    [aux_sym_header_token5] = ACTIONS(37),
    [aux_sym_header_token6] = ACTIONS(37),
    [aux_sym_header_token7] = ACTIONS(37),
    [aux_sym_header_token8] = ACTIONS(37),
    [aux_sym_date_command_token1] = ACTIONS(37),
    [aux_sym_day_command_token1] = ACTIONS(37),
    [aux_sym_band_token1] = ACTIONS(37),
    [aux_sym_band_token2] = ACTIONS(37),
    [anon_sym_CW] = ACTIONS(37),
    [anon_sym_SSB] = ACTIONS(37),
    [anon_sym_FM] = ACTIONS(37),
    [anon_sym_AM] = ACTIONS(37),
    [anon_sym_DIGI] = ACTIONS(37),
    [anon_sym_FT8] = ACTIONS(37),
    [anon_sym_FT4] = ACTIONS(37),
    [anon_sym_PSK] = ACTIONS(37),
    [anon_sym_RTTY] = ACTIONS(37),
    [anon_sym_VARAC] = ACTIONS(37),
    [anon_sym_MFSK] = ACTIONS(37),
    [anon_sym_DATA] = ACTIONS(37),
    [anon_sym_JS8] = ACTIONS(37),
    [anon_sym_cw] = ACTIONS(37),
    [anon_sym_ssb] = ACTIONS(37),
    [anon_sym_fm] = ACTIONS(37),
    [anon_sym_am] = ACTIONS(37),
    [anon_sym_digi] = ACTIONS(37),
    [anon_sym_ft8] = ACTIONS(37),
    [anon_sym_ft4] = ACTIONS(37),
    [anon_sym_psk] = ACTIONS(37),
    [anon_sym_rtty] = ACTIONS(37),
    [anon_sym_varac] = ACTIONS(37),
    [anon_sym_mfsk] = ACTIONS(37),
    [anon_sym_data] = ACTIONS(37),
    [anon_sym_js8] = ACTIONS(37),
    [sym_time] = ACTIONS(37),
    [sym_callsign] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [13] = {
    [sym_header] = STATE(14),
    [sym_date_command] = STATE(14),
    [sym_day_command] = STATE(14),
    [sym_band_mode_line] = STATE(14),
    [sym_band] = STATE(24),
    [sym_mode] = STATE(24),
    [sym_qso_line] = STATE(14),
    [aux_sym_source_file_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(69),
    [sym_comment] = ACTIONS(71),
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
  [14] = {
    [sym_header] = STATE(14),
    [sym_date_command] = STATE(14),
    [sym_day_command] = STATE(14),
    [sym_band_mode_line] = STATE(14),
    [sym_band] = STATE(24),
    [sym_mode] = STATE(24),
    [sym_qso_line] = STATE(14),
    [aux_sym_source_file_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(73),
    [sym_comment] = ACTIONS(75),
    [aux_sym_header_token1] = ACTIONS(78),
    [aux_sym_header_token2] = ACTIONS(78),
    [aux_sym_header_token3] = ACTIONS(78),
    [aux_sym_header_token4] = ACTIONS(78),
    [aux_sym_header_token5] = ACTIONS(78),
    [aux_sym_header_token6] = ACTIONS(78),
    [aux_sym_header_token7] = ACTIONS(78),
    [aux_sym_header_token8] = ACTIONS(78),
    [aux_sym_date_command_token1] = ACTIONS(81),
    [aux_sym_day_command_token1] = ACTIONS(84),
    [aux_sym_band_token1] = ACTIONS(87),
    [aux_sym_band_token2] = ACTIONS(87),
    [anon_sym_CW] = ACTIONS(90),
    [anon_sym_SSB] = ACTIONS(90),
    [anon_sym_FM] = ACTIONS(90),
    [anon_sym_AM] = ACTIONS(90),
    [anon_sym_DIGI] = ACTIONS(90),
    [anon_sym_FT8] = ACTIONS(90),
    [anon_sym_FT4] = ACTIONS(90),
    [anon_sym_PSK] = ACTIONS(90),
    [anon_sym_RTTY] = ACTIONS(90),
    [anon_sym_VARAC] = ACTIONS(90),
    [anon_sym_MFSK] = ACTIONS(90),
    [anon_sym_DATA] = ACTIONS(90),
    [anon_sym_JS8] = ACTIONS(90),
    [anon_sym_cw] = ACTIONS(90),
    [anon_sym_ssb] = ACTIONS(90),
    [anon_sym_fm] = ACTIONS(90),
    [anon_sym_am] = ACTIONS(90),
    [anon_sym_digi] = ACTIONS(90),
    [anon_sym_ft8] = ACTIONS(90),
    [anon_sym_ft4] = ACTIONS(90),
    [anon_sym_psk] = ACTIONS(90),
    [anon_sym_rtty] = ACTIONS(90),
    [anon_sym_varac] = ACTIONS(90),
    [anon_sym_mfsk] = ACTIONS(90),
    [anon_sym_data] = ACTIONS(90),
    [anon_sym_js8] = ACTIONS(90),
    [sym_time] = ACTIONS(93),
    [sym_callsign] = ACTIONS(96),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(99),
    [sym_comment] = ACTIONS(99),
    [aux_sym_header_token1] = ACTIONS(101),
    [aux_sym_header_token2] = ACTIONS(101),
    [aux_sym_header_token3] = ACTIONS(101),
    [aux_sym_header_token4] = ACTIONS(101),
    [aux_sym_header_token5] = ACTIONS(101),
    [aux_sym_header_token6] = ACTIONS(101),
    [aux_sym_header_token7] = ACTIONS(101),
    [aux_sym_header_token8] = ACTIONS(101),
    [aux_sym_date_command_token1] = ACTIONS(101),
    [aux_sym_day_command_token1] = ACTIONS(101),
    [aux_sym_band_token1] = ACTIONS(101),
    [aux_sym_band_token2] = ACTIONS(101),
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
    [sym_time] = ACTIONS(101),
    [sym_callsign] = ACTIONS(101),
    [aux_sym_rst_sent_token1] = ACTIONS(101),
    [anon_sym_POUND] = ACTIONS(101),
    [anon_sym_AT] = ACTIONS(99),
    [anon_sym_LBRACK] = ACTIONS(99),
    [anon_sym_LT] = ACTIONS(99),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(103),
    [sym_comment] = ACTIONS(103),
    [aux_sym_header_token1] = ACTIONS(105),
    [aux_sym_header_token2] = ACTIONS(105),
    [aux_sym_header_token3] = ACTIONS(105),
    [aux_sym_header_token4] = ACTIONS(105),
    [aux_sym_header_token5] = ACTIONS(105),
    [aux_sym_header_token6] = ACTIONS(105),
    [aux_sym_header_token7] = ACTIONS(105),
    [aux_sym_header_token8] = ACTIONS(105),
    [aux_sym_date_command_token1] = ACTIONS(105),
    [aux_sym_day_command_token1] = ACTIONS(105),
    [aux_sym_band_token1] = ACTIONS(105),
    [aux_sym_band_token2] = ACTIONS(105),
    [anon_sym_CW] = ACTIONS(105),
    [anon_sym_SSB] = ACTIONS(105),
    [anon_sym_FM] = ACTIONS(105),
    [anon_sym_AM] = ACTIONS(105),
    [anon_sym_DIGI] = ACTIONS(105),
    [anon_sym_FT8] = ACTIONS(105),
    [anon_sym_FT4] = ACTIONS(105),
    [anon_sym_PSK] = ACTIONS(105),
    [anon_sym_RTTY] = ACTIONS(105),
    [anon_sym_VARAC] = ACTIONS(105),
    [anon_sym_MFSK] = ACTIONS(105),
    [anon_sym_DATA] = ACTIONS(105),
    [anon_sym_JS8] = ACTIONS(105),
    [anon_sym_cw] = ACTIONS(105),
    [anon_sym_ssb] = ACTIONS(105),
    [anon_sym_fm] = ACTIONS(105),
    [anon_sym_am] = ACTIONS(105),
    [anon_sym_digi] = ACTIONS(105),
    [anon_sym_ft8] = ACTIONS(105),
    [anon_sym_ft4] = ACTIONS(105),
    [anon_sym_psk] = ACTIONS(105),
    [anon_sym_rtty] = ACTIONS(105),
    [anon_sym_varac] = ACTIONS(105),
    [anon_sym_mfsk] = ACTIONS(105),
    [anon_sym_data] = ACTIONS(105),
    [anon_sym_js8] = ACTIONS(105),
    [sym_time] = ACTIONS(105),
    [sym_callsign] = ACTIONS(105),
    [anon_sym_POUND] = ACTIONS(105),
    [anon_sym_AT] = ACTIONS(103),
    [anon_sym_LBRACK] = ACTIONS(103),
    [anon_sym_LT] = ACTIONS(103),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(107),
    [sym_comment] = ACTIONS(107),
    [aux_sym_header_token1] = ACTIONS(109),
    [aux_sym_header_token2] = ACTIONS(109),
    [aux_sym_header_token3] = ACTIONS(109),
    [aux_sym_header_token4] = ACTIONS(109),
    [aux_sym_header_token5] = ACTIONS(109),
    [aux_sym_header_token6] = ACTIONS(109),
    [aux_sym_header_token7] = ACTIONS(109),
    [aux_sym_header_token8] = ACTIONS(109),
    [aux_sym_date_command_token1] = ACTIONS(109),
    [aux_sym_day_command_token1] = ACTIONS(109),
    [aux_sym_band_token1] = ACTIONS(109),
    [aux_sym_band_token2] = ACTIONS(109),
    [anon_sym_CW] = ACTIONS(109),
    [anon_sym_SSB] = ACTIONS(109),
    [anon_sym_FM] = ACTIONS(109),
    [anon_sym_AM] = ACTIONS(109),
    [anon_sym_DIGI] = ACTIONS(109),
    [anon_sym_FT8] = ACTIONS(109),
    [anon_sym_FT4] = ACTIONS(109),
    [anon_sym_PSK] = ACTIONS(109),
    [anon_sym_RTTY] = ACTIONS(109),
    [anon_sym_VARAC] = ACTIONS(109),
    [anon_sym_MFSK] = ACTIONS(109),
    [anon_sym_DATA] = ACTIONS(109),
    [anon_sym_JS8] = ACTIONS(109),
    [anon_sym_cw] = ACTIONS(109),
    [anon_sym_ssb] = ACTIONS(109),
    [anon_sym_fm] = ACTIONS(109),
    [anon_sym_am] = ACTIONS(109),
    [anon_sym_digi] = ACTIONS(109),
    [anon_sym_ft8] = ACTIONS(109),
    [anon_sym_ft4] = ACTIONS(109),
    [anon_sym_psk] = ACTIONS(109),
    [anon_sym_rtty] = ACTIONS(109),
    [anon_sym_varac] = ACTIONS(109),
    [anon_sym_mfsk] = ACTIONS(109),
    [anon_sym_data] = ACTIONS(109),
    [anon_sym_js8] = ACTIONS(109),
    [sym_time] = ACTIONS(109),
    [sym_callsign] = ACTIONS(109),
    [anon_sym_POUND] = ACTIONS(109),
    [anon_sym_AT] = ACTIONS(107),
    [anon_sym_LBRACK] = ACTIONS(107),
    [anon_sym_LT] = ACTIONS(107),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(111),
    [sym_comment] = ACTIONS(111),
    [aux_sym_header_token1] = ACTIONS(113),
    [aux_sym_header_token2] = ACTIONS(113),
    [aux_sym_header_token3] = ACTIONS(113),
    [aux_sym_header_token4] = ACTIONS(113),
    [aux_sym_header_token5] = ACTIONS(113),
    [aux_sym_header_token6] = ACTIONS(113),
    [aux_sym_header_token7] = ACTIONS(113),
    [aux_sym_header_token8] = ACTIONS(113),
    [aux_sym_date_command_token1] = ACTIONS(113),
    [aux_sym_day_command_token1] = ACTIONS(113),
    [aux_sym_band_token1] = ACTIONS(113),
    [aux_sym_band_token2] = ACTIONS(113),
    [anon_sym_CW] = ACTIONS(113),
    [anon_sym_SSB] = ACTIONS(113),
    [anon_sym_FM] = ACTIONS(113),
    [anon_sym_AM] = ACTIONS(113),
    [anon_sym_DIGI] = ACTIONS(113),
    [anon_sym_FT8] = ACTIONS(113),
    [anon_sym_FT4] = ACTIONS(113),
    [anon_sym_PSK] = ACTIONS(113),
    [anon_sym_RTTY] = ACTIONS(113),
    [anon_sym_VARAC] = ACTIONS(113),
    [anon_sym_MFSK] = ACTIONS(113),
    [anon_sym_DATA] = ACTIONS(113),
    [anon_sym_JS8] = ACTIONS(113),
    [anon_sym_cw] = ACTIONS(113),
    [anon_sym_ssb] = ACTIONS(113),
    [anon_sym_fm] = ACTIONS(113),
    [anon_sym_am] = ACTIONS(113),
    [anon_sym_digi] = ACTIONS(113),
    [anon_sym_ft8] = ACTIONS(113),
    [anon_sym_ft4] = ACTIONS(113),
    [anon_sym_psk] = ACTIONS(113),
    [anon_sym_rtty] = ACTIONS(113),
    [anon_sym_varac] = ACTIONS(113),
    [anon_sym_mfsk] = ACTIONS(113),
    [anon_sym_data] = ACTIONS(113),
    [anon_sym_js8] = ACTIONS(113),
    [sym_time] = ACTIONS(113),
    [sym_callsign] = ACTIONS(113),
    [anon_sym_POUND] = ACTIONS(113),
    [anon_sym_AT] = ACTIONS(111),
    [anon_sym_LBRACK] = ACTIONS(111),
    [anon_sym_LT] = ACTIONS(111),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(115),
    [sym_comment] = ACTIONS(115),
    [aux_sym_header_token1] = ACTIONS(117),
    [aux_sym_header_token2] = ACTIONS(117),
    [aux_sym_header_token3] = ACTIONS(117),
    [aux_sym_header_token4] = ACTIONS(117),
    [aux_sym_header_token5] = ACTIONS(117),
    [aux_sym_header_token6] = ACTIONS(117),
    [aux_sym_header_token7] = ACTIONS(117),
    [aux_sym_header_token8] = ACTIONS(117),
    [aux_sym_date_command_token1] = ACTIONS(117),
    [aux_sym_day_command_token1] = ACTIONS(117),
    [aux_sym_band_token1] = ACTIONS(117),
    [aux_sym_band_token2] = ACTIONS(117),
    [anon_sym_CW] = ACTIONS(117),
    [anon_sym_SSB] = ACTIONS(117),
    [anon_sym_FM] = ACTIONS(117),
    [anon_sym_AM] = ACTIONS(117),
    [anon_sym_DIGI] = ACTIONS(117),
    [anon_sym_FT8] = ACTIONS(117),
    [anon_sym_FT4] = ACTIONS(117),
    [anon_sym_PSK] = ACTIONS(117),
    [anon_sym_RTTY] = ACTIONS(117),
    [anon_sym_VARAC] = ACTIONS(117),
    [anon_sym_MFSK] = ACTIONS(117),
    [anon_sym_DATA] = ACTIONS(117),
    [anon_sym_JS8] = ACTIONS(117),
    [anon_sym_cw] = ACTIONS(117),
    [anon_sym_ssb] = ACTIONS(117),
    [anon_sym_fm] = ACTIONS(117),
    [anon_sym_am] = ACTIONS(117),
    [anon_sym_digi] = ACTIONS(117),
    [anon_sym_ft8] = ACTIONS(117),
    [anon_sym_ft4] = ACTIONS(117),
    [anon_sym_psk] = ACTIONS(117),
    [anon_sym_rtty] = ACTIONS(117),
    [anon_sym_varac] = ACTIONS(117),
    [anon_sym_mfsk] = ACTIONS(117),
    [anon_sym_data] = ACTIONS(117),
    [anon_sym_js8] = ACTIONS(117),
    [sym_time] = ACTIONS(117),
    [sym_callsign] = ACTIONS(117),
    [anon_sym_POUND] = ACTIONS(117),
    [anon_sym_AT] = ACTIONS(115),
    [anon_sym_LBRACK] = ACTIONS(115),
    [anon_sym_LT] = ACTIONS(115),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(119),
    [sym_comment] = ACTIONS(119),
    [aux_sym_header_token1] = ACTIONS(121),
    [aux_sym_header_token2] = ACTIONS(121),
    [aux_sym_header_token3] = ACTIONS(121),
    [aux_sym_header_token4] = ACTIONS(121),
    [aux_sym_header_token5] = ACTIONS(121),
    [aux_sym_header_token6] = ACTIONS(121),
    [aux_sym_header_token7] = ACTIONS(121),
    [aux_sym_header_token8] = ACTIONS(121),
    [aux_sym_date_command_token1] = ACTIONS(121),
    [aux_sym_day_command_token1] = ACTIONS(121),
    [aux_sym_band_token1] = ACTIONS(121),
    [aux_sym_band_token2] = ACTIONS(121),
    [anon_sym_CW] = ACTIONS(121),
    [anon_sym_SSB] = ACTIONS(121),
    [anon_sym_FM] = ACTIONS(121),
    [anon_sym_AM] = ACTIONS(121),
    [anon_sym_DIGI] = ACTIONS(121),
    [anon_sym_FT8] = ACTIONS(121),
    [anon_sym_FT4] = ACTIONS(121),
    [anon_sym_PSK] = ACTIONS(121),
    [anon_sym_RTTY] = ACTIONS(121),
    [anon_sym_VARAC] = ACTIONS(121),
    [anon_sym_MFSK] = ACTIONS(121),
    [anon_sym_DATA] = ACTIONS(121),
    [anon_sym_JS8] = ACTIONS(121),
    [anon_sym_cw] = ACTIONS(121),
    [anon_sym_ssb] = ACTIONS(121),
    [anon_sym_fm] = ACTIONS(121),
    [anon_sym_am] = ACTIONS(121),
    [anon_sym_digi] = ACTIONS(121),
    [anon_sym_ft8] = ACTIONS(121),
    [anon_sym_ft4] = ACTIONS(121),
    [anon_sym_psk] = ACTIONS(121),
    [anon_sym_rtty] = ACTIONS(121),
    [anon_sym_varac] = ACTIONS(121),
    [anon_sym_mfsk] = ACTIONS(121),
    [anon_sym_data] = ACTIONS(121),
    [anon_sym_js8] = ACTIONS(121),
    [sym_time] = ACTIONS(121),
    [sym_callsign] = ACTIONS(121),
    [anon_sym_POUND] = ACTIONS(121),
    [anon_sym_AT] = ACTIONS(119),
    [anon_sym_LBRACK] = ACTIONS(119),
    [anon_sym_LT] = ACTIONS(119),
  },
  [21] = {
    [ts_builtin_sym_end] = ACTIONS(123),
    [sym_comment] = ACTIONS(123),
    [aux_sym_header_token1] = ACTIONS(125),
    [aux_sym_header_token2] = ACTIONS(125),
    [aux_sym_header_token3] = ACTIONS(125),
    [aux_sym_header_token4] = ACTIONS(125),
    [aux_sym_header_token5] = ACTIONS(125),
    [aux_sym_header_token6] = ACTIONS(125),
    [aux_sym_header_token7] = ACTIONS(125),
    [aux_sym_header_token8] = ACTIONS(125),
    [aux_sym_date_command_token1] = ACTIONS(125),
    [aux_sym_day_command_token1] = ACTIONS(125),
    [aux_sym_band_token1] = ACTIONS(125),
    [aux_sym_band_token2] = ACTIONS(125),
    [anon_sym_CW] = ACTIONS(125),
    [anon_sym_SSB] = ACTIONS(125),
    [anon_sym_FM] = ACTIONS(125),
    [anon_sym_AM] = ACTIONS(125),
    [anon_sym_DIGI] = ACTIONS(125),
    [anon_sym_FT8] = ACTIONS(125),
    [anon_sym_FT4] = ACTIONS(125),
    [anon_sym_PSK] = ACTIONS(125),
    [anon_sym_RTTY] = ACTIONS(125),
    [anon_sym_VARAC] = ACTIONS(125),
    [anon_sym_MFSK] = ACTIONS(125),
    [anon_sym_DATA] = ACTIONS(125),
    [anon_sym_JS8] = ACTIONS(125),
    [anon_sym_cw] = ACTIONS(125),
    [anon_sym_ssb] = ACTIONS(125),
    [anon_sym_fm] = ACTIONS(125),
    [anon_sym_am] = ACTIONS(125),
    [anon_sym_digi] = ACTIONS(125),
    [anon_sym_ft8] = ACTIONS(125),
    [anon_sym_ft4] = ACTIONS(125),
    [anon_sym_psk] = ACTIONS(125),
    [anon_sym_rtty] = ACTIONS(125),
    [anon_sym_varac] = ACTIONS(125),
    [anon_sym_mfsk] = ACTIONS(125),
    [anon_sym_data] = ACTIONS(125),
    [anon_sym_js8] = ACTIONS(125),
    [sym_time] = ACTIONS(125),
    [sym_callsign] = ACTIONS(125),
    [anon_sym_POUND] = ACTIONS(125),
    [anon_sym_AT] = ACTIONS(123),
    [anon_sym_LBRACK] = ACTIONS(123),
    [anon_sym_LT] = ACTIONS(123),
  },
  [22] = {
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [aux_sym_band_mode_line_repeat1] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(127),
    [sym_comment] = ACTIONS(127),
    [aux_sym_header_token1] = ACTIONS(129),
    [aux_sym_header_token2] = ACTIONS(129),
    [aux_sym_header_token3] = ACTIONS(129),
    [aux_sym_header_token4] = ACTIONS(129),
    [aux_sym_header_token5] = ACTIONS(129),
    [aux_sym_header_token6] = ACTIONS(129),
    [aux_sym_header_token7] = ACTIONS(129),
    [aux_sym_header_token8] = ACTIONS(129),
    [aux_sym_date_command_token1] = ACTIONS(129),
    [aux_sym_day_command_token1] = ACTIONS(129),
    [aux_sym_band_token1] = ACTIONS(131),
    [aux_sym_band_token2] = ACTIONS(131),
    [anon_sym_CW] = ACTIONS(134),
    [anon_sym_SSB] = ACTIONS(134),
    [anon_sym_FM] = ACTIONS(134),
    [anon_sym_AM] = ACTIONS(134),
    [anon_sym_DIGI] = ACTIONS(134),
    [anon_sym_FT8] = ACTIONS(134),
    [anon_sym_FT4] = ACTIONS(134),
    [anon_sym_PSK] = ACTIONS(134),
    [anon_sym_RTTY] = ACTIONS(134),
    [anon_sym_VARAC] = ACTIONS(134),
    [anon_sym_MFSK] = ACTIONS(134),
    [anon_sym_DATA] = ACTIONS(134),
    [anon_sym_JS8] = ACTIONS(134),
    [anon_sym_cw] = ACTIONS(134),
    [anon_sym_ssb] = ACTIONS(134),
    [anon_sym_fm] = ACTIONS(134),
    [anon_sym_am] = ACTIONS(134),
    [anon_sym_digi] = ACTIONS(134),
    [anon_sym_ft8] = ACTIONS(134),
    [anon_sym_ft4] = ACTIONS(134),
    [anon_sym_psk] = ACTIONS(134),
    [anon_sym_rtty] = ACTIONS(134),
    [anon_sym_varac] = ACTIONS(134),
    [anon_sym_mfsk] = ACTIONS(134),
    [anon_sym_data] = ACTIONS(134),
    [anon_sym_js8] = ACTIONS(134),
    [sym_time] = ACTIONS(129),
    [sym_callsign] = ACTIONS(129),
  },
  [23] = {
    [sym_band] = STATE(22),
    [sym_mode] = STATE(22),
    [aux_sym_band_mode_line_repeat1] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(137),
    [sym_comment] = ACTIONS(137),
    [aux_sym_header_token1] = ACTIONS(139),
    [aux_sym_header_token2] = ACTIONS(139),
    [aux_sym_header_token3] = ACTIONS(139),
    [aux_sym_header_token4] = ACTIONS(139),
    [aux_sym_header_token5] = ACTIONS(139),
    [aux_sym_header_token6] = ACTIONS(139),
    [aux_sym_header_token7] = ACTIONS(139),
    [aux_sym_header_token8] = ACTIONS(139),
    [aux_sym_date_command_token1] = ACTIONS(139),
    [aux_sym_day_command_token1] = ACTIONS(139),
    [aux_sym_band_token1] = ACTIONS(139),
    [aux_sym_band_token2] = ACTIONS(139),
    [anon_sym_CW] = ACTIONS(139),
    [anon_sym_SSB] = ACTIONS(139),
    [anon_sym_FM] = ACTIONS(139),
    [anon_sym_AM] = ACTIONS(139),
    [anon_sym_DIGI] = ACTIONS(139),
    [anon_sym_FT8] = ACTIONS(139),
    [anon_sym_FT4] = ACTIONS(139),
    [anon_sym_PSK] = ACTIONS(139),
    [anon_sym_RTTY] = ACTIONS(139),
    [anon_sym_VARAC] = ACTIONS(139),
    [anon_sym_MFSK] = ACTIONS(139),
    [anon_sym_DATA] = ACTIONS(139),
    [anon_sym_JS8] = ACTIONS(139),
    [anon_sym_cw] = ACTIONS(139),
    [anon_sym_ssb] = ACTIONS(139),
    [anon_sym_fm] = ACTIONS(139),
    [anon_sym_am] = ACTIONS(139),
    [anon_sym_digi] = ACTIONS(139),
    [anon_sym_ft8] = ACTIONS(139),
    [anon_sym_ft4] = ACTIONS(139),
    [anon_sym_psk] = ACTIONS(139),
    [anon_sym_rtty] = ACTIONS(139),
    [anon_sym_varac] = ACTIONS(139),
    [anon_sym_mfsk] = ACTIONS(139),
    [anon_sym_data] = ACTIONS(139),
    [anon_sym_js8] = ACTIONS(139),
    [sym_time] = ACTIONS(139),
    [sym_callsign] = ACTIONS(139),
  },
  [24] = {
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
    [aux_sym_band_mode_line_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(141),
    [sym_comment] = ACTIONS(141),
    [aux_sym_header_token1] = ACTIONS(143),
    [aux_sym_header_token2] = ACTIONS(143),
    [aux_sym_header_token3] = ACTIONS(143),
    [aux_sym_header_token4] = ACTIONS(143),
    [aux_sym_header_token5] = ACTIONS(143),
    [aux_sym_header_token6] = ACTIONS(143),
    [aux_sym_header_token7] = ACTIONS(143),
    [aux_sym_header_token8] = ACTIONS(143),
    [aux_sym_date_command_token1] = ACTIONS(143),
    [aux_sym_day_command_token1] = ACTIONS(143),
    [aux_sym_band_token1] = ACTIONS(145),
    [aux_sym_band_token2] = ACTIONS(145),
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
    [sym_time] = ACTIONS(143),
    [sym_callsign] = ACTIONS(143),
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(151),
    [sym_comment] = ACTIONS(151),
    [aux_sym_header_token1] = ACTIONS(153),
    [aux_sym_header_token2] = ACTIONS(153),
    [aux_sym_header_token3] = ACTIONS(153),
    [aux_sym_header_token4] = ACTIONS(153),
    [aux_sym_header_token5] = ACTIONS(153),
    [aux_sym_header_token6] = ACTIONS(153),
    [aux_sym_header_token7] = ACTIONS(153),
    [aux_sym_header_token8] = ACTIONS(153),
    [aux_sym_date_command_token1] = ACTIONS(153),
    [aux_sym_day_command_token1] = ACTIONS(153),
    [aux_sym_band_token1] = ACTIONS(153),
    [aux_sym_band_token2] = ACTIONS(153),
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
    [sym_time] = ACTIONS(153),
    [sym_callsign] = ACTIONS(153),
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(155),
    [sym_comment] = ACTIONS(155),
    [aux_sym_header_token1] = ACTIONS(157),
    [aux_sym_header_token2] = ACTIONS(157),
    [aux_sym_header_token3] = ACTIONS(157),
    [aux_sym_header_token4] = ACTIONS(157),
    [aux_sym_header_token5] = ACTIONS(157),
    [aux_sym_header_token6] = ACTIONS(157),
    [aux_sym_header_token7] = ACTIONS(157),
    [aux_sym_header_token8] = ACTIONS(157),
    [aux_sym_date_command_token1] = ACTIONS(157),
    [aux_sym_day_command_token1] = ACTIONS(157),
    [aux_sym_band_token1] = ACTIONS(157),
    [aux_sym_band_token2] = ACTIONS(157),
    [anon_sym_CW] = ACTIONS(157),
    [anon_sym_SSB] = ACTIONS(157),
    [anon_sym_FM] = ACTIONS(157),
    [anon_sym_AM] = ACTIONS(157),
    [anon_sym_DIGI] = ACTIONS(157),
    [anon_sym_FT8] = ACTIONS(157),
    [anon_sym_FT4] = ACTIONS(157),
    [anon_sym_PSK] = ACTIONS(157),
    [anon_sym_RTTY] = ACTIONS(157),
    [anon_sym_VARAC] = ACTIONS(157),
    [anon_sym_MFSK] = ACTIONS(157),
    [anon_sym_DATA] = ACTIONS(157),
    [anon_sym_JS8] = ACTIONS(157),
    [anon_sym_cw] = ACTIONS(157),
    [anon_sym_ssb] = ACTIONS(157),
    [anon_sym_fm] = ACTIONS(157),
    [anon_sym_am] = ACTIONS(157),
    [anon_sym_digi] = ACTIONS(157),
    [anon_sym_ft8] = ACTIONS(157),
    [anon_sym_ft4] = ACTIONS(157),
    [anon_sym_psk] = ACTIONS(157),
    [anon_sym_rtty] = ACTIONS(157),
    [anon_sym_varac] = ACTIONS(157),
    [anon_sym_mfsk] = ACTIONS(157),
    [anon_sym_data] = ACTIONS(157),
    [anon_sym_js8] = ACTIONS(157),
    [sym_time] = ACTIONS(157),
    [sym_callsign] = ACTIONS(157),
  },
  [27] = {
    [ts_builtin_sym_end] = ACTIONS(159),
    [sym_comment] = ACTIONS(159),
    [aux_sym_header_token1] = ACTIONS(161),
    [aux_sym_header_token2] = ACTIONS(161),
    [aux_sym_header_token3] = ACTIONS(161),
    [aux_sym_header_token4] = ACTIONS(161),
    [aux_sym_header_token5] = ACTIONS(161),
    [aux_sym_header_token6] = ACTIONS(161),
    [aux_sym_header_token7] = ACTIONS(161),
    [aux_sym_header_token8] = ACTIONS(161),
    [aux_sym_date_command_token1] = ACTIONS(161),
    [aux_sym_day_command_token1] = ACTIONS(161),
    [aux_sym_band_token1] = ACTIONS(161),
    [aux_sym_band_token2] = ACTIONS(161),
    [anon_sym_CW] = ACTIONS(161),
    [anon_sym_SSB] = ACTIONS(161),
    [anon_sym_FM] = ACTIONS(161),
    [anon_sym_AM] = ACTIONS(161),
    [anon_sym_DIGI] = ACTIONS(161),
    [anon_sym_FT8] = ACTIONS(161),
    [anon_sym_FT4] = ACTIONS(161),
    [anon_sym_PSK] = ACTIONS(161),
    [anon_sym_RTTY] = ACTIONS(161),
    [anon_sym_VARAC] = ACTIONS(161),
    [anon_sym_MFSK] = ACTIONS(161),
    [anon_sym_DATA] = ACTIONS(161),
    [anon_sym_JS8] = ACTIONS(161),
    [anon_sym_cw] = ACTIONS(161),
    [anon_sym_ssb] = ACTIONS(161),
    [anon_sym_fm] = ACTIONS(161),
    [anon_sym_am] = ACTIONS(161),
    [anon_sym_digi] = ACTIONS(161),
    [anon_sym_ft8] = ACTIONS(161),
    [anon_sym_ft4] = ACTIONS(161),
    [anon_sym_psk] = ACTIONS(161),
    [anon_sym_rtty] = ACTIONS(161),
    [anon_sym_varac] = ACTIONS(161),
    [anon_sym_mfsk] = ACTIONS(161),
    [anon_sym_data] = ACTIONS(161),
    [anon_sym_js8] = ACTIONS(161),
    [sym_time] = ACTIONS(161),
    [sym_callsign] = ACTIONS(161),
  },
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(163),
    [sym_comment] = ACTIONS(163),
    [aux_sym_header_token1] = ACTIONS(165),
    [aux_sym_header_token2] = ACTIONS(165),
    [aux_sym_header_token3] = ACTIONS(165),
    [aux_sym_header_token4] = ACTIONS(165),
    [aux_sym_header_token5] = ACTIONS(165),
    [aux_sym_header_token6] = ACTIONS(165),
    [aux_sym_header_token7] = ACTIONS(165),
    [aux_sym_header_token8] = ACTIONS(165),
    [aux_sym_date_command_token1] = ACTIONS(165),
    [aux_sym_day_command_token1] = ACTIONS(165),
    [aux_sym_band_token1] = ACTIONS(165),
    [aux_sym_band_token2] = ACTIONS(165),
    [anon_sym_CW] = ACTIONS(165),
    [anon_sym_SSB] = ACTIONS(165),
    [anon_sym_FM] = ACTIONS(165),
    [anon_sym_AM] = ACTIONS(165),
    [anon_sym_DIGI] = ACTIONS(165),
    [anon_sym_FT8] = ACTIONS(165),
    [anon_sym_FT4] = ACTIONS(165),
    [anon_sym_PSK] = ACTIONS(165),
    [anon_sym_RTTY] = ACTIONS(165),
    [anon_sym_VARAC] = ACTIONS(165),
    [anon_sym_MFSK] = ACTIONS(165),
    [anon_sym_DATA] = ACTIONS(165),
    [anon_sym_JS8] = ACTIONS(165),
    [anon_sym_cw] = ACTIONS(165),
    [anon_sym_ssb] = ACTIONS(165),
    [anon_sym_fm] = ACTIONS(165),
    [anon_sym_am] = ACTIONS(165),
    [anon_sym_digi] = ACTIONS(165),
    [anon_sym_ft8] = ACTIONS(165),
    [anon_sym_ft4] = ACTIONS(165),
    [anon_sym_psk] = ACTIONS(165),
    [anon_sym_rtty] = ACTIONS(165),
    [anon_sym_varac] = ACTIONS(165),
    [anon_sym_mfsk] = ACTIONS(165),
    [anon_sym_data] = ACTIONS(165),
    [anon_sym_js8] = ACTIONS(165),
    [sym_time] = ACTIONS(165),
    [sym_callsign] = ACTIONS(165),
  },
  [29] = {
    [ts_builtin_sym_end] = ACTIONS(167),
    [sym_comment] = ACTIONS(167),
    [aux_sym_header_token1] = ACTIONS(169),
    [aux_sym_header_token2] = ACTIONS(169),
    [aux_sym_header_token3] = ACTIONS(169),
    [aux_sym_header_token4] = ACTIONS(169),
    [aux_sym_header_token5] = ACTIONS(169),
    [aux_sym_header_token6] = ACTIONS(169),
    [aux_sym_header_token7] = ACTIONS(169),
    [aux_sym_header_token8] = ACTIONS(169),
    [aux_sym_date_command_token1] = ACTIONS(169),
    [aux_sym_day_command_token1] = ACTIONS(169),
    [aux_sym_band_token1] = ACTIONS(169),
    [aux_sym_band_token2] = ACTIONS(169),
    [anon_sym_CW] = ACTIONS(169),
    [anon_sym_SSB] = ACTIONS(169),
    [anon_sym_FM] = ACTIONS(169),
    [anon_sym_AM] = ACTIONS(169),
    [anon_sym_DIGI] = ACTIONS(169),
    [anon_sym_FT8] = ACTIONS(169),
    [anon_sym_FT4] = ACTIONS(169),
    [anon_sym_PSK] = ACTIONS(169),
    [anon_sym_RTTY] = ACTIONS(169),
    [anon_sym_VARAC] = ACTIONS(169),
    [anon_sym_MFSK] = ACTIONS(169),
    [anon_sym_DATA] = ACTIONS(169),
    [anon_sym_JS8] = ACTIONS(169),
    [anon_sym_cw] = ACTIONS(169),
    [anon_sym_ssb] = ACTIONS(169),
    [anon_sym_fm] = ACTIONS(169),
    [anon_sym_am] = ACTIONS(169),
    [anon_sym_digi] = ACTIONS(169),
    [anon_sym_ft8] = ACTIONS(169),
    [anon_sym_ft4] = ACTIONS(169),
    [anon_sym_psk] = ACTIONS(169),
    [anon_sym_rtty] = ACTIONS(169),
    [anon_sym_varac] = ACTIONS(169),
    [anon_sym_mfsk] = ACTIONS(169),
    [anon_sym_data] = ACTIONS(169),
    [anon_sym_js8] = ACTIONS(169),
    [sym_time] = ACTIONS(169),
    [sym_callsign] = ACTIONS(169),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(171), 1,
      aux_sym_qsl_info_token1,
  [4] = 1,
    ACTIONS(173), 1,
      anon_sym_GT,
  [8] = 1,
    ACTIONS(175), 1,
      anon_sym_RBRACK,
  [12] = 1,
    ACTIONS(177), 1,
      sym_header_value,
  [16] = 1,
    ACTIONS(179), 1,
      aux_sym_inline_comment_token1,
  [20] = 1,
    ACTIONS(181), 1,
      aux_sym_name_token1,
  [24] = 1,
    ACTIONS(183), 1,
      aux_sym_grid_token1,
  [28] = 1,
    ACTIONS(185), 1,
      ts_builtin_sym_end,
  [32] = 1,
    ACTIONS(187), 1,
      sym_callsign,
  [36] = 1,
    ACTIONS(189), 1,
      sym_day_value,
  [40] = 1,
    ACTIONS(191), 1,
      sym_date_value,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(30)] = 0,
  [SMALL_STATE(31)] = 4,
  [SMALL_STATE(32)] = 8,
  [SMALL_STATE(33)] = 12,
  [SMALL_STATE(34)] = 16,
  [SMALL_STATE(35)] = 20,
  [SMALL_STATE(36)] = 24,
  [SMALL_STATE(37)] = 28,
  [SMALL_STATE(38)] = 32,
  [SMALL_STATE(39)] = 36,
  [SMALL_STATE(40)] = 40,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 1),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 3),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 3),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 2),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 2),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 4),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 4),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 5),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 5),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(36),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(35),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(34),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(30),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(33),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(40),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(39),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(25),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(38),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst_sent, 1),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst_sent, 1),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst_rcvd, 1),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst_rcvd, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 2),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name, 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid, 2),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qsl_info, 3),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qsl_info, 3),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_comment, 3),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_comment, 3),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_extra, 1),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_extra, 1),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(25),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(26),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 2),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 2),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 1),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 1),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 1), SHIFT(25),
  [148] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 1), SHIFT(26),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band, 1),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band, 1),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mode, 1),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mode, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day_command, 2),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_day_command, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_command, 2),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_command, 2),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 2),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 2),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [185] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
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
