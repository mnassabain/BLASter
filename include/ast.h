#ifndef __AST_H__
#define __AST_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_NAME 100

typedef struct node
{
    char* name;
    struct node* first_child;
    struct node* next;
} node, *ast;


ast create_ast();

ast add_child(node* node, char* name);

char* get_name(node* node);

ast* get_children(node * node);

void print_ast(ast tree);

void free_ast(ast tree);


#endif