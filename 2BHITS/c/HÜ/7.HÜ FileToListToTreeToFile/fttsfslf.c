/**
* @brief File To List To Tree To File
* @author Jai Kumar & Martin Köck
* @date 2023-12-04
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FORWARD  1
#define BACKWARD 0
/*
#define TXTNAME "FTLTTTF.txt"
#define TXT2NAME "outputFile.txt"
*/
 
typedef struct data{
    int ID;
    int secValue;
}data_t;
 
typedef struct node {
    data_t* subPayload;
    struct node* next;
    struct node* prev;
}node_t;
 
typedef struct list {
    int size;
    node_t* head;
    node_t* tail;
}list_t;
 
typedef struct treenode {
    data_t* subPayload;
    struct treenode* left;
    struct treenode* right;
} treenode_t;
 
typedef struct tree {
    int element;
    treenode_t* root;
} tree_t;
 
//Funktionsprototypen
tree_t* createTree();
list_t* createList();
treenode_t* createTreeNode(int ID, int secValue);
node_t* createNode(int ID, int currSecValue);
 
void insertTail(list_t** list, int currID, int currSecValue);
void listToTree(list_t** list, tree_t** tree);
void saveTreeToFile(tree_t* tree, FILE* file);
void traverseInOrder(treenode_t* treenode);
void fileWriteInOrder(treenode_t* treenode, FILE* file);
 
void printTree(tree_t* tree);
void printList(list_t* list, int direction);
 
int getID(FILE* file);
int getSecValue(FILE* file);
 
int main (int argc, char* argv[]) {
	char* TXTNAME = malloc(20*sizeof(char));
	char* TXT2NAME = malloc(20*sizeof(char));
	strcpy(TXTNAME, "FTLTTTF.txt");
	strcpy(TXT2NAME, "outputFile.txt");
	if (argc == 3) {
		TXTNAME = realloc(TXTNAME, strlen(argv[1]) * sizeof(char));
		TXT2NAME = realloc(TXT2NAME, strlen(argv[2]) * sizeof(char));
		strcpy(TXTNAME, argv[1]);
		strcpy(TXT2NAME, argv[2]);
	}
	printf("Source file: %s\n", TXTNAME);
	printf("Destination file: %s\n", TXT2NAME);
    // AKT 1: FILE TO LIST
    //öffnen der Datei
    FILE* file = fopen(TXTNAME, "r");
    if (file == NULL) {
        printf("Datei nicht vorhanden\n");
        return EXIT_FAILURE;
    }
    // Speicher allokieren
    tree_t* tree = createTree();
    list_t* list = createList();
    int currID = 0;
    int currSecValue = 0;
    // Daten von TXT in DDL hinten einfügen
    while(feof(file) == 0){
        currID = getID(file);
        currSecValue = getSecValue(file);
        insertTail(&list, currID, currSecValue);
    }
    printList(list, FORWARD);
 
    // AKT 2: LIST TO TREE
    listToTree(&list, &tree);
    printTree(tree);
    fclose(file);
    // AKT 3: TREE TO LIST
    file = fopen(TXT2NAME, "w");
    saveTreeToFile(tree, file);
    return EXIT_SUCCESS;
}
 
 
void insertTail(list_t** list, int currID, int currSecValue){
    // The list does not exist
    if (*list == NULL)
    {
        *list = createList();
        if (*list == NULL)
        {
            printf("Could not create list!");
            return;
        }
    }
    // Create a new node
    node_t* newNode = createNode(currID, currSecValue);
    if (newNode == NULL){
        printf("Could not create node!");
        return;
    }
    // The list is not empty
    if ((*list)->head != NULL){
        (*list)->tail->next = newNode;
        newNode->prev = (*list)->tail;
        (*list)->tail = newNode;
    } else {
        (*list)->head = newNode;
        (*list)->tail = newNode;
    }
    (*list)->size++;
}
 
void listToTree(list_t** list, tree_t** tree){
    node_t* ListCurrent = (*list)->head;
    while(ListCurrent != NULL){
            treenode_t* treenode = createTreeNode(ListCurrent->subPayload->ID, ListCurrent->subPayload->secValue);
            if(NULL == treenode){
                printf("Could not insert treenode with ID: %i \n", ListCurrent->subPayload->ID);
                return;
            }
            if((*tree)->root == NULL){
                (*tree)->root = treenode;
            }else{
                treenode_t* TreeCurrent = (*tree)->root;
                while (1) {
                    if(ListCurrent->subPayload->ID <= TreeCurrent->subPayload->ID){
                        if(TreeCurrent->left == NULL){
                            TreeCurrent->left = treenode;
                            break;
                        } else {
                            TreeCurrent = TreeCurrent->left;
                        }
                    } else {
                        if(TreeCurrent->right == NULL){
                            TreeCurrent->right = treenode;
                            break;
                        } else {
                            TreeCurrent = TreeCurrent->right;
                        }
                    }
                }
            }
            (*tree)->element++;
        ListCurrent = ListCurrent->next;
    }
}
 
void traverseInOrder(treenode_t* treenode){
    if(treenode != NULL){
        traverseInOrder(treenode->left);
        printf("%i,%i; ", treenode->subPayload->ID, treenode->subPayload->secValue);
        traverseInOrder(treenode->right);
    }
}
 
// AUSGEBEN DER DATENTYPEN
 
void printList(list_t* list, int direction) // 0
{
    if (list != NULL)
    {
        if (direction == BACKWARD)
        {
            node_t* current = list->tail;
            printf("NULL <- ");
            while (current != NULL)
            {
                printf("%d;%d", current->subPayload->ID, current->subPayload->secValue);
                if (current->prev != NULL) {
                    printf(" <-> ");
                }
                current = current->prev;
            }
            printf(" -> NULL\n");
        } else {
            node_t* current = list->head;  
            printf("NULL <- ");
            while (current != NULL)
            {
                printf("%d;%d", current->subPayload->ID, current->subPayload->secValue);
                if (current->next != NULL)
                {
                    printf(" <-> ");
                }
                current = current->next;
            }
            printf(" -> NULL\n");
        }
    }
}
 
void printTree(tree_t* tree) {
    printf("Ausgabe des Baums mit %i Elementen:\n", tree->element);
    traverseInOrder(tree->root);
    printf("\n");
}
 
void saveTreeToFile(tree_t* tree, FILE* file){
    fileWriteInOrder(tree->root, file);
    printf("\n");
}
void fileWriteInOrder(treenode_t* treenode, FILE* file) {
    if(treenode != NULL){
        fileWriteInOrder(treenode->left, file);
        fprintf(file, "%i,%i;", treenode->subPayload->ID, treenode->subPayload->secValue);
        fileWriteInOrder(treenode->right, file);
    }
}
// ERSTELLEN DER DATENTYPEN
tree_t* createTree(){
    tree_t* tree = malloc(sizeof(tree_t));
    if(NULL == tree){
        printf("Could not create tree!\n");
        exit(EXIT_FAILURE);
    }
    tree->element = 0;
    tree->root = NULL;
    return tree;
}
list_t* createList() {
    list_t* liste = malloc(sizeof(list_t));
    if (NULL == liste) {
        printf("Liste konnte nicht erstellt werden.\n");
        return NULL;
    }
    liste->size = 0;
    liste->head = NULL;
    liste->tail = NULL;
    return liste;
}
 
treenode_t* createTreeNode(int ID, int secValue){
    treenode_t* treenode = malloc(sizeof(treenode_t));
    if(NULL == treenode){
        printf("Could not create Treenode with ID");
    }
    treenode->subPayload = malloc(sizeof(data_t));
    if(NULL == treenode->subPayload){
        printf("Could not create Space for Treenode with ID");
    }
    treenode->subPayload->ID = ID;
    treenode->subPayload->secValue = secValue;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}
 
node_t* createNode(int ID, int currSecValue){
    node_t* node = malloc(sizeof(node_t));
    node->subPayload = malloc(sizeof(data_t));
    if(NULL == node) {
        printf("malloc fehlt for node %d", ID);
        return NULL;
    }
    node->subPayload->ID = ID;
    node->subPayload->secValue = currSecValue;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
 
int getID(FILE* file) {
    char* ID = malloc(2* sizeof(char));
    if(NULL == ID){
        printf("failed to get ID");
    }
    ID[0] = '\0';
    ID[1] = '\0';
    char c;
    int i = 0;
    while ((c = getc(file)) != EOF) {
        if (c == ',') {
            break;
        } else {
            ID[i] = c;
        }
        i++;
    }
    int result = atoi(ID);
    return result;
}
 
// 5,500;13,700;2,330
 
int getSecValue(FILE* file){
    char* secValue = malloc(6* sizeof(char));
    if(NULL == secValue){
        printf("failed to get secValue");
    }
    int i;
    for(i = 0; i < 6; i++){
        secValue[i] = '\0';
    }
    char c;
    i = 0;
    while (((c = getc(file)) != EOF)) {
 
        if (c == ';') {
            break;
        } else {
            secValue[i++] = c;
        }
    }
    secValue[i] = '\0';
    int result  = atoi(secValue);
    return result;
}