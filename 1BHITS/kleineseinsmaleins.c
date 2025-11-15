#include <stdio.h>

int main(){
	
	int i;
	int Zahl;
	int erg;
	
	
	for(Zahl=1;Zahl<=10;Zahl++){		
		for(i=1;i<=10;i++){
		erg=Zahl * i;
		printf("\r\n%d * %d = %d ",i,Zahl,erg);
			
		}
		printf("\r\n");
	}
	return 0;
}
