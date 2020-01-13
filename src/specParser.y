%{
#include <stdio.h>
#include <string.h>
#include "ast.h"

int zzlex();
void zzerror(char*);
void lex_free();
extern int yylineno;
extern FILE* zzin;

ast specTree;

%}


%union {
    char* string;
    int int_val;
    double double_val;
    ast specTree;
}

%token <string> IDENTIFIER
%token <int_val> INT_VAL
%token <double_val> DOUBLE_VAL
%token <string> STRING
%token <string> COMMENT
%token <string> ASSIGN IF WHILE ELSE FOR
%token <string> MACRO MAIN RETURN
%token <string> INT DOUBLE VOID
%token <string> INC DEC
%token <string> PRINTF
%token <string> AND_OP OR_OP GEQ_OP LEQ_OP EQ_OP NEQ_OP

%type <specTree>   expression
%type <specTree>   condition
%type <specTree>   iteration
%type <specTree>   selection
%type <specTree>   increment_action
%type <specTree>   update_list
%type <specTree>   update
%type <specTree>   element
%type <specTree>   assign_list
%type <specTree>   type
%type <specTree>   declaration
%type <specTree>   statement
%type <specTree>   statement_list
%type <specTree>   return
%type <specTree>   axiom
%type <specTree>   table
%type <specTree>   init_table
%type <specTree>   size_list
%type <specTree>   expression_list
%type <specTree>   constant
%type <specTree>   init_table_list
%type <specTree>   initialisation_list
%type <specTree>   initialisation
%type <specTree>   condition_list
%type <specTree>   function_list
%type <specTree>   function
%type <specTree>   arg_list
%type <specTree>   arg

%start axiom

%left OR_OP
%left AND_OP
%left EQ_OP NEQ_OP GEQ_OP LEQ_OP
%left '+' '-'
%left '*' '/'

%right UMINUS

%%

axiom:
    function_list
        {   
            specTree = new_list(LIST_FUNC);
            add_child_node(specTree, $1);
            // printf("\nFOUND\n");
            return 0;
        }
    ;

function_list:
    function_list function
        {
            $$ = add_brother_node($1, $2);
        }
    | function  { $$ = $1; }
    ;

function:
    type IDENTIFIER '(' arg_list ')' '{' statement_list '}'
        {
            $$ = new_node(AST_FUNC);

            add_child_node($1, new_id($2));
            add_child_node($$, $1);

            ast list = new_list(LIST_ARG);
            add_child_node(list, $4);

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, $7);

            add_child_node($$, list);
            add_child_node($$, statements);
        }
    ;

arg_list:
    arg_list ',' arg
        {
            
            $$ = add_brother_node($1, $3);
        }
    | type IDENTIFIER     
        {
            $$ = add_child_node($1, new_id($2)); 
        }
    ;

arg:
    type '*' IDENTIFIER
        {
            $$ = add_child_node($1, new_id($3));
        }
    | type IDENTIFIER 
        {
            $$ = add_child_node($1, new_id($2));
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
    | PRINTF        { $$ = new_printf($1); }
    ;

initialisation_list:
    initialisation_list ',' initialisation    { $$ = add_brother_node($1, $3); }
    | initialisation                       { $$ = $1; }
    ;

initialisation:
    type IDENTIFIER ASSIGN expression 
        {
            ast assign = new_node(AST_ASSIGN);
            add_child_node(assign, new_id($2));
            add_child_node(assign, $4);
            $$ = add_child_node($1, assign); 
        }
    | IDENTIFIER ASSIGN expression
        {
            $$ = new_node(AST_ASSIGN);
            add_child_node($$, new_id($1));
            add_child_node($$, $3);
        }
    ;

declaration:
    type assign_list    { $$ = add_child_node($1, $2); }
    | assign_list       { $$ = $1; }
    ;

type:
    INT         { $$ = new_node(AST_INT); }
    | DOUBLE    { $$ = new_node(AST_DOUBLE); }
    | VOID      { $$ = new_node(AST_VOID); }
    ;

assign_list:
    assign_list ',' element     { $$ = add_brother_node($1, $3); }
    | element                   { $$ = $1; }
    ;

element:
    IDENTIFIER  { $$ = new_id($1); }
    | table     { $$ = $1 ;}
    | update    { $$ = $1; }
    ;

table:
    IDENTIFIER size_list
        {
            $$ = new_node(AST_TABLE);
            add_child_node($$, new_id($1));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, $2);
            add_child_node($$, dimensions);
        }
    | IDENTIFIER size_list ASSIGN init_table
        {
            $$ = new_node(AST_ASSIGN);
            ast table = new_node(AST_TABLE);
            add_child_node(table, new_id($1));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, $2);
            add_child_node(table, dimensions);
            add_child_node($$, table);
            add_child_node($$, $4);
        }
    | IDENTIFIER size_list ASSIGN expression
        {
            $$ = new_node(AST_ASSIGN);
            ast table = new_node(AST_TABLE);
            add_child_node(table, new_id($1));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, $2);
            add_child_node(table, dimensions);
            add_child_node($$, table);
            add_child_node($$, $4);
        }
    ;

size_list:
    size_list '[' expression ']'
        {
            $$ = add_brother_node($1, $3);
        }
    | '[' expression ']'
        {
            $$ = $2;
        }
    ;

init_table_list:
    init_table_list ',' init_table      { $$ = add_brother_node($1, $3);  }
    | init_table                        { $$ = $1; }
    ;

init_table:
    '{' expression_list '}'
        {
            $$ = new_node(AST_ARRAY);
            add_child_node($$, $2);
        }
    | '{' init_table_list '}'
        {
            $$ = new_node(AST_ARRAY);
            add_child_node($$, $2);
        }
    ;

update_list:
    update_list ',' update  { $$ = add_brother_node($1, $3);  }
    | update                { $$ = $1; }
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
            $$ = new_node(AST_IF);
            add_child_node($$, $3);

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, $6);
            add_child_node($$, statements);
        }
    | IF '(' condition ')' '{' statement_list '}' ELSE '{' statement_list '}'
        {
            $$ = new_node(AST_IF);
            add_child_node($$, $3);
            
            ast statements = new_list(LIST_STAT);
            add_child_node(statements, $6);
            add_child_node($$, statements);

            statements = new_list(LIST_STAT);
            add_child_node(statements, $10);
            add_child_node($$, statements);
        }   
    ;

iteration:
    WHILE '(' condition_list ')' '{' statement_list '}'
        {
            $$ = new_node(AST_WHILE);

            ast condition = new_list(LIST_COND);
            add_child_node(condition, $3);
            add_child_node($$, condition);

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, $6);
            add_child_node($$, statements);
        }
    | FOR '(' initialisation_list ';' condition_list ';' update_list ')' '{' statement_list '}'
        {
            $$ = new_node(AST_FOR);

            ast init = new_list(LIST_INIT);
            add_child_node(init, $3);
            add_child_node($$, init);

            ast condition = new_list(LIST_COND);
            add_child_node(condition, $5);
            add_child_node($$, condition);

            ast update = new_list(LIST_UPDATE);
            add_child_node(update, $7);
            add_child_node($$, update);

            ast statements = new_list(LIST_STAT);
            add_child_node(statements, $10);
            add_child_node($$, statements);
        }
    ;

condition_list:
    condition_list ',' condition    { $$ = add_brother_node($1, $3); }
    | condition                     { $$ = $1; }
    ;

condition:
    condition OR_OP condition
        {
            $$ = new_node(AST_OR_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | condition AND_OP condition 
        {
            $$ = new_node(AST_AND_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression GEQ_OP expression
        {
            $$ = new_node(AST_GEQ_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression '>' expression %prec GEQ_OP
        {
            $$ = new_node(AST_GT_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression LEQ_OP expression 
        {
            $$ = new_node(AST_LEQ_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression '<' expression %prec LEQ_OP
        {
            $$ = new_node(AST_LT_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression EQ_OP expression
        {
            $$ = new_node(AST_EQ_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | expression NEQ_OP expression
        {
            $$ = new_node(AST_NEQ_OP);
            add_child_node($$, $1);
            add_child_node($$, $3);
        }
    | '(' condition ')'
        {
            $$ = $2;
        }
    ;

expression_list:
    expression_list ',' expression
        {
            $$ = add_brother_node($1, $3);
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
    | IDENTIFIER size_list
        {
            $$ = new_node(AST_TABLE);
            add_child_node($$, new_id($1));
            ast dimensions = new_node(AST_DIM);
            add_child_node(dimensions, $2);
            add_child_node($$, dimensions);
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

void zzerror (char *s) {
    fprintf(stderr, "[Yacc] error line %d: %s\n", yylineno, s);
}

#ifndef SPEC_PARSER
int main() {

    ////////// parse a test file ///
    FILE* f = fopen ("spec.c", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = f;
    ////////////////////////////////

    specParser();

    // Affichage de l'specTree 
    print_ast(specTree);

    print_code(specTree, 0);

    // Clean
    delete_node(specTree);
    lex_free();
    fclose(f);

    return 0;
}
#endif