#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* next;
    struct node* prev;
    int value;
} node_t;

typedef struct header {
    node_t* first;
    node_t* last;
    int size;
} header_t;

header_t* createHeader();
node_t* createNode(int value);
void insertAtBeginning(int value, header_t* header);
void printList(header_t* header);
node_t* searchNode(header_t* header, int value);

int main() {
    header_t* header = createHeader();

    insertAtBeginning(9, header);
    insertAtBeginning(7, header);
    insertAtBeginning(5, header);

    node_t* foundNode = searchNode(header, 5);
    if (foundNode != NULL) {
        printf("Node found: %d\n", foundNode->value);
    }

    printList(header);

    return 0;
}

header_t* createHeader() {
    header_t* h = malloc(sizeof(header_t));
    if (NULL == h) {
        printf("Allocation of HEADER failed");
    } else {
        h->size = 0;
        h->first = NULL;
        h->last = NULL;
    }
    return h;
}

node_t* createNode(int value) {
    node_t* nn = malloc(sizeof(node_t));
    if (NULL == nn) {
        printf("Allocation of NEW NODE failed!");
    } else {
        nn->next = NULL;
        nn->prev = NULL;
        nn->value = value;
    }
    return nn;
}

void insertAtBeginning(int value, header_t* header) {
    node_t* nn = createNode(value);
    if (NULL == header->first) {
        header->first = nn;
        header->last = nn;
    } else {
        nn->next = header->first;
        header->first->prev = nn;  // Set previous of the current first node to nn
        header->first = nn;
    }
    header->size++;
}

void printList(header_t* header) {
    node_t* current = header->first;
    while (current != NULL) {
        printf("%d->", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

node_t* searchNode(header_t* header, int value) {
    node_t* current = header->first;
    if (current == NULL) {
        printf("EMPTY LIST\n");
        return NULL;
    } else {
        while (current != NULL) {
            if (current->value == value) {
                printf("Node found: %d\n", current->value);
                return current;
            }
            current = current->next;
        }
        printf("Node not found\n");
        return NULL;
    }
}
