#include "../include/ast.h"

int main()
{
    printf("## test build tree ##\n");
    ast a = create_ast();
    a = add_child(a, "racine");
    a = add_child(add_child(a, "fils1"), "fils2");
    a->first_child = add_child(a->first_child, "fils1 du fils1");
    a->first_child = add_child(a->first_child, "fils2 du fils1");
    a->first_child = add_child(a->first_child, "fils3 du fils1");
    a->first_child = add_child(a->first_child, "fils4 du fils1");
    a->first_child = add_child(a->first_child, "fils5 du fils1");
    a->first_child = add_child(a->first_child, "fils6 du fils1");
    a->first_child = add_child(a->first_child, "fils7 du fils1");
    a->first_child = add_child(a->first_child, "fils8 du fils1");
    a->first_child = add_child(a->first_child, "fils9 du fils1");
    print_ast(a);

    printf("\n## test get children ##\n");
    ast* children = get_children(a->first_child);
    printf("child 4 of racine is %s\n", get_name(children[3]));

    free(children);
    free_ast(a);

    return 0;
}