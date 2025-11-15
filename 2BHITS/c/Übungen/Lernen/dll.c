#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int value_n;
	struct node* next;
}node_t;
typedef struct list{
	int size;
	struct node* first;
	struct node* last;
}list_t;

insertFirst();
insertLast();
findNode();
deleteNode();
//createList();
//createNode();
printList(list_t* list);


int main(){
	
}
node_t* createNode(value_n){
	node = malloc(sizeof(node_t));
	if(NULL == node){
		printf("allocation of NODE failed!");
	}
	node->value_n = value;
	node->next = NULL;
	return node;
}
list_t* createList(){
	list = malloc(sizeof(list_t));
	if(NULL == list){
		printf("allocation of LIST failed!");
	}
	list->first = NULL;
	list-last = NULL;
	list->size = 0;
}
insertFirst(){
	node_t* nn = createNode(value_n);
	nn->next = (*list)->first;
	(*list)->first = nn;
	if(list->size == 0{
		list->tail = nn;
	}
	(*list)->size++;
}
insertLast(){
	node_t* nn = createNode(value_n);
	nn->next = NULL;
	(*list)->last->next = nn;
	(*list)->last = newNode;
	(*list)->size++;
	if(list->size = 0){
		
	}
	}
}

