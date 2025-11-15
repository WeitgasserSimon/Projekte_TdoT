/**
 * \author: Lothar Sch�fer
 * \date: 01.11.2022
 * \brief: Methoden des circles
 */

#ifndef KREIS_H
#define KREIS_H

#include "figur.h"

struct kreis {
	struct figur* figur; 
	struct object* object;
	float Radius;
	void (*setRadius)(struct kreis*, float);
	float (*getRadius)(struct kreis*);
};

// Prototyp des Konstruktors
struct kreis* newKreis();

// Prototyp des Destruktors
void destroyCircle(struct kreis* this);

// Prototypen der Getter- und Setter-Methoden
void setRadius(struct kreis* this, float radius);
float getRadius(struct kreis* this);
#endif
