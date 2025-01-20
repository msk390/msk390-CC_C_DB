## **Description du projet**
**Class DB** est une base de données simple en ligne de commande, développée en **langage C**, avec la gestion des commandes de type SQL suivantes :
- `CREATE TABLE` : Permet de créer une table avec un nombre maximum de colonnes et leurs noms.
- `INSERT` : Ajoute des données à la table ligne par ligne, colonne par colonne.
- `SELECT` : Affiche le contenu complet de la table.
- `PRINT TREE` : Affiche les données indexées dans un arbre binaire selon une clé. // pas encore mis en place
- `EXIT` : Ferme le programme.

Ce projet est conçu pour apprendre et appliquer les concepts fondamentaux :
1. La gestion des structures de données en C (tableaux, arbres binaires).
2. La manipulation d'une interface en ligne de commande interactive (REPL).
3. L'organisation d'un projet avec une architecture modulaire.

---

## **Caractéristiques principales**
1. **Création de table dynamique :**
   - Le programme demande à l'utilisateur de définir le nombre de colonnes (jusqu'à 5) et leurs noms.
   - Les tables peuvent contenir jusqu'à 100 lignes.

2. **Gestion des données avec un arbre binaire :** // pas encore mis en place
   - Les données sont indexées dans un arbre binaire à l'aide de la première colonne comme clé.
   - L'arbre binaire facilite les recherches et l'affichage trié.

3. **Interface interactive :**
   - Les commandes sont tapées directement dans le terminal.
   - Des messages clairs guident l'utilisateur à chaque étape.

---

## **Prérequis**
- Un compilateur compatible **C99** (ex. GCC).
- Une distribution Linux (testée sous Debian).
- **Make** installé pour automatiser la compilation.

---

## **Structure du projet**
- `src/` : Contient les fichiers source du projet.
  - `main.c` : Point d'entrée principal.
  - `btree.c` et `btree.h` : Gestion des structures d'arbre binaire.
  - `repl.c` et `repl.h` : Interface REPL et logique SQL.
- `Makefile` : Automatisation de la compilation.
- `README.md` : Documentation du projet.

1. **Compiler le projet** :
   ```bash
   make
   ```

2. **Exécuter le programme** :
   ```bash
   ./class_db
   ```

3. **Nettoyer les fichiers compilés** (optionnel) :
   ```bash
   make clean
   ```

---

## **Utilisation**
Lancez le programme et utilisez les commandes suivantes :

### Commandes disponibles :
- `CREATE TABLE` : Créez une table.
  - Exemple :
    ```
    CREATE TABLE
    Combien de colonnes voulez-vous ? (max 5) : 2
    Nom de la colonne 1 : id
    Nom de la colonne 2 : name
    Table créée avec succès !
    ```
- `INSERT` : Ajoutez une ligne dans la table.
  - Exemple :
    ```
    INSERT
    Entrez les valeurs pour les 2 colonnes :
    id : 1
    name : Alice
    Ligne insérée avec succès !
    ```
- `SELECT` : Affichez la table.
  - Exemple :
    ```
    SELECT
    Contenu de la table :
    +---------------+---------------+
    | id            | name          |
    +---------------+---------------+
    | 1             | Alice         |
    +---------------+---------------+
    ```

- `PRINT TREE` : Affichez l'arbre binaire.
  - Exemple :
    ```
    PRINT TREE
    Clé : 1, Ligne : 0 // pas encore mis en place
    ```

- `EXIT` : Quittez le programme.

---

## **Exemples d'améliorations possibles**
1. Ajout d'une persistance des données (enregistrement dans un fichier).
2. Recherche avancée dans la table avec des filtres (type SQL `WHERE`).
3. Suppression de données avec mise à jour de l'arbre binaire.

---

## **Contributeurs**
- [OUAZIL Mimoun]
