#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

int main() {
    /* Pfad zur CSV-Datei */
    const char* dateiPfad = "Daten.csv";

    /* CSV-Datei öffnen */
    FILE* datei = fopen(dateiPfad, "r");
    if (!datei) {
        printf("Fehler beim Öffnen der Datei.\n");
        return 1;
    }

    /* Tabelle in der cmd ausgeben */
    char zeile[MAX_LINE_LENGTH];
    int maxSpalten = 0;
    while (fgets(zeile, MAX_LINE_LENGTH, datei) != NULL) {
        char* feld = strtok(zeile, ",");
        int spalten = 0;
        while (feld != NULL) {
            printf("%s\t", feld);
            feld = strtok(NULL, ",");
            spalten++;
        }
        if (spalten > maxSpalten) {
            maxSpalten = spalten;
        }
        printf("\n");
    }

    /* Trennlinie zwischen Header und Daten */
    int i;
    for (i = 0; i < maxSpalten; i++) {
        printf("--------\t");
    }
    printf("\n");

    /* CSV-Datei schließen */
    fclose(datei);

    return 0;
}

