#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

// Fonction pour créer un nouveau nœud
Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erreur : allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Fonction pour insérer un nœud dans l'arbre
void insert_node(Node** root, int key) {
    if (*root == NULL) {
        *root = create_node(key);
    } else if (key < (*root)->key) {
        insert_node(&(*root)->left, key);
    } else {
        insert_node(&(*root)->right, key);
    }
}

// Fonction pour afficher l'arbre en ordre croissant
void print_tree(Node* root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d\n", root->key);
        print_tree(root->right);
    }
}
