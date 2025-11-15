/**
@brief eingabeparameter entgegennehmen und verarbeiten
*/

#include <stdio.h>
#include <stdlib.h>
	
int main(int argc, char* argv[]){
	// argc... argument count( Anzahl der Argumente)
	// argv... argument value( Wert der Argumente)
	printf(" Anzahl der Eingabeparameter = %i \n",argc);
	int i;
	for(i=0;i<argc;i++){
		printf(" Der uebergebene Parameter = %s ",argv[i]);
		if (strcmp(argv[i],"Das")){
			printf("Einer der Eingabeparameter ist das Wort Das");
		}
	}
	
	
	return EXIT_SUCCESS;
}
