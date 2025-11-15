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
void printList(list_t* list);

int main() {
    list_t* list = createList();
    insertHead(&list, 5);
    insertHead(&list, 9);
    insertHead(&list, 11);
    printList(list);

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

void insertHead(list_t** list, int value) {
    node_t* nn = createNode(value);
    if (NULL == nn) {
        printf("Allocation of NEW NODE failed!");
        exit(EXIT_FAILURE);
    }
    nn->next = (*list)->head;
    (*list)->head = nn;
    if ((*list)->tail == NULL) {
        (*list)->tail = nn;
    }
    (*list)->size++;
}

void printList(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value_n);
        current = current->next;
    }
    printf("NULL\n");
}

