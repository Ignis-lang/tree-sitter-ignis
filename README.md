# Tree-sitter Ignis

This repository contains the Tree-sitter grammar for the Ignis programming language.
Tree-sitter is a high-performance parser used for syntax highlighting and other functionality
in text editors and development tools.

## Features

- Fast and accurate syntax highlighting for Ignis.
- Can be integrated into text editors that support Tree-sitter.

## Installation

### Neovim

To use this Tree-sitter grammar with Neovim:

```lua
local parser_config = require("nvim-treesitter.parsers").get_parser_configs()

parser_config["ignis"] = {
  install_info = {
    url = "https://github.com/Ignis-lang/tree-sitter-ignis.git",
    files = { "src/parser.c" },
    branch = "main",
    generate_requires_npm = false,
    requires_generate_from_grammar = true,
  },
  filetype = "ign",
}
```

And then run `:TSUpdate` or `:TSInstall ignis` in Neovim.

## Usage

After installing the grammar in your editor, Ignis files should automatically start benefiting from
syntax highlighting and other features provided by Tree-sitter.

## Contribute

Contributions are welcome! If you encounter any problems or have suggestions for improvement,
please open an issue or send a pull request.

## License

[MIT](LICENSE) © Ignacio Perez

