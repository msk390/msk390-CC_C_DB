#ifndef BTREE_H
#define BTREE_H

// Définition de la structure Node
typedef struct Node {
	int key;
	struct Node* left;
	struct Node* right;
} Node;

// Déclaration des fonctions pour gérer l'arbre binaire
Node* create_node(int key);
void insert_node(Node** root, int key);
void print_tree(Node* root);

#endif
