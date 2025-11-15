/**
@brief  
@author Weitgasser Simon
@date 	2023-10-02
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 32

void add(){
	struct person p;
	printf("Bitte Vorname eingeben:");
}
void display(){
}
struct person{
	char vorname[MAXLEN];
	char nachname[MAXLEN];
	char datum[MAXLEN];	
}person;
int main() {
    printf("Please select\n");
    printf("[1] Display all watched movies\n");
    printf("[2] Add a watched movie\n");
    printf("ESC Exit movie database\n");
    printf("\nEnter your choice: ");
    char select;

    do {
        select = getch(); // Auf Tasteneingabe warten

        switch (select) {
            case '1':
                display(); // Anzeigefunktion aufrufen, wenn '1' ausgewählt wurde
                break;
            case '2':
                add(); // Hinzufügen-Funktion aufrufen, wenn '2' ausgewählt wurde
                break;
        }
    } while (select != 27); // Endlosschleife, bis ESC (27) gedrückt wird

    return 0; // Programm erfolgreich beenden
}

