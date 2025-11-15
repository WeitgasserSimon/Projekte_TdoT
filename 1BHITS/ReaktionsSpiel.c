#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    char input;
    int randomValue, randvalue10;
    int i = 1;
    double fasterdifference;
    
    time(&t);
    srand(t);
    clock_t startClock = clock();
    clock_t stopClock;
    double difference;
    
    do {
        if (input != randvalue10) {
            break;
        }
        else {
            randomValue = rand();
            randvalue10 = (randomValue % 10);
        
            printf("%d\r\n", randvalue10);
            scanf("%c", &input);
            //clear input buffer
            fflush(stdin);
            randvalue10 = randvalue10 + 0x30;
        
            i = i + 1;
        }
        
    } while (i < 10);
    stopClock = clock();
    
    difference = (double)(stopClock - startClock) / CLOCKS_PER_SEC * 1000;
    
    if (i == 10) {
        printf("Du hast %.0lf ms gebraucht um %d Zahlen einzugeben\r\n", difference, i);
        
    }
    else {
        printf("Falsche Eingabe!\r\nVersuche es direkt erneut");
        return 0;
    }
    fasterdifference = 10924.6 - difference;
    
    if (difference < 10924.6) {
        printf("Du warst um %.0f ms schneller als der Ersteller dieses Spiels\r\n", fasterdifference);
    }
    
    return 0;
}






