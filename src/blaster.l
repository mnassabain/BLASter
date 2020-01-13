%{
#include <stdlib.h>
#include <stdio.h>
// Doit être AVANT y.tab.h
#include "../include/ast.h"
#include "../include/symbolsTable.h"
#include "y.tab.h"

extern int DEBUG_LEX;
extern FILE* output_d;

/// MACROS AND COMMENTS IGNORED, NEED TO BE COPIED IN DESTINATION FILE
%}

%option yylineno

inline_comment  \/\/.*$
comment_multi   \/\*([^*]*[*]+[^*\/])*[^*]*[*]+\/
identifier      [a-zA-Z_][a-zA-Z0-9_]*
macro           #(define|include).*$
int             [0-9]*
double          ((([0-9])*\.[0-9]*)|([0-9]+\.)|([0-9]+))([eE][+-]?[0-9]+)?
string          \"(\\.|[^\"\\])*\"
printf          printf([[:space:]])?\({string}[^;]*;
endline         ;

%%

[=]             { if ( DEBUG_LEX ) printf("ASSIGN "); return ASSIGN; }
"++"            { if ( DEBUG_LEX ) printf("INC "); return INC;}
"--"            { if ( DEBUG_LEX ) printf("DEC "); return DEC;}
"main"          { if ( DEBUG_LEX ) printf("MAIN "); return MAIN; }
{macro}         { if ( DEBUG_LEX ) printf("MACRO "); fprintf(output_d, "%s\n", yytext); }
{printf}        { yylval.string = strdup(yytext); if ( DEBUG_LEX ) printf("PRINTF "); return PRINTF; }
"return"        { if ( DEBUG_LEX ) printf("RETURN "); return RETURN; }
"if"            { if ( DEBUG_LEX ) printf("IF "); return IF; }
"while"         { if ( DEBUG_LEX ) printf("WHILE "); return WHILE; }
"else"          { if ( DEBUG_LEX ) printf("ELSE "); return ELSE; }
"for"           { if ( DEBUG_LEX ) printf("FOR "); return FOR; }
"int"           { if ( DEBUG_LEX ) printf("INT "); return INT; }
"double"        { if ( DEBUG_LEX ) printf("DOUBLE "); return DOUBLE; }
"void"          { if ( DEBUG_LEX ) printf("VOID "); return VOID; }
"&&"            { if ( DEBUG_LEX ) printf("AND_OP "); return AND_OP;}
"||"            { if ( DEBUG_LEX ) printf("OR_OP "); return OR_OP;}
">="            { if ( DEBUG_LEX ) printf("GEQ_OP "); return GEQ_OP;}
"<="            { if ( DEBUG_LEX ) printf("LEQ_OP "); return LEQ_OP;}
"=="            { if ( DEBUG_LEX ) printf("EQ_OP "); return EQ_OP;}
"!="            { if ( DEBUG_LEX ) printf("NEQ_OP "); return NEQ_OP;}
{identifier}    { yylval.string = strdup(yytext); if ( DEBUG_LEX ) printf("IDENTIFIER "); return IDENTIFIER; }
{int}           { yylval.int_val = atoi(yytext); if ( DEBUG_LEX ) printf("INT_VAL "); return INT_VAL; }
{double}        { yylval.double_val = atof(yytext); if ( DEBUG_LEX ) printf("DOUBLE_VAL "); return DOUBLE_VAL; }
{inline_comment} { if ( DEBUG_LEX ) printf("COMMENT "); /* printf("%s\n", yytext); */ }
{comment_multi} { if ( DEBUG_LEX ) printf("COMMENT "); /* printf("%s\n", yytext); */ }
[ \t\n\r]       { if ( DEBUG_LEX ) printf("%s",yytext); }
.               { if ( DEBUG_LEX ) printf("%s",yytext);  return yytext[0]; }

%%

// Free the memory allocated for Lex when we are done.
void lex_yyfree() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}
