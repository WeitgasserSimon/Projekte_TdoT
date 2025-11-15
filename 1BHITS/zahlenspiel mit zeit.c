#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    time_t t;
  
    time(&t);
    srand(t);
    randomValue = rand();
    randvalue10 = (randomValue%10) +1;
    time_t startSeconds;
	time_t stopSeconds;
	double difference;
	
	time(&startSeconds);
	
	do {
        printf("Geben Sie eine Zahl ein\r\n");
        scanf("%d",&input);
        i =i +1;
    } while (input != randvalue10);
	
	time(&stopSeconds);
	difference = difftime(stopSeconds,startSeconds);
	
    printf("SEHR GUT!!! SIE HABEN DIE ZAHL ERRATEN!!!\r\n");
    printf("Sie haben %.3f Sekunden und %d Versuche gebraucht!", difference,i);
    return 0;
}
