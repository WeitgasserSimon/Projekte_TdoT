#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
	int value;
	struct Node* nxt;
} node;

typedef struct Header{
	node* first;
	node* last;
	int size;
} header;

node* createNode(int value){
	node* nn = malloc(sizeof(node));
	if(NULL!=nn){
		nn->value = value;
		nn->nxt = NULL;
	}
	return nn;
}

header* createHeader(){
	header* nh = malloc(sizeof(header));
	if(NULL != nh){
	nh->first=NULL;
	nh->last=NULL;
	nh->size = 0;
	}
	return nh;
}
void InsertIntoListTail(header** list,int value){
	if(*list = NULL){
		*list = createHeader();
	}
	
	node* nn = createNode(value);
	//wenn die Liste leer ist
	if(*list->cnt == 0){
		
		*list->first == nn;
		*list->last == nn;
		*list->ctn++;
		
	}
	//Wenn die Liste NICHT leer ist
	else{
		*list->last->next = nn;
		*list->last = nn;
		*list->ctn++;
	}
}
int main(int argc, char const *argv[]){
	header* list = NULL;
	InsertIntoListTail(list,5);
	return 0;
}
	
