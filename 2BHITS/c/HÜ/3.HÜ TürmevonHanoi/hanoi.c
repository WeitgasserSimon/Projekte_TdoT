#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char destination);

int main() {
    int n;
    printf("Geben Sie die Anzahl der Scheiben ein: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}

void printTowers(int n, char source[], char auxiliary[], char destination[]) {
    printf("\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c\t%c\t%c\n", source[i], auxiliary[i], destination[i]);
    }
    printf("A\tB\tC\n\n");
}

void moveBlock(char from[], char to[]) {
    int i = 0;
    while (from[i] == ' ') {
        i++;
    }
    char block = from[i];
    from[i] = ' ';
    i = 0;
    while (to[i] == ' ') {
        i++;
    }
    to[i - 1] = block;
}

void hanoi(int n, char source, char auxiliary, char destination) {
    char towerA[n], towerB[n], towerC[n];
    for (int i = 0; i < n; i++) {
        towerA[i] = (i < n) ? '|' : ' ';
        towerB[i] = ' ';
        towerC[i] = ' ';
    }

    for (int i = 0; i < n; i++) {
        printf("\n");
        printf("%c\t%c\t%c\n", towerA[i], towerB[i], towerC[i]);
    }
    printf("A\tB\tC\n\n");

    if (n == 1) {
        moveBlock(towerA, towerC);
        printTowers(n, towerA, towerB, towerC);
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);

    moveBlock(towerA, towerC);
    printTowers(n, towerA, towerB, towerC);

    hanoi(n - 1, auxiliary, source, destination);
}

