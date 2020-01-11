#ifndef __AST_H__
#define __AST_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_NAME 100

typedef enum ast_type { AST_ID, AST_INT, AST_DOUBLE, AST_INT_VAL, AST_DOUBLE_VAL, AST_ADD, AST_MUL, AST_DIV, AST_MINUS, AST_UMINUS, AST_ASSIGN, AST_WHILE, AST_IF, AST_ELSE, AST_MAIN, AST_INC, AST_DEC, AST_RETURN, AST_FOR, AST_AND_OP, AST_OR_OP, AST_STAT} ast_type;

/* 
 * IMPORTANT: même si avec cette structure on peut ajouter des frères au
 *   noeud racine, on ne va pas le faire; nous allons nous concentrer sur les
 *   arbres
 */ 
typedef struct node
{
    ast_type type;
    union {
        int int_val;
        double double_val;
        char* id;
    };
    struct {
        struct node* first_child;
        struct node* next;
    };
    
} node, *ast;


ast new_node(ast_type type);
ast new_int(int val);
ast new_double(double val);
ast new_id(char* id);


/**
 * @brief Ajoute un noeud existant (peut avoir des fils) à un noeud existant
 * 
 * @param n noeud au lequel on veut rajouter un fils
 * @param child le noeud qu'on veut ajouter comme fils
 * @return ast le noeud parent (arg 1)
 */
ast add_child_node(node* n, node* child);

ast add_brother_node(node* n, node* brother);


/**
 * @brief Récupérer tous les fils d'un noeud
 * 
 * @param node Noeud parent
 * @return ast* Liste de fils (ne pas oublier de free(liste))
 */
ast* get_children(node * node);


/**
 * @brief Afficher un AST
 * 
 * @param tree AST à afficher
 */
void print_ast(ast tree);

void print_node(ast node);

/**
 * @brief Libérer mémoire de l'AST
 * 
 * @param tree AST à free
 */
void free_ast(ast tree);


#endif