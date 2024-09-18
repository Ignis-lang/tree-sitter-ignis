package tree_sitter_ignis_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-ignis"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_ignis.Language())
	if language == nil {
		t.Errorf("Error loading Ignis grammar")
	}
}
