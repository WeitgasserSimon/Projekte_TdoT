	/**
	* \author: Weitgasser Simon, Kumar Jai
	* \date: 2022-10-19
	* Eingaben (scanf),Datentypen (int, float, char)
	* Verarbeitung (Rechen) 
	* Ausgabe (printf)
	* EVA-Prinzip
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	
	int main() {
		// Notwendige Variablendeklarationen
		
		
		float plus;
		float minus;
		float mal;
		float durch;
		
		// Eingabe vom Benutzer anfordern:
		printf("Bitte eine x eingeben\n");
		scanf("%.1f",&x);
		printf("Geben sie bitte y ein");
		scanf(".1%f",&y);
		/* Ausgabe des Ergebnisses
	    printf("%f, %f, %f\n", x, y, z);
	    */
	    plus = x + y;
	    minus = x - y;
	    mal = x * y;
	    durch = x / y;
	    
	    printf("%.1f + %.1f = %.1f", x, y, plus);
	    printf("%.1f - %.1f = %.1f", x, y, minus);
	    printf("%.1f * %.1f = %.1f", x, y, mal);
	    printf("%.1f / %.1f = %.1f", x, y, durch);
	    
		
		
		
		
		return 0;
	
	}
	
	

