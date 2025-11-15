/**
 * @brief   Implementation des circles
 * @author  Lothar Schäfer
 * @date    15.01.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "circle.h"

// Konstruktor
struct circle* createCircle(unsigned int x, unsigned int  y) {
	struct circle* circle = (struct circle*) malloc(sizeof(struct circle));
	circle->object = (struct object*) malloc(sizeof(struct object));
	circle->object->position = (struct position*) malloc(sizeof(struct position));
	circle->object->position->x = x;
	circle->object->position->y = y;
	circle->toString = toString;
	circle->move = moveCircle;
	return circle;
}

// Destruktor
void destroyCircle(struct circle* this) {
   free(this->object->position);
   free(this->object);
   free(this);
}

// Selektoren
void toString(struct circle* this) {
	printf("Circle on position (%u, %u)\n", this->object->position->x, this->object->position->y);
}

// Modifizierer
void moveCircle(struct circle* this, unsigned int x, unsigned int y) {
   this->object->position->x += x;
   this->object->position->y += y;
}
