#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int zufallszahl;
    clock_t start, end;
    int RandomArray[3];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        do {
            zufallszahl = rand() % 45 + 1;
            
            for (j = 0; j < i; j++) {
                if (RandomArray[j] == zufallszahl) {
                    break;
                }
            }
        } while (j < i); 

        RandomArray[i] = zufallszahl;
        printf("%d\n", RandomArray[i]);
    }

    return 0;
}

