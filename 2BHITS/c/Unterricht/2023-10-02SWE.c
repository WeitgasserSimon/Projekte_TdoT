/**
@brief  Zeiger und structs in dynamischen Datenstrukturen
@author Weitgasser Simon
@date 	2023-10-02
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32

//Datenstruktur, welche eine Person repräsentiert
typedef struct person {
	char vorname [MAX_NAME_LENGTH];
	char nachname [MAX_NAME_LENGTH];
} person;

int main(){
	//Eine einzelne Person deklarieren
	 person p;
	//Die Attribute der Person initialisieren (setzen)
	strcpy(p.vorname, "Simon");
	strcpy(p.nachname, "Weitgasser");
	printf("Person: %s %s\n",p.vorname, p.nachname);
	
	
	person liste[10];
	//Die Attribute der ersten Person initialisieren (setzen)
	strcpy(liste[0].vorname, "Hans");
	strcpy(liste[0].nachname, "Maulwurf");
	//Die Person ausgeben
	printf("Person: %s %s\n",liste[0].vorname, liste[0].nachname);
	
	
	//Die Attribute einer weiteren Person setzen
	printf("Adresse von Liste: %p\n", liste);
	printf("Adresse von Liste[0]: %p\n", &liste[0]);
	printf("Adresse von Liste[1]: %p\n",&liste[1]);
	printf("Adresse von Liste[1]: %p\n",(liste+1));
	printf("Nachname in Liste[0]: %s\n",liste[0].nachname);
	printf("Nachname in Liste[0]: %s\n",(*liste).nachname);
	//strcpy(liste[1].vorname, "Peter");
	
	//Eine dynamisch wachsende Liste von Personen deklarieren
	person *l = malloc(1 * sizeof(person));	
	
	if(NULL == l){
		printf("Fehler bei der Speicherallokierung");
		return EXIT_FAILURE;
	}					
		printf("Adresse von L: %p\n", l);
		
		//Die Attribute der ersten Person in Liste l setzen
		
		strcpy((*l).vorname, "Chief");
		strcpy((*l).nachname, "Wiggum");
		printf("Person: %s %s\n",(*l).vorname,(*l).nachname);
		
		
		strcpy(l->vorname, "Chief");
		strcpy(l->nachname, "Wiggum");
		printf("Person: %s %s\n",(*l).vorname,(*l).nachname);
		
		l = realloc(l, 2 * sizeof(person));
		strcpy((l+1)->vorname, "Homer"); //strcpy braucht eine Adresse
		strcpy((l+1)->nachname, "Simpson");
		
		free(l);

	return EXIT_SUCCESS;
}
