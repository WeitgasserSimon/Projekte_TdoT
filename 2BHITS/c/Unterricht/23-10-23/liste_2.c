#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;

struct list{
    int size;
    node_t* first;
    node_t* last;
};

typedef struct list list_t;

list_t* createList();
node_t* createNode(int value);
void insertHead(list_t** list, int value);
void insertTail(list_t** list, int value);
node_t* findNode(list_t* list, int value);
void deleteNode(list_t** list, int value);
void printList(list_t* list);

int main(){
    list_t* list = createList();
    insertHead(&list, 5);
    insertHead(&list, 9);
    insertHead(&list, 11);
    printList(list);
    node_t* found = findNode(list, 9);
    if(found != NULL){
        printf("%d wurde gefunden.\n",found->data);
    } else{
        printf("8 wurde nicht gefunden.\n");
    }
    deleteNode(&list, 9);
    printList(list);
    
    return EXIT_SUCCESS;
}

void insertTail(list_t** list, int value){
    // Implement the function
}

list_t* createList(){
    list_t* list = malloc(sizeof(list_t));
    if(NULL == list){
        printf("malloc failed for list!");
        return NULL;
    }
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
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

void insertHead(list_t** list, int value){
    node_t* newNode = createNode(value);
    if(NULL==newNode){
        printf("malloc failed for node %d!", value);
    }
    newNode->next = (*list)->first; // den neuen knoten an den head dran hängen
    (*list)->first = newNode;		// der liste sagen dass es einen neuen head gibt
    if((*list)->last == NULL){		//wenn es das erste element ist, dann sag der liste das der neue auch das letzte ist
        (*list)->last = newNode;
    }
    (*list)->size++;				//Gib der Liste mit das sie einen neuen hat.
}

node_t* findNode(list_t* list, int value){
    node_t* current = list->first;
    while(current != NULL){
        if(current->data == value){
            break;
        }
        current = current->next;
    }

    return current;
}

void deleteNode(list_t** list, int value){
    node_t* previous = NULL;
    node_t* current = (*list)->first;

    while((current != NULL) && (current->data != value)){
        previous = current;
        current = current->next;
    }

    if(current == NULL){
        return;
    }

    if(previous == NULL){
        (*list)->first = current->next;
    } else {
        previous->next = current->next;
    }

    if(current == (*list)->last){
        (*list)->last = previous;
    }

    free(current);
    (*list)->size--;
}

void printList(list_t* list){
    node_t* current = list->first;
    while(NULL != current){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
