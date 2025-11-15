#include <stdio.h>
#include <stdlib.h>
#define N 4

		
int main(){
	int i;
	int j;
	int k;
	int Array[N]={1,2,3,4};
	int newArray[N];
	
	for(i=0;i<sizeof(Array);i++){
		newArray[i]=Array[i];
	}
	for(j=0;j<N;j++){
		newArray[j]=newArray[j]*newArray[j];
	}
	for(k=0;k<N;k++){
		printf("%d\n",newArray[k]);
	}
	return 0;
}
