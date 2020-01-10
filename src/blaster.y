%{
#include <stdio.h>
#include <string.h>
#include "../include/ast.h"

int yylex();
void yyerror(char*);
extern int yylineno;
extern FILE* yyin;

ast arbre;

%}

%union {
    int valeur;
    ast arbre;
}

%token <arbre> KEYWORD
%token <arbre> TYPE
%token <arbre> IDENTIFIER
%token <arbre> CONSTANT
%token <arbre> STRING
%token <arbre> COMMENT
%token <arbre> OPERATOR
%token <arbre> ENDLINE ASSIGN IF WHILE ELSE FOR TRUE FALSE 
%token <arbre> MACRO MAIN RETURN
%token <arbre> INT DOUBLE
%token <arbre> INC DEC

%type <arbre>   expression
%type <arbre>   condition
%type <arbre>   iteration
%type <arbre>   selection
%type <arbre>   increment_action
%type <arbre>   increment
%type <arbre>   increment_list
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


%left '+' '-'
%left '*' '/'

%right UMINUS

%%

// TODO

axiom:
    INT MAIN '(' ')' '{' statement_list '}'
        {
            // todo: return est un statement?? peut etre si on a le temps ça m'a l'air pas trop dur
            arbre = add_child(arbre, "main");
            arbre = add_child_node(arbre, $6);
            // ajout du return de cette manière pour l'instant 
            // arbre = add_child_node(arbre, $7);
            printf("\n\nFOUND\n");
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
    IDENTIFIER ASSIGN expression
        {
            //////////////
            $$ = $1;
        }

    | IDENTIFIER
        {
            //////////////
            $$ = $1;
        }
    | table
        {

        }
    ;

table:
    IDENTIFIER size_list
        {
            //////////////
            $$ = $1;
        }
    | IDENTIFIER size_list ASSIGN init_table
        {
            //////////////
            $$ = $1;
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

increment_list:
    increment_list ',' increment
        {
            //////////////
            $$ = $1;
        }
    | increment
        {
            //////////////
            $$ = $1;
        }
    ;

increment:
    increment_action IDENTIFIER
        {
            //////////////
            $$ = $1;
        }
    | IDENTIFIER increment_action
        {
            //////////////
            $$ = $1;
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
    | FOR '(' declaration ';' condition ';' increment_list ')' '{' statement_list '}'
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
    TRUE
        {
            // todo
            //////////////
            $$ = create_ast();
            $$ = add_child($$, "condition");
        }
    | FALSE
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

    return 0;
}
