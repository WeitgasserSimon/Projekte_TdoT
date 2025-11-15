#include <stdio.h>
#include <stdlib.h>

#define ASC   1
#define DESC -1

// Definition des Datenstrukturelements für einen Listeneintrag.
typedef struct node {
    int value;
    struct node* next;
} node_t;

// Definition des Datenstrukturelements für die Liste.
typedef struct list {
    int size;
    node_t* first;
    node_t* last;
} list_t;

list_t* createList();
node_t* createNode(int value);
void insertFront(list_t** list, int value);
void insertEnd(list_t** list, int value);
node_t* findNode(list_t* list, int value);
void deleteNode(list_t** list, int value);
void sortList(list_t* list, int order);
void printList(list_t* list);
void insertInOrder(list_t** list, int value);

int main()
{
    // Erstellen eines Zeigers auf den Anfang der Liste
    // Dieser Zeiger MUSS auf NULL gesetzt werden, um ordnungsgemäß zu funktionieren
    list_t* list = createList();

    // Einfügen von Knoten in die Liste
   
    insertFront(&list, 30);   
	insertFront(&list, 20); 
	insertFront(&list, 10); 






	insertInOrder(&list, 15);    
	printList(list);
    // Sortieren der Liste in aufsteigender und absteigender Reihenfolge
    sortList(list, ASC);    printList(list);
    sortList(list, DESC);    printList(list);

    return EXIT_SUCCESS;
}

// Eine Funktion zum Erstellen einer neuen Liste.
list_t* createList()
{
    list_t* list = malloc(sizeof(list_t));
    if (NULL == list) {
        printf("Unable to create list!\n");
        return NULL;
    }
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

// Eine Funktion zum Erstellen eines neuen Knotens.
// Die Funktion erfordert den Wert des neuen Knotens.
// Die Funktion gibt einen Zeiger auf den neuen Knoten zurück.
node_t* createNode(int value)
{
    node_t* node = malloc(sizeof(node_t));
    if (NULL == node) {
        printf("Unable to create node %d!\n", value);
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

// Eine Funktion zum Einfügen eines neuen Knotens am Anfang der Liste.
// Die Funktion erfordert den Zeiger auf die Liste und den Wert des neuen Knotens.
void insertFront(list_t** list, int value)
{
    printf("Trying to insert node \"%d\" at the front. ", value);
    node_t* newNode = createNode(value);
    if (NULL == newNode) {
        printf("Unable to insert node %d!\n", value);
        return;
    }
    // Füge den neuen Knoten am Anfang der Liste ein
    newNode->next = (*list)->first;
    (*list)->first = newNode;
    if ((*list)->last == NULL) {
        (*list)->last = newNode;
    }
    (*list)->size++;
    printf("Node \"%d\" inserted.\n", value);
}

// Eine Funktion zum Einfügen eines neuen Knotens am Ende der Liste.
// Die Funktion erfordert den Zeiger auf die Liste und den Wert des neuen Knotens.
void insertEnd(list_t** list, int value)
{
    printf("Trying to insert node \"%d\" at the end. ", value);
    node_t* newNode = createNode(value);
    if (NULL == newNode) {
        printf("Unable to insert node %d!\n", value);
        return;
    }
    // Die Liste enthält keine Knoten
    // Der neue Knoten wird der neue Kopf und der neue Schwanz
    if ((*list)->size == 0)
    {
        (*list)->first = newNode;
        (*list)->last = newNode;
        (*list)->size++;
    }
    // Die Liste enthält Knoten
    // Der neue Knoten wird der neue Schwanz
    else
    {
        (*list)->last->next = newNode;
        (*list)->last = newNode;
        (*list)->size++;
    }
    printf("Node \"%d\" inserted.\n", value);
}

// Eine Funktion zum Suchen eines Knotens in der Liste.
// Die Funktion erfordert den Zeiger auf die Liste und den Wert des neuen Knotens.
// Die Funktion gibt den Zeiger auf diesen Knoten zurück.
node_t* findNode(list_t* list, int value)
{
    node_t* current = list->first;
    printf("Trying to find node \"%d\". ", value);
    while (current != NULL && current->value != value)
    {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node \"%d\" not found.\n", value);
    } else {
        printf("Node \"%d\" found.\n", value);
    }

    return current;
}

// Eine Funktion, die einen Knoten in der Liste löscht.
// Die Funktion erfordert den Zeiger auf die Liste und den Wert des zu entfernenden Knotens.
void deleteNode(list_t** list, int value)
{
    node_t* previous = NULL;
    node_t* current = (*list)->first;

    // Durchlaufe die Liste, bis das Ende erreicht ist oder der gesuchte Wert gefunden ist
    printf("Trying to delete node \"%d\". ", value);
    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    // Der Knoten ist nicht in der Liste
    if (current == NULL)
    {
        printf("Node \"%d\" not found. Cannot delete node \"%d\".\n", value, value);
        return;
    }

    // Der Knoten ist der erste Knoten in der Liste
    if ((*list)->first == current)
    {
        (*list)->first = current->next;
    }
    // Der Knoten ist der letzte Knoten in der Liste
    else if ((*list)->last == current)
    {
        (*list)->last = previous;
        previous->next = NULL;
    }
    else {
        previous->next = current->next;
    }

    (*list)->size--;
    free(current);
    printf("Node \"%d\" found. Node \"%d\" deleted.\n", value, value);
    return;
}

// Eine Funktion zum Sortieren der Liste
// Die Funktion erfordert den Zeiger auf die Liste und die Sortierreihenfolge.
// Verwenden Sie ASC für aufsteigende Reihenfolge und DESC für absteigende Reihenfolge
void sortList(list_t* list, int order)
{
    printf("Trying to sort the list in %s order.\n", order == ASC ? "ascending" : "descending");
    if (list->size == 0) {
        printf("List is empty. Unable to sort list.\n");
        return;
    }
    node_t* current = list->first;
    node_t* final = NULL;
    int value;
    while (current->next != final)
    {
        while (current->next != final)
        {
            if (current->value > current->next->value * order) {
                value = current->value;
                current->value = current->next->value;
                current->next->value = value;
            }
            current = current->next;
        }
        final = current;
        current = list->first;
    }
}

// Eine Funktion zum Drucken der einfach verketteten Liste.
// Die Funktion erfordert den Zeiger auf die Liste und die Reihenfolge.
void printList(list_t* list)
{
    printf("List (%i): ", list->size);
    node_t* current = list->first;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("\n");
}
void insertInOrder(list_t** list, int value) {
    printf("Trying to insert node \"%d\" in order. ", value);
    node_t* newNode = createNode(value);
    if (NULL == newNode) {
        printf("Unable to insert node %d!\n", value);
        return;
    }

    // Die Liste enthält keine Knoten oder der einzufügende Wert ist kleiner als der Kopf der Liste
    if ((*list)->size == 0 || value < (*list)->first->value) {
        newNode->next = (*list)->first;
        (*list)->first = newNode;

        // Falls die Liste leer war, ist der eingefügte Knoten auch der letzte Knoten
        if ((*list)->size == 0) {
            (*list)->last = newNode;
        }

        (*list)->size++;
        printf("Node \"%d\" inserted.\n", value);
        return;
    }

    // Durchlaufe die Liste, um die richtige Position für den neuen Knoten zu finden
    node_t* current = (*list)->first;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    // Füge den neuen Knoten an der richtigen Stelle ein
    newNode->next = current->next;
    current->next = newNode;

    // Falls der eingefügte Knoten der letzte Knoten ist, aktualisiere das Listenende
    if (newNode->next == NULL) {
        (*list)->last = newNode;
    }

    (*list)->size++;
    printf("Node \"%d\" inserted.\n", value);
}
