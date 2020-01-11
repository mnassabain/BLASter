%{
#include <stdio.h>
#include <string.h>
#include "ast.h"

int yylex();
void yyerror(char*);
void lex_free();
extern int yylineno;
extern FILE* yyin;

ast arbre;

%}

%union {
    char* string;
    int int_val;
    double double_val;
    ast arbre;
}

%token <string> IDENTIFIER
%token <int_val> INT_VAL
%token <double_val> DOUBLE_VAL
%token <string> STRING
%token <string> COMMENT
%token <string> ASSIGN IF WHILE ELSE FOR
%token <string> MACRO MAIN RETURN
%token <string> INT DOUBLE
%token <string> INC DEC
%token <string> PRINTF
%token <string> AND_OP OR_OP GEQ_OP LEQ_OP EQ_OP NEQ_OP

%type <arbre>   expression
%type <arbre>   condition
%type <arbre>   iteration
%type <arbre>   selection
%type <arbre>   increment_action
%type <arbre>   update_list
%type <arbre>   update
%type <arbre>   element
%type <arbre>   assign_list
%type <arbre>   type
%type <arbre>   declaration
%type <arbre>   statement
%type <arbre>   statement_list
%type <arbre>   return
%type <arbre>   axiom
%type <arbre>   table
%type <arbre>   init_table
%type <arbre>   size_list
%type <arbre>   expression_list
%type <arbre>   constant

%start axiom

%left OR_OP
%left AND_OP
%left EQ_OP NEQ_OP GEQ_OP LEQ_OP
%left '+' '-'
%left '*' '/'

%right UMINUS

%%

// TODO

axiom:
    INT MAIN '(' ')' '{' statement_list '}'
        {
            add_child_node(arbre, $6);
            printf("\nFOUND\n");
            return 0;
        }
    ;

return:
    RETURN ';'
        {
            $$ = new_node(AST_RETURN);
        }
    | RETURN expression ';'
        {
            $$ = new_node(AST_RETURN);
            add_child_node($$, $2);
        }
    ;

statement_list:
    statement statement_list
        {
            $$ = new_node(AST_STAT);
            add_brother_node($$, $2);
            add_child_node($$, $1);
         }
    | statement
        {
            $$ = new_node(AST_STAT);
            add_child_node($$, $1);
        }
    ;

statement:
    declaration ';' { $$ = $1; }
    | selection     { $$ = $1; }
    | iteration     { $$ = $1; }
    | return        { $$ = $1; }
    | PRINTF        { // TODO ;
        }
    ;

declaration:
    type assign_list    { $$ = add_child_node($1, $2); }
    | assign_list       { $$ = $1; }
    ;

type:
    INT         { $$ = new_node(AST_INT); }
    | DOUBLE    { $$ = new_node(AST_DOUBLE); }
    ;

assign_list:
    assign_list ',' element     { $$ = add_brother_node($1, $3); }
    | element                   {  $$ = $1; }
    ;

element:
    IDENTIFIER  { $$ = new_id($1); }
    | table
        {
            
        }
    | update
        {

        }
    ;

table:
    IDENTIFIER size_list
        {

        }
    | IDENTIFIER size_list ASSIGN init_table
        {

        }
    ;

size_list:
    size_list '[' expression ']'
        {

        }
    | '[' expression ']'
        {

        }
    ;

init_table_list:
    init_table_list ',' init_table
        {

        }
    | init_table
    ;

init_table:
    '{' expression_list '}'
        {

        }
    | '{' init_table_list '}'
        {

        }
    ;

update_list:
    update_list ',' update
        {

        }
    | update
        {

        }
    ;

update:
    increment_action IDENTIFIER
        {   
            // TODO : REVOIR PRECEDENCE OPERATEUR UNAIRES
            $$ = add_child_node($1, new_id($2));
        }
    | IDENTIFIER increment_action
        {
            // TODO : REVOIR PRECEDENCE OPERATEUR UNAIRES
            $$ = add_child_node($2, $$ = new_id($1));
        }
    | IDENTIFIER ASSIGN expression
        {   
            $$ = new_node(AST_ASSIGN);
            add_child_node($$, new_id($1));
            add_child_node($$, $3);
        }
    ;

increment_action:
    INC
        {
            $$ = new_node(AST_INC);
        }
    | DEC 
        {
            $$ = new_node(AST_DEC);
        }
    ;
    
selection:
    IF '(' condition ')' '{' statement_list '}'
        {
            
            // $$ = add_child_node($$, "selection");

            // $$ = add_child_node($$, "if");
            // $$ = add_child_node($$, $3);
            // $$ = add_child_node($$, $6);
        }
    | IF '(' condition ')' '{' statement_list '}' ELSE '{' statement_list '}'
        {
            
            // $$ = add_child_node($$, "selection");

            // $$ = add_child_node($$, "if");
            // $$ = add_child_node($$, $3);
            // $$ = add_child_node($$, $6);
            // $$ = add_child_node($$, "else");
            // $$ = add_child_node($$, $10);
        }   
    ;

iteration:
    WHILE '(' condition ')' '{' statement_list '}'
        {
            $$ = new_node(AST_WHILE);
            $$ = add_child_node($$, $3);
            $$ = add_child_node($$, $6);

        }
    | FOR '(' declaration ';' condition ';' update_list ')' '{' statement_list '}'
        {
            $$ = new_node(AST_FOR);
            add_child_node($$, $3);
            add_child_node($$, $5);
            add_child_node($$, $7);
            add_child_node($$, $10);
        }
    ;

condition:
    condition OR_OP condition
        {

        }
    | condition AND_OP condition 
        {

        }
    | expression GEQ_OP expression
        {

        }
    | expression '>' expression %prec GEQ_OP
        {

        }
    | expression LEQ_OP expression 
        {

        }
    | expression '<' expression %prec LEQ_OP
        {

        }
    | expression EQ_OP expression
        {

        }
    | expression NEQ_OP expression
        {

        }
    | '(' condition ')'
        {

        }
    ;

expression_list:
    expression_list ',' expression
        {
            add_brother_node($$, $3);
        }
    | expression
        {
            $$ = $1;
        }
    ;

expression:
    expression '+' expression
        {
            $$ = new_node(AST_ADD);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression '-' expression
        {
            $$ = new_node(AST_MINUS);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression '*' expression
        {
            $$ = new_node(AST_MUL);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression '/' expression
        {
            $$ = new_node(AST_DIV);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | '(' expression ')'
        {
            $$ = $2;
        }
    | '-' expression %prec UMINUS
        {
            $$ = new_node(AST_UMINUS);
            add_child_node($$, $2);
        } 
    | IDENTIFIER
        {
            $$ = new_id($1);
        }
    | constant
        {
            $$ = $1;
        }
    ;
    
constant:
    INT_VAL
        {
            $$ = new_int($1);
        }
    | DOUBLE_VAL
        {
            $$ = new_double($1);
        }
    ;

%%

void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error line %d: %s\n", yylineno, s);
}

#ifndef TESTING
int main() {

    arbre = new_node(AST_MAIN);

    ////////// parse a test file ///
    // FILE* f = fopen ("test.c", "r");
    FILE* f = fopen ("simple.c", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = f;
    ////////////////////////////////

    yyparse();

    // Affichage de l'arbre 
    print_ast(arbre);

    // Clean
    free_ast(arbre);
    lex_free();
    fclose(f);

    return 0;
}
#endif
