#include <stdio.h>

	int main(){
		int x;
		scanf("%d",&x);
		
		if(x%5==0){
			printf("Die Zahl %d ist durch 5 teilbar",x);
		}
		else{
			printf("Die Zahl %d ist nicht durch 5 teilbar",x);
		}
	return 0;
	}

