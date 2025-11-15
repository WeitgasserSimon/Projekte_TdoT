#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value_n;
    struct node* prev;
    struct node* next;
} node_t;

typedef struct list {
    int size;
    node_t* first;
    node_t* last;
} list_t;

list_t* createList();
node_t* createNode(list_t* list, int value);
void insertFirst(list_t* list, int value);
void insertLast(list_t* list, int value);
void findNode(list_t* list, int value);
void deleteNode(list_t* list, int value_n);
void printList(list_t* list);


int main() {
    list_t* myList = createList();
    insertFirst(myList, 4);
    insertFirst(myList, 5);
    insertFirst(myList, 6);

    printList(myList);
    
    return 0;
}

list_t* createList() {
    list_t* liste = malloc(sizeof(list_t));
    if (liste == NULL) {
        printf("Allocation of LIST failed!");
        exit(EXIT_FAILURE);
    }
    liste->size = 0;
    liste->first = NULL;
    liste->last = NULL;

    return liste;
}

node_t* createNode(list_t* list, int value) {
    node_t* node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Allocation of NODE failed!");
        exit(EXIT_FAILURE);
    }
    node->value_n = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertFirst(list_t* list, int value) {
    node_t* nn = createNode(list, value);
    if (nn == NULL) {
        printf("Allocation of NEWNODE [IF] failed!");
        return;
    }
    if (list->size == 0) {
        list->first = nn;
        list->last = nn;
        nn->prev = NULL;
        nn->next = NULL;
    } else {
        nn->next = list->first;
        nn->next->prev = nn; // Set the previous node of the current first node to nn
        list->first = nn;
    }
    list->size++;
}

void printList(list_t* list) {
    if (list->size == 0) {
        printf("NULL\n");
    } else {
        node_t* current = list->first;
        while (current != NULL) {
            if (current->prev != NULL) {
                printf("<->%d", current->value_n);
            } else {
                printf("%d", current->value_n);
            }
            current = current->next;
        }
        printf("->NULL\n");
    }
}


