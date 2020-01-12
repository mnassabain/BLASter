#ifndef __AST_H__
#define __AST_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_NAME 100

typedef enum ast_type { AST_ID, AST_INT, AST_DOUBLE, AST_INT_VAL, AST_DOUBLE_VAL, AST_ADD, AST_MUL, AST_DIV, AST_MINUS, AST_UMINUS, AST_ASSIGN, AST_WHILE, AST_IF, AST_MAIN, AST_INC, AST_DEC, AST_RETURN, AST_FOR, AST_AND_OP, AST_OR_OP, AST_GEQ_OP, AST_LEQ_OP, AST_GT_OP, AST_LT_OP, AST_EQ_OP, AST_NEQ_OP,AST_STAT, AST_TABLE, AST_DIM, AST_ARRAY, AST_PRINTF, AST_LIST, AST_FUNC, AST_VOID, AST_CALL } ast_type;

typedef enum list_type {LIST_COND, LIST_STAT, LIST_INIT, LIST_UPDATE, LIST_FUNC, LIST_ARG} list_type;
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
        list_type list_type;
    };
    struct {
        struct node* first_child;
        struct node* next;
        struct node* prev;
        struct node* parent;
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
 * @brief Crée un noeud de type list qui est une liste de list_type
 * 
 * @param list_type le type de liste à créer
 * @return ast noeud créé
 */
ast new_list(list_type list_type);

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
 * @param n1 noeud à échanger  
 * @param n2 noeud à échanger
 */
void swap_nodes(node* n1, node* n2);

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
 * @param indent indentation
 */
void print_code(ast tree, int indent);

/**
 * @brief Affiche le type d'une enum list_type
 * 
 * @param list le type de liste
 */
void print_list(list_type list);

/**
 * @brief Retourne le nombre d'enfants d'un noeud
 * 
 * @param node le noeud dont on veut connaire le nombre d'enfants
 */
int count_child(ast node);

/**
 * @brief Comparer 2 ast
 * 
 * @param tree1 
 * @param tree2 
 * @return int 0 si tree1 != tree2, !=0 sinon
 */
int compare(ast tree1, ast tree2);

/**
 * @brief Fonction à appeler - remplace toutes les opérations par les appels fct
 * 
 * @param tree ast sur lequel on veut travailler 
 */
void replace(ast tree);
#endif