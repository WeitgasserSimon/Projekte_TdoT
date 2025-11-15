/**
 * @brief   Implementation des circles
 * @author  Lothar Schäfer
 * @date    15.01.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "kreis.h"

// Implementation des Konstruktors
struct kreis* newKreis() {
	struct kreis* k = malloc(sizeof(struct kreis));
	k->figur->getFlaeche = getArea;
	k->figur->getUmfang = getUmfang;	// der Funktionsname ist schon die Adresse der Funktion
	k->setRadius = setRadius;
	k->getRadius = getRadius;

	return k;
}

// Implementation des Destruktors
void destroyCircle(struct kreis* this) {
	free(this->figur);
	free(this);
}

// Implementation der Getter- und Setter-Methoden

float getArea(struct kreis* this) {
	return this->Radius * this->Radius * 3.14159265358979323846;
}
void setRadius(struct kreis* this, float radius) {
	this->Radius = radius;
}
float getRadius(struct kreis* this) {
	return this->Radius;
}