# Ignis Grammar (BNF)

This document mirrors the syntax accepted by the reference compiler
(`ignisc.rs`, `crates/ignis_parser`). It is the contract this tree-sitter
grammar is written against. Tokens the lexer reserves but the parser never
consumes (`..`, `..=`, `...`, `#`, `is`, `in`, `this`, `when`, `meta`,
`decorator`, `declare`) are intentionally excluded.

## Source structure

```bnf
<source-file>    ::= <item>*
<item>           ::= <declaration> | <attribute> | <conditional-block>
<declaration>    ::= <import> | <export> | <function> | <const>
                   | <type-alias> | <record> | <enum> | <trait>
                   | <extern> | <namespace>
```

## Items

```bnf
<import>         ::= "import" <import-name> ("," <import-name>)* ","?
                     "from" <string> ";"
<import-name>    ::= <identifier> ("as" <identifier>)?

<export>         ::= "export" <declaration>
                   | "export" <identifier> ("," <identifier>)* ";"
                   | "export" <identifier> ("," <identifier>)*
                     "from" <string> ";"

<inline>         ::= "inline" ("(" ("always" | "never") ")")?

<function>       ::= <inline>? "function" <identifier> <type-params>?
                     <parameters> ":" <type> <block>

<parameters>     ::= "(" (<parameter> ("," <parameter>)* ","?)? ")"
<parameter>      ::= <attribute>* <identifier> ":" <type>
<self-param>     ::= "&" "mut"? "self"

<const>          ::= "const" <identifier> ":" <type> "=" <expression> ";"

<type-alias>     ::= "type" <identifier> <type-params>? "=" <type> ";"

<record>         ::= "record" <identifier> <type-params>? <decl-body>
<trait>          ::= "trait" <identifier> <type-params>? <decl-body>
<decl-body>      ::= "{" (<attribute> | <field> | <method>)* "}"

<field>          ::= <member-modifier>* <identifier> ":" <type>
                     ("=" <expression>)? ";"
<method>         ::= <member-modifier>* "function"? <identifier>
                     <type-params>? "(" <self-param>? ("," <parameter>)* ")"
                     (":" <type>)? (<block> | ";")
<member-modifier> ::= "static" | "public" | "private" | <inline>

<enum>           ::= "enum" <identifier> <type-params> <enum-body>
<enum-body>      ::= "{" (<attribute> | <enum-variant> | <field> | <method>)* "}"
<enum-variant>   ::= <identifier> ("(" <type> ("," <type>)* ","? ")")? ","?

<extern>         ::= "extern" <path> "{" (<attribute> | <extern-fn> | <extern-const>)* "}"
<extern-fn>      ::= "function" <identifier> <parameters> ":" <type> ";"
<extern-const>   ::= "const" <identifier> ":" <type> ";"

<namespace>      ::= "namespace" <path> "{" <item>* "}"
```

## Attributes and compile-time directives

```bnf
<attribute>      ::= "@" <path> ("(" <attr-arg> ("," <attr-arg>)* ","? ")")?
<attr-arg>       ::= <expression> | <primitive-type> | "mut"
                   | <identifier> ":" <expression>

<conditional-block> ::= "@" ("if" | "ifelse") "(" <expression> ")"
                        <conditional-body>
                        ("@" "else" <conditional-body>)?
<conditional-body>  ::= "{" (<item> | <statement>)* "}"
```

`@configFlag(...)` before an item or statement is an ordinary attribute
applied to the next single item. In expression position it folds to a
boolean literal at parse time.

## Statements

```bnf
<statement>      ::= <let> | <let-else> | <const> | <expr-statement>
                   | <return> | <defer> | <break> | <continue>
                   | <if> | <while> | <for> | <for-of> | <block>
                   | <conditional-block> | <attribute>

<let>            ::= "let" "mut"? <identifier> (":" <type>)?
                     ("=" <expression>)? ";"
<let-else>       ::= "let" "mut"? <pattern> "=" <expression>
                     "else" <block> ";"
<expr-statement> ::= <expression> ";"
<return>         ::= "return" <expression>? ";"
<defer>          ::= "defer" <expression> ";"
<break>          ::= "break" ";"
<continue>       ::= "continue" ";"

<if>             ::= "if" "(" <condition> ")" <block>
                     ("else" (<block> | <if>))?
<while>          ::= "while" "(" <condition> ")" <block>
<condition>      ::= <expression> | "let" <pattern> "=" <expression>

<for>            ::= "for" "(" "let" <identifier> (":" <type>)?
                     "=" <expression> ";" <expression> ";" <expression> ")"
                     <block>
<for-of>         ::= "for" "(" "let" <identifier> (":" <type>)?
                     "of" <expression> ")" <block>

<block>          ::= "{" <statement>* "}"
```

## Expressions

Binding powers from the compiler's Pratt table, weakest to tightest.
Assignment and ternary are right-associative; the rest are left-associative.

| Level | Operators |
|---|---|
| assignment | `=` `+=` `-=` `*=` `/=` `%=` `&=` `\|=` `~=` `^=` `<<=` `>>=` |
| ternary | `?` `:` |
| pipe | `\|>` |
| logical or | `\|\|` |
| logical and | `&&` |
| bitor | `\|` |
| bitxor | `^` |
| bitand | `&` |
| equality | `==` `!=` |
| comparison | `<` `<=` `>` `>=` |
| shift | `<<` `>>` |
| additive | `+` `-` |
| multiplicative | `*` `/` `%` |
| cast | `as` |
| prefix unary | `++` `--` `-` `!` `~` `&` `&mut` `*` |
| postfix | `++` `--` `!` (try) |
| call / index / member | `(...)` `[...]` `.` |

```bnf
<expression>     ::= <literal> | <identifier> | <path> | "self"
                   | <unit> | <tuple> | <group>
                   | <unary> | <binary> | <assignment> | <ternary>
                   | <cast> | <call> | <member> | <index> | <postfix>
                   | <match> | <lambda> | <builtin> | <capture>
                   | <record-init>

<unit>           ::= "(" ")"
<group>          ::= "(" <expression> ")"
<tuple>          ::= "(" <expression> ("," <expression>)+ ","? ")"

<call>           ::= <expression> <type-args>? "(" <expr-list>? ")"
<member>         ::= <expression> "." <identifier>
<index>          ::= <expression> "[" <expression> "]"
<cast>           ::= <expression> "as" <type>

<match>          ::= "match" "(" <expression> ")"
                     "{" (<match-arm> ("," <match-arm>)* ","?)? "}"
<match-arm>      ::= <pattern> ("if" <expression>)? "->"
                     (<expression> | <block>)

<lambda>         ::= <parameters> ":" <type> "->" (<expression> | <block>)

<builtin>        ::= "@" <identifier> <type-args>? "(" <expr-list>? ")"
<capture>        ::= "@" ("move" | "ref" | "refMut") <expression>

<record-init>    ::= <path> <type-args>? "{" (<init-field>
                     ("," <init-field>)* ","?)? "}"
<init-field>     ::= <identifier> ":" <expression>
```

`2(x)` (a literal directly followed by a call) is parsed by the compiler
as implicit multiplication; this grammar keeps it a call node.

## Patterns

```bnf
<pattern>        ::= <simple-pattern> ("|" <simple-pattern>)*
<simple-pattern> ::= "_" | <literal-pattern> | <path-pattern> | <tuple-pattern>
<literal-pattern> ::= <literal> | "-" <number>
<path-pattern>   ::= <path> ("(" <pattern> ("," <pattern>)* ","? ")")?
<tuple-pattern>  ::= "(" (<pattern> ("," <pattern>)* ","?)? ")"
```

## Types

```bnf
<type>           ::= <primitive-type> | <path> | <generic-type>
                   | <function-type> | <reference-type> | <pointer-type>
                   | <mutable-type> | <array-type>

<primitive-type> ::= "i8" | "i16" | "i32" | "i64"
                   | "u8" | "u16" | "u32" | "u64"
                   | "f32" | "f64" | "boolean" | "char" | "atom"
                   | "str" | "void"

<generic-type>   ::= <path> <type-args>
<function-type>  ::= "(" (<type> ("," <type>)*)? ")" "->" <type>
<reference-type> ::= "&" <type>
<pointer-type>   ::= "*" <type>
<mutable-type>   ::= "mut" <type>
<array-type>     ::= <type> "[" <integer>? "]"

<type-params>    ::= "<" <type-param> ("," <type-param>)* ","? ">"
<type-param>     ::= <identifier> (":" <type> ("&" <type>)*)?
<type-args>      ::= "<" <type> ("," <type>)* ","? ">"
```

There are no union, intersection, or tuple types: the compiler's AST has
those variants but the parser never produces them.

## Lexical

```bnf
<identifier>     ::= [A-Za-z_][A-Za-z0-9_]*          ; ASCII only
<path>           ::= <identifier> ("::" <identifier>)*

<integer>        ::= [0-9]+ ("_" [0-9]+)*             ; no suffixes
<float>          ::= <integer> "." <integer>          ; digits required on both sides
<hex>            ::= "0" [xX] [0-9a-fA-F]+            ; no separators
<binary>         ::= "0" [bB] [01]+                   ; no separators
<string>         ::= '"' (escape | char)* '"'         ; \" \\ \b \f \n \r \t \0
<char>           ::= "'" (char | escape | "\u{" hex+ "}") "'"
<atom>           ::= ":" <identifier>
<boolean>        ::= "true" | "false"
```

Comments: `//`, `/* */` (non-nesting). Doc comments: `///`, `//!`,
`/** */`, `/*! */`.
