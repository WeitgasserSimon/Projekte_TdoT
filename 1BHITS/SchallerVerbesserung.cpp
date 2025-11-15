#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
// & holt sich die Adresse von der Variable
int main()
{
	system("CHCP 1250");
	system("CLS");
	
	float l;
	float b;
	float area = l * b;
	
	
	
	printf("Geben sie die Laenge ein:%.2f",l);
	scanf("%f",&l);
	printf("Geben sie die Breite ein:%.2f",b);
	scanf("%f",&b);
	
	if(area>110)
	{
	
	printf("%s Die Area ist %.2f Quadratcentimeter groﬂ",FG_RED, area, RESET);
	}
	
	else
	{
	
	printf("%s  Die Area ist %.2f Quadratcentimeter groﬂ",FG_GREEN, area);
	
}
	return 0;
	
	
	
	
}
