#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur zur Speicherung von Personendaten
struct Person {
    char vorname[50];
    char nachname[50];
    char geburtsdatum[11]; // Format: YYYY-MM-DD
};

int main() {
    FILE *datei;
    struct Person person;
    char weitere_person[3]; // Für die Benutzereingabe (ja/nein)
    
    // Eine leere Liste zum Speichern der Personen erstellen
    struct Person *personenliste = NULL;
    int anzahl_personen = 0;
    
    // Schleife zum Hinzufügen von Personen
    do {
        // Benutzer nach Vorname, Nachname und Geburtsdatum fragen
        printf("Vorname: ");
        scanf("%s", person.vorname);
        printf("Nachname: ");
        scanf("%s", person.nachname);
        printf("Geburtsdatum (YYYY-MM-DD): ");
        scanf("%s", person.geburtsdatum);
        
        // Die Person zur Liste hinzufügen
        anzahl_personen++;
        personenliste = realloc(personenliste, anzahl_personen * sizeof(struct Person));
        if (personenliste == NULL) {
            printf("Speicher konnte nicht allokiert werden.\n");
            return 1;
        }
        personenliste[anzahl_personen - 1] = person;
        
        // Benutzer fragen, ob eine weitere Person hinzugefügt werden soll
        printf("Moechten Sie eine weitere Person hinzufuegen? (ja/nein): ");
        scanf("%s", weitere_person);
    } while (strcmp(wei tere_person, "ja") == 0);
    
    // Die eingegebenen Personen in die Datei "personen.txt" schreiben
    datei = fopen("personen.txt", "w");
    if (datei == NULL) {
        printf("Die Datei konnte nicht geoeffnet werden.\n");
        return 1;
    }
    int i;
    for ( i = 0; i < anzahl_personen; i++) {
        fprintf(datei, "Vorname: %s, Nachname: %s, Geburtsdatum: %s\n", personenliste[i].vorname, personenliste[i].nachname, personenliste[i].geburtsdatum);
    }
    
    fclose(datei);
    free(personenliste);
    
    printf("Die Personen wurden in die Datei 'personen.txt' geschrieben.\n");
    
    return 0;
}

