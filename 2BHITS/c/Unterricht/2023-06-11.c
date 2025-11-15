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
void printList(node_t* head){
    node_t* current = head;
    while(current-> != NULL){
        printf("%d ->", current->data);
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