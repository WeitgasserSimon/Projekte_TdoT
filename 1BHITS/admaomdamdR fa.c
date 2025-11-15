#include <stdio.h>
#include <stdlib.h>

void dtob(int dezimal) {
    int binary[32];
    int i = 0;

    while (dezimal > 0) {
        binary[i] = dezimal % 2;
        dezimal = dezimal / 2;
        i++;
    }

    printf("Binäre Darstellung: ");
    int j;
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int dezimal = 14;
    dtob(dezimal);

    return 0;
}

