%{
#include <stdio.h>
#include <string.h>
#include <getopt.h>
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
%type <arbre>   init_table_list
%type <arbre>   initialisation_list
%type <arbre>   initialisation
%type <arbre>   condition_list

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
            arbre = new_node(AST_MAIN);
            ast list = new_list(LIST_STAT);
            add_child_node(list, $6);
            add_child_node(arbre, list);
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

void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error line %d: %s\n", yylineno, s);
}

#ifndef TESTING
int main(int argc, char** argv) {

    /*
    printf("\n888888b.   888             d8888  .d8888b.  888\n");                    
    printf("888  \"88b  888            d88888 d88P  Y88b 888\n");                    
    printf("888  .88P  888           d88P888 Y88b.      888\n");                    
    printf("8888888K.  888          d88P 888  \"Y888b.   888888 .d88b.  888d888\n");  
    printf("888  \"Y88b 888         d88P  888     \"Y88b. 888   d8P  Y8b 888P\"\n");    
    printf("888    888 888        d88P   888       \"888 888   88888888 888\n");      
    printf("888   d88P 888       d8888888888 Y88b  d88P Y88b. Y8b.     888\n");      
    printf("8888888P\"  88888888 d88P     888  \"Y8888P\"   \"Y888 \"Y8888  888\n");
    printf("\n888888888888888888888888888888888888888888888888888888888888888888\n\n");

    int opt, optindex;
    struct option options[] = {
        {"version", no_argument, 0, 'v' },
        {"tos", no_argument, 0, 't' },
        {"ast", no_argument, 0, 'a' },
        {"output", required_argument, 0, 'o' }
    };

    char * output_file;

    while((opt = getopt_long(argc, argv, "vtao:", options, &optindex)) != -1)
    {
        switch(opt)
        {
            case 'v':
                printf("Membres du projet:\n");
                printf(" * CHRISTOFFEL Quentin\n");
                printf(" * WENDLING Nicolas\n");
                printf(" * NASSABAIN Marco\n");
                break;
            case 't':
                printf("option tos\n");
                break;
            case 'a':
                printf("option ast\n");
                break;
            case 'o':
                printf("option output with arg: %s\n", optarg);
                output_file = optarg;
                break;
            default:
                printf("option non gérée\n");
        }
    }

    printf("output file = %s\n", output_file);
    */


    ////////// parse a test file ///
    // FILE* f = fopen ("test.c", "r");
    // FILE* f = fopen ("simple.c", "r");
    FILE* f = fopen ("exemple.c", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = f;
    ////////////////////////////////

    yyparse();

    // Affichage de l'arbre 
    print_ast(arbre);

    print_code(arbre, 0);


    // TEST SWAP
    ast racine = new_node(AST_MAIN);
    ast fils1 = new_node(AST_ADD);
    ast fils2 = new_node(AST_MINUS);
    ast fils3 = new_node(AST_MUL);
    ast fils4 = new_node(AST_DIV);
    add_child_node(racine, fils1);
    add_child_node(racine, fils2);
    add_child_node(racine, fils3);
    add_child_node(racine, fils4);

    
    print_ast(racine);
    swap_nodes(fils1, fils3);
    print_ast(racine);

    // Clean
    delete_node(arbre);
    lex_free();
    fclose(f);

    return 0;
}
#endif
