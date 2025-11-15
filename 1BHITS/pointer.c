#include <stdio.h>
#include <stdlib.h>

int main(){
	int myVar;
	int *pmyVar;
	
	myVar=15;
	pmyVar = &myVar; //pmyVar zeigt auf Adresse von myVar
	*pmyVar =18;//dawo pmyVar hinzeigt wird der wert mit 18 gespeichert
	
	return 0;
}
