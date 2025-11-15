#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 4

void mergeArrays(int a[], int n, int b[], int m, int c[]);

int main() {
    int a[N] = { 1 , 2, 6 , 7, 8};
    int b[M] = {3 , 5 , 5 , 10};
    int c[N+M];
    mergeArrays(a, N, b, M ,c);
    int i;
    for (i = 0; i < N+M; i++){
        printf("%i ",c[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}


void mergeArrays(int a[], int n, int b[], int m, int c[]){
	int i, j, k;
	for(k = 0; k < n+m; k++){
		if (a[i] <= b[j]){
			c[k] = a[i];
			i++;
		}else {
			c[k] = b[j];
			j++;
		}
	}
}
