#include <stdio.h>



	int main(){
	char select;
		
	printf("Geben sie bitte eine Zahl ein:");
	scanf("%c",&select);
	
	
	switch(select){
		case 'A':
			printf("Sie haben a eingegeben");
			break;
		case 'B':
			printf("Sie haben b eingegeben");
			break;
			
		case 'C':
			printf("Sie haben c eingegeben");
			break;
			
		default:
			printf("Falsche Eingabe");			
		}			
	}
	
	
