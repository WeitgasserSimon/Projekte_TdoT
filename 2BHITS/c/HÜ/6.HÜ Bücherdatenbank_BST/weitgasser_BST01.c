#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Datenstruktur für einen Knoten (root, node, leaf)
typedef struct book {
    char title[100]; 
    char author[100];
    char date[20];
    char isbn[20];
} book_t;

typedef struct treenode {
    book_t* info;
    struct treenode* left;
    struct treenode* right;
} treenode_t;

typedef struct tree {
    int element;
    treenode_t* root;
} tree_t;

// Funktionsprototypen
tree_t* createTree();
treenode_t* createTreeNode(book_t* info);
void insertTreeNode(tree_t* tree, book_t* info);
void traverseInOrder(treenode_t* treenode);
void printTree(tree_t* tree);

int main() {
    // Einen leeren Baum erzeugen
    tree_t* tree = createTree();

    // Knoten einfügen
    book_t book1 = {"Offene See", "Benjamin Myers", "17-11-1993", "123456789"};
    book_t book2 = {"Pragmaticus", "n.a.", "1-11-2023", "987654321"};
    book_t book3 = {"Nichts Neues im Westen", "Author 3", "03-01-2023", "456789123"};
    book_t book4 = {"Book 1", "Author 1", "01-01-2023", "123456789"};
    book_t book5 = {"Book 2", "Author 2", "02-01-2023", "987654321"};
    book_t book6 = {"Book 3", "Author 3", "03-01-2023", "456789123"};

    insertTreeNode(tree, &book1);
    printTree(tree);
    insertTreeNode(tree, &book2);
    printTree(tree);
    insertTreeNode(tree, &book3);
    printTree(tree);
    insertTreeNode(tree, &book4);
    printTree(tree);
    insertTreeNode(tree, &book5);
    printTree(tree);
    insertTreeNode(tree, &book6);
    printTree(tree);
    
    return EXIT_SUCCESS;
}

tree_t* createTree() {
    tree_t* tree = malloc(sizeof(tree_t));
    if (tree == NULL) {
        printf("Kein Speicherplatz vorhanden!\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    tree->element = 0;
    return tree;
}

treenode_t* createTreeNode(book_t* info) {
    treenode_t* treenode = malloc(sizeof(treenode_t));
    if (treenode == NULL) {
        printf("Kein Speicherplatz vorhanden!\n");
        exit(EXIT_FAILURE);
    }
    treenode->info = info;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}

void insertTreeNode(tree_t* tree, book_t* info) {
    treenode_t* ntn = createTreeNode(info); // lege neuen Knoten an
    if (tree->root == NULL) {            // Baum ist leer
        tree->root = ntn;             // ntn ist die neue Wurzel
    } else {
        treenode_t* tmp = tree->root;   // temporary zum Durchlaufen anlegen am Anfang (root)
        while (tmp != NULL) {   // wenn tmp ( welches im ersten Durchlauf NULL ist) nicht NULL ist sprich existiert
            int cmp_result = strcmp(info->title, tmp->info->title); // man speichert das Ergebnis des Vergleiches in einer Variable
            if (cmp_result < 0) {   // wenn der Titel des neuen Knoten "kleiner" ist als der Titel des aktuellen und...
                if (tmp->left == NULL) {    // wenn der linke frei ist 
                    tmp->left = ntn;    // ntn wird zum Linken
                    break;
                } else {
                    tmp = tmp->left;    // wenn nicht temporary wird zum linken von ihm
                }
            } else {
                if (cmp_result > 0) {   // wenn der Titel des neuen Knoten "größer" ist als der Titel des aktuellen und...
                    if (tmp->right == NULL) {   // der Rechte nicht existiert
                        tmp->right = ntn;   // wird der Neue zum Rechten
                        break;
                    } else {
                        tmp = tmp->right; // wenn es einen rechten gibt, wird tmp zum Rechten von tmp
                    }
                } else {
                     // If titles are equal, overwrite the existing node
                free(ntn);  // Free the memory of the new node
                tmp->info = info;
                break;
                    break;
                }
            }
        }
    }
}

void printTree(tree_t* tree) {
    if (tree->root == NULL) {
        printf("Tree is empty.\n");
    } else {
        // Pass root and initial space count
        printTreeHelper(tree->root, 0);
    }
}

void printTreeHelper(treenode_t* root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTreeHelper(root->right, space);

    // Print current node
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("Title: %s, Author: %s, Date: %s, ISBN: %s\n", root->info->title, root->info->author, root->info->date, root->info->isbn);

    // Process left child
    printTreeHelper(root->left, space);
}

