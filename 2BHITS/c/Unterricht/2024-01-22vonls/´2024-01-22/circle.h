/**
 * \author: Lothar Sch�fer
 * \date: 01.11.2022
 * \brief: Methoden des circles
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "object.h"

struct circle {
	struct object* object;
	void (*toString)(struct circle*);
	void (*move)(struct circle*, unsigned int x, unsigned int y);
};

// Konstruktor
struct circle* createCircle(unsigned int x, unsigned int  y);

// Destruktor
void destroyCircle(struct circle* this);

// Selektoren
void toString(struct circle* this);

// Modifizierer
void moveCircle(struct circle* this, unsigned int x, unsigned int y);

#endif
