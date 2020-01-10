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
#define TYPE_INT	0
#define TYPE_FLOAT	1
#define TYPE_DOUBLE	2

// Taille maximale du nom de la variable 
#define MAX_NAME_SIZE	100

/**
 * @brief Structure table des symboles 
 * Si le symbole est une cste, on écrit la valeur sinon c'est le nom
 */
typedef struct st
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

	// taille du tableau (par défaut 1)
	int size;

} symbol, *symbolTable;

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
symbol create_symbol_int(symbolTable st, char* name, int value, bool is_constant);

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
symbol create_symbol_double(symbolTable st, char* name, double value, bool is_constant);

//TODO Faire lookup 


#endif