#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"

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
		} else {
			printf("Commande inconnue. Essayez EXIT, INSERT ou SELECT.\n");
		}
	}
}

