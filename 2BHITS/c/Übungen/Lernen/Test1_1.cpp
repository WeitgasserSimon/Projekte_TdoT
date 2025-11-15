#include <stdio.h>
#include <stdlib.h>

int main(){
	int size = 5;
	int *dynamicArray = (int *)malloc(size * (sizeof(int)));
	
	int i;
	printf("Bitte geben Sie Ihre %d Werte ein\n", size);
	for(i = 0;i < size;i++){
		scanf("%d",&dynamicArray);
	}
	for(i = 0;i < size;i++){
		printf("%d  ",dynamicArray[i]);
	}
}
