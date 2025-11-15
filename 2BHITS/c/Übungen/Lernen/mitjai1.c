#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Definition einer Datenstruktur für einen Knoten
struct node {
    int data;           // Der Inhalt des Knotens
    struct node* next;  // Der Zeiger auf den naechsten Knoten
};
 
// Definition eines Datentypes für Knoten
typedef struct node node_t;
// Definition einer >Datenstruktur für die Liste
struct list{
    int size;
    node_t* first;
    node_t* last;
};
// Definition eines Datentypes für Knoten
typedef struct list list_t;
//Prototypen für Listenfunktionen
list_t* createList();
node_t* createNode(int value);
void insertHead(list_t** list, int value);
node_t* findNode(list_t* list, int value);
void deleteNode(list_t** list, int value);
void printList(list_t* list);
void insertTail(list_t** list, int value);
 
int main(){
    // Definition des Zeigers auf die Liste
    list_t* list = createList();
    // Konkrete Umsetztung
    insertHead(&list, 5);
 
    insertHead(&list, 9);
    insertHead(&list, 11);
    printList(list);
    node_t* found = findNode(list, 9);
    if(found != NULL){
    printf("%d wurde gefunden\n", found->data);
    } else {
        printf("Der Wert wurde nicht gefunden");
    }
    deleteNode(&list, 9);
    printList(list);
    insertTail(&list, 6);
    printList(list);
 
    return EXIT_SUCCESS;
}
 
list_t* createList() {
    list_t* list = malloc(sizeof(list_t));
    if(NULL == list){
        printf("Unable to create list");
        return NULL;    
    }
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}
 
node_t* createNode(int value) {
    node_t* node = malloc(sizeof(node_t));
    if(NULL == node) {
        printf("malloc fehlt for node %d", value);
            return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}
void insertHead(list_t** list, int value) {
    // Einen neuen Knoten für das Einfügen am Anfang erzeugen
    node_t* newNode = createNode(value);
    if(NULL == newNode) {
        printf("Unable to insert node %i\n", value);
    }
    newNode->next = (*list)->first;
    (*list)->first = newNode;
    if((*list)->last == NULL){
        (*list)->last = newNode;
    }
    (*list)->size++;
}
void deleteNode(list_t** list, int value) {
    node_t* previous  = NULL;
    node_t* current = (*list)->first;
    // Loeschen des ersten Knotens
    if ((current != NULL) && (current->data == value)){
        (*list)->first = current->next;
        free(current);
        return;
    }
    //Zu loeschenden Knoten suchen
    while ((current != NULL) && (current->data != value)){
        previous = current;
        current = current->next;
    }
    // Der Knoten nicht gefunden
    if(current == NULL){
        return;
    }
    // Den gefundenen Knoten loeschen
    previous->next = current->next;
    free(current);
}
 
void printList(list_t* list) {
    node_t* current = list->first;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
 
node_t* findNode(list_t* list, int value) {
    node_t* current = list->first;
    while(current != NULL) {
        if(current->data == value) {
            break;
        }
        current = current->next;
    }
    return current;
}
 
void insertTail(list_t** list, int value) {
    node_t* tail = createNode(value);
    if (NULL == tail) {
        printf("Unable to insert node %i\n", value);
        return;
    }
 
    if ((*list)->first == NULL) {
        (*list)->first = tail;
        (*list)->last = tail;
    } else {
        (*list)->last->next = tail;
        (*list)->last = tail;
    }
 
    (*list)->size++;
}
 
