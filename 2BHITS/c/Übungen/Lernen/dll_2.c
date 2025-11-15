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
node_t* createNode(int value_n);
void insertFirst(list_t* list, int value_n);
void insertLast(list_t* list, int value_n);
void printList(list_t* list);
node_t* findNode(list_t* list, int value_n);
void deleteNode(list_t* list, int value_n);
void insertInBetween(list_t* list, int value_n, int target_value_n);

int main() {
    list_t* myList = createList();
    insertFirst(myList, 5);
    insertFirst(myList, 6);
    insertFirst(myList, 7);
    insertFirst(myList, 8);
    insertFirst(myList, 9);
    printList(myList);

    int targetValue = 7;
    node_t* foundNode = findNode(myList, targetValue);
    if (foundNode != NULL) {
        printf("Node with value %d found!\n", targetValue);
    } else {
        printf("Node with value %d not found.\n", targetValue);
    }

    int deleteValue = 8;
    deleteNode(myList, deleteValue);
    printf("After deleting node with value %d:\n", deleteValue);
    printList(myList);

    int insertValue = 99;
    int afterValue = 6;
    insertInBetween(myList, insertValue, afterValue);
    printf("After inserting %d after node with value %d:\n", insertValue, afterValue);
    printList(myList);

    return 0;
}

list_t* createList() {
    list_t* list = malloc(sizeof(list_t));
    if (list == NULL) {
        printf("Allocation of LIST failed!");
        return NULL;
    }
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

node_t* createNode(int value_n) {
    node_t* node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Allocation of node failed!");
        return NULL;
    }
    node->next = NULL;
    node->prev = NULL;
    node->value_n = value_n;

    return node;
}

void insertFirst(list_t* list, int value_n) {
    node_t* nn = createNode(value_n);
    if (list->size == 0) {
        list->first = nn;
        list->last = nn;
        nn->next = NULL;
        nn->prev = NULL;
    } else {
        nn->next = list->first;
        nn->prev = NULL;
        list->first->prev = nn;
        list->first = nn;
    }
    list->size++;
}

void insertLast(list_t* list, int value_n) {
    node_t* nn = createNode(value_n);
    if (list->size == 0) {
        list->first = nn;
        list->last = nn;
        nn->prev = NULL;
        nn->next = NULL;
    } else {
        nn->prev = list->last;
        list->last->next = nn;
        list->last = nn;
        nn->next = NULL;
    }
    list->size++;
}

void printList(list_t* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
    } else {
        node_t* current = list->first;
        while (current != NULL) {
            printf("%d -> ", current->value_n);
            current = current->next;
        }
        printf("NULL\n");
    }
}

node_t* findNode(list_t* list, int value_n) {
    node_t* current = list->first;
    while (current != NULL) {
        if (current->value_n == value_n) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteNode(list_t* list, int value_n) {
    node_t* current = list->first;
    while (current != NULL) {
        if (current->value_n == value_n) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // If the node is the first node
                list->first = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                // If the node is the last node
                list->last = current->prev;
            }
            free(current);
            list->size--;
            return;
        }
        current = current->next;
    }
}

void insertInBetween(list_t* list, int value_n, int target_value_n) {
    node_t* nn = createNode(value_n);
    node_t* targetNode = findNode(list, target_value_n);
    if (targetNode != NULL) {
        nn->prev = targetNode;
        nn->next = targetNode->next;
        if (targetNode->next != NULL) {
            targetNode->next->prev = nn;
        } else {
            // If the targetNode is the last node
            list->last = nn;
        }
        targetNode->next = nn;
        list->size++;
    } else {
        printf("Target node with value %d not found.\n", target_value_n);
    }
}

