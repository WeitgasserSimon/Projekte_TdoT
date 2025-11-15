#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
	
	int main()
	{
	system("CHCP 1250");
	system("CLS");
	
	int c;
	int height;
	int areat;
	int length;
	int width;
	int areaq;
	
	int select;
	
	printf("Wollen sie ein Dreieck(1) oder Rechteck(2) berechnen\n");
	scanf("%d",&select);
	
	if(select==1){
	
	printf("Sie haben Dreieck gew‰hlt\n");
	printf("Geben sie bitte die L‰nge des Dreiecks an\n",c);
	scanf("%d",&c);
	printf("Geben sie bitte die Hoehe des Dreiecks an\n",height);
	scanf("%d",&height);
	areat = c * height / 3;
	printf("%sIhr Dreieck ist %d Quadratzentimeter groﬂ\n",areat);
	
	}

	if(select==2){
	printf("Sie haben Rechteck gew‰hlt");
	printf("Geben sie bitte die L‰nge der Seite an\n",length);
	scanf("%d",&length);
	printf("Geben sie bitte die L‰nge der Seite an\n",width);
	scanf("%d",&width);
	areaq = length * width;
	printf("Ihr Rechteck ist %d Quadratzentimeter groﬂ\n",areaq);
		
	}
	
	else{
	printf("Sie haben nicht 1 oder 2 gew‰hlt");
	}
	return 0;	
	}
