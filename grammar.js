/**
 * Tree-sitter grammar for the Ignis programming language.
 *
 * The contract for this grammar is the reference compiler at
 * ignisc.rs (crates/ignis_parser). Precedence levels mirror its
 * Pratt binding-power table (parser/mod.rs), and every construct
 * here is one the reference parser actually produces. Tokens the
 * compiler lexes but never parses (ranges, `#`, `is`, `in`, `when`,
 * `this`, variadics) are intentionally absent.
 */

const PREC = {
  ASSIGN: 1,
  TERNARY: 2,
  PIPE: 3,
  OR: 4,
  AND: 5,
  BITOR: 6,
  BITXOR: 7,
  BITAND: 8,
  EQUALITY: 9,
  COMPARATIVE: 10,
  SHIFT: 11,
  ADDITIVE: 12,
  MULTIPLICATIVE: 13,
  CAST: 14,
  UNARY: 15,
  POSTFIX: 16,
  CALL: 17,
  MEMBER: 18,
};

const PRIMITIVE_TYPES = [
  'i8',
  'i16',
  'i32',
  'i64',
  'u8',
  'u16',
  'u32',
  'u64',
  'f32',
  'f64',
  'boolean',
  'char',
  'atom',
  'str',
  'void',
];

const ASSIGNMENT_OPERATORS = [
  '=',
  '+=',
  '-=',
  '*=',
  '/=',
  '%=',
  '&=',
  '|=',
  '~=',
  '^=',
  '<<=',
  '>>=',
];

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)), optional(','));
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}

module.exports = grammar({
  name: 'ignis',

  extras: ($) => [/\s/, $.doc_comment, $.comment],

  word: ($) => $.identifier,

  supertypes: ($) => [
    $._declaration,
    $._statement,
    $._expression,
    $._type,
    $._pattern,
    $._literal,
  ],

  conflicts: ($) => [
    [$.parameters, $.unit_expression],
    [$._expression, $._path],
    [$.call_expression, $.reference_expression, $.binary_expression],
    [$.call_expression, $.unary_expression, $.binary_expression],
    [$.call_expression, $.dereference_expression, $.binary_expression],
    [$.call_expression, $.capture_expression, $.binary_expression],
    [$.call_expression, $.binary_expression],
    [$.self_parameter, $.self_expression],
    [$._type, $._path],
    [$._expression, $._type],
    [$.mutable_type, $.mutable_specifier],
    [$.variable_declaration, $._path],
    [$.unit_expression, $.function_type],
    [$.conditional_block],
    [$.builtin_expression, $._path],
  ],

  rules: {
    source_file: ($) => repeat($._item),

    _item: ($) =>
      choice(
        $._declaration,
        $.attribute,
        $.conditional_block,
      ),

    _declaration: ($) =>
      choice(
        $.import_statement,
        $.export_declaration,
        $.function_declaration,
        $.const_declaration,
        $.type_definition,
        $.record_declaration,
        $.enum_declaration,
        $.trait_declaration,
        $.extern_declaration,
        $.namespace_declaration,
      ),

    // #region Items

    import_statement: ($) =>
      seq(
        'import',
        commaSep1($.import_name),
        'from',
        field('source', $.string_literal),
        ';',
      ),

    import_name: ($) =>
      seq(
        field('name', $.identifier),
        optional(seq('as', field('alias', $.identifier))),
      ),

    export_declaration: ($) =>
      seq(
        'export',
        choice(
          $._declaration,
          seq(commaSep1(field('name', $.identifier)), optional(seq('from', field('source', $.string_literal))), ';'),
        ),
      ),

    inline_specifier: ($) =>
      seq('inline', optional(seq('(', choice('always', 'never'), ')'))),

    function_declaration: ($) =>
      seq(
        optional($.inline_specifier),
        'function',
        field('name', $.identifier),
        optional(field('type_parameters', $.type_parameters)),
        field('parameters', $.parameters),
        ':',
        field('return_type', $._type),
        field('body', $.block),
      ),

    parameters: ($) =>
      seq('(', commaSep(choice($.self_parameter, $.parameter)), ')'),

    parameter: ($) =>
      seq(
        repeat($.attribute),
        field('name', $.identifier),
        ':',
        field('type', $._type),
      ),

    self_parameter: ($) => seq('&', optional($.mutable_specifier), 'self'),

    const_declaration: ($) =>
      seq(
        'const',
        field('name', $.identifier),
        ':',
        field('type', $._type),
        '=',
        field('value', $._expression),
        ';',
      ),

    type_definition: ($) =>
      seq(
        'type',
        field('name', $.identifier),
        optional(field('type_parameters', $.type_parameters)),
        '=',
        field('value', $._type),
        ';',
      ),

    record_declaration: ($) =>
      seq(
        'record',
        field('name', $.identifier),
        optional(field('type_parameters', $.type_parameters)),
        field('body', $.declaration_body),
      ),

    enum_declaration: ($) =>
      seq(
        'enum',
        field('name', $.identifier),
        optional(field('type_parameters', $.type_parameters)),
        field('body', $.enum_body),
      ),

    trait_declaration: ($) =>
      seq(
        'trait',
        field('name', $.identifier),
        optional(field('type_parameters', $.type_parameters)),
        field('body', $.declaration_body),
      ),

    declaration_body: ($) =>
      seq(
        '{',
        repeat(choice($.attribute, $.field_declaration, $.method_declaration)),
        '}',
      ),

    enum_body: ($) =>
      seq(
        '{',
        repeat(
          choice(
            $.attribute,
            $.enum_variant,
            $.field_declaration,
            $.method_declaration,
          ),
        ),
        '}',
      ),

    enum_variant: ($) =>
      seq(
        field('name', $.identifier),
        optional(seq('(', commaSep($._type), ')')),
        optional(','),
      ),

    member_modifier: ($) =>
      choice('static', 'public', 'private', $.inline_specifier),

    field_declaration: ($) =>
      seq(
        repeat($.member_modifier),
        field('name', $.identifier),
        ':',
        field('type', $._type),
        optional(seq('=', field('value', $._expression))),
        ';',
      ),

    method_declaration: ($) =>
      seq(
        repeat($.member_modifier),
        optional('function'),
        field('name', $.identifier),
        optional(field('type_parameters', $.type_parameters)),
        field('parameters', $.parameters),
        optional(seq(':', field('return_type', $._type))),
        choice(field('body', $.block), ';'),
      ),

    extern_declaration: ($) =>
      seq(
        'extern',
        field('name', $._path),
        field('body', $.extern_body),
      ),

    extern_body: ($) =>
      seq(
        '{',
        repeat(choice($.attribute, $.extern_function, $.extern_const)),
        '}',
      ),

    extern_function: ($) =>
      seq(
        'function',
        field('name', $.identifier),
        field('parameters', $.parameters),
        ':',
        field('return_type', $._type),
        ';',
      ),

    extern_const: ($) =>
      seq(
        'const',
        field('name', $.identifier),
        ':',
        field('type', $._type),
        ';',
      ),

    namespace_declaration: ($) =>
      seq(
        'namespace',
        field('name', $._path),
        field('body', $.namespace_body),
      ),

    namespace_body: ($) => seq('{', repeat($._item), '}'),

    // Attributes and compile-time directives: `@name`, `@path::name(args)`,
    // `@if`/`@ifelse` conditional blocks. `@configFlag(...)` before an item
    // is an ordinary attribute node.
    attribute: ($) =>
      prec.right(
        seq(
          '@',
          field('name', $._path),
          optional(field('arguments', $.attribute_arguments)),
        ),
      ),

    attribute_arguments: ($) =>
      seq('(', commaSep($._attribute_argument), ')'),

    _attribute_argument: ($) =>
      choice(
        $._expression,
        $.primitive_type,
        $.mutable_specifier,
        seq(field('name', $.identifier), ':', field('value', $._expression)),
      ),

    conditional_block: ($) =>
      seq(
        '@',
        choice('if', alias('ifelse', 'if')),
        '(',
        field('condition', $._expression),
        ')',
        field('consequence', $.conditional_body),
        optional(
          seq('@', 'else', field('alternative', $.conditional_body)),
        ),
      ),

    conditional_body: ($) =>
      seq(
        '{',
        repeat(
          choice(
            $._statement,
            $.import_statement,
            $.export_declaration,
            $.function_declaration,
            $.type_definition,
            $.record_declaration,
            $.enum_declaration,
            $.trait_declaration,
            $.extern_declaration,
            $.namespace_declaration,
          ),
        ),
        '}',
      ),

    // #endregion
    // #region Statements

    block: ($) => seq('{', repeat($._statement), '}'),

    _statement: ($) =>
      choice(
        $.variable_declaration,
        $.let_else_statement,
        $.const_declaration,
        $.expression_statement,
        $.return_statement,
        $.defer_statement,
        $.break_statement,
        $.continue_statement,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.for_of_statement,
        $.block,
        $.conditional_block,
        $.attribute,
      ),

    variable_declaration: ($) =>
      seq(
        'let',
        optional($.mutable_specifier),
        field('name', $.identifier),
        optional(seq(':', field('type', $._type))),
        optional(seq('=', field('value', $._expression))),
        ';',
      ),

    let_else_statement: ($) =>
      seq(
        'let',
        optional($.mutable_specifier),
        field('pattern', $._pattern),
        '=',
        field('value', $._expression),
        'else',
        field('alternative', $.block),
        ';',
      ),

    expression_statement: ($) => seq($._expression, ';'),

    return_statement: ($) => seq('return', optional($._expression), ';'),

    defer_statement: ($) => seq('defer', $._expression, ';'),

    break_statement: (_) => seq('break', ';'),

    continue_statement: (_) => seq('continue', ';'),

    if_statement: ($) =>
      seq(
        'if',
        '(',
        field('condition', $._condition),
        ')',
        field('consequence', $.block),
        optional(field('alternative', $.else_clause)),
      ),

    else_clause: ($) => seq('else', choice($.block, $.if_statement)),

    while_statement: ($) =>
      seq(
        'while',
        '(',
        field('condition', $._condition),
        ')',
        field('body', $.block),
      ),

    _condition: ($) => choice($._expression, $.let_condition),

    let_condition: ($) =>
      seq(
        'let',
        field('pattern', $._pattern),
        '=',
        field('value', $._expression),
      ),

    for_statement: ($) =>
      seq(
        'for',
        '(',
        field('initializer', $.for_initializer),
        ';',
        field('condition', $._expression),
        ';',
        field('increment', $._expression),
        ')',
        field('body', $.block),
      ),

    for_initializer: ($) =>
      seq(
        'let',
        field('name', $.identifier),
        optional(seq(':', field('type', $._type))),
        '=',
        field('value', $._expression),
      ),

    for_of_statement: ($) =>
      seq(
        'for',
        '(',
        'let',
        field('name', $.identifier),
        optional(seq(':', field('type', $._type))),
        'of',
        field('right', $._expression),
        ')',
        field('body', $.block),
      ),

    // #endregion
    // #region Expressions

    _expression: ($) =>
      choice(
        $.identifier,
        $.scoped_identifier,
        $.self_expression,
        $._literal,
        $.record_init,
        $.unit_expression,
        $.tuple_expression,
        $.group_expression,
        $.unary_expression,
        $.reference_expression,
        $.dereference_expression,
        $.postfix_expression,
        $.binary_expression,
        $.assignment_expression,
        $.ternary_expression,
        $.cast_expression,
        $.call_expression,
        $.member_expression,
        $.index_expression,
        $.match_expression,
        $.lambda_expression,
        $.builtin_expression,
        $.capture_expression,
      ),

    self_expression: (_) => 'self',

    unit_expression: (_) => seq('(', ')'),

    group_expression: ($) => seq('(', $._expression, ')'),

    tuple_expression: ($) =>
      seq(
        '(',
        $._expression,
        ',',
        optional(seq($._expression, repeat(seq(',', $._expression)), optional(','))),
        ')',
      ),

    member_expression: ($) =>
      prec.left(
        PREC.MEMBER,
        seq(
          field('object', $._expression),
          '.',
          field('property', $.identifier),
        ),
      ),

    index_expression: ($) =>
      prec.left(
        PREC.MEMBER,
        seq(
          field('object', $._expression),
          '[',
          field('index', $._expression),
          ']',
        ),
      ),

    call_expression: ($) =>
      prec.left(
        PREC.CALL,
        seq(
          field('function', $._expression),
          optional(field('type_arguments', $.type_arguments)),
          field('arguments', $.arguments),
        ),
      ),

    arguments: ($) => seq('(', commaSep($._expression), ')'),

    unary_expression: ($) =>
      prec.right(
        PREC.UNARY,
        seq(
          field('operator', choice('-', '+', '!', '~', '++', '--')),
          field('operand', $._expression),
        ),
      ),

    reference_expression: ($) =>
      prec.right(
        PREC.UNARY,
        seq('&', optional($.mutable_specifier), field('operand', $._expression)),
      ),

    dereference_expression: ($) =>
      prec.right(PREC.UNARY, seq('*', field('operand', $._expression))),

    // Postfix `!` is the try operator (`@lang(try)`).
    postfix_expression: ($) =>
      prec.left(
        PREC.POSTFIX,
        seq(
          field('operand', $._expression),
          field('operator', choice('++', '--', '!')),
        ),
      ),

    binary_expression: ($) => {
      const table = [
        [PREC.MULTIPLICATIVE, choice('*', '/', '%')],
        [PREC.ADDITIVE, choice('+', '-')],
        [PREC.SHIFT, choice('<<', '>>')],
        [PREC.COMPARATIVE, choice('<', '<=', '>', '>=')],
        [PREC.EQUALITY, choice('==', '!=')],
        [PREC.BITAND, '&'],
        [PREC.BITXOR, '^'],
        [PREC.BITOR, '|'],
        [PREC.AND, '&&'],
        [PREC.OR, '||'],
        [PREC.PIPE, '|>'],
      ];

      return choice(
        ...table.map(([precedence, operator]) =>
          prec.left(
            precedence,
            seq(
              field('left', $._expression),
              field('operator', operator),
              field('right', $._expression),
            ),
          ),
        ),
      );
    },

    assignment_expression: ($) =>
      prec.right(
        PREC.ASSIGN,
        seq(
          field('left', $._expression),
          field('operator', choice(...ASSIGNMENT_OPERATORS)),
          field('right', $._expression),
        ),
      ),

    ternary_expression: ($) =>
      prec.right(
        PREC.TERNARY,
        seq(
          field('condition', $._expression),
          '?',
          field('consequence', $._expression),
          ':',
          field('alternative', $._expression),
        ),
      ),

    cast_expression: ($) =>
      prec.left(
        PREC.CAST,
        seq(field('value', $._expression), 'as', field('type', $._type)),
      ),

    match_expression: ($) =>
      seq(
        'match',
        '(',
        field('value', $._expression),
        ')',
        '{',
        optional(seq($.match_arm, repeat(seq(',', $.match_arm)), optional(','))),
        '}',
      ),

    match_arm: ($) =>
      seq(
        field('pattern', $._pattern),
        optional(field('guard', $.match_guard)),
        '->',
        field('value', choice($._expression, $.block)),
      ),

    match_guard: ($) => seq('if', field('condition', $._expression)),

    lambda_expression: ($) =>
      seq(
        field('parameters', $.parameters),
        ':',
        field('return_type', $._type),
        '->',
        field('body', choice($._expression, $.block)),
      ),

    builtin_expression: ($) =>
      seq(
        '@',
        field('name', $.identifier),
        optional(field('type_arguments', $.type_arguments)),
        field('arguments', $.arguments),
      ),

    // Lambda capture overrides: `@move expr`, `@ref expr`, `@refMut expr`.
    capture_expression: ($) =>
      prec.right(
        PREC.UNARY,
        seq(
          '@',
          field('kind', choice('move', 'ref', 'refMut')),
          field('operand', $._expression),
        ),
      ),

    record_init: ($) =>
      seq(
        field('type', $._path),
        optional(field('type_arguments', $.type_arguments)),
        field('body', $.record_init_body),
      ),

    record_init_body: ($) => seq('{', commaSep($.record_init_field), '}'),

    record_init_field: ($) =>
      seq(field('name', $.identifier), ':', field('value', $._expression)),

    // #endregion
    // #region Patterns

    _pattern: ($) =>
      choice(
        $._simple_pattern,
        $.or_pattern,
      ),

    _simple_pattern: ($) =>
      choice(
        $.wildcard_pattern,
        $.literal_pattern,
        $.path_pattern,
        $.tuple_pattern,
      ),

    wildcard_pattern: (_) => '_',

    literal_pattern: ($) =>
      choice(
        $._literal_value,
        seq('-', choice($.integer_literal, $.float_literal, $.hex_literal, $.binary_literal)),
      ),

    path_pattern: ($) =>
      prec.right(
        seq(
          field('name', $._path),
          optional(seq('(', commaSep($._pattern), ')')),
        ),
      ),

    tuple_pattern: ($) => seq('(', commaSep($._pattern), ')'),

    or_pattern: ($) =>
      seq(
        $._simple_pattern,
        repeat1(seq('|', $._simple_pattern)),
      ),

    // #endregion
    // #region Types

    _type: ($) =>
      choice(
        $.primitive_type,
        $.identifier,
        $.scoped_identifier,
        $.generic_type,
        $.function_type,
        $.reference_type,
        $.pointer_type,
        $.mutable_type,
        $.array_type,
      ),

    primitive_type: (_) => choice(...PRIMITIVE_TYPES),

    generic_type: ($) =>
      seq(
        field('name', $._path),
        field('type_arguments', $.type_arguments),
      ),

    function_type: ($) =>
      seq('(', commaSep($._type), ')', '->', field('return_type', $._type)),

    reference_type: ($) => prec.right(seq('&', $._type)),

    pointer_type: ($) => prec.right(seq('*', $._type)),

    mutable_type: ($) => prec.right(seq('mut', $._type)),

    array_type: ($) =>
      prec.left(
        1,
        seq(
          field('element', $._type),
          '[',
          optional(field('size', $.integer_literal)),
          ']',
        ),
      ),

    type_parameters: ($) => seq('<', commaSep1($.type_parameter), '>'),

    type_parameter: ($) =>
      seq(
        field('name', $.identifier),
        optional(seq(':', field('constraint', $.constraint_list))),
      ),

    constraint_list: ($) => seq($._type, repeat(seq('&', $._type))),

    type_arguments: ($) => prec.dynamic(1, seq('<', commaSep1($._type), '>')),

    // #endregion
    // #region Literals and lexical

    _literal: ($) =>
      choice($._literal_value, $.vector_literal),

    _literal_value: ($) =>
      choice(
        $.integer_literal,
        $.float_literal,
        $.hex_literal,
        $.binary_literal,
        $.string_literal,
        $.template_literal,
        $.char_literal,
        $.boolean_literal,
        $.null_literal,
        $.atom_literal,
      ),

    vector_literal: ($) => seq('[', commaSep($._expression), ']'),

    integer_literal: (_) => token(/[0-9]+(_[0-9]+)*/),

    float_literal: (_) => token(/[0-9]+(_[0-9]+)*\.[0-9]+(_[0-9]+)*/),

    hex_literal: (_) => token(/0[xX][0-9a-fA-F]+/),

    binary_literal: (_) => token(/0[bB][01]+/),

    string_literal: ($) =>
      seq(
        '"',
        repeat(
          choice(
            $.escape_sequence,
            token.immediate(prec(1, /[^"\\]+/)),
          ),
        ),
        '"',
      ),

    escape_sequence: (_) => token.immediate(/\\./),

    // Everything between the delimiters is content, whitespace included, so each
    // piece is an immediate token: a non-immediate one would let `extras` swallow
    // the spaces and newlines the literal is supposed to keep.
    template_literal: ($) =>
      seq(
        '`',
        repeat(
          choice(
            $.template_substitution,
            $.escape_sequence,
            $._template_chars,
            $._template_dollar,
          ),
        ),
        token.immediate('`'),
      ),

    _template_chars: (_) => token.immediate(prec(1, /[^`\\$]+/)),

    // A `$` that does not open a slot is ordinary text. `${` is the longer match,
    // so the lexer prefers the substitution wherever one actually starts.
    _template_dollar: (_) => token.immediate('$'),

    template_substitution: ($) => seq(token.immediate('${'), field('expression', $._expression), '}'),

    char_literal: (_) =>
      token(
        seq(
          "'",
          choice(
            /[^'\\]/,
            /\\[bfnrt0\\']/,
            /\\u\{[0-9a-fA-F]+\}/,
          ),
          "'",
        ),
      ),

    boolean_literal: (_) => choice('true', 'false'),

    null_literal: (_) => 'null',

    atom_literal: ($) => seq(':', field('name', $.identifier)),

    mutable_specifier: (_) => 'mut',

    identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

    scoped_identifier: ($) =>
      seq(
        field('path', $.identifier),
        repeat1(seq('::', field('name', $.identifier))),
      ),

    _path: ($) => choice($.identifier, $.scoped_identifier),

    comment: (_) =>
      token(
        choice(
          seq('//', /.*/),
          seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'),
        ),
      ),

    doc_comment: (_) =>
      token(
        prec(2,
          choice(
            seq('///', /.*/),
            seq('//!', /.*/),
            seq('/**', /[^*]*\*+([^/*][^*]*\*+)*/, '/'),
            seq('/*!', /[^*]*\*+([^/*][^*]*\*+)*/, '/'),
          ),
        ),
      ),

    // #endregion
  },
});
