/**
 * @brief   Vererbung
 * @author  Lothar Schäfer
 * @date    15.01.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "figur.h"
#include "kreis.h"

int main() {
	struct figur* f = newFigur();
	// keine Möglichkeiten auf getArea oder getUmfang zuzugteifen
	
	struct kreis* k = newKreis();
	k->setRadius(k, 10);

	printf("Der kreis hat die Fläche %.2f\n", k->figur->getArea(k));
	printf("Der kreis hat den Umfang %.2f\n", k->figur->getUmfang(k));

	destroyObject(f);
	destroyCircle(k);

	return 0;	
}
