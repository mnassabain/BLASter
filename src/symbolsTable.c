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
		for (int i = 0; i < st->nb_var; i++)
		{
			if (!st->symbol_table[i].isConstant)
			{
				printf("name = %s, ", st->symbol_table[i].name);
			}
			printf("constante = %d, ", st->symbol_table[i].isConstant);

			if (st->symbol_table[i].type == TYPE_INT)
			{
				printf("type = int");
				if (st->symbol_table[i].isConstant)
				{
					printf(", value = %d", st->symbol_table[i].value.int_value);
				}
			}
			else if (st->symbol_table[i].type == TYPE_DOUBLE)
			{
				printf("type = double");
				if (st->symbol_table[i].isConstant) {
					printf(", value = %lf", 
									    st->symbol_table[i].value.double_value);
				}
			}
			else // TYPE_UNKNOWN
				printf("type inconnu");

			printf("\n");
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
		st->symbol_table = realloc(st->symbol_table, st->nb_var + 1 * sizeof(struct sy));
	}

	if (is_constant == false)
	{
		if (lookup(st, name) != NULL)
		{
			fprintf(stderr, "insert_symbol %d : illegal car symbole déjà présent dans scope", st->nb_var);
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
		st->symbol_table = realloc(st->symbol_table, st->nb_var + 1 * sizeof(struct sy));
	}

	if (is_constant == false)
	{
		if (lookup(st, name) != NULL)
		{
			fprintf(stderr, "insert_symbol %d : illegal car symbole déjà présent dans scope", st->nb_var);
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