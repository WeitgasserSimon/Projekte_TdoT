#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int zufallszahl;
    int guess;
    clock_t start, end;
    double diff;
    
    srand(time(NULL));   
    zufallszahl = rand() % 10 + 1;   
    
    start = clock();
    
    while(1){
        printf("Erraten Sie die Zahl: \r\n");
        scanf("%d",&guess);
        if(guess==zufallszahl){
            end = clock();
            diff = (double)(end - start) / CLOCKS_PER_SEC * 1000;
            printf("Sie haben die Zahl erraten! Es hat %.2f Millisekunden gedauert.\r\n", diff);
            break;
        }
        if(guess<zufallszahl){
            printf("Die Zufallszahl ist groesser\r\n\r\n");7
        }
        if(guess>zufallszahl){
            printf("Die Zufallszahl ist kleiner\r\n\r\n");
        }
    }
    
    return 0;
}
