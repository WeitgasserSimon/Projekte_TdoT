//Single Linked List
//Knoten sind die Elemente der Liste
//Kanten sind die Zeiger (Verbindungen) zwischen den Knoten
//Spezielle Kante: am Anfang heißt Head, am Ende heißt Tail



#include <stdio.h>
#include <stdlib.h>



//Definition einer Datenstruktur
struct node {
    int data;           //Inhalt des Knotens
    struct node* next;  //Zeiger auf den nächsten Knoten
};

//Definition eines Datentyps für Knoten
typedef struct node node_t;

//Prototypen für Listenfunktionen
node_t* createNode(int value);
void insertHead(node_t** head, int value);
node_t* findNode(node_t* head, int value);
void deleteNode(node_t** head, int value);
void printList(node_t* head);
int main(){
    //Definition des Zeigers auf die Liste
    node_t* head = NULL;
    //Idee für den Umgang mit einer Liste
    //node_t node = createNode(5, head);
    //head = insertHead(node, head);
    //printList(head);

    //Konkrete Umsetzung
    insertHead(&head, 5);
    insertHead(&head, 9);
    insertHead(&head, 11);
    printList(head);
    node_t* found = findNode(head, 8);
    if(found != NULL){
        printf("%d wurde gefunden.\n",found->data);
    } else{
        printf("8 wurde nicht gefunden.\n");
    }
    deleteNode(&head, 9);
    printList(head);
    
    return EXIT_SUCCESS;
}

node_t* createNode(int value){
    node_t* node = malloc(sizeof(node_t));
    if(NULL == node){
        printf("malloc failed for node %d!", value);
        return NULL;
    } 
    node->data = value;
    node->next = NULL;
    return node;
} 

void insertHead(node_t** head, int value){
    //Einen neuen Knoten, für das Einfügen am Anfang, erzeugen
    node_t* newHead = createNode(value);
    newHead->next = *head;//*head ist die Adresse von head
    *head = newHead;
}
node_t* findNode(node_t* head, int value){
    node_t* current = head;
    while(current != NULL){
        if(current->data == value){
            break;
        }
        current = current->next;
    }

    return current;
}

void deleteNode(node_t** head, int value){
    node_t* previous = NULL;
    node_t* current = *head;

    //Löschen des ERSTEN Knotens
    if((current != NULL) && (current->data == value)){
        *head = current->next;
        free(current);
        return;
    }

    while((current != NULL) && (current->data != value)){
        previous = current;
        current = current->next;
    }

    // Der Knoten wurde nicht gefunden
    if(current == NULL){
        return;
    }

    // Den gefundenen Knoten löschen
    previous->next = current->next;
    free(current);
}
void printList(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}









/*int main(){
    int summe;
    summe = addiere(2, 3);

    addiere(2, 3, &summe);
}

//Pass by value
int addiere(int a, int b){
    return a + b;
}
//Pass by reference
addiere(int a, int b, int* summe){

}*/
