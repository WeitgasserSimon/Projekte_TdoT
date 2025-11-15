#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int randomValue;
	int input;
	time_t start,end;
	
	srand(time(NULL));
	
	randomValue=rand()%98+3;
	printf("%d",randomValue);
	scanf("%d",&input);
	if(input==randomValue*3){
		printf("RICHTIG");
	}
	else{
		printf("FALSCH");
	}
	return 0;
}
