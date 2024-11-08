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
      nodejs
      yarn
    ];
  };
}
