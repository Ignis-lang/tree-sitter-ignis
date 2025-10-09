```
<program> ::= (<declaration>)* <EOF>

<declaration> ::= <function>
  | <import>
  | <export>
  | <inline>
  | <const>
  | <record>
  | <enum>
  | <type-alias>
  | <extern>
  | <namespace>
  | <declare>
  | <meta>
  | <decorator>

<function> ::= "function" <identifier> (<generic-type>)? "(" <parameters>? ")" ":" <type> <block>
<parameters> ::= <parameter> ("," <parameter>)*
<parameter> ::= <metadata-expression>? "..."? <identifier> "?"? ":" <variable-modifiers>? <type-expression>

<import> ::= "import" <import-list> "from" <string> ";"
<import-list> ::= <import-item> | <import-item> "," <import-list>
<import-item> ::= <identifier> | <identifier> "as" <identifier>

<export> ::= "export" (<function> | <const> | <record> | <enum> | <type-alias> | <declare> | <meta> | <decorator>)

<inline> ::= "inline" (<function> | <const>)

<const> ::= "const" <identifier> ":" <type> "=" <expression> ";"

# Record syntax
<record> ::= "record" <generic-type>? <identifier> "{" <record-item>* "}"
<record-item> ::= <metadata-expression>? (<record-property> | <record-method> | <decorator-use>)
<record-property> ::= <property-modifier>* <identifier> <variable-modifiers>? <generic-type>? "?"? ":" <type-expression> ("=" <expression>)? ";"
<record-method> ::= <method-modifier>* <identifier> <generic-type>? "(" <parameters>? ")" "?"? ":" <type-expression> (<block> | ";")

<property-modifier> ::= "public" | "private" | "static" | "mut" | "abstract"
<method-modifier> ::= "public" | "private" | "static" | "final" | "abstract" | "inline"
<variable-modifiers> ::= ("mut" | "&" | "*")+
<metadata-expression> ::= "#" "[" (<identifier> ("(" <expression-list>? ")")? ","?)* "]"
                        | "#" <identifier> ("(" <expression-list>? ")")?

<generic-type> ::= "<" (<type-expression> | <cast>) ("," (<type-expression> | <cast>))* ">"

# Enum syntax
<enum> ::= "enum" <identifier> <generic-type>? "{" (<metadata-expression>? (<enum-variant> | <enum-method> | <decorator-use>))* "}"
<enum-variant> ::= <identifier> ("=" <expression> | "(" <type-list> ")")? ","
<enum-method> ::= <method-modifier>* <identifier> <generic-type>? "(" <parameters>? ")" ":" <type-expression> <block>

# Type alias syntax
<type-alias> ::= "type" <identifier> <generic-type>? "=" <type> ";"

# Extern syntax
<extern> ::= "extern" (<qualified-identifier>) "{" <extern-item>* "}"
<extern-item> ::= <function> | <record> | <enum> | <type-alias> | <declare>

# Namespace syntax
<namespace> ::= "namespace" <qualified-identifier> "{" <namespace-item>* "}"
<namespace-item> ::= <function> | <const> | <record> | <enum> | <type-alias> | <declare> | <extern>

# Declare syntax
<declare> ::= "declare" <identifier> ":" <type>

# Meta syntax
<meta> ::= "meta" <identifier> ("(" <parameters> ")")? ";"

# Decorator syntax
<decorator> ::= "decorator" <qualified-identifier> "(" <expression>? ")" (";" | <block>)

# Statements
<statement> ::= <declaration>
  | <if>
  | <for>
  | <for-in>
  | <while>
  | <return>
  | <break>
  | <continue>
  | <block>
  | <variable>
  | <expression> ";"

<if> ::= "if" "(" <expression> ")" <block> ("else if" "(" <expression> ")" <block>)* ("else" <block>)?
<for> ::= "for" "(" "let" <identifier> "=" <expression> ";" <expression> ";" <expression> ")" <block>
<for-of> ::= "for" "(" ("let" <identifier> | <identifier>) "of" <expression> ")" <block>
<while> ::= "while" "(" <expression> ")" <block>

<return> ::= "return" <expression>? ";"
<break> ::= "break" ";"
<continue> ::= "continue" ";"

<block> ::= "{" <statement>* "}"
<variable> ::= "let" "mut"? <identifier> ":" <type> ("=" <expression>)? ";"

<expression> ::= <assignment> | <match>

## Match expression
<match> ::= "match" "(" <expression> ")" "{" <match-arm>+ "}"
<match-arm> ::= <match-pattern> "->" (<expression> | <block>) ","?
<match-pattern> ::= <pattern> ( "|" <pattern> )*
<pattern> ::= <expression> <guard-clause>? | <when-clause> | "_"
<guard-clause> ::= "if" <expression>
<when-clause> ::= <expression> "when" <expression>

<assignment> ::= <ternary-expression> ( ( <assignment-operators> ) <assignment> )?
<ternary-expression> ::= <or-expression> ( "?" <expression> ":" <expression> )?
<or-expression> ::= <and-expression> ( "||" <and-expression> )*
<and-expression> ::= <bitwise-or-expression> ( "&&" <bitwise-or-expression> )*

<bitwise-or-expression> ::= <bitwise-xor-expression> ( "|" <bitwise-xor-expression> )*
<bitwise-xor-expression> ::= <bitwise-and-expression> ( "^" <bitwise-and-expression> )*
<bitwise-and-expression> ::= <equality> ( "&" <equality> )*

<equality> ::= <comparison> ( ( "==" | "!=" ) <comparison> )*
<comparison> ::= <range> ( ( "<" | ">" | "<=" | ">=" ) <range> )*
<range> ::= <shift> ( ( ".." | "..=" ) <shift> )*
<shift> ::= <term> ( ( "<<" | ">>" ) <term> )*
<term> ::= <factor> ( ( "+" | "-" ) <factor> )*
<factor> ::= <cast> ( ( "*" | "/" | "%" ) <cast> )*
<cast> ::= <unary> ( "as" <type> )?
<unary> ::= ( "++" | "--" | "-" | "!" | "~" )* <postfix>
<postfix> ::= <primary> <generic-type>? ( ("++" | "--") | <call-suffix> )*
<call-suffix> ::= <arguments> | "[" <expression> "]" | <member-access>
<arguments> ::= "(" <expression> ("," <expression>)* ")"
<member-access> ::= <generic-type>? ("." | "::") <identifier>

<primary> ::= <identifier>
  | <literal>
  | <group>
  | <this>
  | <self>
  | <decorator-expression>
  | <meta-expression>
  | <lambda>

# Literals
<integer> ::= <numbers> ("_" <numbers>)*
<float> ::= (<integer>? "." <numbers>) | (<integer> "." <numbers>?)
<hex> ::= <hex-numbers>
<binary> ::= <binary-numbers>
<string> ::= "\"" (<string-char> | <escape-sequence>)* "\""
<string-char> ::= [^"\\] | <escape-sequence>
<char> ::= "'" ( [^'\\] | <escape-sequence> ) "'"
<escape-sequence> ::= "\\" [abfnrtv'"\\]
<boolean> ::= "true" | "false"
<null> ::= "null"
<vector> ::= "[" <expression> ("," <expression>)* "]"

<object> ::= "{" <object-item>* "}"
<object-item> ::= (<object-property> | <object-method>) ","?
<object-property> ::= <identifier> ":" <expression>
<object-method> ::= <identifier> "(" <expression>? ")" ":" <type> <block>

<tuple> ::= "(" <expression> ("," <expression>)* ")"

<literal> ::= <integer>
  | <float>
  | <hex>
  | <binary>
  | <string>
  | <boolean>
  | <null>
  | <vector>
  | <object>
  | <tuple>

<group> ::= "(" <expression> ")"
<this> ::= "this"
<self> ::= "self"

<decorator-expression> ::= "@" <qualified-identifier> "(" <expression>? ")"
<meta-expression> ::= "#" <qualified-identifier> ("(" <expression>*? ")")? | "#" "[" (<expression>? ","?)* "]"
<lambda> ::= (<generic-type>)? "(" <parameters>? ")" ":" <type> "->" (<expression> | <block>)

<comment> ::= "//" ([a-zA-Z_][a-zA-Z0-9_]*)?
<multiline-comment> ::= "/*" ([a-zA-Z_][a-zA-Z0-9_]*)?
<documentation-comment> ::= "/**" ([a-zA-Z_][a-zA-Z0-9_]*)? "**/"

<type-modifier> ::= ("mut" | "&" | "*")+
<type-parameter> ::= <type> ("as" <type>)?
<qualified-identifier> ::= <identifier> ( (":" | ".") <identifier> )*

<type> ::= <type-identifier> | <union-type> | <intersection-type> | <vector-type> | <function-type>
<type-identifier> ::= <type-modifier>? (<primitive> | <identifier>) <generic-type>? "[]"?

<tuple-type> ::= "(" <type> ("," <type>)* ")"
<function-type> ::= "(" <type-list>? ")" "->" <type>
<type-list> ::= <type> ("," <type>)*

<vector-type> ::= <type-modifier>? <type-identifier> "[" <number>? "]"
<primitive> ::= "void"
  | "boolean"
  | "char"
  | "string"
  | "i8"
  | "i16"
  | "i32"
  | "i64"
  | "u8"
  | "u16"
  | "u32"
  | "u64"
  | "f32"
  | "f64"
  | "unknown"
  | "hex"
  | "binary"
<union-type> ::= <type> ("|" <type>)+
<intersection-type> ::= <type> ("&" <type>)+

<identifier> ::= [a-zA-Z_][a-zA-Z0-9_]*
<numbers> ::= [0-9]+ ("." [0-9]+)?
<hex-numbers> ::= "0x" [0-9a-fA-F]+
<binary-numbers> ::= "0b" [01]+

<assignment-operators> ::= "=" | "+=" | "-=" | "*=" | "/=" | "%=" | "&=" | "|=" | "^=" | "<<=" | ">>="
<separator> ::= "," | ";" | ":"
<delimiter> ::= <separator> | "[" | "]" | "(" | ")" | "{" | "}"
<symbol> ::= <assignment-operators>
  | <delimiter>
  | "."
  | "+"
  | "-"
  | "*"
  | "/"
  | "%"
  | "&"
  | "|"
  | "^"
  | "<<"
  | ">>"
  | "<"
  | ">"
  | "<="
  | ">="
  | "=="
  | "!="
  | "!"
  | "~"
  | "?"
  | ":"
  | "||"
  | "&&"
  | "++"
  | "--"
<keyword> ::= "as"
  | "async"
  | "await"
  | "break"
  | "continue"
  | "const"
  | "declare"
  | "else"
  | "enum"
  | "export"
  | "false"
  | "for"
  | "from"
  | "function"
  | "is"
  | "if"
  | "import"
  | "in"
  | "include"
  | "inline"
  | "let"
  | "meta"
  | "namespace"
  | "new"
  | "null"
  | "private"
  | "public"
  | "record"
  | "return"
  | "self"
  | "source"
  | "static"
  | "this"
  | "true"
  | "type"
  | "typeof"
  | "void"
  | "when"
  | "while"
  | "with"
  | "mut"
```
