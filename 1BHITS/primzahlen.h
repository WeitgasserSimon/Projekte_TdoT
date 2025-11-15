/**
* \brief   Bibliotheken mit Primzahlfunktionen
  \author  Simon Weitgasser
  \date    2023-03-01
*/

#ifndef PRIMZAHLEN_H
#define PRIMZAHLEN_H


int istPrim(int n){
	
	int i = 2;
	if (n < 2){
		while(i*i <= n){
			if(n % i == 0){
				
				return 0;
			}			
		}
		i=i+1;
	}

	return 1;
}
void primzahlenBis(int n){
	int i;
	for (i = 2; i<= n;i++){
		if(istPrim(i)){
			printf("%d", i);
		}
	}
	printf("\n");
}
#endif
