#include <stdio.h>
#include <stdlib.h>
#define N 20
int main(){
	int Daten[N]={20,30,23,43,6534,12,32,54,8881,25,18,23,16,18,19,24,20,16,16,12};
	int i;
	int m;
	int minimum;
	int SortedDaten[N];
	
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
    int size = sizeof(Daten);
    printf("\n%i",size);
    int dtype=sizeof(int);
    printf("\nDatatype = %i",dtype);
    int datasize = sizeof(Daten)/sizeof(int);
    printf("Groesse des Arrays");
    
	return 0;
}
