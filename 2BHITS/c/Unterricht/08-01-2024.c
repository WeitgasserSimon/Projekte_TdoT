// Funktionszeiger

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int verdopple(int x){
    return 2*x;
}
int halbiere(int x){
    return x/2;
}


int main(){
    // Gebietsschema setzen(generell)
    setlocale(LC_ALL, "DE_de.UTF-8"); 
    // Den Bildschirm löschen
    printf("\33c");
    printf("ÄÖÜö\n");
    
    // Definition eines Funktionszeigers    (Funktion liegt am Stack wie variablen, deswegen geht das)
    int (*funktion)(int) = NULL;   //Rückgabe und Eingabe

    // Zuweisen einer Funktion
    funktion = &halbiere; // Auf die Adresse wo die Funktion ist die adresse von verdopple speicher
    // Ausführen einer Funktion
    printf("x/2 = %i \n",funktion(2));// funktion(2);
    

    return EXIT_SUCCESS;
}