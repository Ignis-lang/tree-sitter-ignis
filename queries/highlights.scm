;; ============================================================================
;; Comments
;; ============================================================================

[
  (comment)
  (doc_comment)
] @comment

(doc_comment) @comment.documentation

;; ============================================================================
;; Literals
;; ============================================================================

(string_literal) @string
(char_literal) @string.special

(integer_literal) @number
(float_literal) @number.float

(boolean_literal) @boolean
(null_literal) @constant.builtin
(atom_literal) @string.special.symbol

;; ============================================================================
;; Punctuation
;; ============================================================================

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

(generic_type_declaration
  [
    "<"
    ">"
  ] @punctuation.bracket)

(generic_parameter_declaration
  [
    "<"
    ">"
  ] @punctuation.bracket)

[
  ","
  "."
  ":"
  "::"
  ";"
  "->"
] @punctuation.delimiter

[
  "#"
  "@"
] @punctuation.special

;; ============================================================================
;; Operators
;; ============================================================================

[
  "+"
  "-"
  "*"
  "/"
  "%"
  "&"
  "|"
  "^"
  "~"
  "<<"
  ">>"
  "!"
  "&&"
  "||"
  "++"
  "--"
  ".."
  "..="
  "..."
  "|>"
  "?"
] @operator

[
  "="
  "+="
  "-="
  "*="
  "/="
  "%="
  "&="
  "|="
  "^="
  "<<="
  ">>="
  "=="
  "!="
  "<"
  ">"
  "<="
  ">="
] @operator

;; ============================================================================
;; Keywords
;; ============================================================================

[
  "import"
  "from"
  "as"
] @keyword.import

"function" @keyword.function

[
  "record"
  "enum"
  "trait"
  "type"
  "namespace"
  "directive"
] @keyword.type

[
  "if"
  "else"
  "match"
  "when"
] @keyword.conditional

[
  "for"
  "while"
  "of"
  "break"
  "continue"
  "in"
] @keyword.repeat

"return" @keyword.return

[
  "const"
  "let"
  "mut"
  "static"
  "public"
  "private"
  "final"
  "inline"
  "extern"
  "export"
  "new"
] @keyword

[
  (mutable_specifier)
  (pointer_specifier)
  (reference_operator)
] @keyword.modifier

;; ============================================================================
;; Special identifiers and naming conventions
;; ============================================================================

(this_expression) @variable.builtin
(self_expression) @variable.builtin
(self_parameter) @variable.builtin

(pattern "_" @variable.builtin)

((identifier) @constant
  (#match? @constant "^[A-Z][A-Z0-9_]+$"))

((identifier) @type
  (#match? @type "^[A-Z][a-zA-Z0-9_]*$"))

;; ============================================================================
;; Types and modules
;; ============================================================================

(primitive_keyword) @type.builtin

(type_identifier
  (base_type
    (qualified_identifier) @type))

(typed_object_literal
  (qualified_identifier) @constructor)

(record_declaration
  name: (identifier) @type)

(enum_declaration
  name: (identifier) @type)

(trait_declaration
  name: (identifier) @type)

(type_definition
  (identifier) @type.definition)

(namespace_declaration
  (qualified_identifier
    (identifier) @module))

(extern_declaration
  (qualified_identifier
    (identifier) @module))

(qualified_identifier
  . (identifier) @module)

(scoped_identifier
  . (identifier) @module)

;; ============================================================================
;; Functions and methods
;; ============================================================================

(function_declaration
  name: (identifier) @function)

(extern_function
  name: (identifier) @function)

(method_declaration
  name: (identifier) @function.method)

(record_method_declaration
  name: (identifier) @function.method)

(enum_method_declaration
  name: (identifier) @function.method)

(trait_method_declaration
  name: (identifier) @function.method)

(call_expression
  function: (primary_expression
    (identifier) @function.call))

(method_call_expression
  function: (property_access
    name: (identifier) @function.method.call))

(directive_builtin_expression
  name: (identifier) @function.builtin)

;; ============================================================================
;; Variables, parameters, fields, and variants
;; ============================================================================

(variable_declaration
  name: (identifier) @variable)

(const_declaration
  name: (identifier) @constant)

(parameter_declaration
  name: (identifier) @variable.parameter)

(for_variable_declaration
  (identifier) @variable)

(for_of_statement
  (identifier) @variable)

(record_property_declaration
  name: (identifier) @variable.member)

(property_access
  name: (identifier) @variable.member)

(object_literal
  (identifier) @variable.member)

(enum_variant_declaration
  name: (identifier) @constant)

;; ============================================================================
;; Directives and attributes
;; ============================================================================

(directive_attr
  (qualified_identifier) @attribute)

(directive_attr_item
  (qualified_identifier) @attribute)

(directive_expression
  (qualified_identifier) @attribute)

;; ============================================================================
;; Match expressions
;; ============================================================================

(match_expression
  "match" @keyword.conditional)

(match_arm
  "->" @punctuation.delimiter)

;; ============================================================================
;; Fallback
;; ============================================================================

(identifier) @variable
