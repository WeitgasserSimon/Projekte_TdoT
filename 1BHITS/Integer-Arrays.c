/**
 	\brief	Visualisierung von Integer-Arrays
 	\author	Weitgasser Simon
 	\date  2023-03-15
 	*/
 	#include <stdio.h>
 	#include <stdlib.h>
 	
 	//Größe des Integer-Arrays festlegen
 	#define N 5
 	
 	int main(){
 		/*
 		Ein Array ist eine Menge an indizierten Werten;
		  die man über Name und Index ansprechen kann.
		  Beispiel:
		  Zahlen[] = { 1, 3, 5, 7, 9 }
		  Buchstaben[] ={'z', 'y', 'x'}
		  Der Index entspricht der Position des Elements.
		  Zahlen[1] würde 3 liefern
		  Buchstaben[2] würde x liefern
		*/
		//Deklaration eines Integer-Arrays
		int zahlen1[5];
		//Deklaration eines Integer-Arrays mit zuvor festgelegter Größe
		int zahlen2[N];
		//Deklaration und Initialisierung eines Integer-Arrays
		int zahlen3[] = { 1, 3, 5, 7, 9 };
		//Deklaration und Initialisierung eines Integer-Arrays
		int zahlen4[N] = { 1 };
		
		int i;
		for(i = 0; i < N; i++){
			printf("%i ", zahlen4[i]);
		}
 		printf("\n");
 		return EXIT_SUCCESS;
	 }
