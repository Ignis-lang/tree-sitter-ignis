; Imports
(import_statement
  (identifier) @local.definition.import)

; Functions and methods
(function_declaration
  name: (identifier) @local.definition.function)

(extern_function
  name: (identifier) @local.definition.function)

(record_method_declaration
  name: (identifier) @local.definition.method)

(enum_method_declaration
  name: (identifier) @local.definition.method)

(trait_method_declaration
  name: (identifier) @local.definition.method)

; Variables
(parameter_declaration
  name: (identifier) @local.definition.var)

(variable_declaration
  name: (identifier) @local.definition.var)

(const_declaration
  name: (identifier) @local.definition.var)

(for_variable_declaration
  (identifier) @local.definition.var)

(for_of_statement
  (identifier) @local.definition.var)

; Types and namespaces
(record_declaration
  name: (identifier) @local.definition.type)

(enum_declaration
  name: (identifier) @local.definition.type)

(trait_declaration
  name: (identifier) @local.definition.type)

(type_definition
  (identifier) @local.definition.type)

(namespace_declaration
  (qualified_identifier
    (identifier) @local.definition.namespace))

; Fields and variants
(record_property_declaration
  name: (identifier) @local.definition.field)

(enum_variant_declaration
  name: (identifier) @local.definition.field)

; References
(identifier) @local.reference

; Scopes
[
  (source_file)
  (block)
  (function_declaration)
  (lambda_expression)
  (namespace_declaration)
  (extern_declaration)
  (record_declaration)
  (enum_declaration)
  (trait_declaration)
  (for_statement)
  (for_of_statement)
  (while_statement)
  (if_statement)
  (else_clause)
  (else_if_clause)
  (match_expression)
  (match_arm)
] @local.scope
