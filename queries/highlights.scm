(comment) @comment

(string_literal) @string
(char_literal) @string
(integer_literal) @number
(float_literal) @number

(null_literal) @constant

["-" "=" "<" "<=" ">" ">=" "!" "++" "--" "||" "&&" "/" "*" "+" "%" "&" "|" "==" "?"] @operator

(expression (identifier) @variable.property)

(generic_type_declaration
  "<" @punctuation.bracket
  ">" @punctuation.bracket)
  
((identifier) @constant
 (#match? @constant "^[A-Z][A-Z\\d_]+$"))
 
(type_identifier (identifier) @type)

(call_expression
  function: (identifier) @function.call)

(cast (identifier) @variable)

(call_expression
  function: (identifier) @function.call)
  
(call_expression
	  arguments: (expression (identifier) @variable.parameter))

(method_call_expression
  function: (property_access name: (identifier) @keword))
  
(method_call_expression
	  function: (property_access) @variable)
      
(method_call_expression
	  arguments: (expression (identifier) @variable.parameter))
  
(interface_declaration
	(interface_method_declaration function: (identifier) @function.method))
    
(method_declaration (identifier) @method)

(property_declaration (identifier) @class.property)

(get_expression (property_access name: (identifier) @class.property))

(get_expression (property_access (identifier) @variable))

(class_instance_expression (identifier) @variable.class)

(function_declaration (identifier) @function.declaration)
    
(assignment_expression (property_access name: (identifier) @variable))

(variable_declaration (identifier) @variable)
    
(parameter_declaration (identifier) @variable.parameter)

(array_access_expression (identifier) @variable)

(for_variable_declaration (identifier) @variable)

(for_of_statement left: (identifier) @variable)

(record_declaration (identifier) @type)
   
(record_property_declaration name: (identifier) @property)

(record_method_declaration name: (identifier) @method)

(extern_declaration
  (identifier) @type.extern)

["(" ")" "{" "}" "[" "]"] @punctuation.bracket

[":" "." "," ";" ] @punctuation.delimiter

[
  "if"
  "else"
  "let"
  "return"
  "function"
  "import"
  "from"
  "for"
  "enum"
  "export"
  "while"
  "of"
  "interface"
  "extends"
  (mutable_specifier)
  (this_expression)
  (primitive_keyword)
  "public"
  "private"
  "new"
  "class"
  "implements"
  "super"
  "static"
  "final"
  "readonly"
  "in"
  "const"
  "as"
  "break"
  "export"
  "void"
  "extern"
  "continue"
  "unknown"
  "type"
  "record"
  "export"
] @keyword
