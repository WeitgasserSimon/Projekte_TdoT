#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD 0

typedef struct node {
    int value_n;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct list {
    int size;
    node_t* first;
    node_t* last;
} list_t;

list_t* createList();
node_t* createNode(int value_n);

void insertFirst(list_t* list, int value_n);
void insertAfter(list_t* list, int* search, int* value_n);
void insertLast(list_t* list, int value_n);

node_t* findNode(list_t* list, int value_n);
void deleteNode(list_t* list, int value_n);

void printList(list_t* list, int direction);

int main() {
    list_t* myList = createList();
    insertFirst(myList, 8);
    insertFirst(myList, 9);
    insertFirst(myList, 10);
    
    // Beispiel: Einfügen von 12 nach 10
    int searchValue = 10;
    int newValue = 12;
    insertAfter(myList, &searchValue, &newValue);

    printf("Original list:\n");
    printList(myList, FORWARD);

    // Beispiel: Löschen des Knotens mit dem Wert 9
    deleteNode(myList, 9);

    printf("\nListe nach dem Löschen des Knotens mit dem Wert 9:\n");
    printList(myList, FORWARD);

    return 0;
}

list_t* createList() {
    list_t* list = malloc(sizeof(list_t));
    if (list == NULL) {
        printf("Allocation for LIST failed!");
        exit(EXIT_FAILURE);
    }
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

node_t* createNode(int value_n) {
    node_t* node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Allocation for NODE failed!");
        exit(EXIT_FAILURE);
    }
    node->next = NULL;
    node->prev = NULL;
    node->value_n = value_n;

    return node;
}

void insertFirst(list_t* list, int value_n) {
    node_t* nn = createNode(value_n);

    if (list->first == NULL) {
        list->first = nn;
        list->last = nn;
        nn->next = NULL;
        nn->prev = NULL;
    } else {
        nn->next = list->first;
        list->first->prev = nn;
        list->first = nn;
    }

    list->size++;
}

void insertAfter(list_t* list, int* search, int* value_n) {
    node_t* nn = createNode(*value_n);
    node_t* current = list->first;

    while (current != NULL) {
        if (current->value_n == *search) {
            nn->next = current->next;
            nn->prev = current;

            if (current->next != NULL) {
                current->next->prev = nn;
            } else {
                // Wenn der aktuelle Knoten der letzte in der Liste ist
                list->last = nn;
            }

            current->next = nn;
            list->size++;
            return;
        }

        current = current->next;
    }
}

void insertLast(list_t* list, int value_n) {
    node_t* nn = createNode(value_n);

    if (list->last == NULL) {
        list->first = nn;
        list->last = nn;
        nn->next = NULL;
        nn->prev = NULL;
    } else {
        nn->prev = list->last;
        list->last->next = nn;
        list->last = nn;
    }

    list->size++;
}

node_t* findNode(list_t* list, int value_n) {
    node_t* current = list->first;

    while (current != NULL) {
        if (current->value_n == value_n) {
            return current;
        }
        current = current->next;
    }

    return NULL; // Node not found
}

void deleteNode(list_t* list, int value_n) {
    if (list != NULL) {
        node_t* current = list->first;
        while (current != NULL) {
            if (current->value_n == value_n) {
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    // If the node is the first node
                    list->first = current->next;
                    if (list->first != NULL) {
                        list->first->prev = NULL;
                    }
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                } else {
                    // If the node is the last node
                    list->last = current->prev;
                    if (list->last != NULL) {
                        list->last->next = NULL;
                    }
                }
                free(current);
                list->size--;
                return;
            }
            current = current->next;
        }
    }
}

void printList(list_t* list, int direction) {
    if (list != NULL) {
        if (direction == FORWARD) {
            node_t* current = list->first;
            printf("NULL -> ");
            while (current != NULL) {
                printf("%d -> ", current->value_n);
                current = current->next;
            }
            printf("NULL\n");
        } else {
            node_t* current = list->last;
            printf("NULL <- ");
            while (current != NULL) {
                printf("%d <- ", current->value_n);
                current = current->prev;
            }
            printf("NULL\n");
        }
    }
}
