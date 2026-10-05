([
  (comment)
  (doc_comment)
] @injection.content
  (#set! injection.language "comment"))

; Inline assembly bodies are Intel-syntax text for the generic `asm` parser.
; Child nodes are excluded from the injected range, so holes, escaped braces
; and comments stay Ignis.
((asm_body) @injection.content
  (#set! injection.language "asm"))
