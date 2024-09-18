{
  pkgs ? import <nixpkgs> { },
}:
{
  default = pkgs.mkShell {
    nativeBuildInputs = with pkgs; [
      git
      cargo
      rustc
      gcc
      tree-sitter
      nodejs
      yarn
    ];
  };
}
