/**
 * erstelle rectangle.c und .h analog zu circle.c und .h. mod makefile für rechteckg
 * @brief   Vererbung
 * @author  Lothar Schäfer
 * @date    15.01.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "circle.h"

int main() {
	struct object* o = createObject(10, 10);
	o->toString(o);
	o->move(o, 0, 10);
	o->toString(o);

	struct circle* c = createCircle(20, 20);
	c->toString(c);
	c->move(c, 0, 10);
	c->toString(c);

	destroyObject(o);
	destroyCircle(c);

	return 0;
}
