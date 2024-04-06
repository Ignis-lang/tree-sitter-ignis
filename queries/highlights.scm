(comment) @comment

[
  (string_literal)
  (char_literal)
] @string

[
  (integer_literal)
  (float_literal)
] @number

(object_literal key: (identifier) @object.key)

(object_literal (identifier) @object.key)

(object_literal (method_declaration name: (identifier) @object.key))

(null_literal) @constant

["-" "=" "<" "<=" ">" ">=" "!" "++" "--" "||" "&&" "/" "*" "+" "%" "&" "|" "==" "?" "@"] @operator

(type_identifier (identifier) @type)
(primitive_keyword) @type

(get_expression (property_access (identifier) @type))

(enum_declaration (identifier) @type)

(type_definition (identifier) @variable)

(interface_declaration (identifier) @variable)

(extern_declaration (identifier) @variable)

(call_expression
  function: (identifier) @function.call)

(call_expression
  arguments: (expression (identifier) @variable.parameter))

(method_call_expression
  function: (property_access name: (identifier) @method)
)

(method_call_expression
  arguments: (expression (identifier) @variable.parameter))

(interface_declaration
  (interface_method_declaration function: (identifier) @function.interface)
)

(method_declaration (identifier) @method)

(property_declaration (identifier) @property)

(property_access name: (identifier) @property)

(class_instance_expression (identifier) @type.class)

(function_declaration (identifier) @function)

(variable_declaration (identifier) @variable)

(parameter_declaration (identifier) @parameter)

(array_access_expression (identifier) @variable.array)

(for_variable_declaration (identifier) @variable.loop)

(for_of_statement left: (identifier) @variable.loop)

(record_declaration (identifier) @type.record)
   
(record_property_declaration name: (identifier) @property)

(record_method_declaration name: (identifier) @method)
  
(decorator_declaration (identifier) @decorator)

(decorator_use (identifier) @decorator)

(get_expression (property_access name: (identifier) @property))

(enum_member_declaration (identifier) @method)

(expression (identifier) @variable)

["(" ")" "{" "}" "[" "]"] @punctuation.bracket

[":" "." "," ";" ] @punctuation.delimiter

[
  "if" "else" "let" "return" "function" "import" "from" "for" "enum" "export"
  "while" "of" "interface" "extends" (mutable_specifier) (this_expression)
  "public" "private" "new" "class" "implements" "super" "static" "final"
  "readonly" "in" "const" "as" "break" "void" "extern" "continue" "unknown"
  "type" "record" "decorator"
] @keyword

(boolean_literal) @boolean
