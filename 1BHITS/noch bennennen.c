/**
* \brief Das Programm ermittelt eine Liste von Primzahlen bis zur Zahl n.
	\author Simon Weitgasser
	\date  2023-03-01
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "primzahlen.h"

int main(){
	// Funktionstests
	// Diese Tests überprüfen ob die Funktionen 
	//istPrim und primzahlListe richtig programmiert sind
	if(istPrim(2) == ){
		printf("Test 1 bestanden!");
	}
	else{
		printf("Test 1 NICHT bestanden! ");
	}
		if(istPrim(4) == 1){
		printf("Test 2 bestanden!");
	}
	else{
		printf("Test 2 NICHT bestanden! ");
	}
	return EXIT_SUCCESS;
}

