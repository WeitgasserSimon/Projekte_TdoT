#include <stdio.h>

// Funktion zur Verschiebung einer Scheibe von Pfosten 'a' nach Pfosten 'b'
void turmeVonHanoi(int n, char a, char b, char c) {
    if (n == 1) {
        printf("Bewege Scheibe 1 von Pfosten %c nach Pfosten %c\n", a, c);
        return;
    }
    turmeVonHanoi(n - 1, a, c, b); // Verschiebe (n-1) Scheiben von 'A' nach 'C' mit 'B' als Hilfspfosten
    printf("Bewege Scheibe %d von Pfosten %c nach Pfosten %c\n", n, a, c);
    turmeVonHanoi(n - 1, b, a, c); // Verschiebe (n-1) Scheiben von 'B' nach 'C' mit 'A' als Hilfspfosten
}

int main() {
    int n = 3; // Anzahl der Scheiben
    turmeVonHanoi(n, 'A', 'B', 'C'); // Die Pfosten werden A, B und C genannt
    return 0;
}

