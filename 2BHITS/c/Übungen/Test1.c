#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    // Benutzer nach der Größe des Arrays fragen
    printf("Geben Sie die Größe des Arrays ein: ");
    scanf("%d", &size);

    // Dynamischen Speicher für das Array allozieren
    int *dynamicArray = (int *)malloc(size * sizeof(int));

    // Überprüfen, ob die Speicherallokation erfolgreich war
    if (dynamicArray == NULL) {
        fprintf(stderr, "Speicher konnte nicht alloziert werden.\n");
        return 1;  // Fehlercode
    }

    // Zählvariable außerhalb der for-Schleife deklarieren
    int i;

    // Benutzer nach den Array-Elementen fragen und diese speichern
    printf("Geben Sie die %d Array-Elemente ein:\n", size);
    for (i = 0; i < size; ++i)
        scanf("%d", dynamicArray + i);

    // Array-Elemente anzeigen
    printf("Array-Elemente: ");
    for (i = 0; i < size; ++i)
        printf("%d ", *(dynamicArray + i));
    printf("\n");

    // Dynamisch allozierten Speicher freigeben
    free(dynamicArray);

    return 0;
}

