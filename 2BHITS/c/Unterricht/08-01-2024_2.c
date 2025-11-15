#include <stdio.h>
#include <stdlib.h>

struct position {
    int x;
    int y;
};

struct object {
    char name[32];
    struct position* pos;

    void (*setX)(struct object*, int);
    void (*setY)(struct object*, int);
    int (*getX)(struct object*);
    int (*getY)(struct object*);
    int (*getDistance)(struct object*);
    char* (*toString)(struct object*);
};

typedef struct object object_t;

// Setter-Methode
void setObjectX(object_t* obj, int x) {
    obj->pos->x = x;
}

// Getter-Methode
int getObjectX(object_t* obj) {
    return obj->pos->x;
}

// Getter-Methode
int getObjectY(object_t* obj) {
    return obj->pos->y;
}

// toString-Methode
char* toString(object_t* obj) {
    static char buffer[100];  // Statischer Puffer für die Zeichenkette
    snprintf(buffer, sizeof(buffer), "Das Objekt ist an der Position (%i,%i)\n", obj->pos->x, obj->pos->y);
    return buffer;
}

// Konstruktor des Objekts
object_t* createObject() {
    object_t* obj = malloc(sizeof(object_t));
    if (NULL == obj) {
        printf("malloc failed for object_t");
        return NULL;
    }
    obj->pos = malloc(sizeof(struct position));
    if (NULL == obj->pos) {
        printf("malloc failed for position");
        free(obj);
        return NULL;
    }
    obj->pos->x = 0;
    obj->pos->y = 0;
    obj->setX = &setObjectX;
    obj->getY = &getObjectY;
    obj->toString = &toString;
    return obj;
}

int main() {
    object_t* obj = createObject();
    obj->setX(obj, 10);
    printf("%s", obj->toString(obj));  // Verwende toString, um die Position zu drucken
    return EXIT_SUCCESS;
}
