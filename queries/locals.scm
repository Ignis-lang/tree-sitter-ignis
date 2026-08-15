; Scopes

[
  (source_file)
  (block)
  (function_declaration)
  (method_declaration)
  (lambda_expression)
  (namespace_declaration)
  (record_declaration)
  (enum_declaration)
  (trait_declaration)
  (match_arm)
  (for_statement)
  (for_of_statement)
] @local.scope

; Definitions

(function_declaration
  name: (identifier) @local.definition.function)

(method_declaration
  name: (identifier) @local.definition.method)

(extern_function
  name: (identifier) @local.definition.function)

(variable_declaration
  name: (identifier) @local.definition.var)

(const_declaration
  name: (identifier) @local.definition.constant)

(parameter
  name: (identifier) @local.definition.parameter)

(for_initializer
  name: (identifier) @local.definition.var)

(for_of_statement
  name: (identifier) @local.definition.var)

(type_definition
  name: (identifier) @local.definition.type)

(record_declaration
  name: (identifier) @local.definition.type)

(enum_declaration
  name: (identifier) @local.definition.type)

(trait_declaration
  name: (identifier) @local.definition.type)

(type_parameter
  name: (identifier) @local.definition.type)

(import_name
  name: (identifier) @local.definition.import)

(import_name
  alias: (identifier) @local.definition.import)

(namespace_declaration
  name: (identifier) @local.definition.namespace)

(field_declaration
  name: (identifier) @local.definition.field)

; References

(identifier) @local.reference
