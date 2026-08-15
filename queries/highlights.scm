; Comments

(comment) @comment
(doc_comment) @comment.documentation

; Literals

(integer_literal) @number
(hex_literal) @number
(binary_literal) @number
(float_literal) @number.float
(string_literal) @string
(escape_sequence) @string.escape
(char_literal) @character
(boolean_literal) @boolean
(null_literal) @constant.builtin
(atom_literal) @constant
(atom_literal
  name: (identifier) @constant)

; Types

(primitive_type) @type.builtin

(type_definition
  name: (identifier) @type.definition)

(record_declaration
  name: (identifier) @type)

(enum_declaration
  name: (identifier) @type)

(trait_declaration
  name: (identifier) @type)

(type_parameter
  name: (identifier) @type)

(generic_type
  name: (identifier) @type)

(generic_type
  name: (scoped_identifier
    name: (identifier) @type))

(record_init
  type: (identifier) @type)

(record_init
  type: (scoped_identifier
    name: (identifier) @type))

(variable_declaration
  type: (identifier) @type)

(parameter
  type: (identifier) @type)

(field_declaration
  type: (identifier) @type)

(const_declaration
  type: (identifier) @type)

(for_initializer
  type: (identifier) @type)

(for_of_statement
  type: (identifier) @type)

(function_declaration
  return_type: (identifier) @type)

(method_declaration
  return_type: (identifier) @type)

(extern_function
  return_type: (identifier) @type)

(lambda_expression
  return_type: (identifier) @type)

(cast_expression
  type: (identifier) @type)

(function_type
  return_type: (identifier) @type)

(constraint_list
  (identifier) @type)

(array_type
  element: (identifier) @type)

(reference_type
  (identifier) @type)

(pointer_type
  (identifier) @type)

(mutable_type
  (identifier) @type)

; Functions and methods

(function_declaration
  name: (identifier) @function)

(extern_function
  name: (identifier) @function)

(method_declaration
  name: (identifier) @function.method)

(call_expression
  function: (identifier) @function.call)

(call_expression
  function: (scoped_identifier
    name: (identifier) @function.call))

(call_expression
  function: (member_expression
    property: (identifier) @function.method.call))

(builtin_expression
  name: (identifier) @function.builtin)

(capture_expression
  kind: _ @keyword.modifier)

; Declarations and bindings

(const_declaration
  name: (identifier) @constant)

(extern_const
  name: (identifier) @constant)

(variable_declaration
  name: (identifier) @variable)

(for_initializer
  name: (identifier) @variable)

(for_of_statement
  name: (identifier) @variable)

(parameter
  name: (identifier) @variable.parameter)

(field_declaration
  name: (identifier) @variable.member)

(member_expression
  property: (identifier) @variable.member)

(record_init_field
  name: (identifier) @variable.member)

(enum_variant
  name: (identifier) @constant)

(namespace_declaration
  name: (identifier) @module)

(namespace_declaration
  name: (scoped_identifier) @module)

(extern_declaration
  name: (identifier) @module)

(extern_declaration
  name: (scoped_identifier) @module)

(import_name
  name: (identifier) @variable)

(import_name
  alias: (identifier) @variable)

(scoped_identifier
  path: (identifier) @module)

; Patterns

(wildcard_pattern) @variable.builtin

(path_pattern
  name: (identifier) @constant)

(path_pattern
  name: (scoped_identifier
    name: (identifier) @constant))

; Attributes

(attribute
  "@" @attribute
  name: (identifier) @attribute)

(attribute
  name: (scoped_identifier) @attribute)

; Keywords

[
  "function"
  "record"
  "enum"
  "trait"
  "type"
  "namespace"
  "extern"
] @keyword

[
  "let"
  "const"
] @keyword

(mutable_specifier) @keyword.modifier

[
  "static"
  "public"
  "private"
  "inline"
] @keyword.modifier

[
  "if"
  "else"
  "match"
] @keyword.conditional

[
  "while"
  "for"
  "of"
] @keyword.repeat

[
  "import"
  "from"
  "export"
] @keyword.import

[
  "return"
  "break"
  "continue"
  "defer"
] @keyword

"as" @keyword.operator

(self_expression) @variable.builtin
(self_parameter) @variable.builtin

[
  "always"
  "never"
] @keyword.modifier

; Operators

[
  "+"
  "-"
  "*"
  "/"
  "%"
  "="
  "=="
  "!="
  "<"
  "<="
  ">"
  ">="
  "&&"
  "||"
  "!"
  "~"
  "&"
  "|"
  "^"
  "<<"
  ">>"
  "+="
  "-="
  "*="
  "/="
  "%="
  "&="
  "|="
  "~="
  "^="
  "<<="
  ">>="
  "++"
  "--"
  "|>"
  "->"
  "?"
  "::"
] @operator

; Punctuation

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

[
  ","
  ";"
  ":"
  "."
] @punctuation.delimiter

"@" @punctuation.special

; Fallback

(identifier) @variable
