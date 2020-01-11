#include "../include/ast.h"


ast new_node(ast_type type) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = type;
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_int(int val) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_INT_VAL;
    new_node->int_val = val;
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_double(double val) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_DOUBLE_VAL;
    new_node->double_val = val;
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}

ast new_id(char* id) {
    ast new_node = (ast)malloc(sizeof(struct node));
    new_node->type = AST_ID;
    new_node->id = id; /// NEEDS TO BE FREED, COMES FROM STRDUP
    new_node->first_child = NULL;
    new_node->next = NULL;

    return new_node;
}


// ast add_child(ast node, ast_type type)
// {
//     ast new_node = (ast)malloc(sizeof(struct node));
//     new_node->type = type;
//     new_node->first_child = NULL;
//     new_node->next = NULL;

//     if (node == NULL)
//     {
//         return new_node;
//     }

//     if (node->first_child == NULL)
//     {
//         node->first_child = new_node;
//         return node;
//     }

//     ast ptr = node->first_child;
//     while(ptr->next != NULL)
//     {
//         ptr = ptr->next;
//     }

//     ptr->next = new_node;

//     return node;
// }

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
        printf("\t");
    }
    // printf("%s\n", tree->name);
    print_node(tree);

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

    // printf("%s\n", tree->name);
    print_node(tree);

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
    if (tree->type == AST_ID)
        free(tree->id);
    free(tree);
}


ast add_child_node(node* n, node* child)
{
    if (n == NULL)
    {
        return child;
    }

    if (n->first_child == NULL)
    {
        n->first_child = child;
        return n;
    }

    ast ptr = n->first_child;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = child;

    return n;
}

ast add_brother_node(node* n, node* brother) {
    if (n == NULL)
    {
        return brother;
    }

    if (n->next == NULL) {
        n->next = brother;
        return n;
    }

    ast ptr = n->next;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = brother;

    return n;
}

void print_node (ast node) {

    if (node == NULL)
        return;

    switch (node->type) {
        case AST_ID:
            printf("ID (%s)\n", node->id);
            break;  
        case AST_INT:
            printf("TYPE INT\n");
            break;
        case AST_DOUBLE:
            printf("TYPE DOUBLE\n");
            break;
        case AST_INT_VAL:
            printf("INT (%d)\n", node->int_val);
            break;
        case AST_DOUBLE_VAL:
            printf("DOUBLE (%f)\n", node->double_val);
            break;
        case AST_ADD:
            printf("+\n");
            break;
        case AST_MUL:
            printf("*\n");
            break;
        case AST_DIV:
            printf("/\n");
            break;
        case AST_MINUS:
            printf("BINARY -\n");
            break;
        case AST_UMINUS:
            printf("UNARY -\n");
            break;
        case AST_ASSIGN:
            printf("ASSIGN\n");
            break;
        case AST_WHILE:
            printf("WHILE\n");
            break;
        case AST_IF:
            printf("IF\n");
            break;
        case AST_ELSE:
            printf("ELSE\n");
            break;
        case AST_MAIN:
            printf("MAIN\n");
            break;
        case AST_INC:
            printf("++\n");
            break;
        case AST_DEC:
            printf("--\n");
            break;
        case AST_RETURN:
            printf("RETURN\n");
            break;
        case AST_FOR:
            printf("FOR\n");
            break;
        case AST_AND_OP:
            printf("&&\n");
            break;
        case AST_OR_OP:
            printf("||\n");
            break;
        case AST_STAT:
            printf("STATEMENT\n");
            break;
        default:
            printf("UNDEFINED %d\n", node->type);
            break;
    }
}