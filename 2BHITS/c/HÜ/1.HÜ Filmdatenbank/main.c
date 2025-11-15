#include <stdio.h>
#include <conio.h>


// Funktion zum Anzeigen der Filmliste aus der Datei "filmliste.txt"
void display() {
    FILE *datei = fopen("filmliste.txt", "r"); // Datei zum Lesen öffnen

    if (datei != NULL) {
        int c;
        // Zeichenweise aus der Datei lesen und ausgeben
        while ((c = fgetc(datei)) != EOF) {
            putchar(c);
        }
        fclose(datei); // Datei schließen
    } else {
        printf("Datei konnte nicht geöffnet werden.\n");
    }
    printf("Displaying worked\n"); // Meldung, dass die Anzeige erfolgreich war
}

// Funktion zum Hinzufügen eines Films zur Datei "filmliste.txt"
void add() {
    FILE *datei = fopen("filmliste.txt", "a"); // Datei zum Anhängen öffnen (wird erstellt, falls nicht vorhanden)

    if (datei != NULL) {
        char filmName[100];
        char datum[20];

        // Benutzereingabe für Filmtitel
        printf("Geben Sie den Filmtitel ein: ");
        fgets(filmName, sizeof(filmName), stdin);
        
        // Benutzereingabe für Datum (YYYY-MM-DD)
        printf("Geben Sie das Datum ein (YYYY-MM-DD): ");
        fgets(datum, sizeof(datum), stdin);

        // Informationen in die Datei schreiben
        fprintf(datei, "Filmtitel: %s, Datum: %s\n", filmName, datum);

        fclose(datei); // Datei schließen
    } else {
        printf("Datei konnte nicht geöffnet werden.\n");
    }
    printf("Adding worked\n"); // Meldung, dass das Hinzufügen erfolgreich war
}

// Hauptfunktion
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

