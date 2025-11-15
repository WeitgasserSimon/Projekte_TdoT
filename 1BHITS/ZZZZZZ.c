#include <stdio.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(char binary[]) {
    int dezimal = 0;
    int length = strlen(binary);
    int i;
    for (i = length - 1; i >= 0; i--) {
        int bit = binary[i] - '0'; // Konvertiert das Zeichen '0' oder '1' in den entsprechenden numerischen Wert 0 oder 1
        int power = 1;
        int j;
        for (j = 0; j < length - i - 1; j++) {
            power *= 2;
        }
        dezimal += bit * power;
    }

    return dezimal;
}

void DecimalToBinary(int dezimal) {
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
    char binary[] = "1011";
    int dezimal = binaryToDecimal(binary);
    printf("Dezimale Darstellung: %d\n", dezimal);
    
    DecimalToBinary(10);

    return 0;
}

