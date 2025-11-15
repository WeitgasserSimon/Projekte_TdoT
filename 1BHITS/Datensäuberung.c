#include <stdio.h>
#include <stdlib.h>

int main(){
	int array[20]={20,30,23,43,6534,12,32,54,8881,25,18,23,16,18,19,24,20,16,16};
	int average = 0;
	int i;
	int m;
	
	for(i=0;i<20;i++){
		average= array[i]+average;
		
	}
	average=average/20;
	printf("Average:%d\n",average);
	for(m=0;m<20;m++){
		if(average<array[m]*10){
			printf("Index:%d\n",m);
		}
	}
	
	return 0;
}

