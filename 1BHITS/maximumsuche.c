#include <stdio.h>

int getIndexOfMaximum(unsigned char IPv4Data[], int len, unsigned char maximum) {
    int i;
    for(i = 0; i < len; i++) {
        if(maximum == IPv4Data[i]) {
            return i;
        }
    }
    return -1; // -1 zurückgeben, wenn Maximum nicht gefunden wird
}

unsigned char getMaximum(unsigned char IPv4Data[], int len) {
    int i;
    unsigned char maximum = IPv4Data[0];
    for(i = 1; i < len; i++) {
        if(maximum < IPv4Data[i]) {
            maximum = IPv4Data[i];
        }
    }
    return maximum;
}

unsigned char getSumofIPv4Data(unsigned char IPv4Data[], int len) {
    int i;
    unsigned char sum = 0;
    for(i = 0; i < len; i++) {
        sum += IPv4Data[i];
    }
    return sum;
}

int main() {
    unsigned char IPv4Data[] = {0x12, 0x56, 0x7C, 0x0A};
    int len = sizeof(IPv4Data) / sizeof(unsigned char);
    
    unsigned char maximum = getMaximum(IPv4Data, len);
    int index = getIndexOfMaximum(IPv4Data, len, maximum);

    if(index != -1) {
        printf("Index des Maximums: %d\n", index);
    } else {
        printf("Maximum nicht gefunden\n");
    }
    printf("Maximum in Hex: 0x%X\n", maximum);
    unsigned char sum = getSumofIPv4Data(IPv4Data, len);
    printf("Summe der IPv4-Daten: %\n", sum);

    return 0;
}
