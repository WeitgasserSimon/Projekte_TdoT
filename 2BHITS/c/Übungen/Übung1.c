#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Kontakte{
	char vorname[32];
	char nachname[32];
	
			
}Kontakte;

int main(){
	Kontakte person1;
	strcpy(person1.vorname, "Lukas");
	strcpy(person1.nachname, "Winkler");
	
	printf("%s\n",person1.vorname);
	printf("%s\n",person1.nachname);
	printf("%p\n",&person1.nachname);
	printf("%s\n",*&person1.nachname);
	
	

}
