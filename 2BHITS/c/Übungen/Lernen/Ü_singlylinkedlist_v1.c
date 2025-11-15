#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int* value_n;
    struct node* next;
} node_t;

node_t* createNode(int value);
void insertHead(node_t** head, int value);
void printList(node_t* head);

int main() {
    struct node *n1, *n2, *n3;
    struct node* head = NULL;

    insertHead(&head, 3);
    insertHead(&head, 4);
    insertHead(&head, 5);

    printList(head);
    
    freelist(head);

    return 0;
}

node_t* createNode(int value) {
    node_t* node = malloc(sizeof(node_t));
    if (NULL == node) {
        printf("Allocation did not work!");
        return NULL;
    }
    node->value_n = malloc(sizeof(int));
    *(node->value_n) = value;
    node->next = NULL;
    return node;
}

void insertHead(node_t** head, int value) {
    node_t* nn = createNode(value);
    nn->next = *head;
    *head = nn;
}

void printList(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%d -> ", *(current->value_n));
        current = current->next;
    }
    printf("NULL\n");
}
void freeList(node_t* head) {
    while (head != NULL) {
        node_t* temp = head;
        head = head->next;
        free(temp->value_n);
        free(temp);
    }
