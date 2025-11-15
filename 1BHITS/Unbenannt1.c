
#include <stdio.h>

int TriangleAreaCalc(float length, float height){
	float erg;
	erg = length*height/2;
	return erg;
	}

int main (void){
	int length_c, height_, erg;
	
	printf("Geben sie bitte die Laenge ein:");
	scanf("%.2f",&length_h);
	
	printf("Geben sie bitte die Hoehe ein:");
	scanf("%.2f",&height_c);
	
	erg=TriangleAreaCalc(length_c,height_h);
	
	printf("Ihre Flaeche ist : %.2f groﬂ",erg);
	
	

	
}
