%{
#include <stdlib.h>
#include <stdio.h>
// Doit être AVANT y.tab.h
#include "../include/ast.h"
#include "y.tab.h"

// #define KEYWORD         0    
// #define TYPE            0
// #define IDENTIFIER      0
// #define CONSTANT        0
// #define STRING          0
// #define COMMENT         0
// #define OPERATOR        0

int DEBUG_LEX = 1;
// if ((debug = getenv ("DEBUG_LEX")) != NULL) {
//     DEBUG_LEX = atoi(debug);
// }


/// MACROS AND COMMENTS IGNORED, NEED TO BE COPIED IN DESTINATION FILE
%}

%option yylineno

inline_comment  \/\/.*$
comment_multi   \/\*([^*]*[*]+[^*\/])*[^*]*[*]+\/
keyword         struct|return|typedef
identifier      [a-zA-Z_][a-zA-Z0-9_]*
macro           #(define|include).*$
constant        ((([0-9])*\.[0-9]*)|([0-9]+\.)|([0-9]+))([eE][+-]?[0-9]+)?
string          \"(\\.|[^\"\\])*\"
endline         ;

%%

[=]             { if ( DEBUG_LEX ) printf("ASSIGN "); return ASSIGN; }
"++"            { if ( DEBUG_LEX ) printf("INC "); return INC;}
"--"            { if ( DEBUG_LEX ) printf("DEC "); return DEC;}
"main"          { if ( DEBUG_LEX ) printf("MAIN "); return MAIN; }
{macro}         { if ( DEBUG_LEX ) printf("MACRO "); }
"return"        { if ( DEBUG_LEX ) printf("RETURN "); return RETURN; }
"if"            { if ( DEBUG_LEX ) printf("IF "); return IF; }
"while"         { if ( DEBUG_LEX ) printf("WHILE "); return WHILE; }
"else"          { if ( DEBUG_LEX ) printf("ELSE "); return ELSE; }
"for"           { if ( DEBUG_LEX ) printf("FOR "); return FOR; }
"int"           { if ( DEBUG_LEX ) printf("INT "); return INT; }
"double"        { if ( DEBUG_LEX ) printf("DOUBLE "); return DOUBLE; }
"&&"            { if ( DEBUG_LEX ) printf("AND_OP "); return AND_OP;}
"||"            { if ( DEBUG_LEX ) printf("OR_OP "); return OR_OP;}
">="            { if ( DEBUG_LEX ) printf("GEQ_OP "); return GEQ_OP;}
"<="            { if ( DEBUG_LEX ) printf("LEQ_OP "); return LEQ_OP;}
"=="            { if ( DEBUG_LEX ) printf("EQ_OP "); return EQ_OP;}
"!="            { if ( DEBUG_LEX ) printf("NEQ_OP "); return NEQ_OP;}
{keyword}       { if ( DEBUG_LEX ) printf("KEYWORD "); return KEYWORD; }
{identifier}    { if ( DEBUG_LEX ) printf("IDENTIFIER "); return IDENTIFIER; }
{constant}      { if ( DEBUG_LEX ) printf("CONSTANT "); return CONSTANT; }
{inline_comment} { if ( DEBUG_LEX ) printf("COMMENT "); /* printf("%s\n", yytext); */ }
{comment_multi} { if ( DEBUG_LEX ) printf("COMMENT "); /* printf("%s\n", yytext); */ }
[ \t\n]         { if ( DEBUG_LEX ) printf("%s",yytext); }
.               { if ( DEBUG_LEX ) printf("%s",yytext);  return yytext[0]; }

%%


// int main(void)
// {

  
//   while(1)
//     yylex();

//   return 0;
// }
