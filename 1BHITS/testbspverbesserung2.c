#include <stdio.h>


int main(){
	
	long testzahl =441367;
	int i,erg;
	
	for(i = 2;i < 441367;i++){
		erg = testzahl%i;
		if(erg == 0) {
			printf("1.Teiler wurde gefunden=%d\r\n",i);
			erg = testzahl / i;
			printf("2.Teiler wurde gefunden=%d\r\n",erg);
			break;
		}
	}
	
	
		
		
		
		

	

return 0;	
}

	

