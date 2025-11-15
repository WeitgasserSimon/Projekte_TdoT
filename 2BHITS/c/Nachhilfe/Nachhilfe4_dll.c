#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[50];
    struct node* next;
    struct node* prev;
} node;

typedef struct list {
    node* head;
    node* tail;
    int count;
} list;

void InsertIntoListOrdered(list** list,char* data){
    if(NULL == *list){
        *list = createList();
    }
    //Existiert die Liste?
    if(NULL != *list){
        node* nn = createNode(data);
        //Wenn Liste leer ist
        if((*list)->head == NULL){
            (*list)->head = nn;
            (*list)->tail = nn;
            (*list)->count++;
        }else{//Wenn nicht leer
            node* current = (*list)->head;
            while(current->next != NULL){
                // wollen wissen ob data kleiner als string ist
                //Rückgabe von strcmp:
                //0, wenn beide gleich
                //<0, wenn der erste kleiner ist
                //>0, wenn der erste größe ist
                if(strcmp(current->data, string) > 0){
                    break;
                }
                current = current->next;
            }          
        }
        // wenn das neue das erste wird
        if(current == (*list)->first){
            (*list)->first = nn;
        }
        // wenn das neue das letzte wird
        if(current == NULL){
            (*list)->last->next = nn;
            nn->prev = (*list)->last;
            (*list)->last = nn;
            (*list)->count++;
        }
        nn->next = current;
        nn->prev = current->prev;
        nn->prev->next = nn;
        current->prev = nn;
        (*list)->count++;
    }   
}

int main(){
    list* l = NULL;
    InsertIntoListOrdered(&l,"Hallo");


}