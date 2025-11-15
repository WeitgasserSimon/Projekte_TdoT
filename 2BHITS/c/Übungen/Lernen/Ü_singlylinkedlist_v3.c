#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value_n;
    struct node* next;
} node_t;

typedef struct list {
    int size;
    node_t* head;
    node_t* tail;
} list_t;

list_t* createList();
node_t* createNode(int value);
void insertHead(list_t** list, int value);
void insertTail(list_t** list, int value);
node_t* findNode(list_t* list, int value);
void deleteNode(list_t** list, int value);
void printList(list_t* list);

int main() {
    list_t* head = createList(); // 'head' sollte hier als 'list' initialisiert werden
    insertHead(head, 5);
    insertHead(head, 6);
    insertHead(head, 7);
    printList(head);
    
    // Speicher freigeben
    // (Sie haben die Speicherfreigabe im Originalcode nicht implementiert,
    // es ist wichtig, den Speicher freizugeben, um Speicherlecks zu vermeiden)
    // Hier sollte die Funktion freeList(list) implementiert werden.
    // Zum Testzweck ist die Funktion im Beispiel jedoch auskommentiert.
    // freeList(head);

    return 0;
}

list_t* createList() {
    list_t* list = malloc(sizeof(list_t));
    if (NULL == list) {
        printf("Allocation of LIST failed!");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

node_t* createNode(int value) {
    node_t* node = malloc(sizeof(node_t));
    if (NULL == node) {
        printf("Allocation of NODE failed!");
        exit(EXIT_FAILURE);
    }
    node->value_n = value;
    node->next = NULL;

    return node;
}

void insertHead(list_t* list, int value) {
    node_t* nn = createNode(value);
    nn->next = list->head;
    list->head = nn;
    if (list->tail == NULL) {
        list->tail = nn;
    }
    list->size++;
}

void printList(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value_n);
        current = current->next;
    }
    printf("NULL\n");
}
void deleteNode(list_t** list, int value){
	
}

// Speicher freigeben
// Diese Funktion löscht die gesamte Liste und gibt den Speicher für jeden Knoten frei.
// Beachten Sie, dass Sie diese Funktion aufrufen sollten, wenn Sie den Speicher freigeben möchten.
void freeList(list_t* list) {
    while (list->head != NULL) {
        node_t* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}

