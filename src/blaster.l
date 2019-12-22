%{
  #include <stdlib.h>
  #include <stdio.h>
  #include "y.tab.h"

  // #define KEYWORD         0    
  // #define TYPE            0
  // #define IDENTIFIER      0
  // #define CONSTANT        0
  // #define STRING          0
  // #define COMMENT         0
  // #define OPERATOR        0
%}

comment       \/\/.*$|\/*([^*]*[*]+[^*\/])*[^*]*[*]+\/
keyword       for|while|if|else|struct|return|typedef
type          int|double
identifier    [a-zA-Z_][a-zA-Z0-9_]*
constant      [+-]?(([0-9])*\.[0-9]+)|([0-9]+\.)|([0-9]+)|([eE][+-]?[0-9]+)?
string        \"(\\.|[^\"\\])*\"
operator      ==|<=|>=|[+\-*\/><=]
symbol        [{}|,\"\"\'& ()]

%%

{keyword}    {
                printf("KEYWORD");
                return KEYWORD;
              }
{type}        {
                printf("TYPE");
                return TYPE;
              }
{identifier}  {
                printf("IDENTIFIER");
                return IDENTIFIER;
              }
{constant}    {
                printf("CONSTANT");
                return CONSTANT;
              }
{string}      {
                printf("STRING");
                return STRING;
              }
{comment}     {
                printf("COMMENT");
                return COMMENT;
              }
{operator}    {
                printf("OPERATOR");
                return OPERATOR;
              }
{symbol}      {
                printf("%s",yytext);
                return yytext[0];
              }
.             { 
                printf("Caractere inconnu: %s", yytext); 
                }

%%


int main(void)
{

  
  while(1)
    yylex();

  return 0;
}
