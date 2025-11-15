/*
	\brief	Invertieren eines Integer-Arrays
	\author	Weitgasser Simon
	\date	22-03-23

Präprozessordirektive
Eingabe Parameter
Rückgabedatentyp
*/

#include <stdio.h>
#include <stdlib.h>
#define N 3

void printArray(int a[], int n){
	int i;
	for(i = 0;i<N;i++){
		printf("%i",a[i]);
	}
	printf("\n");
	
}
void invertiereArray(int a[], int n){
	
	int tmp = a[0];
	a[0] = a[2];
	a[2] = tmp;
	
}



int main(){
	int a[N] = { 1, 2, 3};
	

	printArray(a,N);
	invertiereArray(a, N);
	printArray(a,N);
	return EXIT_SUCCESS;
}
