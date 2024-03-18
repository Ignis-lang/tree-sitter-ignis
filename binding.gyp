{
  "targets": [
    {
      "target_name": "tree_sitter_ignis_binding",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "<!@(node -p \"require('nan').include_dirs\")",
        "src"
      ],
      "sources": [
        "bindings/node/binding.cc",
        "src/parser.c"
      ]
    }
  ]
}

