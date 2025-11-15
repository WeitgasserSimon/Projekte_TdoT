#include <stdio.h>
#include <stdlib.h>

// Definition des Datenstrukturelements für einen Listeneintrag
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Definition des Datenstrukturelements für die Liste
typedef struct {
    Node* head;
} LinkedList;

// Funktion zum Erstellen eines neuen Knotens
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Funktion zum Erstellen einer leeren Liste
LinkedList* createList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    if (newList == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newList->head = NULL;
    return newList;
}

// Funktion zum Einfügen eines neuen Knotens am Anfang der Liste
void insertFirst(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
}

// Funktion zum Einfügen eines neuen Knotens am Ende der Liste
void insertLast(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Funktion zum Löschen eines Knotens mit einem bestimmten Wert
void deleteNode(LinkedList* list, int value) {
    if (list->head == NULL) {
        fprintf(stderr, "List is empty. Cannot delete.\n");
        return;
    }

    if (list->head->value == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        fprintf(stderr, "Value not found in the list. Cannot delete.\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Funktion zum Anzeigen aller Elemente in der Liste
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Funktion zum Freigeben des Speichers der Liste
void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    LinkedList* myList = createList();

    insertFirst(myList, 3);
    insertFirst(myList, 2);
    insertFirst(myList, 1);

    printf("Original list:\n");
    printList(myList);

    deleteNode(myList, 2);

    printf("\nList after deleting node with value 2:\n");
    printList(myList);

    insertLast(myList, 4);

    printf("\nList after inserting node with value 4 at the end:\n");
    printList(myList);

    freeList(myList);

    return 0;
}
