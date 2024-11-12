const PREC = {
  CALL: 15,
  FIELD: 14,
  TRY: 13,
  UNARY: 12,
  CAST: 11,
  MULTIPLICATIVE: 10,
  ADDITIVE: 9,
  SHIFT: 8,
  BITAND: 7,
  BITXOR: 6,
  BITOR: 5,
  COMPARATIVE: 4,
  AND: 3,
  OR: 2,
  RANGE: 1,
  ASSIGN: 0,
  CLOSURE: -1,
};

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)), optional(','));
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}

function pipeSepRepeat(rule) {
  return seq(rule, repeat(seq('|', rule)));
}

function optionalPipeSep(rule) {
  return optional(pipeSepRepeat(rule));
}

const PRIMITIVE_TYPES = [
  'u8',
  'u16',
  'u32',
  'u64',
  'i8',
  'i16',
  'i32',
  'i64',
  'f32',
  'f64',
  'boolean',
  'char',
  'string',
  'void',
  'unknown',
  'hex',
  'binary',
];

const KEYWORDS = [
  'abstract',
  'as',
  'async',
  'await',
  'break',
  'continue',
  'class',
  'const',
  'declare',
  'else',
  'enum',
  'export',
  'extends',
  'false',
  'for',
  'from',
  'function',
  'is',
  'if',
  'implements',
  'import',
  'in',
  'interface',
  'let',
  'meta',
  'namespace',
  'new',
  'null',
  'private',
  'public',
  'record',
  'return',
  'static',
  'this',
  'true',
  'type',
  'typeof',
  'void',
  'when',
  'while',
  'with',
  'mut',
  'override',
  'super',
];

const SEPARATORS = [',', ';', ':'];
const DELIMITERS = ['.', '[', ']', '(', ')', '{', '}'];
const ASSIGNMENT_OPERATORS = ['=', '+=', '-=', '*=', '/=', '%=', '&=', '|=', '^=', '<<=', '>>='];
const SYMBOLS = [
  ...SEPARATORS,
  ...DELIMITERS,
  '.',
  '+',
  '-',
  '*',
  '/',
  '%',
  '&',
  '|',
  '^',
  '<<',
  '>>',
  '<',
  '>',
  '<=',
  '>=',
  '==',
  '!=',
  '!',
  '~',
  '?',
  ':',
  '||',
  '&&',
  '++',
  '--',
];

module.exports = grammar({
  name: 'ignis',

  extras: ($) => [/\s/, $.doc_comment, $.comment],
  words: (_) => KEYWORDS,

  conflicts: ($, previous) =>
    previous.concat([
      [$.call_expression, $.expression],
      [$.prefix_unary_expression, $.suffix_unary_expression],
      [$.primary_expression, $.vector_access_expression],
      [$.primary_expression, $.get_expression],
      [$._expression, $.primary_expression],
      [$.method_declaration, $.primary_expression],
      [$.for_statement, $.expression],
      [$.interface_method_declaration],
      [$.decorator_use],
      [$.function_declaration],
      [$.block, $.object_literal],
      [$.method_modifier, $.property_modifier],
      [$.union_type, $.intersection_type, $.type_expression],
      [$.union_type, $.intersection_type, $.type_expression, $.vector_type],
      [$.lambda_expression, $._expression],
    ]),

  rules: {
    source_file: ($) => repeat($._definition),

    _definition: ($) =>
      choice(
        $.export_statement,
        $.import_statement,
        $.class_declaration,
        $.function_declaration,
        $.variable_declaration,
        $.interface_declaration,
        $.enum_declaration,
        $.type_definition,
        $.record_declaration,
        $.extern_declaration,
        $.decorator_declaration,
        $.decorator_use,
        $.metadata_declaration,
        $.namespace_declaration,
        $.const_declaration,
        $.expression,
      ),

    type_definition: ($) => seq('type', $.identifier, '=', $.type_expression, ';'),

    export_statement: ($) =>
      seq(
        'export',
        choice(
          $.class_declaration,
          $.function_declaration,
          $.interface_declaration,
          $.enum_declaration,
          $.type_definition,
          $.record_declaration,
          $.extern_declaration,
          $.decorator_declaration,
          $.metadata_declaration,
        ),
      ),

    enum_declaration: ($) =>
      seq(
        'enum',
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '{',
        commaSep($.enum_member_declaration),
        '}',
      ),

    enum_member_declaration: ($) =>
      seq(
        field('name', $.identifier),
        choice(optional(seq('=', $.expression)), optional(seq('(', $.expression, ')'))),
      ),

    import_statement: ($) =>
      seq(
        'import',
        '{',
        commaSep1(seq($.identifier, optional(seq('as', $.identifier)))),
        '}',
        'from',
        $.string_literal,
        ';',
      ),

    // #region Class
    interface_declaration: ($) =>
      seq(
        'interface',
        field('name', $.identifier),
        optional(commaSep1($.generic_type_declaration)),
        '{',
        repeat($.interface_method_declaration),
        '}',
      ),

    interface_method_declaration: ($) =>
      seq(
        field('function', $.identifier),
        optional(commaSep1($.generic_type_declaration)),
        '(',
        commaSep1(optional($.parameter_declaration)),
        ')',
        ':',
        $.type_expression,
        ';',
      ),

    implement_statement: ($) =>
      seq('implements', commaSep1(seq($.identifier, optional($.generic_type_declaration)))),

    extends_statement: ($) => seq('extends', $.identifier, optional($.generic_type_declaration)),

    class_declaration: ($) =>
      prec(
        1,
        seq(
          optional($.class_modifier),
          'class',
          optional($.generic_type_declaration),
          $.identifier,
          optional(choice($.extends_statement, $.implement_statement)),
          '{',
          repeat($._class_body_declaration),
          '}',
        ),
      ),

    class_instance_expression: ($) =>
      seq(
        'new',
        $.identifier,
        optional(repeat($.generic_type_declaration)),
        '(',
        optional(commaSep1($.expression)),
        ')',
      ),

    _class_body_declaration: ($) =>
      choice($.constructor_declaration, $.method_declaration, $.property_declaration),

    this_expression: (_) => 'this',

    primary_expression: ($) =>
      choice(
        $.identifier,
        $.this_expression,
        $.method_call_expression,
        $.literal,
        $.group_expression,
        $.vector_access_expression,
        $.class_instance_expression,
        $.lambda_expression,
      ),

    // <lambda> ::= "(" <parameters>? ")" ":" <type> "->" (<expression> | <block>)
    lambda_expression: ($) =>
      seq(
        '(',
        optional($.parameter_declaration),
        ')',
        ':',
        $.type_expression,
        '->',
        choice($.expression, $.block),
      ),

    property_access: ($) =>
      prec(PREC.FIELD, seq($.expression, choice('.', '::'), field('name', $.identifier))),

    get_expression: ($) => choice($.property_access, $.method_call_expression),

    method_call_expression: ($) =>
      prec(
        PREC.CALL,
        seq(
          field('function', $.property_access),
          optional($.generic_type_declaration),
          '(',
          commaSep(field('arguments', $.expression)),
          ')',
        ),
      ),

    constructor_declaration: ($) =>
      seq(
        optional(repeat($.method_modifier)),
        $.identifier,
        optional($.generic_type_declaration),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        optional($.block),
      ),

    property_declaration: ($) =>
      seq(optional(repeat($.property_modifier)), $.identifier, ':', $.type_expression, ';'),

    method_declaration: ($) =>
      seq(
        optional(repeat($.method_modifier)),
        field('name', $.identifier),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        ':',
        $.type_expression,
        $.block,
      ),

    record_property_declaration: ($) =>
      seq(
        field('name', $.identifier),
        optional($.variable_modifiers),
        optional($.generic_type_declaration),
        optional('?'),
        ':',
        $.type_expression,
        ';',
      ),

    record_method_declaration: ($) =>
      seq(
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        optional('?'),
        ':',
        $.type_expression,
        ';',
      ),

    record_declaration: ($) =>
      seq(
        'record',
        optional($.generic_type_declaration),
        optional($.variable_modifiers),
        $.type_expression,
        '{',
        repeat(
          seq(
            optional($.metadata_expression),
            choice($.record_property_declaration, $.record_method_declaration, $.decorator_use),
          ),
        ),
        '}',
      ),

    extern_declaration: ($) => seq('extern', optional($.identifier), '{', repeat($.extern_items), '}'),
    extern_items: ($) =>
      choice(
        $.function_declaration,
        $.enum_declaration,
        $.record_declaration,
        $.export_statement,
        $.class_declaration,
        $.interface_declaration,
      ),

    decorator_use: ($) => seq('@', $.identifier, optional(seq('(', optional(commaSep($.expression)), ')'))),

    decorator_declaration: ($) =>
      seq(
        'decorator',
        $.identifier,
        optional($.generic_type_declaration),
        optional(seq('(', optional(commaSep($.type_expression)), ')')),
        ';',
      ),

    metadata_declaration: ($) =>
      prec.left(
        seq(
          'meta',
          $.identifier,
          optional(seq('(', optional(commaSep1(choice($.parameter_declaration, $.type_expression))), ')')),
          ';',
        ),
      ),

    metadata_expression: ($) =>
      seq(
        '#',
        '[',
        repeat(
          seq(
            $.identifier,
            optional(commaSep1(seq('(', optional(commaSep($.expression)), ')'))),
            optional(','),
          ),
        ),
        ']',
      ),

    namespace_declaration: ($) => seq('namespace', $.identifier, '{', repeat($.namespace_items), '}'),
    namespace_items: ($) =>
      choice(
        $.function_declaration,
        $.class_declaration,
        $.record_declaration,
        $.enum_declaration,
        $.type_definition,
        $.const_declaration,
        $.export_statement,
      ),

    // #endregion
    // #region Function
    generic_type_declaration: ($) => seq('<', commaSep1(choice($.type_expression, $.cast)), '>'),

    function_declaration: ($) =>
      seq(
        'function',
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '(',
        commaSep($.parameter_declaration),
        ')',
        ':',
        $.type_expression,
        choice($.block, ';'),
      ),

    return_statement: ($) => seq('return', $.expression, ';'),

    // #endregion

    assignment_expression: ($) =>
      prec(
        PREC.ASSIGN,
        seq(
          field('name', choice($.identifier, $.property_access)),
          choice(...ASSIGNMENT_OPERATORS),
          $.expression,
          ';',
        ),
      ),

    reference_operator: (_) => '&',
    mutable_specifier: (_) => 'mut',
    pointer_specifier: (_) => '*',
    variable_modifiers: ($) =>
      seq(repeat1(choice($.mutable_specifier, $.reference_operator, $.pointer_specifier))),

    const_declaration: ($) =>
      seq('const', field('name', $.identifier), ':', $.type_expression, '=', $.expression, ';'),

    variable_declaration: ($) =>
      seq(
        token('let'),
        optional($.variable_modifiers),
        field('name', $.identifier),
        token(':'),
        field('type', $.type_expression),
        optional(seq('=', field('value', $.expression))),
        token(';'),
      ),

    parameter_declaration: ($) =>
      seq(
        optional($.metadata_expression),
        optional('...'),
        field('name', $.identifier),
        token(':'),
        optional($.variable_modifiers),
        $.type_expression,
      ),

    block: ($) => seq('{', repeat($._statement), '}'),

    _statement: ($) =>
      choice(
        $.variable_declaration,
        $.return_statement,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.for_of_statement,
        $.assignment_expression,
        $.expression_statement,
      ),

    expression_statement: ($) => seq($.expression, ';'),

    if_statement: ($) => seq('if', '(', $.expression, ')', $.block, optional(seq('else', $.block))),

    while_statement: ($) => seq('while', '(', $.expression, ')', $.block),

    for_of_statement: ($) =>
      seq(
        'for',
        '(',
        field('left', choice(seq('let', $.identifier), $.identifier)),
        'of',
        field('right', $.expression),
        ')',
        $.block,
      ),

    for_variable_declaration: ($) => seq('let', $.identifier, '=', field('value', $.expression)),

    for_statement: ($) =>
      seq(
        'for',
        '(',
        $.for_variable_declaration,
        ';',
        $.expression,
        ';',
        choice($.expression, $.prefix_unary_expression, $.suffix_unary_expression),
        ')',
        $.block,
      ),

    _expression: ($) => choice($.literal, $.expression),

    group_expression: ($) => seq('(', $._expression, ')'),

    vector_access_expression: ($) => seq($.identifier, '[', $.expression, ']'),

    expression: ($) =>
      choice(
        alias(choice(...PRIMITIVE_TYPES), $.identifier),
        $.primary_expression,
        $.prefix_unary_expression,
        $.suffix_unary_expression,
        $.binary_expression,
        $.call_expression,
        $.cast,
        $.match_expression,
        $.get_expression,
        $.metadata_expression,
      ),

    cast: ($) => prec(PREC.CAST, seq($.identifier, 'as', $.type_expression)),

    prefix_unary_expression: ($) => prec(PREC.UNARY, seq(choice('!', '++', '--'), $.expression)),

    suffix_unary_expression: ($) => prec(PREC.UNARY, seq($.expression, choice('++', '--'))),

    binary_expression: ($) => {
      const table = [
        [PREC.AND, '&&'],
        [PREC.OR, '||'],
        [PREC.BITAND, '&'],
        [PREC.BITOR, '|'],
        [PREC.BITXOR, '^'],
        [PREC.COMPARATIVE, choice('==', '!=', '<', '<=', '>', '>=')],
        [PREC.SHIFT, choice('<<', '>>')],
        [PREC.ADDITIVE, choice('+', '-')],
        [PREC.MULTIPLICATIVE, choice('*', '/', '%')],
        [PREC.RANGE, choice('..')],
      ];

      return choice(
        ...table.map(([precedence, operator]) =>
          prec.left(
            precedence,
            seq(field('left', $._expression), field('operator', operator), field('right', $._expression)),
          ),
        ),
      );
    },

    call_expression: ($) =>
      prec.dynamic(
        PREC.CALL,
        seq(
          field('function', $.primary_expression),
          optional($.generic_type_declaration),
          '(',
          commaSep(field('arguments', $.expression)),
          ')',
        ),
      ),

    match_expression: ($) =>
      seq('match', '(', field('value', $._expression), ')', '{', repeat1($.match_arm), '}'),

    match_arm: ($) => seq(field('pattern', $.pattern), '->', choice($._expression, $.block), optional(',')),

    when_clause: ($) => seq(field('pattern', $.pattern), 'when', field('condition', $.expression)),

    pattern: ($) => choice($.expression, $.when_clause, '_'),

    comment: (_) => token(choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),
    doc_comment: (_) => token(prec(1, seq('/**', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),

    identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

    type_identifier: ($) => seq(choice($.primitive_keyword, $.identifier), optional('[]')),

    union_type: ($) => prec.left(seq($.type_identifier, repeat(seq('|', $.type_identifier)))),

    intersection_type: ($) => prec.left(seq($.type_identifier, repeat(seq('&', $.type_identifier)))),

    type_function: ($) =>
      seq('(', optional(commaSep($.parameter_declaration)), ')', '-', '>', $.type_expression),

    type_expression: ($) =>
      choice($.type_function, $.type_identifier, $.union_type, $.intersection_type, $.vector_type),

    vector_type: ($) => seq($.type_identifier, '[', optional($.integer_literal), ']'),

    loop_control: (_) => choice('break', 'continue'),

    class_modifier: (_) => choice('abstract'),

    property_modifier: (_) => choice('public', 'private', 'static', 'mut', 'abstract'),

    method_modifier: (_) => choice('public', 'private', 'static', 'final', 'abstract'),

    other_keyword: (_) => choice('in', 'as', 'readonly', 'export', 'super', 'declare', 'namespace'),

    primitive_keyword: (_) => choice(...PRIMITIVE_TYPES),

    literal: ($) =>
      choice(
        $.integer_literal,
        $.float_literal,
        $.string_literal,
        $.char_literal,
        $.boolean_literal,
        $.null_literal,
        $.vector_literal,
        $.object_literal,
      ),

    null_literal: (_) => 'null',

    vector_literal: ($) => seq('[', commaSep($.expression), ']'),

    decimal_literal: (_) => token(seq(optional('-'), /[0-9]+(_[0-9]+)*/)),

    hex_literal: (_) => token(seq(optional('-'), /0[xX][0-9a-fA-F]+(_[0-9a-fA-F]+)*/)),

    binary_literal: (_) => token(seq(optional('-'), /0[bB][01]+(_[01]+)*/)),

    integer_literal: ($) => choice($.decimal_literal, $.hex_literal, $.binary_literal),
    float_literal: (_) => token(seq(optional('-'), /\d+(_\d+)*\.\d+(_\d+)*/)),

    char_literal: (_) => /'(\\.|[^'\\])'/,
    string_literal: (_) => /"([^"\\]|\\.)*"/,

    boolean_literal: (_) => choice('true', 'false'),

    object_literal: ($) =>
      seq(
        '{',
        commaSep(
          choice(
            seq(field('key', $.identifier), ':', field('value', $.expression)),
            $.identifier,
            $.method_declaration,
          ),
        ),
        optional(','),
        '}',
      ),

    keywords: (_) => choice(...KEYWORDS),
  },
});
