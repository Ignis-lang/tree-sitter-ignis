[
  (block)
  (function_declaration)
  (record_declaration)
  (enum_declaration)
  (trait_declaration)
  (namespace_declaration)
  (extern_declaration)
  (match_expression)
  (if_statement)
  (else_clause)
  (else_if_clause)
  (for_statement)
  (for_of_statement)
  (while_statement)
  (lambda_expression)
  (object_literal)
  (typed_object_literal)
] @indent.begin

(block
  "}" @indent.end)

(object_literal
  "}" @indent.end)

(typed_object_literal
  "}" @indent.end)

(else_clause) @indent.branch
(else_if_clause) @indent.branch

(_ "[" "]" @indent.end) @indent
(_ "{" "}" @indent.end) @indent
(_ "(" ")" @indent.end) @indent

[
  (comment)
  (doc_comment)
] @indent.ignore
