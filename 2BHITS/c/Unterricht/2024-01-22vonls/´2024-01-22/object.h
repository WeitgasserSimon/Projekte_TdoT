/**
 * @brief   Methoden des objects
 * @author  Lothar Schäfer
 * @date    15.01.2024

 */

#ifndef OBJECT_H
#define OBJECT_H

struct position {
	unsigned int x;
	unsigned int y;
};

struct object {
	struct position* position;
	void (*move)(struct object*, unsigned int dx, unsigned int dy);
	void (*toString)(struct object*);
};

// Constructor
struct object* createObject(unsigned int x, unsigned int  y);

// Destructor
void destroyObject(struct object* this);

// Getter-methods
struct position* getPosition(struct object* this);
void getObjectInfo(struct object* this);

// Modifizierer
void moveObject(struct object* this, unsigned int x, unsigned int y);

#endif
