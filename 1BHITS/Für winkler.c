#include <stdio.h>
#include <stdlib.h>

 

int main (void) {
    int i;
    for (i = 0; i < 6; i++) {
        int randomValue;
        int lottoValue;
        randomValue = rand();
        lottoValue = randomValue % 49+1;
        printf("Zufallszahl = %d\n", lottoValue);
    }
    return 0;
//HÜ zuerst auswahl rechteck/dreieck/kreis berechnung fläche dann eingabe parameter 3. berechnung ausgabe fläche,4. jede Flächen berechnung in eigener funktion beschreiben
//prototypes = float calcTriangleArea(length_c, length_h); strich punkt wichtig am ende


