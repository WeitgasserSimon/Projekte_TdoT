#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdio.h>
#include <stdlib.h>

struct triangle {
	float c; // Basis
	float h; // Höhe
	// Setter-Methoden
	void (*setBasis)(struct triangle*, float);
	void (*setHoehe)(struct triangle*, float);
	// Getter-Methoden
	float (*getBasis)(struct triangle*);
	float (*getHoehe)(struct triangle*);
};

typedef struct triangle triangle_t;


void setBasis(triangle_t* this, float c) {
	this->c = c;
}

void setHoehe(triangle_t* this, float h) {
	this->h = h;
}

float getBasis(triangle_t* this) {
	return this->c;
}

float getHoehe(triangle_t* this) {
	return this->h;
}

// Konstruktor
triangle_t* createTriangle(float c, float h) {
	triangle_t* t = malloc(sizeof(triangle_t));
	if (NULL != t) {
		t->c = c; // Initialisieren der Basis
		t->h = h; // Initialisieren der Hoehe
		t->setBasis = &setBasis;
		t->setHoehe = &setHoehe;
		t->getBasis = &getBasis;
		t->getHoehe = &getHoehe;
	}
	return t;
}

// Destruktor
void destroyTriangle(triangle_t* this) {
	free(this);
}

#endif