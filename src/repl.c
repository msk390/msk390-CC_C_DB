#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"

Table db_table;

void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


void display_table(Table* table) {
	if (table->column_count == 0) {
		printf("Aucune table créée.\n");
		return;
	}

	// Affiche les en-têtes de colonnes
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

	// Affiche les données des lignes
	for (int r = 0; r < table->row_count; r++) {
		printf("|");
		for (int c = 0; c < table->column_count; c++) {
			printf(" %-13s |", table->rows[r].data[c]);
		}
		printf("\n");
	}
	printf("+");
	for (int i = 0; i < table->column_count; i++) {
		printf("---------------+");
	}
	printf("\n");
}


void start_repl() {
	char command[256];  // Buffer pour lire les commandes
	  // Arbre binaire initialisé à NULL

	printf("Bienvenue dans Class DB !\n");
	printf("Commandes disponibles :\n");
	printf("  - CREATE TABLE\n");
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
		} else if (strcmp(command, "INSERT") == 0) {
			if (db_table.column_count == 0) {
			printf("Erreur : aucune table n'a été créée. Utilisez CREATE TABLE d'abord.\n");
			continue;
		}

			char values[MAX_COLUMNS][50];
			printf("Entrez les valeurs pour les %d colonnes : /n", db_table.column_count);
			for (int i = 0; i < db_table.column_count; i++) {
				printf("%s : ", db_table.column_names[i]);
				if (fgets(values[i], sizeof(values[i]), stdin) == NULL) {
					printf("Erreur lors de la lecture de la valeur.\n");
					continue;
				}
				values[i][strcspn(values[i], "\n")] = '\0'; // Supprime le retour à la ligne
			}

			insert_row(&db_table, values);
			printf("Ligne insérée avcec succès!\n");
		} else if (strcmp(command, "SELECT") == 0) {
			if (db_table.column_count == 0) {
				printf("Erreur : aucune table n'a été créée. Utilisez CREATE TABLE d'abord.\n");
				continue;
			}

			printf("Contenu de la table :\n");
			display_table(&db_table);

		} else if (strcmp(command, "CREATE TABLE") == 0) {
			printf("Combien de colonnes voulez-vous ? (max %d) : ", MAX_COLUMNS);
			char input[10];
			int col_count;

			// Lire le nombre de colonnes avec fgets et convertir en entier
			if (fgets(input, sizeof(input), stdin) == NULL || (col_count = atoi(input)) <= 0 || col_count > MAX_COLUMNS) {
				printf("Nombre de colonnes invalide. Réessayez.\n");
				continue;
			}
			db_table.column_count = col_count;

			// Lire les noms des colonnes
			printf("Entrez les noms des colonnes (un par un) :\n");
			for (int i = 0; i < col_count; i++) {
				printf("Nom de la colonne %d : ", i + 1);
				if (fgets(db_table.column_names[i], sizeof(db_table.column_names[i]), stdin) == NULL) {
				printf("Erreur lors de la lecture du nom de la colonne.\n");
				continue;
				}
			// Supprimer le retour à la ligne laissé par fgets
			db_table.column_names[i][strcspn(db_table.column_names[i], "\n")] = '\0';
			}
			printf("Table créée avec succès !\n");
			display_table(&db_table);



		} else if (strcmp(command, "PRINT TREE") == 0) {
			if (db_table.index == NULL) {
				printf("L'arbre est vide.\n");
			} else {
				printf("Contenu de l'arbre binaire :\n");
				print_tree(db_table.index);
			}

		} else {
			printf("Commande inconnue. Essayez CREATE TABLE,  EXIT, INSERT ou SELECT.\n");
		}
	}
}

void insert_row(Table* table, char values[MAX_COLUMNS][50]) {
	if (table->row_count >= MAX_ROWS) {
		printf("Erreur : nombre maximum de lignes atteint.\n");
		return;
	}
	// Copie des valeurs dans la nouvelle ligne
	for (int i = 0; i < table->column_count; i++) {
		strncpy(table->rows[table->row_count].data[i], values[i], 50);
	}

	// Utiliser la première colonne comme clé pour l'arbre (par exemple, id)
	int key = atoi(values[0]);
	table->index = insert_node(table->index, key, table->row_count);

	table->row_count++;
	printf("Ligne insérée avec succès !\n");
}

