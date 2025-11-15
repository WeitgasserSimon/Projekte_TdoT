#include <stdio.h>

int main() {
    unsigned char Table_17[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int dezimal;
    int rest;
    int i = 0;
    unsigned char output[100];

    while (1) {
        printf("Bitte geben Sie Ihre dezimale Zahl ein (q zum Beenden):\n");
        if (scanf("%d", &dezimal) != 1) {
            char input[2];
            scanf("%1s", input);
            if (input[0] == 'q' || input[0] == 'Q') {
                printf("Programm abgebrochen!\n");
                break;
            } else {
                printf("Ungültige Eingabe. Bitte geben Sie eine Dezimalzahl ein oder q zum Beenden.\n");
            }
            continue;
        }

        while (dezimal != 0) {
            rest = dezimal % 17;
            output[i] = Table_17[rest];
            dezimal = dezimal / 17;
            i++;
        }

        printf("\nDas Ergebnis in der Basis 17 ist: ");
        int j;
        for (j = i - 1; j >= 0; j--) {
            printf("%c", output[j]);
        }
        printf("\n");
        i = 0;  // Setze den Index zurück
    }

    return 0;
}

