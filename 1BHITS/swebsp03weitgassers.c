
	#include <stdio.h>

	float main() {
	float km;
	float liter;
	float benzinverbrauch;
		
	printf("Wie viele Kilometer sind sie gefahren?\n");
	scanf("%f",&km);
	printf("Wie viele Treibstoff haben sie verbraucht?\n");
	scanf("%f",&liter);

	benzinverbrauch= liter*100/km;
	printf(" Ihr Durchschnittsverbrauch bei 100km betraegt %f Liter\n",benzinverbrauch);
	
	
	
	return 0;
}

