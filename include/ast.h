#ifndef __AST_H__
#define __AST_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_NAME 100

typedef enum ast_type { AST_ID, AST_INT, AST_DOUBLE, AST_INT_VAL, AST_DOUBLE_VAL, AST_ADD, AST_MUL, AST_DIV, AST_MINUS, AST_UMINUS, AST_ASSIGN, AST_WHILE, AST_IF, AST_ELSE, AST_MAIN, AST_INC, AST_DEC, AST_RETURN, AST_FOR, AST_AND_OP, AST_OR_OP, AST_GEQ_OP, AST_LEQ_OP, AST_GT_OP, AST_LT_OP, AST_EQ_OP, AST_NEQ_OP,AST_STAT, AST_TABLE, AST_DIM, AST_ARRAY, AST_PRINTF, AST_LIST} ast_type;

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
        char* printf;
    };
    struct {
        struct node* first_child;
        struct node* next;
    };
    
} node, *ast;

/**
 * @brief Crée un noeud avec un type passé en argument
 * 
 * @param type type du noeud qu'on veut
 * @return ast noeud créé
 */
ast new_node(ast_type type);

/**
 * @brief Crée un noeud de type int avec une valeur
 * 
 * @param val valeur du noeud (en int)
 * @return ast noeud créé
 */
ast new_int(int val);

/**
 * @brief Crée un noeud de type double avec une valeur
 * 
 * @param val valeur du noeud (double)
 * @return ast noeud créé
 */
ast new_double(double val);

/**
 * @brief Crée un noeud de type id avec l'identifiant
 * 
 * @param id identifiant du noeud (en string)
 * @return ast noeud créé
 */
ast new_id(char* id);

/**
 * @brief Crée un noeud de type printf
 * 
 * @param printf la commande entière printf
 * @return ast noeud créé
 */
ast new_printf(char* printf);

/**
 * @brief Ajoute un noeud existant (peut avoir des fils) à un noeud existant
 * comme fils
 * 
 * @param n noeud au lequel on veut rajouter un fils
 * @param child le noeud qu'on veut ajouter comme fils
 * @return ast le noeud parent (arg 1)
 */
ast add_child_node(node* n, node* child);

/**
 * @brief Ajoute un noeud existant (peut avoir des fils) à un noeud existant
 * comme frère
 * 
 * @param n noeud au lequel on veut rajouter un frère
 * @param brother le noeud qu'on veut ajouter comme frère
 * @return ast le noeud parent (arg 1)
 */
ast add_brother_node(node* n, node* brother);

/**
 * @brief Récupérer tous les fils d'un noeud
 * 
 * @param node Noeud parent
 * @return ast* Liste de fils (ne pas oublier de free(liste))
 */
ast* get_children(node * node);

/**
 * @brief Afficher un noeud
 * 
 * @param node noeud à afficher
 */
void print_node(ast node);

/**
 * @brief Afficher un AST
 * 
 * @param tree AST à afficher
 */
void print_ast(ast tree);

/**
 * @brief Effacer noeud et ses fils - fonction à utiliser
 * 
 * @param node noeud à effacer
 * @return null
 */
ast delete_node(ast node);

/**
 * @brief Effacer tous les fils d'un noeud
 * 
 * @param node noeud dont les fils on veut effacer
 * @return ast noeud passé en argument
 */
ast delete_children(ast node);

/**
 * @brief Générer un code source à partir d'un AST
 * 
 * @param tree AST à transformer en code
 */
void print_code(ast tree);

#endif