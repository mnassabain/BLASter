/**
 * @file symbolsTable.h
 * @author Nicolas WENDLING
 * @brief Structure et jeu de fonctions concernant la table des symboles
 * @version 0.1
 * 
 */

#ifndef __SYMBOLS_TABLE_H__
#define __SYMBOLS_TABLE_H__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>

// Les différents types stockés dans l'AST
#define TYPE_INT		0
#define TYPE_DOUBLE		1
#define TYPE_UNKNOWN	2

// Taille maximale du nom de la variable 
#define MAX_NAME_SIZE	100

/**
 * @brief Structure d'un symbole
 * Si le symbole est une cste, on écrit la valeur sinon c'est le nom
 */
typedef struct sy
{
	// Nom de la variable	
	char name[MAX_NAME_SIZE];

	// Types int / float / doubles
	short type;

	// On gère uniquement des int, double
	union val {
		int int_value;
		double double_value;
	} value;

	// Boléen indiquant si la variable en cours est une constante
	bool isConstant; 

} symbol;

/**
 * @brief Structure de la table des symboles. On suit le nombre de symboles 
 * ajoutés pour sa restitution
 *
 */
typedef struct st
{
	// Nombre de variables
	int nb_var;

	// Nombre de scope inférieurs présents
	int nb_scope;

	// Les valeurs 
	symbol* symbol_table;

	/**
	 * Pour les variables globales 
	 * Exemple avec un int déclaré avant un for 
	 */
	struct st* higher_scope;

	/**
	 * Pour affichage de la table des symboles en entier
	 * Tableau des tables des symboles de sous-scope.
	 */
	struct st** lower_scope;
	

} *symbolTable;

/**
 * @brief Crée une table des symboles vierges
 * 
 * @return symbolTable 
 */
symbolTable create_symbolt(void);

/**
 * @brief Libère la table des symboles st
 * 
 * @param st 
 */
void free_symbolt(symbolTable st);

/**
 * @brief Affiche la table des symboles st
 * 
 * @param st 
 */
void display_symbolt(symbolTable st);

/**
 * @brief Crée un symbol de type int e	t l'ajoute à la table des symboles st.
 * Provoque un exit si le symbol existe déjà dans st.
 * 
 * @param st 
 * @param value 
 * @param is_constant
 * @return symbol, pointeur dans la table des symboles 
 */
symbol* insert_symbol_int(symbolTable st, char* name, int value, 
						bool is_constant);

/**
 * @brief Crée un symbol de type double et l'ajoute à la table des symboles st.
 * Provoque un exit si le symbol existe déjà dans st.
 * 
 * @param st 
 * @param name 
 * @param value 
 * @param is_constant 
 * @return symbol, pointeur dans la table des symboles
 */
symbol* insert_symbol_double(symbolTable st, char* name, double value, 
							bool is_constant);

//TODO Faire lookup qui regarde également dans la table des symboles des parents

/**
 * @brief retourne le symbole s'il est trouvé dans la table. S'il n'est pas
 * trouvé return NULL.
 * 
 * @param name nom de l'id à chercher 
 * @return symbol 
 */
symbol* lookup(symbolTable st, char* name);

/*
 * Remarque : lookup inutile dans le cas des cste, on ne va pas les appeler dans 
 * la suite du programme
 */

/**
 * @brief Ajoute un scope supérieur (st_higher) à st_lower. Référencement de 
 * st_lower dans le tableau de sous scope de st_higher.
 * 
 * @param st_higher 
 * @param st_lower 
 */
void add_higher_scope(symbolTable st_higer, symbolTable st_lower);

#endif