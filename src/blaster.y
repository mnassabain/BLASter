%{
  #include <stdio.h>
  int yylex();
  void yyerror(char*);
%}

%union {
  int valeur;
}

%token <valeur> KEYWORD
%token <valeur> TYPE
%token <valeur> IDENTIFIER
%token <valeur> CONSTANT
%token <valeur> STRING
%token <valeur> COMMENT
%token <valeur> OPERATOR

%%

  all:
      KEYWORD;

%%

int main() {
  printf("Entrez une addition :\n");
  return yyparse();
}
