const PREC = {
  CALL: 16,
  FIELD: 15,
  TRY: 14,
  UNARY: 13,
  CAST: 12,
  MULTIPLICATIVE: 11,
  ADDITIVE: 10,
  SHIFT: 9,
  BITAND: 8,
  BITXOR: 7,
  BITOR: 6,
  COMPARATIVE: 5,
  AND: 4,
  OR: 3,
  PIPE: 2,
  RANGE: 1,
  TERNARY: 0,
  ASSIGN: -1,
  CLOSURE: -2,
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
  'atom',
];

const KEYWORDS = [
  'as',
  'async',
  'await',
  'break',
  'continue',
  'const',
  'directive',
  'else',
  'enum',
  'export',
  'extern',
  'false',
  'for',
  'from',
  'function',
  'is',
  'if',
  'import',
  'inline',
  'in',
  'let',
  'namespace',
  'new',
  'null',
  'private',
  'public',
  'record',
  'return',
  'self',
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
      [$.primary_expression, $.get_expression],
      [$._expression, $.primary_expression],
      [$.for_statement, $.expression],
      [$.block, $.object_literal],
      [$.method_modifier, $.property_modifier],
      [$.variable_modifiers, $.type_identifier, $.vector_type],
      [$.type_identifier],
      [$._expression, $.guard_clause],
      [$._expression, $.when_clause],
      [$._expression, $.ternary_expression],
      [$.lambda_expression, $.ternary_expression],
      [$.union_type, $.intersection_type, $.type_expression],
      [$.union_type, $.intersection_type, $.type_expression, $.vector_type],
      [$.lambda_expression, $._expression],
      [$._statement, $.expression],
      [$.tuple_literal, $.group_expression],
      [$.tuple_type, $.type_function],
      [$.directive_attr, $.directive_expression],
      [$._definition, $._expression],
      [$.primary_expression, $.qualified_identifier],
      [$.tuple_type],
      [$.enum_declaration],
      [$.record_declaration],
      [$.type_definition],
      [$._expression, $.match_arm],
      [$.self_expression, $.parameter_declaration],
      [$.self_expression, $.self_parameter],
    ]),

  rules: {
    source_file: ($) => repeat($._definition),

    _definition: ($) =>
      choice(
        $.export_statement,
        $.inline_statement,
        $.import_statement,
        $.function_declaration,
        $.variable_declaration,
        $.enum_declaration,
        $.type_definition,
        $.record_declaration,
        $.extern_declaration,
        $.directive_statement,
        $.directive_declaration,
        $.namespace_declaration,
        $.const_declaration,
        $.expression,
      ),

    // <type-alias> ::= <directive-attrs>? "type" <identifier> <generic-type>? "=" <type> ";"
    type_definition: ($) =>
      seq(
        optional($.directive_attrs),
        'type',
        $.identifier,
        optional($.generic_type_declaration),
        '=',
        $.type_expression,
        ';',
      ),

    // <export> ::= "export" (<function> | <const> | <record> | <enum> | <type-alias> | <directive-statement> | <directive>)
    export_statement: ($) =>
      seq(
        'export',
        choice(
          $.function_declaration,
          $.const_declaration,
          $.record_declaration,
          $.enum_declaration,
          $.type_definition,
          $.directive_statement,
          $.directive_declaration,
        ),
      ),

    inline_statement: ($) =>
      seq(
        'inline',
        choice(
          $.function_declaration,
          $.const_declaration,
        ),
      ),

    // <enum> ::= <directive-attrs>? "enum" <identifier> <generic-type>?
    //            "{" (<enum-item>)* "}"
    // <enum-item> ::= <directive-attrs>? (<enum-variant> | <enum-method>)
    enum_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'enum',
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '{',
        repeat(
          seq(
            optional($.directive_attrs),
            choice($.enum_variant_declaration, $.enum_method_declaration),
          ),
        ),
        '}',
      ),

    enum_variant_declaration: ($) =>
      seq(
        field('name', $.identifier),
        optional(
          choice(
            seq('=', $.expression),
            seq('(', commaSep($.type_expression), ')'),
          ),
        ),
        ',',
      ),

    enum_method_declaration: ($) =>
      seq(
        optional(repeat($.method_modifier)),
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        ':',
        $.type_expression,
        $.block,
      ),

    import_statement: ($) =>
      seq(
        'import',
        commaSep1(seq($.identifier, optional(seq('as', $.identifier)))),
        'from',
        $.string_literal,
        ';',
      ),

    // #region Records and Objects

    this_expression: (_) => 'this',

    self_expression: (_) => 'self',

    primary_expression: ($) =>
      prec.left(
        choice(
          seq($.identifier, optional($.generic_type_declaration)),
          $.identifier,
          $.this_expression,
          $.self_expression,
          $.method_call_expression,
          $.literal,
          $.group_expression,
          $.vector_access_expression,
          $.lambda_expression,
        ),
      ),

    // <lambda> ::= (<generic-type>)? "(" <parameters>? ")" ":" <type> "->" (<expression> | <block>)
    lambda_expression: ($) =>
      seq(
        optional($.generic_type_declaration),
        '(',
        commaSep($.parameter_declaration),
        ')',
        ':',
        $.type_expression,
        '->',
        choice($.expression, $.block),
      ),

    property_access: ($) =>
      prec.left(PREC.FIELD, seq($.expression, choice('.', '::'), field('name', $.identifier))),

    get_expression: ($) => prec.left(choice($.property_access, $.method_call_expression)),

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
        optional(repeat($.property_modifier)),
        field('name', $.identifier),
        optional($.variable_modifiers),
        optional($.generic_type_declaration),
        optional('?'),
        ':',
        $.type_expression,
        optional(seq('=', $.expression)),
        ';',
      ),

    record_method_declaration: ($) =>
      seq(
        optional(repeat($.method_modifier)),
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '(',
        optional(commaSep1($.parameter_declaration)),
        ')',
        optional('?'),
        ':',
        $.type_expression,
        choice($.block, ';'),
      ),

    // <record> ::= <directive-attrs>? "record" <identifier> <generic-type>? "{" <record-item>* "}"
    // <record-item> ::= <directive-attrs>? (<record-property> | <record-method>)
    record_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'record',
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '{',
        repeat(
          seq(
            optional($.directive_attrs),
            choice($.record_property_declaration, $.record_method_declaration),
          ),
        ),
        '}',
      ),

    // <extern> ::= <directive-attrs>? "extern" <qualified-identifier> "{" <extern-item>* "}"
    //            | <directive-attrs>? "extern" <extern-item>
    extern_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'extern',
        choice(
          seq($.qualified_identifier, '{', repeat($.extern_item), '}'),
          $.extern_item,
        ),
      ),

    // <extern-item> ::= <directive-attrs>? ( <extern-function> | <record> | <enum> | <type-alias> )
    extern_item: ($) =>
      seq(
        optional($.directive_attrs),
        choice(
          $.extern_function,
          $.record_declaration,
          $.enum_declaration,
          $.type_definition,
        ),
      ),

    // <extern-function> ::= "function" <identifier> (<generic-type>)?
    //                       "(" <parameters>? ")" ":" <type> ";"
    extern_function: ($) =>
      seq(
        'function',
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '(',
        commaSep($.parameter_declaration),
        ')',
        ':',
        $.type_expression,
        ';',
      ),

    // <directive-attrs> ::= (<directive-attr>)+
    directive_attrs: ($) => prec.left(repeat1($.directive_attr)),

    // <directive-attr> ::= "#[" <directive-attr-list>? "]"
    //                    | "#" <qualified-identifier> ("(" <expression-list>? ")")?
    directive_attr: ($) =>
      choice(
        seq('#', '[', commaSep($.directive_attr_item), ']'),
        seq('#', $.qualified_identifier, optional(seq('(', commaSep($.expression), ')'))),
      ),

    // <directive-attr-item> ::= <qualified-identifier> ("(" <expression-list>? ")")?
    directive_attr_item: ($) =>
      seq($.qualified_identifier, optional(seq('(', commaSep($.expression), ')'))),

    // <directive-statement> ::= "directive" <qualified-identifier>
    //                           ("(" <expression-list>? ")")?
    //                           (";" | <block>)
    directive_statement: ($) =>
      seq(
        'directive',
        $.qualified_identifier,
        optional(seq('(', commaSep($.expression), ')')),
        choice(';', $.block),
      ),

    // <directive> ::= "directive" <identifier> ("(" <parameters>? ")")? ";"
    directive_declaration: ($) =>
      seq(
        'directive',
        $.identifier,
        optional(seq('(', commaSep($.parameter_declaration), ')')),
        ';',
      ),

    // <directive-expression> ::= "#" <qualified-identifier> ("(" <expression-list>? ")")?
    //                          | "#[" <expression-list>? "]"
    directive_expression: ($) =>
      prec.left(
        choice(
          seq('#', $.qualified_identifier, optional(seq('(', commaSep($.expression), ')'))),
          seq('#', '[', commaSep($.expression), ']'),
        ),
      ),

    // <namespace> ::= <directive-attrs>? "namespace" <qualified-identifier> "{" <namespace-item>* "}"
    namespace_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'namespace',
        $.qualified_identifier,
        '{',
        repeat($.namespace_item),
        '}',
      ),

    // <namespace-item> ::= <function> | <const> | <record> | <enum> | <type-alias> | <extern> | <directive-statement> | <directive>
    namespace_item: ($) =>
      choice(
        $.function_declaration,
        $.const_declaration,
        $.record_declaration,
        $.enum_declaration,
        $.type_definition,
        $.extern_declaration,
        $.directive_statement,
        $.directive_declaration,
      ),

    // #endregion
    // #region Function
    generic_type_declaration: ($) => seq('<', commaSep1(choice($.type_expression, $.cast)), '>'),

    // <function> ::= <directive-attrs>? "function" <identifier> (<generic-type>)?
    //                "(" <parameters>? ")" ":" <type> <block>
    function_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'function',
        field('name', $.identifier),
        optional($.generic_type_declaration),
        '(',
        commaSep($.parameter_declaration),
        ')',
        ':',
        $.type_expression,
        $.block,
      ),

    return_statement: ($) => seq('return', optional($.expression), ';'),

    // #endregion

    assignment_expression: ($) =>
      prec.left(
        PREC.ASSIGN,
        seq(
          field('name', choice($.identifier, $.property_access, $.vector_access_expression)),
          choice(...ASSIGNMENT_OPERATORS),
          $.expression,
          optional(';'),
        ),
      ),

    reference_operator: (_) => '&',
    mutable_specifier: (_) => 'mut',
    pointer_specifier: (_) => '*',
    variable_modifiers: ($) =>
      prec.left(repeat1(choice($.mutable_specifier, $.reference_operator, $.pointer_specifier))),

    // <const> ::= <directive-attrs>? "const" <identifier> ":" <type> "=" <expression> ";"
    const_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'const',
        field('name', $.identifier),
        ':',
        $.type_expression,
        '=',
        $.expression,
        ';',
      ),

    // <variable> ::= <directive-attrs>? "let" "mut"? <identifier> ":" <type> ("=" <expression>)? ";"
    variable_declaration: ($) =>
      seq(
        optional($.directive_attrs),
        'let',
        optional($.mutable_specifier),
        field('name', $.identifier),
        ':',
        field('type', $.type_expression),
        optional(seq('=', field('value', $.expression))),
        ';',
      ),

    // Special case for self parameter without type annotation
    self_parameter: ($) =>
      seq(
        optional($.variable_modifiers),
        'self',
      ),

    // <parameter> ::= <directive-attrs>? "..."? <variable-modifiers>? <identifier> "?"? ":" <variable-modifiers>? <type>
    parameter_declaration: ($) =>
      choice(
        $.self_parameter,
        seq(
          optional($.directive_attrs),
          optional('...'),
          optional($.variable_modifiers),
          field('name', $.identifier),
          optional('?'),
          ':',
          optional($.variable_modifiers),
          $.type_expression,
        ),
      ),

    block: ($) => seq('{', repeat($._statement), '}'),

    _statement: ($) =>
      choice(
        $.variable_declaration,
        $.return_statement,
        $.break_statement,
        $.continue_statement,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.for_of_statement,
        $.assignment_expression,
        $.expression_statement,
      ),

    // <break> ::= "break" ";"
    break_statement: (_) => seq('break', ';'),

    // <continue> ::= "continue" ";"
    continue_statement: (_) => seq('continue', ';'),

    expression_statement: ($) => seq($.expression, ';'),

    // <if> ::= "if" "(" <expression> ")" <block>
    //          ("else if" "(" <expression> ")" <block>)*
    //          ("else" <block>)?
    if_statement: ($) =>
      seq(
        'if',
        '(',
        $.expression,
        ')',
        $.block,
        repeat($.else_if_clause),
        optional($.else_clause),
      ),

    else_if_clause: ($) => seq('else', 'if', '(', $.expression, ')', $.block),

    else_clause: ($) => seq('else', $.block),

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

    vector_access_expression: ($) => prec(PREC.FIELD, seq(choice($.identifier, $.property_access), '[', $.expression, ']')),

    spread_expression: ($) => prec.left(seq('...', $._expression)),

    expression: ($) =>
      choice(
        alias(choice(...PRIMITIVE_TYPES), $.identifier),
        $.primary_expression,
        $.prefix_unary_expression,
        $.suffix_unary_expression,
        $.binary_expression,
        $.ternary_expression,
        $.call_expression,
        $.cast,
        $.match_expression,
        $.get_expression,
        $.directive_expression,
        $.assignment_expression,
        $.spread_expression,
      ),

    cast: ($) => prec(PREC.CAST, seq($.identifier, 'as', $.type_expression)),

    ternary_expression: ($) =>
      prec.right(
        PREC.TERNARY,
        seq(
          field('condition', $.expression),
          '?',
          field('consequence', $.expression),
          ':',
          field('alternative', $.expression),
        ),
      ),

    // <unary> ::= ( "++" | "--" | "-" | "!" | "~" | "*" | "&" )* <postfix>
    prefix_unary_expression: ($) => 
      prec(PREC.UNARY, 
        choice(
          seq('&', 'mut', $.expression),
          seq(choice('!', '++', '--', '-', '~', '*', '&'), $.expression)
        )
      ),

    suffix_unary_expression: ($) => prec(PREC.UNARY, seq($.expression, choice('++', '--'))),

    binary_expression: ($) => {
      const table = [
        [PREC.AND, '&&'],
        [PREC.OR, '||'],
        [PREC.PIPE, '|>'],
        [PREC.BITAND, '&'],
        [PREC.BITOR, '|'],
        [PREC.BITXOR, '^'],
        [PREC.COMPARATIVE, choice('==', '!=', '<', '<=', '>', '>=')],
        [PREC.SHIFT, choice('<<', '>>')],
        [PREC.ADDITIVE, choice('+', '-')],
        [PREC.MULTIPLICATIVE, choice('*', '/', '%')],
        [PREC.RANGE, choice('..', '..=')],
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

    match_arm: ($) =>
      seq(
        field('pattern', $.match_pattern),
        '->',
        field('body', choice($.expression, $.block)),
        optional(','),
      ),

    match_pattern: ($) =>
      seq(
        $.pattern,
        repeat(seq('|', $.pattern)),
      ),

    pattern: ($) =>
      choice(
        seq($._expression, optional($.guard_clause)),
        $.when_clause,
        '_',
      ),

    guard_clause: ($) =>
      seq('if', field('condition', $.expression)),

    when_clause: ($) =>
      seq(field('pattern', $._expression), 'when', field('condition', $.expression)),

    comment: (_) => token(choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),
    doc_comment: (_) => token(prec(1, seq('/**', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),

    identifier: (_) => /[_a-zA-Z_][a-zA-Z0-9_]*/,
    // <qualified-identifier> ::= <identifier> ("::" <identifier>)*
    qualified_identifier: ($) =>
      prec.left(
        seq(
          field('identifier', $.identifier),
          repeat(seq('::', field('identifier', $.identifier))),
        ),
      ),

    type_identifier: ($) =>
      prec.left(
        seq(
          optional(repeat1(choice($.pointer_specifier, $.reference_operator, $.mutable_specifier))),
          choice($.primitive_keyword, $.identifier),
          optional($.generic_type_declaration),
          optional('[]'),
        ),
      ),

    union_type: ($) => prec.left(seq($.type_identifier, repeat(seq('|', $.type_identifier)))),

    intersection_type: ($) => prec.left(seq($.type_identifier, repeat(seq('&', $.type_identifier)))),

    // <function-type> ::= "(" <type-list>? ")" "->" <type>
    type_function: ($) =>
      seq('(', commaSep($.type_expression), ')', '->', $.type_expression),

    type_expression: ($) =>
      choice($.type_function, $.type_identifier, $.union_type, $.intersection_type, $.vector_type, $.tuple_type),

    // <tuple-type> ::= "(" <type> "," <type> ("," <type>)* ","? ")"
    tuple_type: ($) =>
      prec.left(
        seq(
          '(',
          $.type_expression,
          ',',
          $.type_expression,
          repeat(seq(',', $.type_expression)),
          optional(','),
          ')',
        ),
      ),

    vector_type: ($) =>
      seq(
        optional(repeat1(choice($.pointer_specifier, $.reference_operator, $.mutable_specifier))),
        choice($.primitive_keyword, $.identifier),
        optional($.generic_type_declaration),
        '[',
        optional($.integer_literal),
        ']',
      ),

    property_modifier: (_) => choice('public', 'private', 'static', 'mut', 'abstract'),

    method_modifier: (_) => choice('public', 'private', 'static', 'final', 'abstract', 'inline'),

    other_keyword: (_) => choice('in', 'as', 'readonly', 'export', 'super', 'namespace'),

    primitive_keyword: (_) => choice(...PRIMITIVE_TYPES),

    literal: ($) =>
      choice(
        $.integer_literal,
        $.float_literal,
        $.string_literal,
        $.char_literal,
        $.boolean_literal,
        $.null_literal,
        $.atom_literal,
        $.vector_literal,
        $.tuple_literal,
        $.typed_object_literal,
        $.object_literal,
      ),

    // <atom> ::= ":" <identifier>
    atom_literal: ($) => seq(':', $.identifier),

    // <tuple> ::= "(" <expression> "," <expression> ("," <expression>)* ","? ")"
    tuple_literal: ($) =>
      seq(
        '(',
        $.expression,
        ',',
        $.expression,
        repeat(seq(',', $.expression)),
        optional(','),
        ')',
      ),

    null_literal: (_) => 'null',

    vector_literal: ($) => seq('[', commaSep($.expression), ']'),

    decimal_literal: (_) => token(seq(optional('-'), /[0-9]+(_[0-9]+)*/)),

    hex_literal: (_) => token(seq(optional('-'), /0[xX][0-9a-fA-F]+(_[0-9a-fA-F]+)*/)),

    binary_literal: (_) => token(seq(optional('-'), /0[bB][01]+(_[01]+)*/)),

    integer_literal: ($) => choice($.decimal_literal, $.hex_literal, $.binary_literal),
    float_literal: (_) => token(seq(optional('-'), /\d+(_\d+)*\.\d+(_\d+)*/)),

    char_literal: ($) => seq("'", choice(/[^'\\]/, /\\./, /[\u0080-\uFFFF]/), "'"),
    string_literal: ($) =>
      seq('"', repeat(choice(token.immediate(prec(1, /\\./)), token.immediate(/[^"\\]/))), '"'),

    boolean_literal: (_) => choice('true', 'false'),

    typed_object_literal: ($) =>
      seq(
        field('type', $.qualified_identifier),
        optional($.generic_type_declaration),
        $.object_literal,
      ),

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
