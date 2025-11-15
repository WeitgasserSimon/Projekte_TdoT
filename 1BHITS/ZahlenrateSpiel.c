#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    int input;
    int randomValue, randvalue10;
    int i = 0;
    
    time(&t);
    srand(t);
    randomValue = rand();
    randvalue10 = (randomValue%10) +1;
    
    printf("%d",randvalue10);
    
	return 0;
	
}

