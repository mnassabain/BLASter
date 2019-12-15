#include "../include/ast.h"

ast create_ast()
{
    return NULL;
}

ast add_child(ast node, char* name)
{
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->name = malloc(MAX_NAME);
    strcpy(new_node->name, name); // strcpy
    new_node->first_child = NULL;
    new_node->next = NULL;

    if (node == NULL)
    {
        return new_node;
    }

    if (node->first_child == NULL)
    {
        node->first_child = new_node;
        return node;
    }

    ast ptr = node->first_child;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;

    return node;
}

char* get_name(ast node)
{
    if (node != NULL)
    {
        return node->name;
    }

    return "";
}

ast* get_children(ast node)
{
    if (node == NULL)
    {
        return NULL;
    }

    ast ptr = node->first_child;
    if (ptr == NULL)
    {
        return NULL;
    }

    ast tmp = ptr;
    int nb_children = 0;
    while(ptr != NULL)
    {
        nb_children++;
        ptr = ptr->next;
    }

    ast* children = (ast*)malloc(nb_children * sizeof(ast));
    ptr = tmp;

    int i = 0;
    while(ptr != NULL)
    {
        children[i] = ptr;
        ptr = ptr->next;
        i++;
    }

    return children;
}


void print_ast_aux(ast tree, int depth)
{
    if (tree == NULL)
    {
        return;
    }

    int i;
    for(i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%s\n", tree->name);

    ast ptr = tree->first_child;
    while(ptr != NULL)
    {
        print_ast_aux(ptr, depth + 1);
        ptr = ptr->next;
    }
}

void print_ast(ast tree)
{
    if (tree == NULL)
    {
        return;
    }

    printf("%s\n", tree->name);

    ast ptr = tree->first_child;
    while(ptr != NULL)
    {
        print_ast_aux(ptr, 1);
        ptr = ptr->next;
    }
}


void free_ast(ast tree)
{
    if (tree == NULL)
    {
        return;
    }

    // free children
    ast ptr = tree->first_child;
    while (ptr != NULL)
    {
        ast next_ptr = ptr->next;
        free_ast(ptr);
        ptr = next_ptr;
    }

    // free self
    free(tree->name);
    free(tree);
}