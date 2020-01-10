#include "../include/symbolsTable.h"

// Creation st 
symbolTable create_symbolt(void)
{
	symbolTable st = calloc(1, sizeof(struct st));

	if (st == NULL)
	{
		perror("create_symbolt: ");
		exit(EXIT_FAILURE);
	}

	// Initialisation 
	st->nb_var = 0;
	// Au départ, table des symboles vide 
	st->symbol_table = NULL;

	// Pour l'instant on n'ajoute pas de scope de niveau supérieur
	st->higher_scope = NULL;

	return st;
}

// Libère l'espace mémoire alloué pour la table des symboles 
void free_symbolt(symbolTable st)
{
	if (st->symbol_table != NULL)
	{
		free(st->symbol_table);
	}
	
	// Si il y a scope plus élevé 
	if (st->higher_scope != NULL)
	{
		printf("free_symbolt: Attention table des symboles de scope supérieur"
				" détecté\n");
	}
	st->higher_scope = NULL;

	free(st);
}

// Affichage de la table des symboles 
// ? Doit-on afficher ts les scopes 
void display_symbolt(symbolTable st)
{
	if (st != NULL)
	{
		// for (int i = 0; i < count; i++)
		// {
			/* code */
		// }
		
	}
}

symbol* insert_symbol_int(symbolTable st, char* name, int value, 
						bool is_constant)
{
	
}

symbol* insert_symbol_double(symbolTable st, char* name, double value, 
							bool is_constant)
{

}

symbol* lookup(char* name)
{	

}