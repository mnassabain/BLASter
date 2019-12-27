%{
#include <stdio.h>

int yylex();
void yyerror(char*);
extern int yylineno;
extern FILE* yyin;

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
%token ENDLINE ASSIGN IF WHILE ELSE FOR TRUE FALSE 
%token MACRO MAIN RETURN
%token INT DOUBLE
%token INC DEC

%start axiom



%left '+' '-'
%left '*' '/'

%right UMINUS

%%

// TODO

axiom:
    INT MAIN '(' ')' '{' statement_list return '}'
        {
            printf("\n\nFOUND\n");
            return 0;
        }
    ;

return:
    RETURN ';'
        {

        }
    | RETURN expression ';'
        {

        }
    ;

statement_list:
    statement_list statement
        {

        }
    | statement
        {

        }
    ;

statement:
    declaration ';'
        {

        }
    | selection 
        {

        }
    | iteration
        {

        }
    ;

declaration:
    type assign_list
        {

        }
    | assign_list
        {
            
        }
    ;

type:
    INT 
    | DOUBLE
    ;

assign_list:
    assign_list ',' element
        {

        }
    | element
        {

        }
    ;

element:
    IDENTIFIER ASSIGN expression
        {

        }
    | IDENTIFIER
        {

        }
    | increment
        {

        }
    ;

increment_list:
    increment_list ',' increment
        {

        }
    | increment
        {

        }
    ;

increment:
    increment_action IDENTIFIER
        {

        }
    | IDENTIFIER increment_action
        {

        }
    ;

increment_action:
    INC
        {

        }
    | DEC 
        {

        }
    ;
    
selection:
    IF '(' condition ')' '{' statement_list '}'
        {

        }
    | IF '(' condition ')' '{' statement_list '}' ELSE '{' statement_list '}'
        {

        }   
    ;

iteration:
    WHILE '(' condition ')' '{' statement_list '}'
        {

        }
    | FOR '(' declaration ';' condition ';' increment_list ')' '{' statement_list '}'
        {

        }
    ;

// TODO
condition:
    TRUE
        {

        }
    | FALSE
        {

        }
    
    ;

expression:
    expression '+' expression
        {

        }
    | expression '-' expression
        {

        }
    | expression '*' expression
        {

        }
    | expression '/' expression
        {

        }
    | '(' expression ')'
        {

        }
    | '-' expression %prec UMINUS
        {

        } 
    | IDENTIFIER
        {

        }
    | CONSTANT
        {

        }
    ;
    

%%

void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error line %d: %s\n", yylineno, s);
}

int main() {

    ////////// parse a test file ///
    FILE* f = fopen ("test.test", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file");
        return 1;
    }
    yyin = f;
    ////////////////////////////////

    return yyparse();
}
