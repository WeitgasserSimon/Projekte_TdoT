/**
 * @file 231107.c
 * @author DI Thomas Harald Schmuck, BSc
 * @brief Förderunterricht zu Listen
 * @version 1
 * @date 2023-11-07
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Die Struktur für einen Knoten einer einfach-verketteten Liste. Beinhaltet den eigentlichen Wert und einen Pointer auf das nächste Element der Liste.
 * 
 */
typedef struct node
{
    int value;
    struct node* nxt;
} node;

/**
 * @brief Erstellt einen neuen Knoten und befüllt ihn mit dem gewünschten Wert. Der nxt-Pointer zeigt auf NULL, weil es noch kein nächstes Element gibt.
 * 
 * @param value     Der Wert, den der neue Knoten haben soll
 * @return node*    Adresse des neu erstellten Knotens
 */
node* createNode(int value) {
    node* nn = malloc(sizeof(node));
    if(NULL != nn) {
        nn->value = value;
        nn->nxt = NULL;
    }
    return nn;
}

/**
 * @brief Fügt der Liste hinten einen euen Knoten hinzu oder erstellt 
 * eine neue Liste mit dem neuen Element, wenn sie leer ist
 * 
 * @param list      das erste Element der Liste, oder NULL, wenn die Liste leer ist
 * @param nn        das neue Element, das in die Liste eingefügt werden soll
 * @return node*    das erste Element der Liste (praktisch, wenn sie vorher leer war)
 */
node* addToList(node* list, node* nn) {
    //Wenn die Liste existiert = es mindestens ein Element in der Liste gibt
    if(NULL != list) {
        //Aktuelle Element ist erstes Element der Liste
        node* current = list;
        //Solange wir nicht das letzte Element der List erreicht haben
        while(current->nxt != NULL) {
            //Gehe zum nächsten Element in der Liste
            current = current->nxt;
        }
        //Nach dieser Schleife zeigt current auf das bisherige letzte Element der Liste
        //Fügt an das bisherige letzte Element das neue Element dran
        current->nxt = nn;
    //Wenn es noch keine Liste gibt
    } else {
        //neue Knoten wird erstes Element der Liste
        list = nn;
    }
    return list;
}

/**
 * @brief Durchläuft die ganze Liste und gibt die Werte der einzelnen Knoten aus
 * 
 * @param list      das erste Element der Liste, oder NULL, wenn die Liste leer ist
 */
void printList(node* list) {
    //Wenn die Liste existiert
    if(NULL != list) {
        //Setzte das aktuelle Element auf das erste Element der Liste
        node* current = list;
        //Solange die Liste nicht vollständig durchlaufen wurde
        while(NULL != current) {
            //Gib den Wert des aktuellen Elements aus
            printf("%d ", current->value);
            //Gehe zum nächsten Element in der Liste
            current = current->nxt;
        }
    }
}

int main(int argc, char const *argv[]) //eigentlich nicht nötig
{
    node* list = NULL;

    list = addToList(list, createNode(5));
    list = addToList(list, createNode(7));
    list = addToList(list, createNode(8));
    list = addToList(list, createNode(1));
    list = addToList(list, createNode(3));
    list = addToList(list, createNode(4));

    printList(list);


    return 0;
}

