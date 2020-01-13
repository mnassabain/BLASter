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
	st->nb_scope = 0;
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

	free(st->lower_scope);

	free(st);
}

void display_symbolt(symbolTable st)
{
	if (st != NULL)
	{
		printf("TYPE\tVALUE\n");
		for (int i = 0; i < st->nb_var; i++)
		{
			if (!st->symbol_table[i].isConstant)
			{
				printf("%s\t", st->symbol_table[i].name);
				if (st->symbol_table[i].type == TYPE_DOUBLE)
				{
					printf("%s\n", "DOUBLE");
				}
				else if (st->symbol_table[i].type == TYPE_INT)
				{
					printf("%s\n", "INT");
				}
			}
		}
	}
}

symbol* insert_symbol_int(symbolTable st, char* name, int value, 
						bool is_constant)
{

	if (st == NULL)
	{
		fprintf(stderr, "insert_symbol: La table des symbole est vide\n");
		exit(EXIT_FAILURE);
	}

	int new_idx = st->nb_var;

	if (st->symbol_table == NULL)
	{
		// Table des symboles null, il faut l'allouer 
		st->symbol_table = calloc(1, sizeof(struct sy));

		if (st->symbol_table == NULL)
		{
			perror("insert_symbol, erreur calloc: ");
			exit(EXIT_FAILURE);
		} 	
	}
	else
	{
		// On doit realloc
		st->symbol_table = realloc(st->symbol_table, 
									(st->nb_var + 1) * sizeof(struct sy));
	}

	if (is_constant == false)
	{
		if (lookup(st, name) != NULL)
		{
			fprintf(stderr, "insert_symbol %s : illegal car symbole déjà présent dans scope\n", name);
			exit(EXIT_FAILURE);	
		}
	}

	st->symbol_table[new_idx].type = TYPE_INT;	

	st->symbol_table[new_idx].isConstant = is_constant;

	// Nom de la variable
	if (is_constant)
	{
		// Le nom de la variable est tmpxxx
		// char *tmp_name = st->symbol_table[new_idx].name;
		// strcpy(tmp_name, "tmp");
		// strcat(tmp_name, );
		// tmp_name[strlen(tmp_name)] = '\0';
		
		// Ajout de la valeur de la cste
		st->symbol_table[new_idx].value.double_value = 0;
		st->symbol_table[new_idx].value.int_value = value;
	}
	else 
	{
		// On affecte le nom de l'id à la variable 
		strcpy(st->symbol_table[new_idx].name, name);
		st->symbol_table[new_idx].name[strlen(name)] = '\0';
	}

	// On augmente de 1 le nbr de variables
	st->nb_var++;

	return &st->symbol_table[new_idx];
}	

symbol* insert_symbol_double(symbolTable st, char* name, double value, 
							bool is_constant)
{

	if (st == NULL)
	{
		fprintf(stderr, "insert_symbol: La table des symbole est vide\n");
		exit(EXIT_FAILURE);
	}

	int new_idx = st->nb_var;

	if (st->symbol_table == NULL)
	{
		// Table des symboles null, il faut l'allouer 
		st->symbol_table = calloc(1, sizeof(struct sy));

		if (st->symbol_table == NULL)
		{
			perror("insert_symbol, erreur calloc: ");
			exit(EXIT_FAILURE);
		} 	
	}
	else
	{
		// On doit realloc
		st->symbol_table = realloc(st->symbol_table, 
									(st->nb_var + 1) * sizeof(struct sy));
	}

	if (is_constant == false)
	{
		if (lookup(st, name) != NULL)
		{
			fprintf(stderr, "insert_symbol %s : illegal car symbole déjà présent dans scope\n", name);
			exit(EXIT_FAILURE);	
		}
	}

	st->symbol_table[new_idx].type = TYPE_DOUBLE;	

	st->symbol_table[new_idx].isConstant = is_constant;

	// Nom de la variable
	if (is_constant)
	{
		// Le nom de la variable est tmpxxx
		// char *tmp_name = st->symbol_table[new_idx].name;
		// strcpy(tmp_name, "tmp");
		// strcat(tmp_name, );
		// tmp_name[strlen(tmp_name)] = '\0';
		
		// Ajout de la valeur de la cste
		st->symbol_table[new_idx].value.int_value = 0;
		st->symbol_table[new_idx].value.double_value = value;
	}
	else 
	{
		// On affecte le nom de l'id à la variable 
		strcpy(st->symbol_table[new_idx].name, name);
		st->symbol_table[new_idx].name[strlen(name)] = '\0';
	}

	// On augmente de 1 le nbr de variables
	st->nb_var++;

	return &st->symbol_table[new_idx];
}

symbol* lookup(symbolTable st, char* name)
{	
	if (st == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < st->nb_var; i++)
	{
		if (!st->symbol_table[i].isConstant)
		{
			if (strcmp(st->symbol_table[i].name, name) == 0)
				return &st->symbol_table[i];
		}
	}
	return NULL;
}

void add_higher_scope(symbolTable st_higher, symbolTable st_lower)
{
	if ((st_higher == NULL) || (st_lower == NULL))
	{
		fprintf(stderr, "add_lower_scope, erreur: une des tables des symboles " 
				"est NULL\n");
		exit(EXIT_FAILURE);
	}

	if (st_higher == st_lower)
	{
		fprintf(stderr, "add_lower_scope, erreur: tables des symboles " 
				"identiques\n");
		exit(EXIT_FAILURE);
	}

	// On augmente le nombre de scope

	if(!st_higher->nb_scope)
	{
		// pas de scope avant
		st_higher->lower_scope = calloc(1, sizeof(symbolTable*));
		
		if (st_higher->lower_scope == NULL)
		{
			perror("add_higher_scope, calloc: ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// Ajout d'un nouveau scope aux autres
		st_higher->lower_scope = realloc(st_higher->lower_scope, 
							sizeof(symbolTable*) * (st_higher->nb_scope + 1));

		if (st_higher->lower_scope == NULL)
		{
			perror("add_higher_scope, realloc: ");
			exit(EXIT_FAILURE);
		}
	}

	st_higher->lower_scope[st_higher->nb_scope] = st_lower;
	st_lower->higher_scope = st_higher;
	
	st_higher->nb_scope++;
}