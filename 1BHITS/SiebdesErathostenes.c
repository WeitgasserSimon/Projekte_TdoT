#include <stdio.h>

	void eratosthenes(int range){
		int counter;
		int counter2;
		if(range<=1){
			printf("Der Zahlenbereich muss >1 seien");
			
		}
		else{
			if(counter%counter2==0){
				printf("%d ist durch null teilbar\r\n",counter);
			}
		}
		
	}
	int main(void){
		int range;
		printf("Geben Sie bitte den Zahlenbereich ein, in welchem Primzahlen gesucht werden sollen:",range);
		scanf("%d",&range);
		eratosthenes(range);
		return 0;
		
	}
