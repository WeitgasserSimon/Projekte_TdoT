#include <stdio.h>

typedef struct node{
	int value;
	struct node* nxt;
}node;

node* createNode(int value){
	node* nn=malloc(sizeof(node));
	if(NULL != nn){
		nn->value = value;
		nn->nxt = NULL;
	}
	return nn;
}

node* addToList(node* list, node* nn){ 
	//node... unser Strukt. *zeigt auf die Adresse
	// Wenn es die Liste gibt
	if(NULL != list){
		node* current = list; // Aktuelles Element ist das erste Element der Liste
		//Solange wird nicht das letzte Argument der Liste erreicht haben
		while(current->nxt != NULL){
		//Gehe zum nächsten Element in der Liste
		current = current->nxt;
	}
	current->nxt = nn;// Fügt an das bisherig letzte Element das Neue an.
	//Wenn noch nicht exsistent
	}else{
		// neuer Knoten wird das 1. Element der Liste
		list = nn;
	}
	return list;
}

void printList(node* list){
	if(NULL!=list){
		node* current = list; 
		while(NULL != current){
			printf("%d",current->value);
			current = current->nxt;
			
		}
	}
}

int main(int argc, char const *argv[]){
	node* list = NULL;
	list = addToList(list,createNode(5));
	list = addToList(list,createNode(6));
	list = addToList(list,createNode(7));	
	printList(list);
	return 0;
}
