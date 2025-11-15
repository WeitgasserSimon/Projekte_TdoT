#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <unistd.h>

#define MAXNAME 128
#define MAXCNT 100
#define TRUE 1
#define FALSE 0

struct PERSON{
	char vorname[MAXNAME];
	char nachname[MAXNAME];
};

typedef struct PERSON person;

int main(){
	person p[MAXCNT];
	int quit = FALSE;
	int i = 0;
	int ii;
	char c;
	
	do{
	printf("Bitte eine Person eingeben (Vorname Nachname): \n");
	scanf("%s %s",p[i].vorname,p[i].nachname);	
	
	printf("Sie haben %s %s eingegeben.\n",p[i].vorname,p[i].nachname);
	printf("Wollen Sie eine weitere Person eingeben [J/N]?\n");
	while((c = getchar()) && (c != 'E0F'));
	c = getchar(); // Tastatur Buffer leeren
	
	scanf("%c", &c);
	switch (c){
		case 'N':
		case 'n':
			quit = TRUE;
			break;
	}
		
	}while(!quit);
	//Prüfen ob die datei schon existiert
	int header = FALSE;
	if(access("personen.txt", F_OK)!= -1){
		header = TRUE;
	}
		// Eine Datei zum schreiben öffnen
	FILE* file = fopen("personen.txt", "a");
	if(NULL==file){
		printf("Die datei konnte nicht geöffnet werden");
		return EXIT_FAILURE;
	}
	
	if(!header){
		fprintf(file, " Vorname;Nachname\n");
	}
	
	//Die personen in die datei schreiben
	for(ii=0;ii<i;ii++){
		fprintf(file,"%s %s",p[ii].vorname,p[ii].nachname);
	}
	//Die datei schließen
	fclose(file);
	
	return EXIT_SUCCESS;
}
