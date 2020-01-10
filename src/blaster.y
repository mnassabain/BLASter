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
    int value;
    ast arbre;
}

%token <string> IDENTIFIER
%token <value> CONSTANT
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
            arbre = add_child(arbre, "main");
            arbre = add_child_node(arbre, $6);
            printf("\nFOUND\n");
            return 0;
        }
    ;

return:
    RETURN ';'
        {
            $$ = create_ast();
            $$ = add_child($$, "return");
        }
    | RETURN expression ';'
        {
            $$ = create_ast();
            $$ = add_child($$, "return");

            $$ = add_child_node($$, $2);
        }
    ;

statement_list:
    statement_list statement
        {
            $$ = $1;
            $$ = add_child_node($$, $2);
        }
    | statement
        {
            $$ = create_ast();
            $$ = add_child($$, "statement_list");
            $$ = add_child_node($$, $1);
        }
    ;

statement:
    declaration ';'
        {
            $$ = create_ast();
            $$ = add_child($$, "statement");

            $$ = add_child_node($$, $1);
        }
    | selection 
        {
            $$ = create_ast();
            $$ = add_child($$, "statement");

            $$ = add_child_node($$, $1);
        }
    | iteration
        {
            $$ = create_ast();
            $$ = add_child($$, "statement");

            $$ = add_child_node($$, $1);
        }
    | return
        {
            $$ = create_ast();
            $$ = add_child($$, "statement");

            $$ = add_child_node($$, $1);
        }
    | PRINTF
        {
            
        }
    ;

declaration:
    type assign_list
        {
            $$ = create_ast();
            $$ = add_child($$, "declaration");
            $$ = add_child_node($$, $1);
            $$ = add_child_node($$, $2);
        }
    | assign_list
        {
            $$ = create_ast();
            $$ = add_child($$, "declaration");
            $$ = add_child_node($$, $1);
        }
    ;

type:
    INT 
        {
            // todo: check le nom et valeur
            $$ = create_ast();
            $$ = add_child($$, "type");
        }
    | DOUBLE
        {
            $$ = create_ast();
            $$ = add_child($$, "type");
        }
    ;

assign_list:
    assign_list ',' element
        {
            $$ = $1;
            $$ = add_child($$, "assign");
            $$ = add_child_node($$, $3);
        }
    | element
        {
            $$ = create_ast();
            // Doit-on mettre assign uniquement quand il y en a plusieurs ou à chaque fois ?
            $$ = add_child($$, "assign_list");

            ast s = create_ast();
            s = add_child(s, "assign");
            s = add_child_node(s, $1);

            $$ = add_child_node($$, s);
        }
    ;

element:
    IDENTIFIER
        {

        }
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

        }
    | IDENTIFIER increment_action
        {

        }
    | IDENTIFIER ASSIGN expression
        {

        }
    ;

increment_action:
    INC
        {
            $$ = create_ast();
            $$ = add_child($$, "INC");
        }
    | DEC 
        {
            $$ = create_ast();
            $$ = add_child($$, "DEC");
        }
    ;
    
selection:
    IF '(' condition ')' '{' statement_list '}'
        {
            $$ = create_ast();
            $$ = add_child($$, "selection");

            $$ = add_child($$, "if");
            $$ = add_child_node($$, $3);
            $$ = add_child_node($$, $6);
        }
    | IF '(' condition ')' '{' statement_list '}' ELSE '{' statement_list '}'
        {
            $$ = create_ast();
            $$ = add_child($$, "selection");

            $$ = add_child($$, "if");
            $$ = add_child_node($$, $3);
            $$ = add_child_node($$, $6);
            $$ = add_child($$, "else");
            $$ = add_child_node($$, $10);
        }   
    ;

iteration:
    WHILE '(' condition ')' '{' statement_list '}'
        {
            $$ = create_ast();
            $$ = add_child($$, "while");
            $$ = add_child_node($$, $3);
            $$ = add_child_node($$, $6);
        }
    | FOR '(' declaration ';' condition ';' update_list ')' '{' statement_list '}'
        {
            $$ = create_ast();
            $$ = add_child($$, "for");
            $$ = add_child_node($$, $3);
            $$ = add_child_node($$, $5);
            $$ = add_child_node($$, $7);
            $$ = add_child_node($$, $10);
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
            //////////////
            $$ = create_ast();
            $$ = add_child($$, "condition");
        }
    ;

expression_list:
    expression_list ',' expression
        {

        }
    | expression
        {

        }
    ;

expression:
    expression '+' expression
        {
            $$ = create_ast();
            $$ = add_child($$, "expression");
        }
    | expression '-' expression
        {
            $$ = create_ast();
            $$ = add_child($$, "expression");

            $$ = add_child_node($$, $1);
            $$ = add_child($$, "-");
            $$ = add_child_node($$, $3);
        }
    | expression '*' expression
        {
            $$ = create_ast();
            $$ = add_child($$, "expression");

            $$ = add_child_node($$, $1);
            $$ = add_child($$, "*");
            $$ = add_child_node($$, $3);
        }
    | expression '/' expression
        {
            $$ = create_ast();
            $$ = add_child($$, "expression");

            $$ = add_child_node($$, $1);
            $$ = add_child($$, "/");
            $$ = add_child_node($$, $3);
        }
    | '(' expression ')'
        {
            $$ = create_ast();
            $$ = add_child($$, "expression");

            $$ = add_child($$, "(");
            $$ = add_child_node($$, $2);
            $$ = add_child($$, ")");
        }
    | '-' expression %prec UMINUS
        {
            // wtf
        } 
    | IDENTIFIER
        {
            $$ = create_ast();
            $$ = add_child($$, "identifier");
        }
    | CONSTANT
        {
            $$ = create_ast();
            $$ = add_child($$, "constant");
        }
    ;
    

%%

void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error line %d: %s\n", yylineno, s);
}

#ifndef TESTING
int main() {

    arbre = create_ast();

    ////////// parse a test file ///
    FILE* f = fopen ("test.c", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = f;
    ////////////////////////////////

    yyparse();

    // Affichage de l'arbre 
    print_ast(arbre);

    free_ast(arbre);
    lex_free();
    fclose(f);

    return 0;
}
#endif
