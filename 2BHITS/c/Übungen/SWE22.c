/**
@brief  Der Stack- oder Stapelspeicher
@author Weitgasser Simon
@date 	2023-10-09
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

// Globale Variablen für den Stack und den Stackcounter
int stack[MAX_STACK_SIZE];
int counter = 0;

// Die 5 Stack Funktionen
void push(int x);
int pop();
int peek();
int isempty();
int isfull();

int main(){
	if(!isfull()){
		push(4);
	}
	if(!isfull()){
		push(3);
	}
	if(!isfull()){
		push(2);
	}
	if(!isempty()){
		printf("%i", pop());
	}	
	
	return EXIT_SUCCESS;
}

void push(int x){
	stack[counter++] = x;
	
}
// nicht möglich, weil das fehler rurückgeben über int eigentlich der wert sein sollte
//int pop(){
//	if(!isempty()){
//		return stack[--counter];
//	}
//	
//}
int pop(){
	return stack[--counter];
}

int isempty(){
	if(counter==0){
		return 1;
	}
	else{
		return 0;
	}
}

int isfull(){
	if(counter == MAX_STACK_SIZE){
		return 1;
	}
	else{
		return 0;
	}
}
int peek(){
	
}
