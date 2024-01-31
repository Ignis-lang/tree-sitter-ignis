#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 65
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 57
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 9
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_import = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_from = 4,
  anon_sym_SEMI = 5,
  anon_sym_function = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  anon_sym_COLON = 9,
  anon_sym_COMMA = 10,
  anon_sym_return = 11,
  sym_identifier = 12,
  anon_sym_int = 13,
  anon_sym_float = 14,
  anon_sym_string = 15,
  anon_sym_boolean = 16,
  anon_sym_void = 17,
  anon_sym_char = 18,
  anon_sym_unknown = 19,
  sym_integer_literal = 20,
  sym_float_literal = 21,
  aux_sym_string_literal_token1 = 22,
  anon_sym_DQUOTE = 23,
  anon_sym_true = 24,
  anon_sym_false = 25,
  sym_char_literal = 26,
  anon_sym_let = 27,
  anon_sym_EQ = 28,
  anon_sym_DASH = 29,
  sym__string_content = 30,
  sym_escape_sequence = 31,
  sym_line_comment = 32,
  sym_block_comment = 33,
  sym_program = 34,
  sym__statement = 35,
  sym_import_statement = 36,
  sym_function_declaration = 37,
  sym_parameter_list = 38,
  sym_return_type = 39,
  sym__function_body = 40,
  sym_expression_statement = 41,
  sym_expression = 42,
  sym_function_call = 43,
  sym_arguments = 44,
  sym_return_statement = 45,
  sym_type_identifier = 46,
  sym_literal = 47,
  sym_string_literal = 48,
  sym_boolean_literal = 49,
  sym_variable_declaration = 50,
  sym__semicolon = 51,
  aux_sym_program_repeat1 = 52,
  aux_sym_function_declaration_repeat1 = 53,
  aux_sym_parameter_list_repeat1 = 54,
  aux_sym_arguments_repeat1 = 55,
  aux_sym_string_literal_repeat1 = 56,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_import] = "import",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_from] = "from",
  [anon_sym_SEMI] = ";",
  [anon_sym_function] = "function",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_COMMA] = ",",
  [anon_sym_return] = "return",
  [sym_identifier] = "identifier",
  [anon_sym_int] = "int",
  [anon_sym_float] = "float",
  [anon_sym_string] = "string",
  [anon_sym_boolean] = "boolean",
  [anon_sym_void] = "void",
  [anon_sym_char] = "char",
  [anon_sym_unknown] = "unknown",
  [sym_integer_literal] = "integer_literal",
  [sym_float_literal] = "float_literal",
  [aux_sym_string_literal_token1] = "\"",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_char_literal] = "char_literal",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_DASH] = "-",
  [sym__string_content] = "_string_content",
  [sym_escape_sequence] = "escape_sequence",
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_program] = "program",
  [sym__statement] = "_statement",
  [sym_import_statement] = "import_statement",
  [sym_function_declaration] = "function_declaration",
  [sym_parameter_list] = "parameter_list",
  [sym_return_type] = "return_type",
  [sym__function_body] = "_function_body",
  [sym_expression_statement] = "expression_statement",
  [sym_expression] = "expression",
  [sym_function_call] = "function_call",
  [sym_arguments] = "arguments",
  [sym_return_statement] = "return_statement",
  [sym_type_identifier] = "type_identifier",
  [sym_literal] = "literal",
  [sym_string_literal] = "string_literal",
  [sym_boolean_literal] = "boolean_literal",
  [sym_variable_declaration] = "variable_declaration",
  [sym__semicolon] = "_semicolon",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_function_declaration_repeat1] = "function_declaration_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym_arguments_repeat1] = "arguments_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_from] = anon_sym_from,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_return] = anon_sym_return,
  [sym_identifier] = sym_identifier,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_void] = anon_sym_void,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_unknown] = anon_sym_unknown,
  [sym_integer_literal] = sym_integer_literal,
  [sym_float_literal] = sym_float_literal,
  [aux_sym_string_literal_token1] = anon_sym_DQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_char_literal] = sym_char_literal,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym__string_content] = sym__string_content,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_program] = sym_program,
  [sym__statement] = sym__statement,
  [sym_import_statement] = sym_import_statement,
  [sym_function_declaration] = sym_function_declaration,
  [sym_parameter_list] = sym_parameter_list,
  [sym_return_type] = sym_return_type,
  [sym__function_body] = sym__function_body,
  [sym_expression_statement] = sym_expression_statement,
  [sym_expression] = sym_expression,
  [sym_function_call] = sym_function_call,
  [sym_arguments] = sym_arguments,
  [sym_return_statement] = sym_return_statement,
  [sym_type_identifier] = sym_type_identifier,
  [sym_literal] = sym_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_variable_declaration] = sym_variable_declaration,
  [sym__semicolon] = sym__semicolon,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_function_declaration_repeat1] = aux_sym_function_declaration_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym_arguments_repeat1] = aux_sym_arguments_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_from] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unknown] = {
    .visible = true,
    .named = false,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_float_literal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_string_literal_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_char_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym__string_content] = {
    .visible = false,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_function_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_return_type] = {
    .visible = true,
    .named = true,
  },
  [sym__function_body] = {
    .visible = false,
    .named = true,
  },
  [sym_expression_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_function_call] = {
    .visible = true,
    .named = true,
  },
  [sym_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__semicolon] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
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
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
};

static inline bool sym_identifier_character_set_1(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < 'a'
                ? (c < 'A'
                  ? c == '$'
                  : (c <= 'Z' || c == '_'))
                : (c <= 'z' || (c < 181
                  ? c == 170
                  : c <= 181)))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_identifier_character_set_2(int32_t c) {
  return (c < 6320
    ? (c < 2974
      ? (c < 2308
        ? (c < 1369
          ? (c < 748
            ? (c < 181
              ? (c < '_'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= '_' || (c < 162
                  ? (c >= 'a' && c <= 'z')
                  : (c <= 162 || c == 170))))
              : (c <= 181 || (c < 248
                ? (c < 192
                  ? c == 186
                  : (c <= 214 || (c >= 216 && c <= 246)))
                : (c <= 705 || (c < 736
                  ? (c >= 710 && c <= 721)
                  : c <= 740)))))
            : (c <= 748 || (c < 904
              ? (c < 890
                ? (c < 880
                  ? c == 750
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 902
                  ? c == 895
                  : c <= 902)))
              : (c <= 906 || (c < 1015
                ? (c < 910
                  ? c == 908
                  : (c <= 929 || (c >= 931 && c <= 1013)))
                : (c <= 1153 || (c < 1329
                  ? (c >= 1162 && c <= 1327)
                  : c <= 1366)))))))
          : (c <= 1369 || (c < 1869
            ? (c < 1649
              ? (c < 1568
                ? (c < 1488
                  ? (c >= 1376 && c <= 1416)
                  : (c <= 1514 || (c >= 1519 && c <= 1522)))
                : (c <= 1610 || (c < 1646
                  ? (c >= 1632 && c <= 1641)
                  : c <= 1647)))
              : (c <= 1747 || (c < 1791
                ? (c < 1765
                  ? c == 1749
                  : (c <= 1766 || (c >= 1774 && c <= 1788)))
                : (c <= 1791 || (c < 1810
                  ? c == 1808
                  : c <= 1839)))))
            : (c <= 1957 || (c < 2084
              ? (c < 2042
                ? (c < 1984
                  ? c == 1969
                  : (c <= 2026 || (c >= 2036 && c <= 2037)))
                : (c <= 2042 || (c < 2074
                  ? (c >= 2048 && c <= 2069)
                  : c <= 2074)))
              : (c <= 2084 || (c < 2160
                ? (c < 2112
                  ? c == 2088
                  : (c <= 2136 || (c >= 2144 && c <= 2154)))
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2406
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2415 || (c < 2437
                  ? (c >= 2417 && c <= 2432)
                  : (c <= 2444 || (c >= 2447 && c <= 2448)))))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2534 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2654
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : (c <= 2617 || (c >= 2649 && c <= 2652)))
                : (c <= 2654 || (c < 2674
                  ? (c >= 2662 && c <= 2671)
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2858
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2821
                ? (c < 2790
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2799 || c == 2809))
                : (c <= 2828 || (c < 2835
                  ? (c >= 2831 && c <= 2832)
                  : c <= 2856)))))
            : (c <= 2864 || (c < 2929
              ? (c < 2908
                ? (c < 2869
                  ? (c >= 2866 && c <= 2867)
                  : (c <= 2873 || c == 2877))
                : (c <= 2909 || (c < 2918
                  ? (c >= 2911 && c <= 2913)
                  : c <= 2927)))
              : (c <= 2929 || (c < 2962
                ? (c < 2949
                  ? c == 2947
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))
                : (c <= 2965 || (c < 2972
                  ? (c >= 2969 && c <= 2970)
                  : c <= 2972)))))))))))
      : (c <= 2975 || (c < 3840
        ? (c < 3389
          ? (c < 3200
            ? (c < 3090
              ? (c < 3024
                ? (c < 2984
                  ? (c >= 2979 && c <= 2980)
                  : (c <= 2986 || (c >= 2990 && c <= 3001)))
                : (c <= 3024 || (c < 3077
                  ? (c >= 3046 && c <= 3055)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3165
                ? (c < 3133
                  ? (c >= 3114 && c <= 3129)
                  : (c <= 3133 || (c >= 3160 && c <= 3162)))
                : (c <= 3165 || (c < 3174
                  ? (c >= 3168 && c <= 3169)
                  : c <= 3183)))))
            : (c <= 3200 || (c < 3293
              ? (c < 3242
                ? (c < 3214
                  ? (c >= 3205 && c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))
                : (c <= 3251 || (c < 3261
                  ? (c >= 3253 && c <= 3257)
                  : c <= 3261)))
              : (c <= 3294 || (c < 3332
                ? (c < 3302
                  ? (c >= 3296 && c <= 3297)
                  : (c <= 3311 || (c >= 3313 && c <= 3314)))
                : (c <= 3340 || (c < 3346
                  ? (c >= 3342 && c <= 3344)
                  : c <= 3386)))))))
          : (c <= 3389 || (c < 3648
            ? (c < 3482
              ? (c < 3430
                ? (c < 3412
                  ? c == 3406
                  : (c <= 3414 || (c >= 3423 && c <= 3425)))
                : (c <= 3439 || (c < 3461
                  ? (c >= 3450 && c <= 3455)
                  : c <= 3478)))
              : (c <= 3505 || (c < 3558
                ? (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : (c <= 3517 || (c >= 3520 && c <= 3526)))
                : (c <= 3567 || (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : c <= 3635)))))
            : (c <= 3654 || (c < 3751
              ? (c < 3718
                ? (c < 3713
                  ? (c >= 3664 && c <= 3673)
                  : (c <= 3714 || c == 3716))
                : (c <= 3722 || (c < 3749
                  ? (c >= 3724 && c <= 3747)
                  : c <= 3749)))
              : (c <= 3760 || (c < 3782
                ? (c < 3773
                  ? (c >= 3762 && c <= 3763)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))
                : (c <= 3782 || (c < 3804
                  ? (c >= 3792 && c <= 3801)
                  : c <= 3807)))))))))
        : (c <= 3840 || (c < 4800
          ? (c < 4256
            ? (c < 4186
              ? (c < 3976
                ? (c < 3904
                  ? (c >= 3872 && c <= 3881)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4159
                  ? (c >= 4096 && c <= 4138)
                  : (c <= 4169 || (c >= 4176 && c <= 4181)))))
              : (c <= 4189 || (c < 4213
                ? (c < 4197
                  ? c == 4193
                  : (c <= 4198 || (c >= 4206 && c <= 4208)))
                : (c <= 4225 || (c < 4240
                  ? c == 4238
                  : c <= 4249)))))
            : (c <= 4293 || (c < 4696
              ? (c < 4348
                ? (c < 4301
                  ? c == 4295
                  : (c <= 4301 || (c >= 4304 && c <= 4346)))
                : (c <= 4680 || (c < 4688
                  ? (c >= 4682 && c <= 4685)
                  : c <= 4694)))
              : (c <= 4696 || (c < 4752
                ? (c < 4704
                  ? (c >= 4698 && c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4792
                  ? (c >= 4786 && c <= 4789)
                  : c <= 4798)))))))
          : (c <= 4800 || (c < 5888
            ? (c < 5024
              ? (c < 4882
                ? (c < 4808
                  ? (c >= 4802 && c <= 4805)
                  : (c <= 4822 || (c >= 4824 && c <= 4880)))
                : (c <= 4885 || (c < 4992
                  ? (c >= 4888 && c <= 4954)
                  : c <= 5007)))
              : (c <= 5109 || (c < 5761
                ? (c < 5121
                  ? (c >= 5112 && c <= 5117)
                  : (c <= 5740 || (c >= 5743 && c <= 5759)))
                : (c <= 5786 || (c < 5873
                  ? (c >= 5792 && c <= 5866)
                  : c <= 5880)))))
            : (c <= 5905 || (c < 6108
              ? (c < 5998
                ? (c < 5952
                  ? (c >= 5919 && c <= 5937)
                  : (c <= 5969 || (c >= 5984 && c <= 5996)))
                : (c <= 6000 || (c < 6103
                  ? (c >= 6016 && c <= 6067)
                  : c <= 6103)))
              : (c <= 6108 || (c < 6272
                ? (c < 6160
                  ? (c >= 6112 && c <= 6121)
                  : (c <= 6169 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))))))))))))
    : (c <= 6389 || (c < 43138
      ? (c < 8488
        ? (c < 7960
          ? (c < 7043
            ? (c < 6688
              ? (c < 6528
                ? (c < 6470
                  ? (c >= 6400 && c <= 6430)
                  : (c <= 6509 || (c >= 6512 && c <= 6516)))
                : (c <= 6571 || (c < 6608
                  ? (c >= 6576 && c <= 6601)
                  : (c <= 6617 || (c >= 6656 && c <= 6678)))))
              : (c <= 6740 || (c < 6917
                ? (c < 6800
                  ? (c >= 6784 && c <= 6793)
                  : (c <= 6809 || c == 6823))
                : (c <= 6963 || (c < 6992
                  ? (c >= 6981 && c <= 6988)
                  : c <= 7001)))))
            : (c <= 7072 || (c < 7357
              ? (c < 7245
                ? (c < 7168
                  ? (c >= 7086 && c <= 7141)
                  : (c <= 7203 || (c >= 7232 && c <= 7241)))
                : (c <= 7293 || (c < 7312
                  ? (c >= 7296 && c <= 7304)
                  : c <= 7354)))
              : (c <= 7359 || (c < 7418
                ? (c < 7406
                  ? (c >= 7401 && c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7680
                  ? (c >= 7424 && c <= 7615)
                  : c <= 7957)))))))
          : (c <= 7965 || (c < 8150
            ? (c < 8031
              ? (c < 8025
                ? (c < 8008
                  ? (c >= 7968 && c <= 8005)
                  : (c <= 8013 || (c >= 8016 && c <= 8023)))
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))
              : (c <= 8061 || (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))))
            : (c <= 8155 || (c < 8450
              ? (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))
              : (c <= 8450 || (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))))))))
        : (c <= 8488 || (c < 12445
          ? (c < 11648
            ? (c < 11499
              ? (c < 8517
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : (c <= 8505 || (c >= 8508 && c <= 8511)))
                : (c <= 8521 || (c < 8579
                  ? c == 8526
                  : (c <= 8580 || (c >= 11264 && c <= 11492)))))
              : (c <= 11502 || (c < 11565
                ? (c < 11520
                  ? (c >= 11506 && c <= 11507)
                  : (c <= 11557 || c == 11559))
                : (c <= 11565 || (c < 11631
                  ? (c >= 11568 && c <= 11623)
                  : c <= 11631)))))
            : (c <= 11670 || (c < 11728
              ? (c < 11704
                ? (c < 11688
                  ? (c >= 11680 && c <= 11686)
                  : (c <= 11694 || (c >= 11696 && c <= 11702)))
                : (c <= 11710 || (c < 11720
                  ? (c >= 11712 && c <= 11718)
                  : c <= 11726)))
              : (c <= 11734 || (c < 12337
                ? (c < 11823
                  ? (c >= 11736 && c <= 11742)
                  : (c <= 11823 || (c >= 12293 && c <= 12294)))
                : (c <= 12341 || (c < 12353
                  ? (c >= 12347 && c <= 12348)
                  : c <= 12438)))))))
          : (c <= 12447 || (c < 42560
            ? (c < 13312
              ? (c < 12593
                ? (c < 12540
                  ? (c >= 12449 && c <= 12538)
                  : (c <= 12543 || (c >= 12549 && c <= 12591)))
                : (c <= 12686 || (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : c <= 12799)))
              : (c <= 13312 || (c < 42192
                ? (c < 19968
                  ? c == 19903
                  : (c <= 19968 || (c >= 40959 && c <= 42124)))
                : (c <= 42237 || (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : c <= 42539)))))
            : (c <= 42606 || (c < 42963
              ? (c < 42786
                ? (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : (c <= 42725 || (c >= 42775 && c <= 42783)))
                : (c <= 42888 || (c < 42960
                  ? (c >= 42891 && c <= 42954)
                  : c <= 42961)))
              : (c <= 42963 || (c < 43015
                ? (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : (c <= 43009 || (c >= 43011 && c <= 43013)))
                : (c <= 43018 || (c < 43072
                  ? (c >= 43020 && c <= 43042)
                  : c <= 43123)))))))))))
      : (c <= 43187 || (c < 65142
        ? (c < 43793
          ? (c < 43600
            ? (c < 43396
              ? (c < 43261
                ? (c < 43250
                  ? (c >= 43216 && c <= 43225)
                  : (c <= 43255 || c == 43259))
                : (c <= 43262 || (c < 43312
                  ? (c >= 43264 && c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))))
              : (c <= 43442 || (c < 43520
                ? (c < 43488
                  ? (c >= 43471 && c <= 43481)
                  : (c <= 43492 || (c >= 43494 && c <= 43518)))
                : (c <= 43560 || (c < 43588
                  ? (c >= 43584 && c <= 43586)
                  : c <= 43595)))))
            : (c <= 43609 || (c < 43712
              ? (c < 43697
                ? (c < 43642
                  ? (c >= 43616 && c <= 43638)
                  : (c <= 43642 || (c >= 43646 && c <= 43695)))
                : (c <= 43697 || (c < 43705
                  ? (c >= 43701 && c <= 43702)
                  : c <= 43709)))
              : (c <= 43712 || (c < 43762
                ? (c < 43739
                  ? c == 43714
                  : (c <= 43741 || (c >= 43744 && c <= 43754)))
                : (c <= 43764 || (c < 43785
                  ? (c >= 43777 && c <= 43782)
                  : c <= 43790)))))))
          : (c <= 43798 || (c < 64275
            ? (c < 44032
              ? (c < 43868
                ? (c < 43816
                  ? (c >= 43808 && c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))
                : (c <= 43881 || (c < 44016
                  ? (c >= 43888 && c <= 44002)
                  : c <= 44025)))
              : (c <= 44032 || (c < 63744
                ? (c < 55216
                  ? c == 55203
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64256
                  ? (c >= 64112 && c <= 64217)
                  : c <= 64262)))))
            : (c <= 64279 || (c < 64323
              ? (c < 64312
                ? (c < 64287
                  ? c == 64285
                  : (c <= 64296 || (c >= 64298 && c <= 64310)))
                : (c <= 64316 || (c < 64320
                  ? c == 64318
                  : c <= 64321)))
              : (c <= 64324 || (c < 64914
                ? (c < 64467
                  ? (c >= 64326 && c <= 64433)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))
                : (c <= 64967 || (c < 65136
                  ? (c >= 65008 && c <= 65019)
                  : c <= 65140)))))))))
        : (c <= 65276 || (c < 66816
          ? (c < 65664
            ? (c < 65498
              ? (c < 65382
                ? (c < 65313
                  ? (c >= 65296 && c <= 65305)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))
                : (c <= 65470 || (c < 65482
                  ? (c >= 65474 && c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))))
              : (c <= 65500 || (c < 65596
                ? (c < 65549
                  ? (c >= 65536 && c <= 65547)
                  : (c <= 65574 || (c >= 65576 && c <= 65594)))
                : (c <= 65597 || (c < 65616
                  ? (c >= 65599 && c <= 65613)
                  : c <= 65629)))))
            : (c <= 65786 || (c < 66432
              ? (c < 66349
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))
                : (c <= 66368 || (c < 66384
                  ? (c >= 66370 && c <= 66377)
                  : c <= 66421)))
              : (c <= 66461 || (c < 66720
                ? (c < 66504
                  ? (c >= 66464 && c <= 66499)
                  : (c <= 66511 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67463
            ? (c < 66979
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : c <= 66977)))
              : (c <= 66993 || (c < 67392
                ? (c < 67003
                  ? (c >= 66995 && c <= 67001)
                  : (c <= 67004 || (c >= 67072 && c <= 67382)))
                : (c <= 67413 || (c < 67456
                  ? (c >= 67424 && c <= 67431)
                  : c <= 67461)))))
            : (c <= 67504 || (c < 67647
              ? (c < 67594
                ? (c < 67584
                  ? (c >= 67506 && c <= 67514)
                  : (c <= 67589 || c == 67592))
                : (c <= 67637 || (c < 67644
                  ? (c >= 67639 && c <= 67640)
                  : c <= 67644)))
              : (c <= 67669 || (c < 67828
                ? (c < 67712
                  ? (c >= 67680 && c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_identifier_character_set_3(int32_t c) {
  return (c < 6320
    ? (c < 2974
      ? (c < 2308
        ? (c < 1369
          ? (c < 748
            ? (c < 181
              ? (c < '_'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= '_' || (c < 162
                  ? (c >= 'b' && c <= 'z')
                  : (c <= 162 || c == 170))))
              : (c <= 181 || (c < 248
                ? (c < 192
                  ? c == 186
                  : (c <= 214 || (c >= 216 && c <= 246)))
                : (c <= 705 || (c < 736
                  ? (c >= 710 && c <= 721)
                  : c <= 740)))))
            : (c <= 748 || (c < 904
              ? (c < 890
                ? (c < 880
                  ? c == 750
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 902
                  ? c == 895
                  : c <= 902)))
              : (c <= 906 || (c < 1015
                ? (c < 910
                  ? c == 908
                  : (c <= 929 || (c >= 931 && c <= 1013)))
                : (c <= 1153 || (c < 1329
                  ? (c >= 1162 && c <= 1327)
                  : c <= 1366)))))))
          : (c <= 1369 || (c < 1869
            ? (c < 1649
              ? (c < 1568
                ? (c < 1488
                  ? (c >= 1376 && c <= 1416)
                  : (c <= 1514 || (c >= 1519 && c <= 1522)))
                : (c <= 1610 || (c < 1646
                  ? (c >= 1632 && c <= 1641)
                  : c <= 1647)))
              : (c <= 1747 || (c < 1791
                ? (c < 1765
                  ? c == 1749
                  : (c <= 1766 || (c >= 1774 && c <= 1788)))
                : (c <= 1791 || (c < 1810
                  ? c == 1808
                  : c <= 1839)))))
            : (c <= 1957 || (c < 2084
              ? (c < 2042
                ? (c < 1984
                  ? c == 1969
                  : (c <= 2026 || (c >= 2036 && c <= 2037)))
                : (c <= 2042 || (c < 2074
                  ? (c >= 2048 && c <= 2069)
                  : c <= 2074)))
              : (c <= 2084 || (c < 2160
                ? (c < 2112
                  ? c == 2088
                  : (c <= 2136 || (c >= 2144 && c <= 2154)))
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2406
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2415 || (c < 2437
                  ? (c >= 2417 && c <= 2432)
                  : (c <= 2444 || (c >= 2447 && c <= 2448)))))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2534 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2654
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : (c <= 2617 || (c >= 2649 && c <= 2652)))
                : (c <= 2654 || (c < 2674
                  ? (c >= 2662 && c <= 2671)
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2858
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2821
                ? (c < 2790
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2799 || c == 2809))
                : (c <= 2828 || (c < 2835
                  ? (c >= 2831 && c <= 2832)
                  : c <= 2856)))))
            : (c <= 2864 || (c < 2929
              ? (c < 2908
                ? (c < 2869
                  ? (c >= 2866 && c <= 2867)
                  : (c <= 2873 || c == 2877))
                : (c <= 2909 || (c < 2918
                  ? (c >= 2911 && c <= 2913)
                  : c <= 2927)))
              : (c <= 2929 || (c < 2962
                ? (c < 2949
                  ? c == 2947
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))
                : (c <= 2965 || (c < 2972
                  ? (c >= 2969 && c <= 2970)
                  : c <= 2972)))))))))))
      : (c <= 2975 || (c < 3840
        ? (c < 3389
          ? (c < 3200
            ? (c < 3090
              ? (c < 3024
                ? (c < 2984
                  ? (c >= 2979 && c <= 2980)
                  : (c <= 2986 || (c >= 2990 && c <= 3001)))
                : (c <= 3024 || (c < 3077
                  ? (c >= 3046 && c <= 3055)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3165
                ? (c < 3133
                  ? (c >= 3114 && c <= 3129)
                  : (c <= 3133 || (c >= 3160 && c <= 3162)))
                : (c <= 3165 || (c < 3174
                  ? (c >= 3168 && c <= 3169)
                  : c <= 3183)))))
            : (c <= 3200 || (c < 3293
              ? (c < 3242
                ? (c < 3214
                  ? (c >= 3205 && c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))
                : (c <= 3251 || (c < 3261
                  ? (c >= 3253 && c <= 3257)
                  : c <= 3261)))
              : (c <= 3294 || (c < 3332
                ? (c < 3302
                  ? (c >= 3296 && c <= 3297)
                  : (c <= 3311 || (c >= 3313 && c <= 3314)))
                : (c <= 3340 || (c < 3346
                  ? (c >= 3342 && c <= 3344)
                  : c <= 3386)))))))
          : (c <= 3389 || (c < 3648
            ? (c < 3482
              ? (c < 3430
                ? (c < 3412
                  ? c == 3406
                  : (c <= 3414 || (c >= 3423 && c <= 3425)))
                : (c <= 3439 || (c < 3461
                  ? (c >= 3450 && c <= 3455)
                  : c <= 3478)))
              : (c <= 3505 || (c < 3558
                ? (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : (c <= 3517 || (c >= 3520 && c <= 3526)))
                : (c <= 3567 || (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : c <= 3635)))))
            : (c <= 3654 || (c < 3751
              ? (c < 3718
                ? (c < 3713
                  ? (c >= 3664 && c <= 3673)
                  : (c <= 3714 || c == 3716))
                : (c <= 3722 || (c < 3749
                  ? (c >= 3724 && c <= 3747)
                  : c <= 3749)))
              : (c <= 3760 || (c < 3782
                ? (c < 3773
                  ? (c >= 3762 && c <= 3763)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))
                : (c <= 3782 || (c < 3804
                  ? (c >= 3792 && c <= 3801)
                  : c <= 3807)))))))))
        : (c <= 3840 || (c < 4800
          ? (c < 4256
            ? (c < 4186
              ? (c < 3976
                ? (c < 3904
                  ? (c >= 3872 && c <= 3881)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4159
                  ? (c >= 4096 && c <= 4138)
                  : (c <= 4169 || (c >= 4176 && c <= 4181)))))
              : (c <= 4189 || (c < 4213
                ? (c < 4197
                  ? c == 4193
                  : (c <= 4198 || (c >= 4206 && c <= 4208)))
                : (c <= 4225 || (c < 4240
                  ? c == 4238
                  : c <= 4249)))))
            : (c <= 4293 || (c < 4696
              ? (c < 4348
                ? (c < 4301
                  ? c == 4295
                  : (c <= 4301 || (c >= 4304 && c <= 4346)))
                : (c <= 4680 || (c < 4688
                  ? (c >= 4682 && c <= 4685)
                  : c <= 4694)))
              : (c <= 4696 || (c < 4752
                ? (c < 4704
                  ? (c >= 4698 && c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4792
                  ? (c >= 4786 && c <= 4789)
                  : c <= 4798)))))))
          : (c <= 4800 || (c < 5888
            ? (c < 5024
              ? (c < 4882
                ? (c < 4808
                  ? (c >= 4802 && c <= 4805)
                  : (c <= 4822 || (c >= 4824 && c <= 4880)))
                : (c <= 4885 || (c < 4992
                  ? (c >= 4888 && c <= 4954)
                  : c <= 5007)))
              : (c <= 5109 || (c < 5761
                ? (c < 5121
                  ? (c >= 5112 && c <= 5117)
                  : (c <= 5740 || (c >= 5743 && c <= 5759)))
                : (c <= 5786 || (c < 5873
                  ? (c >= 5792 && c <= 5866)
                  : c <= 5880)))))
            : (c <= 5905 || (c < 6108
              ? (c < 5998
                ? (c < 5952
                  ? (c >= 5919 && c <= 5937)
                  : (c <= 5969 || (c >= 5984 && c <= 5996)))
                : (c <= 6000 || (c < 6103
                  ? (c >= 6016 && c <= 6067)
                  : c <= 6103)))
              : (c <= 6108 || (c < 6272
                ? (c < 6160
                  ? (c >= 6112 && c <= 6121)
                  : (c <= 6169 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))))))))))))
    : (c <= 6389 || (c < 43138
      ? (c < 8488
        ? (c < 7960
          ? (c < 7043
            ? (c < 6688
              ? (c < 6528
                ? (c < 6470
                  ? (c >= 6400 && c <= 6430)
                  : (c <= 6509 || (c >= 6512 && c <= 6516)))
                : (c <= 6571 || (c < 6608
                  ? (c >= 6576 && c <= 6601)
                  : (c <= 6617 || (c >= 6656 && c <= 6678)))))
              : (c <= 6740 || (c < 6917
                ? (c < 6800
                  ? (c >= 6784 && c <= 6793)
                  : (c <= 6809 || c == 6823))
                : (c <= 6963 || (c < 6992
                  ? (c >= 6981 && c <= 6988)
                  : c <= 7001)))))
            : (c <= 7072 || (c < 7357
              ? (c < 7245
                ? (c < 7168
                  ? (c >= 7086 && c <= 7141)
                  : (c <= 7203 || (c >= 7232 && c <= 7241)))
                : (c <= 7293 || (c < 7312
                  ? (c >= 7296 && c <= 7304)
                  : c <= 7354)))
              : (c <= 7359 || (c < 7418
                ? (c < 7406
                  ? (c >= 7401 && c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7680
                  ? (c >= 7424 && c <= 7615)
                  : c <= 7957)))))))
          : (c <= 7965 || (c < 8150
            ? (c < 8031
              ? (c < 8025
                ? (c < 8008
                  ? (c >= 7968 && c <= 8005)
                  : (c <= 8013 || (c >= 8016 && c <= 8023)))
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))
              : (c <= 8061 || (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))))
            : (c <= 8155 || (c < 8450
              ? (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))
              : (c <= 8450 || (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))))))))
        : (c <= 8488 || (c < 12445
          ? (c < 11648
            ? (c < 11499
              ? (c < 8517
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : (c <= 8505 || (c >= 8508 && c <= 8511)))
                : (c <= 8521 || (c < 8579
                  ? c == 8526
                  : (c <= 8580 || (c >= 11264 && c <= 11492)))))
              : (c <= 11502 || (c < 11565
                ? (c < 11520
                  ? (c >= 11506 && c <= 11507)
                  : (c <= 11557 || c == 11559))
                : (c <= 11565 || (c < 11631
                  ? (c >= 11568 && c <= 11623)
                  : c <= 11631)))))
            : (c <= 11670 || (c < 11728
              ? (c < 11704
                ? (c < 11688
                  ? (c >= 11680 && c <= 11686)
                  : (c <= 11694 || (c >= 11696 && c <= 11702)))
                : (c <= 11710 || (c < 11720
                  ? (c >= 11712 && c <= 11718)
                  : c <= 11726)))
              : (c <= 11734 || (c < 12337
                ? (c < 11823
                  ? (c >= 11736 && c <= 11742)
                  : (c <= 11823 || (c >= 12293 && c <= 12294)))
                : (c <= 12341 || (c < 12353
                  ? (c >= 12347 && c <= 12348)
                  : c <= 12438)))))))
          : (c <= 12447 || (c < 42560
            ? (c < 13312
              ? (c < 12593
                ? (c < 12540
                  ? (c >= 12449 && c <= 12538)
                  : (c <= 12543 || (c >= 12549 && c <= 12591)))
                : (c <= 12686 || (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : c <= 12799)))
              : (c <= 13312 || (c < 42192
                ? (c < 19968
                  ? c == 19903
                  : (c <= 19968 || (c >= 40959 && c <= 42124)))
                : (c <= 42237 || (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : c <= 42539)))))
            : (c <= 42606 || (c < 42963
              ? (c < 42786
                ? (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : (c <= 42725 || (c >= 42775 && c <= 42783)))
                : (c <= 42888 || (c < 42960
                  ? (c >= 42891 && c <= 42954)
                  : c <= 42961)))
              : (c <= 42963 || (c < 43015
                ? (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : (c <= 43009 || (c >= 43011 && c <= 43013)))
                : (c <= 43018 || (c < 43072
                  ? (c >= 43020 && c <= 43042)
                  : c <= 43123)))))))))))
      : (c <= 43187 || (c < 65142
        ? (c < 43793
          ? (c < 43600
            ? (c < 43396
              ? (c < 43261
                ? (c < 43250
                  ? (c >= 43216 && c <= 43225)
                  : (c <= 43255 || c == 43259))
                : (c <= 43262 || (c < 43312
                  ? (c >= 43264 && c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))))
              : (c <= 43442 || (c < 43520
                ? (c < 43488
                  ? (c >= 43471 && c <= 43481)
                  : (c <= 43492 || (c >= 43494 && c <= 43518)))
                : (c <= 43560 || (c < 43588
                  ? (c >= 43584 && c <= 43586)
                  : c <= 43595)))))
            : (c <= 43609 || (c < 43712
              ? (c < 43697
                ? (c < 43642
                  ? (c >= 43616 && c <= 43638)
                  : (c <= 43642 || (c >= 43646 && c <= 43695)))
                : (c <= 43697 || (c < 43705
                  ? (c >= 43701 && c <= 43702)
                  : c <= 43709)))
              : (c <= 43712 || (c < 43762
                ? (c < 43739
                  ? c == 43714
                  : (c <= 43741 || (c >= 43744 && c <= 43754)))
                : (c <= 43764 || (c < 43785
                  ? (c >= 43777 && c <= 43782)
                  : c <= 43790)))))))
          : (c <= 43798 || (c < 64275
            ? (c < 44032
              ? (c < 43868
                ? (c < 43816
                  ? (c >= 43808 && c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))
                : (c <= 43881 || (c < 44016
                  ? (c >= 43888 && c <= 44002)
                  : c <= 44025)))
              : (c <= 44032 || (c < 63744
                ? (c < 55216
                  ? c == 55203
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64256
                  ? (c >= 64112 && c <= 64217)
                  : c <= 64262)))))
            : (c <= 64279 || (c < 64323
              ? (c < 64312
                ? (c < 64287
                  ? c == 64285
                  : (c <= 64296 || (c >= 64298 && c <= 64310)))
                : (c <= 64316 || (c < 64320
                  ? c == 64318
                  : c <= 64321)))
              : (c <= 64324 || (c < 64914
                ? (c < 64467
                  ? (c >= 64326 && c <= 64433)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))
                : (c <= 64967 || (c < 65136
                  ? (c >= 65008 && c <= 65019)
                  : c <= 65140)))))))))
        : (c <= 65276 || (c < 66816
          ? (c < 65664
            ? (c < 65498
              ? (c < 65382
                ? (c < 65313
                  ? (c >= 65296 && c <= 65305)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))
                : (c <= 65470 || (c < 65482
                  ? (c >= 65474 && c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))))
              : (c <= 65500 || (c < 65596
                ? (c < 65549
                  ? (c >= 65536 && c <= 65547)
                  : (c <= 65574 || (c >= 65576 && c <= 65594)))
                : (c <= 65597 || (c < 65616
                  ? (c >= 65599 && c <= 65613)
                  : c <= 65629)))))
            : (c <= 65786 || (c < 66432
              ? (c < 66349
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66304 && c <= 66335)))
                : (c <= 66368 || (c < 66384
                  ? (c >= 66370 && c <= 66377)
                  : c <= 66421)))
              : (c <= 66461 || (c < 66720
                ? (c < 66504
                  ? (c >= 66464 && c <= 66499)
                  : (c <= 66511 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67463
            ? (c < 66979
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : c <= 66977)))
              : (c <= 66993 || (c < 67392
                ? (c < 67003
                  ? (c >= 66995 && c <= 67001)
                  : (c <= 67004 || (c >= 67072 && c <= 67382)))
                : (c <= 67413 || (c < 67456
                  ? (c >= 67424 && c <= 67431)
                  : c <= 67461)))))
            : (c <= 67504 || (c < 67647
              ? (c < 67594
                ? (c < 67584
                  ? (c >= 67506 && c <= 67514)
                  : (c <= 67589 || c == 67592))
                : (c <= 67637 || (c < 67644
                  ? (c >= 67639 && c <= 67640)
                  : c <= 67644)))
              : (c <= 67669 || (c < 67828
                ? (c < 67712
                  ? (c >= 67680 && c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(93);
      if (lookahead == '"') ADVANCE(139);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == ',') ADVANCE(103);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '0') ADVANCE(131);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '=') ADVANCE(146);
      if (lookahead == '\\') ADVANCE(69);
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 'c') ADVANCE(6);
      if (lookahead == 'f') ADVANCE(15);
      if (lookahead == 'i') ADVANCE(35);
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 'r') ADVANCE(26);
      if (lookahead == 's') ADVANCE(66);
      if (lookahead == 't') ADVANCE(55);
      if (lookahead == 'u') ADVANCE(37);
      if (lookahead == 'v') ADVANCE(46);
      if (lookahead == '{') ADVANCE(95);
      if (lookahead == '}') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(92)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(157);
      if (lookahead == 'u') ADVANCE(154);
      if (lookahead == 'x') ADVANCE(155);
      if (lookahead != 0) ADVANCE(148);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(139);
      if (lookahead == '/') ADVANCE(150);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0) ADVANCE(156);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == 'b') ADVANCE(106);
      if (lookahead == 'c') ADVANCE(107);
      if (lookahead == 'f') ADVANCE(108);
      if (lookahead == 't') ADVANCE(114);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(130);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(120);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == '-') ADVANCE(80);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == 'b') ADVANCE(106);
      if (lookahead == 'c') ADVANCE(107);
      if (lookahead == 'f') ADVANCE(108);
      if (lookahead == 'r') ADVANCE(109);
      if (lookahead == 't') ADVANCE(114);
      if (lookahead == '}') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(130);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(120);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == 'o') ADVANCE(50);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == 'h') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(144);
      END_STATE();
    case 8:
      if (lookahead == '\'') ADVANCE(144);
      if (lookahead == '\\') ADVANCE(72);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(158);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(159);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '.') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(120);
      END_STATE();
    case 14:
      if (lookahead == '/') ADVANCE(150);
      if (lookahead == '\\') ADVANCE(91);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(156);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(32);
      if (lookahead == 'l') ADVANCE(49);
      if (lookahead == 'r') ADVANCE(47);
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(56);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(63);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(41);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(68);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(125);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(140);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(142);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 27:
      if (lookahead == 'g') ADVANCE(123);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(52);
      END_STATE();
    case 31:
      if (lookahead == 'k') ADVANCE(45);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(25);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 35:
      if (lookahead == 'm') ADVANCE(54);
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 36:
      if (lookahead == 'm') ADVANCE(97);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(104);
      END_STATE();
    case 41:
      if (lookahead == 'n') ADVANCE(124);
      END_STATE();
    case 42:
      if (lookahead == 'n') ADVANCE(127);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(99);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(63);
      END_STATE();
    case 45:
      if (lookahead == 'n') ADVANCE(48);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 48:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 50:
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 51:
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 52:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 53:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 54:
      if (lookahead == 'p') ADVANCE(51);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(70);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(126);
      END_STATE();
    case 57:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 58:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 59:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 60:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(145);
      END_STATE();
    case 63:
      if (lookahead == 't') ADVANCE(128);
      END_STATE();
    case 64:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(94);
      END_STATE();
    case 66:
      if (lookahead == 't') ADVANCE(57);
      END_STATE();
    case 67:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 68:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 69:
      if (lookahead == 'u') ADVANCE(74);
      if (lookahead == 'x') ADVANCE(87);
      if (lookahead != 0) ADVANCE(157);
      END_STATE();
    case 70:
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 71:
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 72:
      if (lookahead == 'u') ADVANCE(75);
      if (lookahead == 'x') ADVANCE(88);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 73:
      if (lookahead == 'w') ADVANCE(42);
      END_STATE();
    case 74:
      if (lookahead == '{') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(83);
      END_STATE();
    case 75:
      if (lookahead == '{') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(89);
      END_STATE();
    case 76:
      if (lookahead == '}') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 77:
      if (lookahead == '}') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 78:
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(132);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(133);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 81:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 82:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(87);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(157);
      END_STATE();
    case 85:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 86:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 87:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(84);
      END_STATE();
    case 88:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(82);
      END_STATE();
    case 89:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(88);
      END_STATE();
    case 90:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(136);
      END_STATE();
    case 91:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(148);
      END_STATE();
    case 92:
      if (eof) ADVANCE(93);
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == ',') ADVANCE(103);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '0') ADVANCE(131);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '=') ADVANCE(146);
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 'c') ADVANCE(6);
      if (lookahead == 'f') ADVANCE(15);
      if (lookahead == 'i') ADVANCE(35);
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 'r') ADVANCE(26);
      if (lookahead == 's') ADVANCE(66);
      if (lookahead == 't') ADVANCE(55);
      if (lookahead == 'u') ADVANCE(37);
      if (lookahead == 'v') ADVANCE(46);
      if (lookahead == '{') ADVANCE(95);
      if (lookahead == '}') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(92)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_return);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '"') ADVANCE(138);
      if (lookahead == '\'') ADVANCE(8);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '"') ADVANCE(138);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(112);
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(120);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(117);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(141);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(143);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(116);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(105);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(118);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(113);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(111);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(119);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(110);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(115);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_unknown);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_integer_literal);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(81);
      if (lookahead == '_') ADVANCE(134);
      if (lookahead == 'b') ADVANCE(78);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == 'o') ADVANCE(79);
      if (lookahead == 'x') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(81);
      if (lookahead == '_') ADVANCE(134);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'i') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'b') ADVANCE(78);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == 'o') ADVANCE(79);
      if (lookahead == 'x') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(134);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == '0' ||
          lookahead == '1' ||
          lookahead == '_') ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'i') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '7') ||
          lookahead == '_') ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'f') ADVANCE(34);
      if (lookahead == 'i') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'f') ADVANCE(135);
      if (lookahead == 'i') ADVANCE(44);
      if (lookahead == 'l') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(136);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == 'f') ADVANCE(135);
      if (lookahead == 'i') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_float_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_true);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_false);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(120);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_char_literal);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym__string_content);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '\n') ADVANCE(156);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(158);
      if (lookahead != 0) ADVANCE(149);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '*') ADVANCE(152);
      if (lookahead == '/') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(156);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '/') ADVANCE(156);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(11);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(11);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '/') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(156);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead == '{') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(83);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym__string_content);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(84);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym__string_content);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(156);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_block_comment);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 4},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 13},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 13},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 13},
  [59] = {.lex_state = 14},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 13},
  [63] = {.lex_state = 13},
  [64] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_from] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_void] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_unknown] = ACTIONS(1),
    [sym_integer_literal] = ACTIONS(1),
    [aux_sym_string_literal_token1] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_char_literal] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_program] = STATE(57),
    [sym__statement] = STATE(9),
    [sym_import_statement] = STATE(9),
    [sym_function_declaration] = STATE(9),
    [sym_variable_declaration] = STATE(9),
    [aux_sym_program_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_import] = ACTIONS(7),
    [anon_sym_function] = ACTIONS(9),
    [anon_sym_let] = ACTIONS(11),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(13), 1,
      anon_sym_RBRACE,
    ACTIONS(15), 1,
      anon_sym_return,
    ACTIONS(18), 1,
      sym_identifier,
    ACTIONS(21), 1,
      sym_integer_literal,
    ACTIONS(27), 1,
      aux_sym_string_literal_token1,
    STATE(46), 1,
      sym_expression,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(24), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(30), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
    STATE(2), 4,
      sym__function_body,
      sym_expression_statement,
      sym_return_statement,
      aux_sym_function_declaration_repeat1,
  [45] = 12,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    ACTIONS(35), 1,
      anon_sym_return,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_integer_literal,
    ACTIONS(43), 1,
      aux_sym_string_literal_token1,
    STATE(46), 1,
      sym_expression,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(41), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(45), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
    STATE(4), 4,
      sym__function_body,
      sym_expression_statement,
      sym_return_statement,
      aux_sym_function_declaration_repeat1,
  [90] = 12,
    ACTIONS(35), 1,
      anon_sym_return,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_integer_literal,
    ACTIONS(43), 1,
      aux_sym_string_literal_token1,
    ACTIONS(47), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      sym_expression,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(41), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(45), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
    STATE(2), 4,
      sym__function_body,
      sym_expression_statement,
      sym_return_statement,
      aux_sym_function_declaration_repeat1,
  [135] = 11,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_integer_literal,
    ACTIONS(43), 1,
      aux_sym_string_literal_token1,
    ACTIONS(49), 1,
      anon_sym_RPAREN,
    STATE(37), 1,
      sym_expression,
    STATE(50), 1,
      sym_arguments,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(41), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(45), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
  [174] = 9,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_integer_literal,
    ACTIONS(43), 1,
      aux_sym_string_literal_token1,
    STATE(39), 1,
      sym_expression,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(41), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(45), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
  [207] = 9,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_integer_literal,
    ACTIONS(43), 1,
      aux_sym_string_literal_token1,
    STATE(40), 1,
      sym_expression,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(41), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(45), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
  [240] = 9,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(39), 1,
      sym_integer_literal,
    ACTIONS(43), 1,
      aux_sym_string_literal_token1,
    STATE(54), 1,
      sym_expression,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(41), 2,
      sym_float_literal,
      sym_char_literal,
    ACTIONS(45), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(29), 2,
      sym_string_literal,
      sym_boolean_literal,
    STATE(31), 2,
      sym_function_call,
      sym_literal,
  [273] = 6,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_function,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(10), 5,
      sym__statement,
      sym_import_statement,
      sym_function_declaration,
      sym_variable_declaration,
      aux_sym_program_repeat1,
  [297] = 6,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    ACTIONS(55), 1,
      anon_sym_import,
    ACTIONS(58), 1,
      anon_sym_function,
    ACTIONS(61), 1,
      anon_sym_let,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(10), 5,
      sym__statement,
      sym_import_statement,
      sym_function_declaration,
      sym_variable_declaration,
      aux_sym_program_repeat1,
  [321] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(64), 4,
      anon_sym_RBRACE,
      sym_float_literal,
      aux_sym_string_literal_token1,
      sym_char_literal,
    ACTIONS(66), 5,
      anon_sym_return,
      sym_identifier,
      sym_integer_literal,
      anon_sym_true,
      anon_sym_false,
  [339] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(68), 4,
      anon_sym_RBRACE,
      sym_float_literal,
      aux_sym_string_literal_token1,
      sym_char_literal,
    ACTIONS(70), 5,
      anon_sym_return,
      sym_identifier,
      sym_integer_literal,
      anon_sym_true,
      anon_sym_false,
  [357] = 3,
    STATE(51), 1,
      sym_type_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(72), 7,
      anon_sym_int,
      anon_sym_float,
      anon_sym_string,
      anon_sym_boolean,
      anon_sym_void,
      anon_sym_char,
      anon_sym_unknown,
  [374] = 3,
    STATE(41), 1,
      sym_type_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(72), 7,
      anon_sym_int,
      anon_sym_float,
      anon_sym_string,
      anon_sym_boolean,
      anon_sym_void,
      anon_sym_char,
      anon_sym_unknown,
  [391] = 3,
    STATE(27), 1,
      sym_type_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(72), 7,
      anon_sym_int,
      anon_sym_float,
      anon_sym_string,
      anon_sym_boolean,
      anon_sym_void,
      anon_sym_char,
      anon_sym_unknown,
  [408] = 3,
    STATE(61), 1,
      sym_type_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(72), 7,
      anon_sym_int,
      anon_sym_float,
      anon_sym_string,
      anon_sym_boolean,
      anon_sym_void,
      anon_sym_char,
      anon_sym_unknown,
  [425] = 4,
    ACTIONS(74), 1,
      anon_sym_DQUOTE,
    STATE(17), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(76), 2,
      sym__string_content,
      sym_escape_sequence,
    ACTIONS(79), 2,
      sym_line_comment,
      sym_block_comment,
  [440] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(81), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_function,
      anon_sym_let,
  [451] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(83), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_function,
      anon_sym_let,
  [462] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(85), 4,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ,
  [473] = 4,
    ACTIONS(87), 1,
      anon_sym_DQUOTE,
    STATE(17), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(79), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(89), 2,
      sym__string_content,
      sym_escape_sequence,
  [488] = 4,
    ACTIONS(91), 1,
      anon_sym_DQUOTE,
    STATE(21), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(79), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(93), 2,
      sym__string_content,
      sym_escape_sequence,
  [503] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(95), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_function,
      anon_sym_let,
  [514] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(97), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_function,
      anon_sym_let,
  [525] = 3,
    ACTIONS(101), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(99), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [538] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(103), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [548] = 4,
    ACTIONS(105), 1,
      anon_sym_RPAREN,
    ACTIONS(107), 1,
      anon_sym_COMMA,
    STATE(32), 1,
      aux_sym_parameter_list_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [562] = 4,
    ACTIONS(109), 1,
      anon_sym_RPAREN,
    ACTIONS(111), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [576] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(114), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [586] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(116), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [596] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(99), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [606] = 4,
    ACTIONS(107), 1,
      anon_sym_COMMA,
    ACTIONS(118), 1,
      anon_sym_RPAREN,
    STATE(38), 1,
      aux_sym_parameter_list_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [620] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(120), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [630] = 4,
    ACTIONS(122), 1,
      anon_sym_RPAREN,
    ACTIONS(124), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [644] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(126), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [654] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(128), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [664] = 4,
    ACTIONS(124), 1,
      anon_sym_COMMA,
    ACTIONS(130), 1,
      anon_sym_RPAREN,
    STATE(34), 1,
      aux_sym_arguments_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [678] = 4,
    ACTIONS(132), 1,
      anon_sym_RPAREN,
    ACTIONS(134), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_parameter_list_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [692] = 3,
    ACTIONS(137), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym__semicolon,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [703] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(109), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [712] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(139), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [721] = 3,
    ACTIONS(141), 1,
      anon_sym_COLON,
    STATE(48), 1,
      sym_return_type,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [732] = 3,
    ACTIONS(143), 1,
      sym_identifier,
    STATE(45), 1,
      sym_parameter_list,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [743] = 2,
    ACTIONS(145), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [751] = 2,
    ACTIONS(147), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [759] = 2,
    ACTIONS(149), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [767] = 2,
    ACTIONS(151), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [775] = 2,
    ACTIONS(153), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [783] = 2,
    ACTIONS(155), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [791] = 2,
    ACTIONS(157), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [799] = 2,
    ACTIONS(159), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [807] = 2,
    ACTIONS(161), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [815] = 2,
    ACTIONS(163), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [823] = 2,
    ACTIONS(165), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [831] = 2,
    ACTIONS(167), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [839] = 2,
    ACTIONS(169), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [847] = 2,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [855] = 2,
    ACTIONS(173), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [863] = 2,
    ACTIONS(175), 1,
      sym__string_content,
    ACTIONS(79), 2,
      sym_line_comment,
      sym_block_comment,
  [871] = 2,
    ACTIONS(177), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [879] = 2,
    ACTIONS(179), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [887] = 2,
    ACTIONS(181), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [895] = 2,
    ACTIONS(183), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [903] = 2,
    ACTIONS(185), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 45,
  [SMALL_STATE(4)] = 90,
  [SMALL_STATE(5)] = 135,
  [SMALL_STATE(6)] = 174,
  [SMALL_STATE(7)] = 207,
  [SMALL_STATE(8)] = 240,
  [SMALL_STATE(9)] = 273,
  [SMALL_STATE(10)] = 297,
  [SMALL_STATE(11)] = 321,
  [SMALL_STATE(12)] = 339,
  [SMALL_STATE(13)] = 357,
  [SMALL_STATE(14)] = 374,
  [SMALL_STATE(15)] = 391,
  [SMALL_STATE(16)] = 408,
  [SMALL_STATE(17)] = 425,
  [SMALL_STATE(18)] = 440,
  [SMALL_STATE(19)] = 451,
  [SMALL_STATE(20)] = 462,
  [SMALL_STATE(21)] = 473,
  [SMALL_STATE(22)] = 488,
  [SMALL_STATE(23)] = 503,
  [SMALL_STATE(24)] = 514,
  [SMALL_STATE(25)] = 525,
  [SMALL_STATE(26)] = 538,
  [SMALL_STATE(27)] = 548,
  [SMALL_STATE(28)] = 562,
  [SMALL_STATE(29)] = 576,
  [SMALL_STATE(30)] = 586,
  [SMALL_STATE(31)] = 596,
  [SMALL_STATE(32)] = 606,
  [SMALL_STATE(33)] = 620,
  [SMALL_STATE(34)] = 630,
  [SMALL_STATE(35)] = 644,
  [SMALL_STATE(36)] = 654,
  [SMALL_STATE(37)] = 664,
  [SMALL_STATE(38)] = 678,
  [SMALL_STATE(39)] = 692,
  [SMALL_STATE(40)] = 703,
  [SMALL_STATE(41)] = 712,
  [SMALL_STATE(42)] = 721,
  [SMALL_STATE(43)] = 732,
  [SMALL_STATE(44)] = 743,
  [SMALL_STATE(45)] = 751,
  [SMALL_STATE(46)] = 759,
  [SMALL_STATE(47)] = 767,
  [SMALL_STATE(48)] = 775,
  [SMALL_STATE(49)] = 783,
  [SMALL_STATE(50)] = 791,
  [SMALL_STATE(51)] = 799,
  [SMALL_STATE(52)] = 807,
  [SMALL_STATE(53)] = 815,
  [SMALL_STATE(54)] = 823,
  [SMALL_STATE(55)] = 831,
  [SMALL_STATE(56)] = 839,
  [SMALL_STATE(57)] = 847,
  [SMALL_STATE(58)] = 855,
  [SMALL_STATE(59)] = 863,
  [SMALL_STATE(60)] = 871,
  [SMALL_STATE(61)] = 879,
  [SMALL_STATE(62)] = 887,
  [SMALL_STATE(63)] = 895,
  [SMALL_STATE(64)] = 903,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_declaration_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(8),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(25),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(29),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(29),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(22),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(30),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(64),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(62),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(58),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 3),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_statement, 3),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 2),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_statement, 2),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(17),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 8),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 7),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 1),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 9),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 7),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_call, 3),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arguments_repeat1, 2), SHIFT_REPEAT(7),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_call, 4),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arguments, 1),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(63),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 4),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [171] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [175] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_type, 2),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ignis(void) {
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
