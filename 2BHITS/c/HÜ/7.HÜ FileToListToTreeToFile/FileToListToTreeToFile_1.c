// Mit lukas winkler in zusammenarbeit erstellt
// Letzten 2 Punkte nicht ganz verstanden ( vorallem den Letzten)
#include <stdio.h>
#include <stdlib.h>

// Definitionen der Datenstrukturen

typedef struct info {
    int id;
    unsigned long size;
} info_t;

typedef struct node {
    info_t data;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct list {
    node_t* first;
    node_t* last;
    int size;
} list_t;

typedef struct treenode {
    info_t data;
    struct treenode* left;
    struct treenode* right;
} treenode_t;

typedef struct tree {
    int elements;
    treenode_t* root;
} tree_t;

// Funktionsprototypen

list_t* createList();
node_t* createNode(info_t value);
void insertAtEnd(list_t** list, info_t value);
void printList(list_t* list);
void freeList(list_t* list);
void readCSVAndFillList(const char* filename, list_t** list);

tree_t* createTree();
treenode_t* createTreeNode(info_t data);
void insertTreeNode(tree_t* tree, info_t data);
void traverseInOrder(treenode_t* treenode);
void printTree(tree_t* tree);
void freeTree(treenode_t* treenode);
void freeEntireTree(tree_t* tree);

// Implementierung der Funktionen

int main() {
    const char* filename = "data.csv";
    list_t* myList = createList();
    readCSVAndFillList(filename, &myList);

    printList(myList);

    tree_t* myTree = createTree();
    node_t* current = myList->first;
    while (current != NULL) {
        insertTreeNode(myTree, current->data);
        current = current->next;
    }

    printTree(myTree);

    freeEntireTree(myTree);
    freeList(myList);

    return 0;
}

list_t* createList() {
    list_t* newList = malloc(sizeof(list_t));
    if (newList != NULL) {
        newList->size = 0;
        newList->first = NULL;
        newList->last = NULL;
    }
    return newList;
}

node_t* createNode(info_t value) {
    node_t* newNode = malloc(sizeof(node_t));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtEnd(list_t** list, info_t value) {
    if (*list == NULL) {
        *list = createList();
        if (*list == NULL) {
            printf("Could not create list!\n");
            return;
        }
    }

    node_t* newNode = createNode(value);
    if (newNode == NULL) {
        printf("Could not create node!\n");
        return;
    }

    if ((*list)->first != NULL) {
        (*list)->last->next = newNode;
        newNode->prev = (*list)->last;
        (*list)->last = newNode;
    } else {
        (*list)->first = newNode;
        (*list)->last = newNode;
    }
    (*list)->size++;
}

void printList(list_t* list) {
    node_t* current = list->first;
    while (current != NULL) {
        printf("ID: %d, SIZE: %lu\n", current->data.id, current->data.size);
        current = current->next;
    }
}

void freeList(list_t* list) {
    node_t* current = list->first;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void readCSVAndFillList(const char* filename, list_t** list) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Fehler beim Öffnen der Datei");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        info_t* data = malloc(sizeof(info_t));
        if (data == NULL) {
            perror("Fehler beim Allozieren von Speicher für data");
            exit(EXIT_FAILURE);
        }

        if (sscanf(line, "%d;%lu", &data->id, &data->size) == 2) {
            printf("Erfolgreich eingelesen: ID=%d, SIZE=%lu\n", data->id, data->size);
            insertAtEnd(list, *data);
        } else {
            fprintf(stderr, "Ungültiges Format in der CSV-Datei: %s", line);
            free(data);
        }
    }

    fclose(file);
}

tree_t* createTree() {
    tree_t* tree = malloc(sizeof(tree_t));
    if (NULL == tree) {
        printf("Could not create tree!\n");
        exit(EXIT_FAILURE);
    }
    tree->elements = 0;
    tree->root = NULL;
    return tree;
}

treenode_t* createTreeNode(info_t data) {
    treenode_t* treenode = malloc(sizeof(treenode_t));
    if (NULL == treenode) {
        printf("Could not create treenode!\n");
        return NULL;
    }
    treenode->data = data;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}

void insertTreeNode(tree_t* tree, info_t data) {
    treenode_t* treenode = createTreeNode(data);
    if (NULL == treenode) {
        printf("Could not insert treenode!\n");
        return;
    }
    if (tree->root == NULL) {
        tree->root = treenode;
    } else {
        treenode_t* current = tree->root;
        while (1) {
            if (data.id <= current->data.id) {
                if (current->left == NULL) {
                    current->left = treenode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = treenode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    tree->elements++;
}

void traverseInOrder(treenode_t* treenode) {
    if (treenode != NULL) {
        traverseInOrder(treenode->left);
        printf("%d ", treenode->data.id);
        traverseInOrder(treenode->right);
    }
}

void printTree(tree_t* tree) {
    printf("Ausgabe des Baums mit %i Elementen:\n", tree->elements);
    traverseInOrder(tree->root);
    printf("\n");
}

void freeTree(treenode_t* treenode) {
    if (treenode != NULL) {
        freeTree(treenode->left);
        freeTree(treenode->right);
        free(treenode);
    }
}

void freeEntireTree(tree_t* tree) {
    freeTree(tree->root);
    free(tree);
}
