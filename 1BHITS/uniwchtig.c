#include <stdio.h>
#include <stdlib.h>

int main(){
	int Array[8]={2,4,8,16,32,-1,-2,-3};
	int i;
	int sum = 1;
	for(i=0;i<8;i++){
		if(Array[i]<0){
			Array[i] = 1;
		}
	}
	for(i=0;i<8;i++){
		sum = sum * Array[i];
	}
	printf("%d",sum);
	return 0;
	
}
