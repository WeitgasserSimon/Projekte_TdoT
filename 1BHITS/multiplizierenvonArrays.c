#include <stdio.h>
#include <stdlib.h>

int multipliziereArrays(int a[], int b[], int n);

int main(){
	int a[] = { 1, 2, 3};
	int b[] = { 4, 5, 6};
	printf("%d",multipliziereArrays(a, b, 3));
	return EXIT_SUCCESS;
}

int multipliziereArrays(int a[], int b[], int n){
	int i, sum = 0;
	for(i = 0;i < n;i++){//Eine Schleife über alle Elemente der beiden Arrays
		sum += a[i] * b[i];//Multipliziere die Elemente und addiere sie zu sum
	} 
	return sum; //gib sum zurück
}
