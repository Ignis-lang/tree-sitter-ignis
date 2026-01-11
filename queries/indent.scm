[
  (block)
  (enum_declaration)
  (record_declaration)
  (namespace_declaration)
  (extern_declaration)
  (match_expression)
] @indent.begin

(block
  "}" @indent.end)

(else_clause) @indent.branch
(else_if_clause) @indent.branch

(_ "[" "]" @end) @indent
(_ "{" "}" @end) @indent
(_ "(" ")" @end) @indent

[
  (comment)
  (doc_comment)
] @indent.ignore
