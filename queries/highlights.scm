;; ============================================================================
;; Comments
;; ============================================================================

(comment) @comment
(doc_comment) @comment.documentation

;; ============================================================================
;; Literals
;; ============================================================================

(string_literal) @string
(char_literal) @character
(integer_literal) @number
(float_literal) @number.float
(boolean_literal) @boolean
(null_literal) @constant.builtin
(atom_literal) @string.special.symbol

;; Tuple literal
(tuple_literal
  "(" @punctuation.bracket
  ")" @punctuation.bracket)

;; Vector literal
(vector_literal
  "[" @punctuation.bracket
  "]" @punctuation.bracket)

;; Object literal
(object_literal
  "{" @punctuation.bracket
  "}" @punctuation.bracket)
(object_literal
  (identifier) @property)

;; ============================================================================
;; Punctuation
;; ============================================================================

["(" ")" "{" "}" "[" "]"] @punctuation.bracket
[":" "," ";"] @punctuation.delimiter
"." @punctuation.delimiter
"::" @punctuation.delimiter

;; ============================================================================
;; Operators
;; ============================================================================

[
  "+" "-" "*" "/" "%"
  "&" "|" "^" "~"
  "<<" ">>"
  "!" "&&" "||"
  "++" "--"
] @operator

[
  "=" "+=" "-=" "*=" "/=" "%="
  "&=" "|=" "^=" "<<=" ">>="
] @operator

[
  "==" "!=" "<" ">" "<=" ">="
] @operator

[
  ".." "..="
  "|>"
  "->"
  "..."
  "?"
] @operator

"#" @punctuation.special

;; ============================================================================
;; Keywords
;; ============================================================================

;; Control flow
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
] @keyword.repeat

"return" @keyword.return

;; Declarations
[
  "function"
  "record"
  "enum"
  "type"
  "namespace"
  "directive"
] @keyword

;; Modifiers
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
] @keyword.modifier

;; Other keywords
[
  "import"
  "from"
  "as"
  "new"
] @keyword

;; Special expressions
(this_expression) @variable.builtin
(self_expression) @variable.builtin

;; ============================================================================
;; Types
;; ============================================================================

;; Primitive types
(primitive_keyword) @type.builtin

;; Type identifiers
(type_identifier
  (identifier) @type)

;; Pointer and reference modifiers in types
(type_identifier
  (pointer_specifier) @operator)
(type_identifier
  (reference_operator) @operator)
(type_identifier
  (mutable_specifier) @keyword.modifier)

;; Generic type parameters
(generic_type_declaration
  "<" @punctuation.bracket
  ">" @punctuation.bracket)

;; Function types
(type_function
  "->" @operator)

;; Tuple types
(tuple_type
  "(" @punctuation.bracket
  ")" @punctuation.bracket)

;; Vector types
(vector_type
  "[" @punctuation.bracket
  "]" @punctuation.bracket)

;; ============================================================================
;; Functions
;; ============================================================================

;; Function declarations
(function_declaration
  name: (identifier) @function)

;; Extern function declarations
(extern_function
  name: (identifier) @function)

;; Method declarations
(method_declaration
  name: (identifier) @function.method)
(record_method_declaration
  name: (identifier) @function.method)
(enum_method_declaration
  name: (identifier) @function.method)

;; Function calls
(call_expression
  function: (primary_expression
    (identifier) @function.call))

;; Method calls
(method_call_expression
  function: (property_access
    name: (identifier) @function.method.call))

;; Lambda expressions
(lambda_expression
  "->" @operator)

;; ============================================================================
;; Variables and Parameters
;; ============================================================================

;; Variable declarations
(variable_declaration
  name: (identifier) @variable)

;; Constant declarations
(const_declaration
  name: (identifier) @constant)

;; Parameter declarations
(parameter_declaration
  name: (identifier) @variable.parameter)

;; For loop variable
(for_variable_declaration
  (identifier) @variable)

;; ============================================================================
;; Records and Enums
;; ============================================================================

;; Record declarations
(record_declaration
  name: (identifier) @type)

;; Record properties
(record_property_declaration
  name: (identifier) @property)

;; Enum declarations
(enum_declaration
  name: (identifier) @type)

;; Enum variants
(enum_variant_declaration
  name: (identifier) @constant)

;; ============================================================================
;; Type Definitions
;; ============================================================================

(type_definition
  (identifier) @type.definition)

;; ============================================================================
;; Namespaces
;; ============================================================================

(namespace_declaration
  (qualified_identifier
    (identifier) @module))

(qualified_identifier
  (identifier) @module)

;; ============================================================================
;; Imports
;; ============================================================================

(import_statement
  (identifier) @type)

(import_statement
  "as" @keyword
  (identifier) @type)

;; ============================================================================
;; Properties and Field Access
;; ============================================================================

(property_access
  name: (identifier) @property)

(vector_access_expression
  (identifier) @variable)

;; ============================================================================
;; Directives and Attributes
;; ============================================================================

;; Directive attributes: #[...] or #name(...)
(directive_attr
  "#" @punctuation.special)

(directive_attr_item
  (qualified_identifier) @attribute)

;; Directive expressions in code
(directive_expression
  "#" @punctuation.special)

;; ============================================================================
;; Extern Declarations
;; ============================================================================

(extern_declaration
  "extern" @keyword.modifier)

;; ============================================================================
;; Match Expressions
;; ============================================================================

(match_expression
  "match" @keyword.conditional)

(match_arm
  "->" @operator)

(pattern
  "_" @variable.builtin)

;; ============================================================================
;; Fallback - General identifiers (lowest priority)
;; ============================================================================

(identifier) @variable
