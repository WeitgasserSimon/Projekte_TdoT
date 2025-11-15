#include <stdio.h>
#include <stdlib.h>
#define N 3
int main() { 
    int m;
    int i;
    int SortedDaten[N];
    int Daten[N] = {3,2,1};
    
    for (m = 0; m < N; m++) {
        int minimum = Daten[m];
        
        for (i = m + 1; i < N; i++) {
            if (Daten[i] < minimum) {
                minimum = Daten[i];
                Daten[i] = Daten[m];
                Daten[m] = minimum;
            }
        }
        
        SortedDaten[m] = minimum;
        printf("%d ", SortedDaten[m]);
    }
    
    return 0;
}

