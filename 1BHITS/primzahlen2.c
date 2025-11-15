#include <stdio.h>
int Zahl;

 

int main () {

 

    int i, merker;
    merker = 0;
    printf("Geben Sie Ihre Zahl ein: ");
    int rest;
    scanf("%d", &Zahl);
    for (i=2;i<Zahl;i++) {
        rest = Zahl%i;
        if (rest == 0) {
            //Zahl ist teilbar
            //daher sicher keine Primzahl
            printf("Die Zahl ist durch %d teilbar", i);
            merker = 1;
            break;
        }
    }
    if (merker == 1) {
        printf("Die Zahl ist keine Primzahl");
    }
    else {
        printf("Die Zahl ist eine Primzahl");
        return 0;
    }
}
