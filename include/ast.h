#ifndef __AST_H__
#define __AST_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_NAME 100

/* 
 * IMPORTANT: même si avec cette structure on peut ajouter des frères au
 *   noeud racine, on ne va pas le faire; nous allons nous concentrer sur les
 *   arbres
 */ 
typedef struct node
{
    char* name;
    struct node* first_child;
    struct node* next;
} node, *ast;


/**
 * @brief Crée un AST vide
 * 
 * @return ast 
 */
ast create_ast();


/**
 * @brief Ajoute fils au noeud donné
 * 
 * @param node noeud au lequel on veut rajouter un fils
 * @param name nom du fils
 * @return ast noeud parent (arg 1)
 */
ast add_child(node* node, char* name);


/**
 * @brief Récupérer le nom d'un noeud
 * 
 * @param node Noeud dont on veut le nom
 * @return char* 
 */
char* get_name(node* node);


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


/**
 * @brief Libérer mémoire de l'AST
 * 
 * @param tree AST à free
 */
void free_ast(ast tree);


#endif