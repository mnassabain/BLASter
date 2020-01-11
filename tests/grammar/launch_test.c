#include <stdio.h>
#include "ast.h"
#include "y.tab.h"

#define MUST_PASS 0
#define MUST_FAIL 1
extern FILE* yyin;
extern ast arbre;
extern void lex_free();

void test (char* test_name, char* test_file, int type) {
    
    FILE* f = fopen (test_file, "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file\n");
        return;
    }

    yyin = f;

    if (yyparse() == type) {
        printf("%s: success\n", test_name);
    } else {
        fprintf(stderr, "%s: failed\n", test_name);
    }

    fclose(f);
}

int main () {

    arbre = new_node(AST_MAIN);

    test("Test types", "../tests/grammar/test_types_success.c", MUST_PASS);
    free_ast(arbre);

    lex_free();
}