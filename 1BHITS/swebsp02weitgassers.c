	
	#include <stdio.h>
	
	int main() {
		
	float x;
	float y;
		
	float plus; 
	float minus;
	float mal;
	float durch;
		
	printf("1. Abfragender Rechner");
		
	
	printf("\wnBitte x eingeben");
	scanf("%.1f",&x);
	printf("\nBitte y eingeben");
	scanf("%.1f",&y);
		
	plus = x + y ;
	minus = x - y;
	mal = x * y ;
	durch = x / y;
		
	printf("\nx + y ist %.1f", plus);	
	printf("\nx - y ist %.1f", minus);
	printf("\nx * y ist %.1f", mal);
	printf("\nx / y ist %.1f", durch);
	
	return 0;
		
	}
