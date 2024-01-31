const numeric_types = [
  'float',
  'int',
];

module.exports = grammar({
  name: 'ignis',

  extras: $ => [
    $.line_comment,
    $.block_comment,
    /\s/
  ],

  rules: {
    program: $ => repeat($._statement),

    _statement: $ => choice(
      $.import_statement,
      $.function_declaration,
      $.variable_declaration,
    ),

    import_statement: $ => seq(
      'import',
      '{', $.identifier, '}',
      'from',
      $._string_content,
      ';'
    ),

    function_declaration: $ => seq(
      'function',
      $.identifier,
      '(', $.parameter_list, ')',
      $.return_type,
      '{', repeat($._function_body), '}'
    ),

    parameter_list: $ => seq(
      $.identifier,
      ':',
      $.type_identifier,
      repeat(seq(
        ',',
        $.identifier,
        ':',
        $.type_identifier
      ))
    ),

    return_type: $ => seq(
      ':',
      $.type_identifier,
    ),

    _function_body: $ => choice(
      $.expression_statement,
      $.return_statement,
    ),

    expression_statement: $ => seq(
      $.expression,
      ';'
    ),

    expression: $ => choice(
      $.literal,
      $.identifier,
      $.function_call,
    ),

    function_call: $ => seq(
      $.identifier,
      '(',
      optional($.arguments),
      ')'
    ),

    arguments: $ => seq(
      $.expression,
      repeat(seq(
        ',',
        $.expression
      ))
    ),

    return_statement: $ => seq(
      'return',
      $.expression,
      ';'
    ),

    identifier: $ => /[\p{L}_$][\p{L}\p{Nd}\u00A2_$]*/,

    type_identifier: $ => choice(
      'int',
      'float',
      'string',
      'boolean',
      'void',
      'char',
      'unknown',
    ),

    literal: $ => choice(
      $.integer_literal,
      $.float_literal,
      $.string_literal,
      $.boolean_literal,
      $.char_literal,
    ),

    integer_literal: _ => /-?[0-9]+[?_0-9]/,
    float_literal: _ => /-?[0-9]+\.[0-9]+/,
    string_literal: _ => /"[^"]*"/,
    boolean_literal: _ => choice('true', 'false'),
    char_literal: _ => /'.'/,

    variable_declaration: $ => seq(
      'let',
      $.identifier,
      ':',
      $.type_identifier,
      '=',
      $.expression,
      $._semicolon
    ),

    negative_literal: $ => seq('-', choice($.integer_literal, $.float_literal)),

    integer_literal: _ => token(seq(
      choice(
        /[0-9][0-9_]*/,
        /0x[0-9a-fA-F_]+/,
        /0b[01_]+/,
        /0o[0-7_]+/,
      ),
      optional(choice(...numeric_types)),
    )),

    _string_content: _ => token.immediate(choice(
      /[^"\\]+/,
      /\\./,
    )),

    string_literal: $ => seq(
      alias(/[bc]?"/, '"'),
      repeat(choice(
        $.escape_sequence,
        $._string_content,
      )),
      token.immediate('"'),
    ),

    char_literal: _ => token(seq(
      optional('b'),
      '\'',
      optional(choice(
        seq('\\', choice(
          /[^xu]/,
          /u[0-9a-fA-F]{4}/,
          /u{[0-9a-fA-F]+}/,
          /x[0-9a-fA-F]{2}/,
        )),
        /[^\\']/,
      )),
      '\'',
    )),

    escape_sequence: _ => token.immediate(
      seq('\\',
        choice(
          /[^xu]/,
          /u[0-9a-fA-F]{4}/,
          /u{[0-9a-fA-F]+}/,
          /x[0-9a-fA-F]{2}/,
        ),
      )),

    line_comment: _ => token(seq('//', /.*/)),
    block_comment: _ => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')),
    _semicolon: _ => ';',
  }
});
