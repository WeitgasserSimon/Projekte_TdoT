/**
 * @brief   The parent class
 * @author  Lothar Schäfer
 * @date    15.01.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

// Konstruktor
 struct object* createObject(unsigned int x, unsigned int  y) {
   struct object* object = (struct object*) malloc(sizeof(struct object));
   object->position = (struct position*) malloc(sizeof(struct position));
   object->position->x = x;
   object->position->y = y;
   object->toString = getObjectInfo;
   object->move = moveObject;
   return object;
}

// Destruktor
void destroyObject(struct object* this) {
   free(this->position);
   free(this);
}

// Selektoren
struct position* getPosition(struct object* this) {
   return this->position;
}

void getObjectInfo(struct object* this) {
	printf("Object at position (%u, %u)\n", this->position->x, this->position->y);
}

// Modifizierer
void moveObject(struct object* this, unsigned int x, unsigned int y) {
   this->position->x += x;
   this->position->y += y;
}
