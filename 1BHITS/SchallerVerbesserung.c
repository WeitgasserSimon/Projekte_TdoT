#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
// & holt sich die Adresse von der Variable
int main()
{
	system("CHCP 1250");
	system("CLS");
	
	float radius;
	const float pi=3.14159265358979323846;
	float area;
	
	
	
	
	printf("Geben sie den Radius in Zentimeter ein:",radius);
	scanf("%f",&radius);

	area = radius * radius * pi;
	
	
	
	if(area>110)
	{
	
	printf("%s Die Area ist %f Quadratzentimeter groﬂ%s",FG_RED, area, RESET);
	}
	
	else
	{
	
	printf("%s Die Area ist %f Quadratzentimeter groﬂ",FG_GREEN, area);
	
	}
	return 0;
	
	
	
	
}
