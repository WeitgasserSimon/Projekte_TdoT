#include <stdio.h>

int main()   {
	double geschwindigkeit =0;
	double strecke = 300;
	double zeit= 3;
	geschwindigkeit = strecke/zeit;
	printf("Durchschnittsgeschwindigkeit (in m/s)  von Salzburg nach Wien betraegt %.2f km/h\n ,wenn sie %.0f km fahren und dafuer %.0f Stunden brauchen   .", geschwindigkeit, strecke, zeit);
	return 0;
}	
