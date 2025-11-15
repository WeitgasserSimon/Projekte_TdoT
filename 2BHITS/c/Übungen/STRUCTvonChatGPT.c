#include <stdio.h>
#include <string.h>

// Definition einer Struktur für eine Person
struct Person {
    char vorname[50];
    char nachname[50];
    int alter;
};

int main() {
    // Deklaration und Initialisierung einer Instanz der Struktur "Person"
    struct Person benutzer1;
    
    // Hinzufügen von Daten zur Instanz
    strcpy(benutzer1.vorname, "Max");
    strcpy(benutzer1.nachname, "Mustermann");
    benutzer1.alter = 30;

    // Ausgabe der Daten aus der Struktur
    printf("Daten der ersten Person:\n");
    printf("Vorname: %s\n", benutzer1.vorname);
    printf("Nachname: %s\n", benutzer1.nachname);
    printf("Alter: %d\n", benutzer1.alter);

    // Deklaration einer weiteren Instanz der Struktur "Person"
    struct Person benutzer2;
    
    // Hinzufügen von Daten zur zweiten Instanz
    strcpy(benutzer2.vorname, "Anna");
    strcpy(benutzer2.nachname, "Musterfrau");
    benutzer2.alter = 25;

    // Ausgabe der Daten aus der zweiten Struktur
    printf("\nDaten der zweiten Person:\n");
    printf("Vorname: %s\n", benutzer2.vorname);
    printf("Nachname: %s\n", benutzer2.nachname);
    printf("Alter: %d\n", benutzer2.alter);

    // Verwendung eines Arrays von Strukturen
    struct Person personen[3]; // Ein Array von 3 Personen erstellen

    // Hinzufügen von Daten zu den einzelnen Personen im Array
    strcpy(personen[0].vorname, "John");
    strcpy(personen[0].nachname, "Doe");
    personen[0].alter = 40;

    strcpy(personen[1].vorname, "Jane");
    strcpy(personen[1].nachname, "Smith");
    personen[1].alter = 35;

    strcpy(personen[2].vorname, "Bob");
    strcpy(personen[2].nachname, "Johnson");
    personen[2].alter = 45;

    // Ausgabe der Daten aus dem Array von Strukturen
    int i;
    printf("\nDaten aus dem Array von Strukturen:\n");
    for ( i = 0; i < 3; i++) {
        printf("Person %d:\n", i + 1);
        printf("Vorname: %s\n", personen[i].vorname);
        printf("Nachname: %s\n", personen[i].nachname);
        printf("Alter: %d\n", personen[i].alter);
    }

    return 0;
}

