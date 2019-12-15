#include "../include/ast.h"

int main()
{
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

    printf("child 2 is %s\n", get_name(get_children(a)[1]));
    return 0;
}