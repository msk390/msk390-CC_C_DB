#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"

Table db_table;

void display_table(Table* table) {
	if (table->column_count == 0) {
		printf("Aucune table créée.\n");
		return;
	}

	printf("+");
	for (int i = 0; i < table->column_count; i++) {
		printf("---------------+");
	}
	printf("\n|");
	for (int i = 0; i < table->column_count; i++) {
		printf(" %-13s |", table->column_names[i]);
	}
	printf("\n+");
	for (int i = 0; i < table->column_count; i++) {
		printf("---------------+");
	}
	printf("\n");
}

void start_repl() {
	char command[256];  // Buffer pour lire les commandes
	Node* root = NULL;  // Arbre binaire initialisé à NULL

	printf("Bienvenue dans Class DB !\n");
	printf("Commandes disponibles :\n");
	printf("  - INSERT <valeur>\n");
	printf("  - SELECT\n");
	printf("  - EXIT\n\n");

	while (1) {
		printf("db> ");  // Affiche le prompt
		if (fgets(command, sizeof(command), stdin) == NULL) {
		break;  // Quitte si EOF est atteint
		}

		// Supprime le saut de ligne à la fin
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "EXIT") == 0) {
			printf("Au revoir !\n");
			break;
		} else if (strncmp(command, "INSERT ", 7) == 0) {
			int key = atoi(command + 7);  // Récupère la valeur après "INSERT "
			insert_node(&root, key);
			printf("Valeur %d insérée dans la base de données.\n", key);
		} else if (strcmp(command, "SELECT") == 0) {
			printf("Contenu de la base de données :\n");
			print_tree(root);
		} else if (strcmp(command, "CREATE TABLE") == 0) {
			printf("Combien de colonnes voulez-vous ? (max %d) : ", MAX_COLUMNS);
			int col_count;
			if (scanf("%d", &col_count) != 1 || col_count <= 0 || col_count > MAX_COLUMNS) {
				printf("Nombre de colonnes invalide. Réessayez.\n");
				continue;
			}
			db_table.column_count = col_count;

			printf("Entrez les noms des colonnes (un par un) :\n");
			for (int i = 0; i < col_count; i++) {
				printf("Nom de la colonne %d : ", i + 1);
				scanf("%s", db_table.column_names[i]);
			}
			printf("Table créée avec succès !\n");
			display_table(&db_table);
		} else {
			printf("Commande inconnue. Essayez CREATE TABLE,  EXIT, INSERT ou SELECT.\n");
		}
	}
}

