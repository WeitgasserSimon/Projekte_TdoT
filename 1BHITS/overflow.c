/**
  buffer overflow im Stackspeicher
  Weitgasser Simon 
  17 May 2023
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //Für das Arbeiten mit Zeichenketten

#define N 16

int main(int argc,char* argv[]){
	char richtig[] = "sicher"; //Das echte Kennwort
	char passwort[N];	//Das eingegebene Kennwort
	int korrekt = 0; // Ist das Passwort richtig?
	 
	
	 while(1){
	  printf("Bitte geben Sie ihr Kennwort ein: \n");
	 printf("Kennwort = ");
	 scanf("%s", passwort);
	 printf("Sie haben \"%s\" eingegeben.\n", passwort); 
	 if(strlen(passwort)>N){
	 	printf("Das Kennwort ist zu lang\n");
	 	korrekt = 0;
	 }
	 if(strcmp(passwort,richtig)){
	 	printf("Das Kennwort ist nicht korrekt!\n");
	 	
	 }
	 else {
	 	printf("Das Kennwort ist richtig");
	 	korrekt=1;
	 }
	 if(korrekt){
	 	break;
	 }
	 if (korrekt){
	 	system("DIR");
	 	break;
	 }
	 }
	
	
	
	
	return EXIT_SUCCESS;
}
