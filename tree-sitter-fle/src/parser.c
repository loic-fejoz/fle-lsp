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
#define STATE_COUNT 43
#define LARGE_STATE_COUNT 32
#define SYMBOL_COUNT 77
#define ALIAS_COUNT 0
#define TOKEN_COUNT 58
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
  aux_sym_inline_hash_comment_token1 = 56,
  aux_sym_inline_hash_comment_token2 = 57,
  sym_source_file = 58,
  sym_header = 59,
  sym_date_command = 60,
  sym_day_command = 61,
  sym_band_mode_line = 62,
  sym_band = 63,
  sym_mode = 64,
  sym_qso_line = 65,
  sym_rst_sent = 66,
  sym_rst_rcvd = 67,
  sym_qso_extra = 68,
  sym_grid = 69,
  sym_name = 70,
  sym_inline_comment = 71,
  sym_qsl_info = 72,
  sym_inline_hash_comment = 73,
  aux_sym_source_file_repeat1 = 74,
  aux_sym_band_mode_line_repeat1 = 75,
  aux_sym_qso_line_repeat1 = 76,
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
  [sym_rst_sent] = "rst_sent",
  [sym_rst_rcvd] = "rst_rcvd",
  [sym_qso_extra] = "qso_extra",
  [sym_grid] = "grid",
  [sym_name] = "name",
  [sym_inline_comment] = "inline_comment",
  [sym_qsl_info] = "qsl_info",
  [sym_inline_hash_comment] = "comment",
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
  [sym_rst_sent] = sym_rst_sent,
  [sym_rst_rcvd] = sym_rst_rcvd,
  [sym_qso_extra] = sym_qso_extra,
  [sym_grid] = sym_grid,
  [sym_name] = sym_name,
  [sym_inline_comment] = sym_inline_comment,
  [sym_qsl_info] = sym_qsl_info,
  [sym_inline_hash_comment] = sym_comment,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(293);
      if (lookahead == '+') ADVANCE(139);
      if (lookahead == '<') ADVANCE(307);
      if (lookahead == '>') ADVANCE(310);
      if (lookahead == '@') ADVANCE(301);
      if (lookahead == 'A') ADVANCE(220);
      if (lookahead == 'C') ADVANCE(231);
      if (lookahead == 'D') ADVANCE(208);
      if (lookahead == 'F') ADVANCE(221);
      if (lookahead == 'J') ADVANCE(223);
      if (lookahead == 'M') ADVANCE(215);
      if (lookahead == 'P') ADVANCE(224);
      if (lookahead == 'R') ADVANCE(229);
      if (lookahead == 'S') ADVANCE(225);
      if (lookahead == 'V') ADVANCE(210);
      if (lookahead == '[') ADVANCE(303);
      if (lookahead == ']') ADVANCE(306);
      if (lookahead == 'a') ADVANCE(243);
      if (lookahead == 'c') ADVANCE(252);
      if (lookahead == 'd') ADVANCE(209);
      if (lookahead == 'f') ADVANCE(244);
      if (lookahead == 'j') ADVANCE(248);
      if (lookahead == 'm') ADVANCE(238);
      if (lookahead == 'p') ADVANCE(246);
      if (lookahead == 'r') ADVANCE(251);
      if (lookahead == 's') ADVANCE(247);
      if (lookahead == 'v') ADVANCE(233);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(268);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(281);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(285);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(201);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(13);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(311);
      if (('\n' <= lookahead && lookahead <= '\r')) SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 4:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(140);
      END_STATE();
    case 5:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(309);
      END_STATE();
    case 6:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(305);
      END_STATE();
    case 7:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (lookahead != 0) ADVANCE(302);
      END_STATE();
    case 8:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8)
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 9:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 10:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(2);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 13:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(11);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(1);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(300);
      END_STATE();
    case 19:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(293);
      if (lookahead == '<') ADVANCE(307);
      if (lookahead == '@') ADVANCE(301);
      if (lookahead == 'A') ADVANCE(220);
      if (lookahead == 'C') ADVANCE(231);
      if (lookahead == 'D') ADVANCE(208);
      if (lookahead == 'F') ADVANCE(221);
      if (lookahead == 'J') ADVANCE(223);
      if (lookahead == 'M') ADVANCE(215);
      if (lookahead == 'P') ADVANCE(224);
      if (lookahead == 'R') ADVANCE(229);
      if (lookahead == 'S') ADVANCE(225);
      if (lookahead == 'V') ADVANCE(210);
      if (lookahead == '[') ADVANCE(303);
      if (lookahead == 'a') ADVANCE(243);
      if (lookahead == 'c') ADVANCE(252);
      if (lookahead == 'd') ADVANCE(209);
      if (lookahead == 'f') ADVANCE(244);
      if (lookahead == 'j') ADVANCE(248);
      if (lookahead == 'm') ADVANCE(238);
      if (lookahead == 'p') ADVANCE(246);
      if (lookahead == 'r') ADVANCE(251);
      if (lookahead == 's') ADVANCE(247);
      if (lookahead == 'v') ADVANCE(233);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(268);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(281);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(285);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(203);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 20:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(24);
      if (lookahead == 'A') ADVANCE(220);
      if (lookahead == 'C') ADVANCE(231);
      if (lookahead == 'D') ADVANCE(208);
      if (lookahead == 'F') ADVANCE(221);
      if (lookahead == 'J') ADVANCE(223);
      if (lookahead == 'M') ADVANCE(215);
      if (lookahead == 'P') ADVANCE(224);
      if (lookahead == 'R') ADVANCE(229);
      if (lookahead == 'S') ADVANCE(225);
      if (lookahead == 'V') ADVANCE(210);
      if (lookahead == 'a') ADVANCE(243);
      if (lookahead == 'c') ADVANCE(252);
      if (lookahead == 'd') ADVANCE(209);
      if (lookahead == 'f') ADVANCE(244);
      if (lookahead == 'j') ADVANCE(248);
      if (lookahead == 'm') ADVANCE(238);
      if (lookahead == 'p') ADVANCE(246);
      if (lookahead == 'r') ADVANCE(251);
      if (lookahead == 's') ADVANCE(247);
      if (lookahead == 'v') ADVANCE(233);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(268);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(281);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(285);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(203);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == 'A') ADVANCE(59);
      if (lookahead == 'C') ADVANCE(70);
      if (lookahead == 'D') ADVANCE(47);
      if (lookahead == 'F') ADVANCE(60);
      if (lookahead == 'J') ADVANCE(62);
      if (lookahead == 'M') ADVANCE(54);
      if (lookahead == 'P') ADVANCE(63);
      if (lookahead == 'R') ADVANCE(68);
      if (lookahead == 'S') ADVANCE(64);
      if (lookahead == 'V') ADVANCE(49);
      if (lookahead == 'a') ADVANCE(82);
      if (lookahead == 'c') ADVANCE(91);
      if (lookahead == 'd') ADVANCE(48);
      if (lookahead == 'f') ADVANCE(83);
      if (lookahead == 'j') ADVANCE(87);
      if (lookahead == 'm') ADVANCE(77);
      if (lookahead == 'p') ADVANCE(85);
      if (lookahead == 'r') ADVANCE(90);
      if (lookahead == 's') ADVANCE(86);
      if (lookahead == 'v') ADVANCE(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(21)
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(108);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(122);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(126);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0) ADVANCE(135);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\r') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_header_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_header_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_header_token2);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_header_token2);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_header_token3);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_header_token3);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_header_token4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_header_token4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_header_token5);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_header_token5);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_header_token6);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_header_token6);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_header_token7);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_header_token7);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_header_token8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_header_token8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == 'A') ADVANCE(59);
      if (lookahead == 'C') ADVANCE(70);
      if (lookahead == 'D') ADVANCE(47);
      if (lookahead == 'F') ADVANCE(60);
      if (lookahead == 'J') ADVANCE(62);
      if (lookahead == 'M') ADVANCE(54);
      if (lookahead == 'P') ADVANCE(63);
      if (lookahead == 'R') ADVANCE(68);
      if (lookahead == 'S') ADVANCE(64);
      if (lookahead == 'V') ADVANCE(49);
      if (lookahead == 'a') ADVANCE(82);
      if (lookahead == 'c') ADVANCE(91);
      if (lookahead == 'd') ADVANCE(48);
      if (lookahead == 'f') ADVANCE(83);
      if (lookahead == 'j') ADVANCE(87);
      if (lookahead == 'm') ADVANCE(77);
      if (lookahead == 'p') ADVANCE(85);
      if (lookahead == 'r') ADVANCE(90);
      if (lookahead == 's') ADVANCE(86);
      if (lookahead == 'v') ADVANCE(72);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(108);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(122);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == 11 ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      if (lookahead == '/' ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          (lookahead < '\n' || '\r' < lookahead)) ADVANCE(135);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '.') ADVANCE(133);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(114);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '4') ADVANCE(156);
      if (lookahead == '8') ADVANCE(154);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '4') ADVANCE(182);
      if (lookahead == '8') ADVANCE(180);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '8') ADVANCE(168);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == '8') ADVANCE(194);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(66);
      if (lookahead == 'I') ADVANCE(55);
      if (lookahead == 'a') ADVANCE(128);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(128);
      if (lookahead == 'a') ADVANCE(69);
      if (lookahead == 'i') ADVANCE(78);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(61);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(166);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A') ADVANCE(53);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'B') ADVANCE(146);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C') ADVANCE(162);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'F') ADVANCE(65);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(98);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'G') ADVANCE(56);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'I') ADVANCE(152);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'K') ADVANCE(158);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'K') ADVANCE(164);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M') ADVANCE(150);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M') ADVANCE(148);
      if (lookahead == 'T') ADVANCE(43);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R') ADVANCE(51);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(45);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(57);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(52);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S') ADVANCE(58);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(50);
      if (lookahead == 't') ADVANCE(102);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(71);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(67);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T') ADVANCE(102);
      if (lookahead == 't') ADVANCE(73);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'W') ADVANCE(144);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'Y') ADVANCE(160);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'a') ADVANCE(84);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'a') ADVANCE(192);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'a') ADVANCE(76);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'b') ADVANCE(172);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'c') ADVANCE(188);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'f') ADVANCE(88);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(98);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'g') ADVANCE(79);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'i') ADVANCE(178);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'k') ADVANCE(184);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'k') ADVANCE(190);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'm') ADVANCE(176);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'm') ADVANCE(174);
      if (lookahead == 't') ADVANCE(44);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'r') ADVANCE(74);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(80);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(75);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(46);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 's') ADVANCE(81);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 't') ADVANCE(92);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 't') ADVANCE(89);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'w') ADVANCE(170);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'y') ADVANCE(186);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(40);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(38);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(113);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(129);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(117);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(95);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(124);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(119);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(121);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(132);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(110);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(115);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(28);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(32);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(125);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(36);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(105);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(34);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(99);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(101);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(118);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(26);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(116);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(111);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(127);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(103);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(97);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(130);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(123);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(131);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(104);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(30);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(109);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(96);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(112);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(107);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(102);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(134);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(120);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(93);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(94);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(106);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_header_value);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_header_value);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_header_value);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_date_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_date_value);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_day_command_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_day_value);
      if (lookahead == '+') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_band_token1);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_band_token1);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_band_token2);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(4);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_CW);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_CW);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_SSB);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_SSB);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_FM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_FM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_AM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_AM);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_DIGI);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_DIGI);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_FT8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_FT8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_FT4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_FT4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_PSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_PSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_RTTY);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_RTTY);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_VARAC);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_VARAC);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_MFSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_MFSK);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_DATA);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_DATA);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_JS8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_JS8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_cw);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_cw);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_ssb);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_ssb);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_fm);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_fm);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_am);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_am);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_digi);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_digi);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_ft8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_ft8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_ft4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_ft4);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_psk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_psk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_rtty);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_rtty);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_varac);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_varac);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_mfsk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_mfsk);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_data);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_data);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_js8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_js8);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(202);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(195);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(202);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(196);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(197);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_time);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(199);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(198);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(202);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(274);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(200);
      if (lookahead == '/' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(155);
      if (lookahead == '8') ADVANCE(153);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '4') ADVANCE(181);
      if (lookahead == '8') ADVANCE(179);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(167);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == '8') ADVANCE(193);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(227);
      if (lookahead == 'I') ADVANCE(216);
      if (lookahead == 'a') ADVANCE(287);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(287);
      if (lookahead == 'a') ADVANCE(230);
      if (lookahead == 'i') ADVANCE(239);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(222);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(165);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A') ADVANCE(214);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'B') ADVANCE(145);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C') ADVANCE(161);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F') ADVANCE(226);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(259);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G') ADVANCE(217);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I') ADVANCE(151);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(157);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K') ADVANCE(163);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(149);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M') ADVANCE(147);
      if (lookahead == 'T') ADVANCE(204);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R') ADVANCE(212);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(206);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(218);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(213);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S') ADVANCE(219);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(211);
      if (lookahead == 't') ADVANCE(262);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(232);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(228);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T') ADVANCE(262);
      if (lookahead == 't') ADVANCE(234);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W') ADVANCE(143);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'Y') ADVANCE(159);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(245);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(191);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'a') ADVANCE(237);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'b') ADVANCE(171);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'c') ADVANCE(187);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'f') ADVANCE(249);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(259);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'g') ADVANCE(240);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'i') ADVANCE(177);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(183);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'k') ADVANCE(189);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(175);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'm') ADVANCE(173);
      if (lookahead == 't') ADVANCE(205);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'r') ADVANCE(235);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(241);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(236);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(207);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 's') ADVANCE(242);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(253);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 't') ADVANCE(250);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'w') ADVANCE(169);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'y') ADVANCE(185);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(39);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(37);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(273);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(288);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(276);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(256);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(283);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(278);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(280);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(291);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(270);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(27);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(136);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(31);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(284);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(35);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(265);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(33);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(260);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(261);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(277);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(25);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(275);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(271);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(141);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(286);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(263);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(258);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(289);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(282);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(290);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(264);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(29);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(269);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(257);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(272);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(267);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(262);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(138);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(279);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(254);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(255);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_callsign);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(266);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_callsign);
      if (('/' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(292);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(295);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(296);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(297);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(298);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(aux_sym_grid_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(299);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(aux_sym_name_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(302);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(304);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(305);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(aux_sym_inline_comment_token1);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(305);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(308);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(309);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_qsl_info_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(309);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_inline_hash_comment_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_inline_hash_comment_token2);
      if (lookahead == '\t' ||
          (11 <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(312);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(313);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_inline_hash_comment_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(313);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 20},
  [2] = {.lex_state = 19},
  [3] = {.lex_state = 19},
  [4] = {.lex_state = 19},
  [5] = {.lex_state = 19},
  [6] = {.lex_state = 19},
  [7] = {.lex_state = 19},
  [8] = {.lex_state = 19},
  [9] = {.lex_state = 19},
  [10] = {.lex_state = 19},
  [11] = {.lex_state = 19},
  [12] = {.lex_state = 19},
  [13] = {.lex_state = 20},
  [14] = {.lex_state = 20},
  [15] = {.lex_state = 19},
  [16] = {.lex_state = 19},
  [17] = {.lex_state = 19},
  [18] = {.lex_state = 19},
  [19] = {.lex_state = 19},
  [20] = {.lex_state = 19},
  [21] = {.lex_state = 19},
  [22] = {.lex_state = 19},
  [23] = {.lex_state = 20},
  [24] = {.lex_state = 20},
  [25] = {.lex_state = 20},
  [26] = {.lex_state = 21},
  [27] = {.lex_state = 20},
  [28] = {.lex_state = 20},
  [29] = {.lex_state = 20},
  [30] = {.lex_state = 20},
  [31] = {.lex_state = 20},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 5},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 312},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 8},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 9},
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
    [aux_sym_rst_sent_token1] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(39),
    [sym_header] = STATE(13),
    [sym_date_command] = STATE(13),
    [sym_day_command] = STATE(13),
    [sym_band_mode_line] = STATE(13),
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
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
    [sym_qso_extra] = STATE(12),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(12),
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
    [aux_sym_rst_sent_token1] = ACTIONS(25),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [3] = {
    [sym_rst_sent] = STATE(5),
    [sym_qso_extra] = STATE(11),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(37),
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
    [aux_sym_rst_sent_token1] = ACTIONS(25),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [4] = {
    [sym_rst_rcvd] = STATE(7),
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(6),
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
    [aux_sym_rst_sent_token1] = ACTIONS(43),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [5] = {
    [sym_rst_rcvd] = STATE(10),
    [sym_qso_extra] = STATE(12),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(12),
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
    [aux_sym_rst_sent_token1] = ACTIONS(43),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [6] = {
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_comment] = ACTIONS(47),
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
    [sym_qso_extra] = STATE(9),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_comment] = ACTIONS(47),
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
  [8] = {
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_comment] = ACTIONS(51),
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
    [anon_sym_POUND] = ACTIONS(53),
    [anon_sym_AT] = ACTIONS(56),
    [anon_sym_LBRACK] = ACTIONS(59),
    [anon_sym_LT] = ACTIONS(62),
  },
  [9] = {
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(65),
    [sym_comment] = ACTIONS(67),
    [aux_sym_header_token1] = ACTIONS(67),
    [aux_sym_header_token2] = ACTIONS(67),
    [aux_sym_header_token3] = ACTIONS(67),
    [aux_sym_header_token4] = ACTIONS(67),
    [aux_sym_header_token5] = ACTIONS(67),
    [aux_sym_header_token6] = ACTIONS(67),
    [aux_sym_header_token7] = ACTIONS(67),
    [aux_sym_header_token8] = ACTIONS(67),
    [aux_sym_date_command_token1] = ACTIONS(67),
    [aux_sym_day_command_token1] = ACTIONS(67),
    [aux_sym_band_token1] = ACTIONS(67),
    [aux_sym_band_token2] = ACTIONS(67),
    [anon_sym_CW] = ACTIONS(67),
    [anon_sym_SSB] = ACTIONS(67),
    [anon_sym_FM] = ACTIONS(67),
    [anon_sym_AM] = ACTIONS(67),
    [anon_sym_DIGI] = ACTIONS(67),
    [anon_sym_FT8] = ACTIONS(67),
    [anon_sym_FT4] = ACTIONS(67),
    [anon_sym_PSK] = ACTIONS(67),
    [anon_sym_RTTY] = ACTIONS(67),
    [anon_sym_VARAC] = ACTIONS(67),
    [anon_sym_MFSK] = ACTIONS(67),
    [anon_sym_DATA] = ACTIONS(67),
    [anon_sym_JS8] = ACTIONS(67),
    [anon_sym_cw] = ACTIONS(67),
    [anon_sym_ssb] = ACTIONS(67),
    [anon_sym_fm] = ACTIONS(67),
    [anon_sym_am] = ACTIONS(67),
    [anon_sym_digi] = ACTIONS(67),
    [anon_sym_ft8] = ACTIONS(67),
    [anon_sym_ft4] = ACTIONS(67),
    [anon_sym_psk] = ACTIONS(67),
    [anon_sym_rtty] = ACTIONS(67),
    [anon_sym_varac] = ACTIONS(67),
    [anon_sym_mfsk] = ACTIONS(67),
    [anon_sym_data] = ACTIONS(67),
    [anon_sym_js8] = ACTIONS(67),
    [sym_time] = ACTIONS(67),
    [sym_callsign] = ACTIONS(67),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [10] = {
    [sym_qso_extra] = STATE(6),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(6),
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
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [11] = {
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(8),
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
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_AT] = ACTIONS(29),
    [anon_sym_LBRACK] = ACTIONS(31),
    [anon_sym_LT] = ACTIONS(33),
  },
  [12] = {
    [sym_qso_extra] = STATE(8),
    [sym_grid] = STATE(22),
    [sym_name] = STATE(22),
    [sym_inline_comment] = STATE(22),
    [sym_qsl_info] = STATE(22),
    [sym_inline_hash_comment] = STATE(22),
    [aux_sym_qso_line_repeat1] = STATE(8),
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
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
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
    [sym_band] = STATE(23),
    [sym_mode] = STATE(23),
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
    [sym_comment] = ACTIONS(101),
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
    [sym_comment] = ACTIONS(105),
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
    [sym_comment] = ACTIONS(109),
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
    [sym_comment] = ACTIONS(113),
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
    [sym_comment] = ACTIONS(117),
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
    [sym_comment] = ACTIONS(121),
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
    [sym_comment] = ACTIONS(125),
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
    [ts_builtin_sym_end] = ACTIONS(127),
    [sym_comment] = ACTIONS(129),
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
    [aux_sym_band_token1] = ACTIONS(129),
    [aux_sym_band_token2] = ACTIONS(129),
    [anon_sym_CW] = ACTIONS(129),
    [anon_sym_SSB] = ACTIONS(129),
    [anon_sym_FM] = ACTIONS(129),
    [anon_sym_AM] = ACTIONS(129),
    [anon_sym_DIGI] = ACTIONS(129),
    [anon_sym_FT8] = ACTIONS(129),
    [anon_sym_FT4] = ACTIONS(129),
    [anon_sym_PSK] = ACTIONS(129),
    [anon_sym_RTTY] = ACTIONS(129),
    [anon_sym_VARAC] = ACTIONS(129),
    [anon_sym_MFSK] = ACTIONS(129),
    [anon_sym_DATA] = ACTIONS(129),
    [anon_sym_JS8] = ACTIONS(129),
    [anon_sym_cw] = ACTIONS(129),
    [anon_sym_ssb] = ACTIONS(129),
    [anon_sym_fm] = ACTIONS(129),
    [anon_sym_am] = ACTIONS(129),
    [anon_sym_digi] = ACTIONS(129),
    [anon_sym_ft8] = ACTIONS(129),
    [anon_sym_ft4] = ACTIONS(129),
    [anon_sym_psk] = ACTIONS(129),
    [anon_sym_rtty] = ACTIONS(129),
    [anon_sym_varac] = ACTIONS(129),
    [anon_sym_mfsk] = ACTIONS(129),
    [anon_sym_data] = ACTIONS(129),
    [anon_sym_js8] = ACTIONS(129),
    [sym_time] = ACTIONS(129),
    [sym_callsign] = ACTIONS(129),
    [anon_sym_POUND] = ACTIONS(129),
    [anon_sym_AT] = ACTIONS(127),
    [anon_sym_LBRACK] = ACTIONS(127),
    [anon_sym_LT] = ACTIONS(127),
  },
  [23] = {
    [sym_band] = STATE(24),
    [sym_mode] = STATE(24),
    [aux_sym_band_mode_line_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(131),
    [sym_comment] = ACTIONS(131),
    [aux_sym_header_token1] = ACTIONS(133),
    [aux_sym_header_token2] = ACTIONS(133),
    [aux_sym_header_token3] = ACTIONS(133),
    [aux_sym_header_token4] = ACTIONS(133),
    [aux_sym_header_token5] = ACTIONS(133),
    [aux_sym_header_token6] = ACTIONS(133),
    [aux_sym_header_token7] = ACTIONS(133),
    [aux_sym_header_token8] = ACTIONS(133),
    [aux_sym_date_command_token1] = ACTIONS(133),
    [aux_sym_day_command_token1] = ACTIONS(133),
    [aux_sym_band_token1] = ACTIONS(135),
    [aux_sym_band_token2] = ACTIONS(135),
    [anon_sym_CW] = ACTIONS(138),
    [anon_sym_SSB] = ACTIONS(138),
    [anon_sym_FM] = ACTIONS(138),
    [anon_sym_AM] = ACTIONS(138),
    [anon_sym_DIGI] = ACTIONS(138),
    [anon_sym_FT8] = ACTIONS(138),
    [anon_sym_FT4] = ACTIONS(138),
    [anon_sym_PSK] = ACTIONS(138),
    [anon_sym_RTTY] = ACTIONS(138),
    [anon_sym_VARAC] = ACTIONS(138),
    [anon_sym_MFSK] = ACTIONS(138),
    [anon_sym_DATA] = ACTIONS(138),
    [anon_sym_JS8] = ACTIONS(138),
    [anon_sym_cw] = ACTIONS(138),
    [anon_sym_ssb] = ACTIONS(138),
    [anon_sym_fm] = ACTIONS(138),
    [anon_sym_am] = ACTIONS(138),
    [anon_sym_digi] = ACTIONS(138),
    [anon_sym_ft8] = ACTIONS(138),
    [anon_sym_ft4] = ACTIONS(138),
    [anon_sym_psk] = ACTIONS(138),
    [anon_sym_rtty] = ACTIONS(138),
    [anon_sym_varac] = ACTIONS(138),
    [anon_sym_mfsk] = ACTIONS(138),
    [anon_sym_data] = ACTIONS(138),
    [anon_sym_js8] = ACTIONS(138),
    [sym_time] = ACTIONS(133),
    [sym_callsign] = ACTIONS(133),
  },
  [24] = {
    [sym_band] = STATE(25),
    [sym_mode] = STATE(25),
    [aux_sym_band_mode_line_repeat1] = STATE(25),
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
    [sym_band] = STATE(25),
    [sym_mode] = STATE(25),
    [aux_sym_band_mode_line_repeat1] = STATE(25),
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
    [aux_sym_band_token1] = ACTIONS(155),
    [aux_sym_band_token2] = ACTIONS(155),
    [anon_sym_CW] = ACTIONS(158),
    [anon_sym_SSB] = ACTIONS(158),
    [anon_sym_FM] = ACTIONS(158),
    [anon_sym_AM] = ACTIONS(158),
    [anon_sym_DIGI] = ACTIONS(158),
    [anon_sym_FT8] = ACTIONS(158),
    [anon_sym_FT4] = ACTIONS(158),
    [anon_sym_PSK] = ACTIONS(158),
    [anon_sym_RTTY] = ACTIONS(158),
    [anon_sym_VARAC] = ACTIONS(158),
    [anon_sym_MFSK] = ACTIONS(158),
    [anon_sym_DATA] = ACTIONS(158),
    [anon_sym_JS8] = ACTIONS(158),
    [anon_sym_cw] = ACTIONS(158),
    [anon_sym_ssb] = ACTIONS(158),
    [anon_sym_fm] = ACTIONS(158),
    [anon_sym_am] = ACTIONS(158),
    [anon_sym_digi] = ACTIONS(158),
    [anon_sym_ft8] = ACTIONS(158),
    [anon_sym_ft4] = ACTIONS(158),
    [anon_sym_psk] = ACTIONS(158),
    [anon_sym_rtty] = ACTIONS(158),
    [anon_sym_varac] = ACTIONS(158),
    [anon_sym_mfsk] = ACTIONS(158),
    [anon_sym_data] = ACTIONS(158),
    [anon_sym_js8] = ACTIONS(158),
    [sym_time] = ACTIONS(153),
    [sym_callsign] = ACTIONS(153),
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(161),
    [sym_comment] = ACTIONS(163),
    [aux_sym_header_token1] = ACTIONS(163),
    [aux_sym_header_token2] = ACTIONS(163),
    [aux_sym_header_token3] = ACTIONS(163),
    [aux_sym_header_token4] = ACTIONS(163),
    [aux_sym_header_token5] = ACTIONS(163),
    [aux_sym_header_token6] = ACTIONS(163),
    [aux_sym_header_token7] = ACTIONS(163),
    [aux_sym_header_token8] = ACTIONS(163),
    [sym_header_value] = ACTIONS(165),
    [aux_sym_date_command_token1] = ACTIONS(163),
    [aux_sym_day_command_token1] = ACTIONS(163),
    [aux_sym_band_token1] = ACTIONS(163),
    [aux_sym_band_token2] = ACTIONS(163),
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
    [sym_time] = ACTIONS(163),
    [sym_callsign] = ACTIONS(163),
  },
  [27] = {
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
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(171),
    [sym_comment] = ACTIONS(171),
    [aux_sym_header_token1] = ACTIONS(173),
    [aux_sym_header_token2] = ACTIONS(173),
    [aux_sym_header_token3] = ACTIONS(173),
    [aux_sym_header_token4] = ACTIONS(173),
    [aux_sym_header_token5] = ACTIONS(173),
    [aux_sym_header_token6] = ACTIONS(173),
    [aux_sym_header_token7] = ACTIONS(173),
    [aux_sym_header_token8] = ACTIONS(173),
    [aux_sym_date_command_token1] = ACTIONS(173),
    [aux_sym_day_command_token1] = ACTIONS(173),
    [aux_sym_band_token1] = ACTIONS(173),
    [aux_sym_band_token2] = ACTIONS(173),
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
    [sym_time] = ACTIONS(173),
    [sym_callsign] = ACTIONS(173),
  },
  [29] = {
    [ts_builtin_sym_end] = ACTIONS(175),
    [sym_comment] = ACTIONS(175),
    [aux_sym_header_token1] = ACTIONS(177),
    [aux_sym_header_token2] = ACTIONS(177),
    [aux_sym_header_token3] = ACTIONS(177),
    [aux_sym_header_token4] = ACTIONS(177),
    [aux_sym_header_token5] = ACTIONS(177),
    [aux_sym_header_token6] = ACTIONS(177),
    [aux_sym_header_token7] = ACTIONS(177),
    [aux_sym_header_token8] = ACTIONS(177),
    [aux_sym_date_command_token1] = ACTIONS(177),
    [aux_sym_day_command_token1] = ACTIONS(177),
    [aux_sym_band_token1] = ACTIONS(177),
    [aux_sym_band_token2] = ACTIONS(177),
    [anon_sym_CW] = ACTIONS(177),
    [anon_sym_SSB] = ACTIONS(177),
    [anon_sym_FM] = ACTIONS(177),
    [anon_sym_AM] = ACTIONS(177),
    [anon_sym_DIGI] = ACTIONS(177),
    [anon_sym_FT8] = ACTIONS(177),
    [anon_sym_FT4] = ACTIONS(177),
    [anon_sym_PSK] = ACTIONS(177),
    [anon_sym_RTTY] = ACTIONS(177),
    [anon_sym_VARAC] = ACTIONS(177),
    [anon_sym_MFSK] = ACTIONS(177),
    [anon_sym_DATA] = ACTIONS(177),
    [anon_sym_JS8] = ACTIONS(177),
    [anon_sym_cw] = ACTIONS(177),
    [anon_sym_ssb] = ACTIONS(177),
    [anon_sym_fm] = ACTIONS(177),
    [anon_sym_am] = ACTIONS(177),
    [anon_sym_digi] = ACTIONS(177),
    [anon_sym_ft8] = ACTIONS(177),
    [anon_sym_ft4] = ACTIONS(177),
    [anon_sym_psk] = ACTIONS(177),
    [anon_sym_rtty] = ACTIONS(177),
    [anon_sym_varac] = ACTIONS(177),
    [anon_sym_mfsk] = ACTIONS(177),
    [anon_sym_data] = ACTIONS(177),
    [anon_sym_js8] = ACTIONS(177),
    [sym_time] = ACTIONS(177),
    [sym_callsign] = ACTIONS(177),
  },
  [30] = {
    [ts_builtin_sym_end] = ACTIONS(179),
    [sym_comment] = ACTIONS(179),
    [aux_sym_header_token1] = ACTIONS(181),
    [aux_sym_header_token2] = ACTIONS(181),
    [aux_sym_header_token3] = ACTIONS(181),
    [aux_sym_header_token4] = ACTIONS(181),
    [aux_sym_header_token5] = ACTIONS(181),
    [aux_sym_header_token6] = ACTIONS(181),
    [aux_sym_header_token7] = ACTIONS(181),
    [aux_sym_header_token8] = ACTIONS(181),
    [aux_sym_date_command_token1] = ACTIONS(181),
    [aux_sym_day_command_token1] = ACTIONS(181),
    [aux_sym_band_token1] = ACTIONS(181),
    [aux_sym_band_token2] = ACTIONS(181),
    [anon_sym_CW] = ACTIONS(181),
    [anon_sym_SSB] = ACTIONS(181),
    [anon_sym_FM] = ACTIONS(181),
    [anon_sym_AM] = ACTIONS(181),
    [anon_sym_DIGI] = ACTIONS(181),
    [anon_sym_FT8] = ACTIONS(181),
    [anon_sym_FT4] = ACTIONS(181),
    [anon_sym_PSK] = ACTIONS(181),
    [anon_sym_RTTY] = ACTIONS(181),
    [anon_sym_VARAC] = ACTIONS(181),
    [anon_sym_MFSK] = ACTIONS(181),
    [anon_sym_DATA] = ACTIONS(181),
    [anon_sym_JS8] = ACTIONS(181),
    [anon_sym_cw] = ACTIONS(181),
    [anon_sym_ssb] = ACTIONS(181),
    [anon_sym_fm] = ACTIONS(181),
    [anon_sym_am] = ACTIONS(181),
    [anon_sym_digi] = ACTIONS(181),
    [anon_sym_ft8] = ACTIONS(181),
    [anon_sym_ft4] = ACTIONS(181),
    [anon_sym_psk] = ACTIONS(181),
    [anon_sym_rtty] = ACTIONS(181),
    [anon_sym_varac] = ACTIONS(181),
    [anon_sym_mfsk] = ACTIONS(181),
    [anon_sym_data] = ACTIONS(181),
    [anon_sym_js8] = ACTIONS(181),
    [sym_time] = ACTIONS(181),
    [sym_callsign] = ACTIONS(181),
  },
  [31] = {
    [ts_builtin_sym_end] = ACTIONS(183),
    [sym_comment] = ACTIONS(183),
    [aux_sym_header_token1] = ACTIONS(185),
    [aux_sym_header_token2] = ACTIONS(185),
    [aux_sym_header_token3] = ACTIONS(185),
    [aux_sym_header_token4] = ACTIONS(185),
    [aux_sym_header_token5] = ACTIONS(185),
    [aux_sym_header_token6] = ACTIONS(185),
    [aux_sym_header_token7] = ACTIONS(185),
    [aux_sym_header_token8] = ACTIONS(185),
    [aux_sym_date_command_token1] = ACTIONS(185),
    [aux_sym_day_command_token1] = ACTIONS(185),
    [aux_sym_band_token1] = ACTIONS(185),
    [aux_sym_band_token2] = ACTIONS(185),
    [anon_sym_CW] = ACTIONS(185),
    [anon_sym_SSB] = ACTIONS(185),
    [anon_sym_FM] = ACTIONS(185),
    [anon_sym_AM] = ACTIONS(185),
    [anon_sym_DIGI] = ACTIONS(185),
    [anon_sym_FT8] = ACTIONS(185),
    [anon_sym_FT4] = ACTIONS(185),
    [anon_sym_PSK] = ACTIONS(185),
    [anon_sym_RTTY] = ACTIONS(185),
    [anon_sym_VARAC] = ACTIONS(185),
    [anon_sym_MFSK] = ACTIONS(185),
    [anon_sym_DATA] = ACTIONS(185),
    [anon_sym_JS8] = ACTIONS(185),
    [anon_sym_cw] = ACTIONS(185),
    [anon_sym_ssb] = ACTIONS(185),
    [anon_sym_fm] = ACTIONS(185),
    [anon_sym_am] = ACTIONS(185),
    [anon_sym_digi] = ACTIONS(185),
    [anon_sym_ft8] = ACTIONS(185),
    [anon_sym_ft4] = ACTIONS(185),
    [anon_sym_psk] = ACTIONS(185),
    [anon_sym_rtty] = ACTIONS(185),
    [anon_sym_varac] = ACTIONS(185),
    [anon_sym_mfsk] = ACTIONS(185),
    [anon_sym_data] = ACTIONS(185),
    [anon_sym_js8] = ACTIONS(185),
    [sym_time] = ACTIONS(185),
    [sym_callsign] = ACTIONS(185),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(187), 1,
      aux_sym_grid_token1,
    ACTIONS(189), 1,
      aux_sym_inline_hash_comment_token1,
  [7] = 1,
    ACTIONS(191), 1,
      aux_sym_qsl_info_token1,
  [11] = 1,
    ACTIONS(193), 1,
      aux_sym_inline_comment_token1,
  [15] = 1,
    ACTIONS(195), 1,
      aux_sym_name_token1,
  [19] = 1,
    ACTIONS(197), 1,
      aux_sym_inline_hash_comment_token2,
  [23] = 1,
    ACTIONS(199), 1,
      anon_sym_RBRACK,
  [27] = 1,
    ACTIONS(201), 1,
      anon_sym_GT,
  [31] = 1,
    ACTIONS(203), 1,
      ts_builtin_sym_end,
  [35] = 1,
    ACTIONS(205), 1,
      sym_callsign,
  [39] = 1,
    ACTIONS(207), 1,
      sym_day_value,
  [43] = 1,
    ACTIONS(209), 1,
      sym_date_value,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(32)] = 0,
  [SMALL_STATE(33)] = 7,
  [SMALL_STATE(34)] = 11,
  [SMALL_STATE(35)] = 15,
  [SMALL_STATE(36)] = 19,
  [SMALL_STATE(37)] = 23,
  [SMALL_STATE(38)] = 27,
  [SMALL_STATE(39)] = 31,
  [SMALL_STATE(40)] = 35,
  [SMALL_STATE(41)] = 39,
  [SMALL_STATE(42)] = 43,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 2),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 2),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 1),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 3),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 4),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 4),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(32),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(35),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(34),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qso_line_repeat1, 2), SHIFT_REPEAT(33),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_line, 5),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_line, 5),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(42),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(41),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(31),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(30),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(40),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst_sent, 1),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst_sent, 1),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qsl_info, 3),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qsl_info, 3),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_comment, 3),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_comment, 3),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_hash_comment, 3),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_hash_comment, 3),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rst_rcvd, 1),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rst_rcvd, 1),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 2),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_name, 2),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_grid, 2),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_grid, 2),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qso_extra, 1),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qso_extra, 1),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 1),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 1),
  [135] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 1), SHIFT(31),
  [138] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 1), SHIFT(30),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band_mode_line, 2),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band_mode_line, 2),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 2), SHIFT(31),
  [148] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_band_mode_line, 2), SHIFT(30),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(31),
  [158] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_band_mode_line_repeat1, 2), SHIFT_REPEAT(30),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 1),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 1),
  [165] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_day_command, 2),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_day_command, 2),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_date_command, 2),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_date_command, 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 2),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 2),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mode, 1),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mode, 1),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_band, 1),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_band, 1),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [203] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
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
