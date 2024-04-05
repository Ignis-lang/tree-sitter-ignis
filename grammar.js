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

const primitiveTypes = ['int', 'float', 'boolean', 'char', 'string', 'void', 'unknown'];

module.exports = grammar({
  name: 'ignis',

  extras: ($) => [/\s/, $.comment],

  conflicts: ($, previous) =>
    previous.concat([
      [$.identifier, $.type_identifier],
      [$.identifier, $.expression],
      [$.identifier, $.literal],
      [$.call_expression, $.for_statement],
      [$.call_expression, $.group_expression, $.binary_expression],
      [$.call_expression, $.expression],
      [$._expression, $.expression],
      [$.suffix_unary_expression, $.expression],
      [$.prefix_unary_expression, $.expression],
      [$.prefix_unary_expression, $.suffix_unary_expression],
      [$.method_call_expression, $.call_expression],
      [$.array_access_expression, $.expression],
      [$.for_statement, $.expression],

      [$.interface_method_declaration],
    ]),

  rules: {
    source_file: ($) => repeat($._definition),

    _definition: ($) =>
      choice(
        $.import_statement,
        $.class_declaration,
        $.function_declaration,
        $.variable_declaration,
        $.interface_declaration,
        $.enum_declaration,
        $.type_definition,
        $.record_declaration,
        $.extern_declaration,
        $.expression,
      ),

    type_definition: ($) => seq('type', $.identifier, '=', choice($.type_identifier, $.union_type), ';'),

    export_statement: ($) => seq('export', choice($.class_declaration, $.function_declaration)),

    enum_declaration: ($) =>
      seq(
        'enum',
        $.identifier,
        optional($.generic_type_declaration),
        '{',
        commaSep($.enum_member_declaration),
        '}',
      ),

    enum_member_declaration: ($) =>
      seq($.identifier, choice(optional(seq('=', $.expression)), optional(seq('(', $.expression, ')')))),

    import_statement: ($) =>
      seq('import', '{', $.identifier, optional(seq('as', $.identifier)), '}', 'from', $.string_literal, ';'),

    // #region Class
    interface_declaration: ($) =>
      seq(
        'interface',
        $.identifier,
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
        $.type_identifier,
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

    property_access: ($) => seq(choice($.this_expression, $.identifier), '.', field('name', $.identifier)),

    get_expression: ($) => seq($.property_access),

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
        optional($.method_modifier),
        $.identifier,
        optional($.generic_type_declaration),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        optional($.block),
      ),

    property_declaration: ($) =>
      seq(
        optional($.method_modifier),
        optional($.mutable_specifier),
        $.identifier,
        ':',
        $.type_identifier,
        ';',
      ),

    method_declaration: ($) =>
      seq(
        optional($.method_modifier),
        field('name', $.identifier),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        ':',
        $.type_identifier,
        $.block,
      ),

    record_property_declaration: ($) =>
      seq(field('name', $.identifier), optional('?'), ':', $.type_identifier, ';'),

    record_method_declaration: ($) =>
      seq(
        field('name', $.identifier),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        optional('?'),
        ':',
        $.type_identifier,
        ';',
      ),

    record_declaration: ($) =>
      seq(
        optional($.record_modifier),
        'record',
        $.identifier,
        '{',
        repeat(choice($.record_property_declaration, $.record_method_declaration)),
        '}',
      ),

    extern_declaration: ($) =>
      seq(optional($.record_modifier), 'extern', $.identifier, '{', $._definition, '}'),

    // #endregion
    // #region Function
    generic_type_declaration: ($) => seq('<', commaSep1($.type_identifier), '>'),

    function_declaration: ($) =>
      seq(
        'function',
        $.identifier,
        optional($.generic_type_declaration),
        '(',
        commaSep($.parameter_declaration),
        ')',
        ':',
        $.type_identifier,
        optional($.block),
        optional(';'),
      ),

    return_statement: ($) => seq('return', $.expression, ';'),

    // #endregion

    assignment_expression: ($) =>
      prec(PREC.ASSIGN, seq(choice($.identifier, $.property_access), '=', $.expression, ';')),

    mutable_specifier: (_) => 'mut',

    variable_declaration: ($) =>
      seq(
        'let',
        optional($.mutable_specifier),
        $.identifier,
        ':',
        field('type', $.type_identifier),
        optional(seq('=', field('value', $.expression))),
        ';',
      ),

    reference_operator: (_) => '$',

    parameter_declaration: ($) =>
      seq(
        optional($.reference_operator),
        optional($.mutable_specifier),
        $.identifier,
        ':',
        $.type_identifier,
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

    array_access_expression: ($) => seq($.identifier, '[', $.expression, ']'),

    expression: ($) =>
      choice(
        alias(choice(...primitiveTypes), $.identifier),
        $.literal,
        $.identifier,
        $.prefix_unary_expression,
        $.suffix_unary_expression,
        $.binary_expression,
        $.call_expression,
        $.group_expression,
        $.class_instance_expression,
        $.get_expression,
        $.method_call_expression,
        $.array_access_expression,
        $.cast,
      ),

    cast: ($) => seq($.identifier, 'as', $.type_identifier),

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
          field('function', $.identifier),
          optional($.generic_type_declaration),
          '(',
          commaSep(field('arguments', $.expression)),
          ')',
        ),
      ),

    comment: (_) => token(choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),

    identifier: (_) => /[a-zA-Z_]\w*/,

    type_identifier: ($) => seq(choice($.primitive_keyword, $.identifier), optional('[]')),

    union_type: ($) => prec.left(seq($.type_identifier, repeat1(seq('|', $.type_identifier)))),

    type_expression: ($) => choice($.type_identifier, $.union_type, $.array_type),

    array_type: ($) => seq($.type_identifier, '[]'),

    loop_control: (_) => choice('break', 'continue'),

    class_modifier: (_) => choice('export', 'abstract'),

    method_modifier: (_) => choice('public', 'private', 'static', 'final', 'abstract'),

    record_modifier: (_) => choice('export'),

    other_keyword: (_) => choice('in', 'const', 'as', 'readonly', 'export', 'super'),

    primitive_keyword: (_) => choice(...primitiveTypes),

    literal: ($) =>
      choice(
        $.integer_literal,
        $.float_literal,
        $.string_literal,
        $.char_literal,
        $.boolean_literal,
        $.null_literal,
        $.array_literal,
      ),

    null_literal: (_) => 'null',

    array_literal: ($) => seq('[', commaSep($.expression), ']'),

    integer_literal: (_) => token(seq(optional('-'), choice(/([0-9][_0-9]*[0-9])|([0-9])/))),
    float_literal: (_) => token(seq(optional('-'), /\d+(_\d+)*\.\d+(_\d+)*/)),

    char_literal: (_) => /'(\\.|[^'\\])'/,
    string_literal: (_) => /"([^"\\]|\\.)*"/,

    boolean_literal: (_) => choice('true', 'false'),
  },
});
