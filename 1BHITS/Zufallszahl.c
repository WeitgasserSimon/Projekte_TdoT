#include <stdio.h>
	
	int main (){
		
	int randomValue = rand();
	int randValue10;
	randValue10=(randomValue%10)+1;
	
	printf("%d",randValue10);
		
	return 0;
}
