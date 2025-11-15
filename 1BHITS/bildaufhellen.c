/**
10 12 14 30
5  3  7  20
3  7  20 30
20 30 8  5
15 30 2  32



**/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int Array[20]={10 ,12, 14, 30,5,  3 , 7  ,20,3 , 7  ,20, 30,20 ,30, 8 , 5,15 ,30, 2 , 32};
	int i;
	int m;
	int maximum;
	
	for(i=0;i<20;i++){
		if(Array[i]>maximum){
			maximum = Array[i];
		}
	}
	int faktor =255/maximum;
	
	int hellerArray[20];
	for(m=0;m<20;m++){
	hellerArray[m]	=Array[m]+faktor;
	printf("%d\n",hellerArray[m]);
	}
	
	
	return 0;
}
