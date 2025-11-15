#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calc_randvalue(void){
    srand(time(NULL));
    int input, rnumber;
    clock_t start, stop;
    double alltime[10];
    double averagetime;
    int bigtime=0;
    int i;

    for(i = 0; i < 10; i++){
        start = clock();
        rnumber = rand()%10;
        printf("Zahl:%d\n", rnumber);
        scanf("%d", &input);
        if(input != rnumber) {
            printf("Nicht richtig\n");
        }
        else{
            printf("Sehr gut!\n");
        }
        stop = clock();
        alltime[i] = (double) (stop - start)/((double)CLOCKS_PER_SEC);
    }

    averagetime = (alltime[0]+alltime[1]+alltime[2]+alltime[3]+alltime[4]+alltime[5]+alltime[6]+alltime[7]+alltime[8]+alltime[9])/10.0;
    printf("Durchschnittliche Zeit: %f\n", averagetime);

    for(i = 0; i < 10; i++){
        if(averagetime < alltime[i]){
            bigtime = bigtime + 1;
        }
    }
    printf("Anzahl der Zeiten, die größer als der Durchschnitt sind: %d\n", bigtime);
    double maximum = alltime[0];
    for(i=1;i<10;i++){
        if(maximum<alltime[i]){
            maximum=alltime[i];
        }
    }
    printf("Maximum: %f\n",maximum);
}	

int main (){
    calc_randvalue();
    return EXIT_SUCCESS;
}

