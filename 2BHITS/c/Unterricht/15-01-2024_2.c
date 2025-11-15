#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct object {
    // Eigenschaften
    char color[32];
    char brand[32];
    int vmax;
    int ps;

    // Methoden
    // SET
    void (*setObjectColor)(struct object* car, const char* color);

    // GET
    int (*getObjectPs)(struct object* car);
    int (*getObjectVmax)(struct object* car);
};

typedef struct object object_t;

// SET
void setObjectColor(struct object* car, const char* color) {
    strncpy(car->color, color, sizeof(car->color) - 1);
    car->color[sizeof(car->color) - 1] = '\0';
}

// GET
int getObjectPs(struct object* car) {
    return car->ps;
}

int getObjectVmax(struct object* car) {
    return car->vmax;
}

// Konstruktor-Funktion
object_t* createObject(const char* color, const char* brand, int vmax, int ps) {
    object_t* car = malloc(sizeof(object_t));
    if (car != NULL) {
        car->setObjectColor = &setObjectColor;
        car->getObjectPs = &getObjectPs;
        car->getObjectVmax = &getObjectVmax;

        // Initialisierung
        strncpy(car->color, color, sizeof(car->color) - 1);
        car->color[sizeof(car->color) - 1] = '\0';

        strncpy(car->brand, brand, sizeof(car->brand) - 1);
        car->brand[sizeof(car->brand) - 1] = '\0';

        car->vmax = vmax;
        car->ps = ps;
    }
    return car;
}

// Destruktor-Funktion
void destroyObject(object_t* car) {
    free(car);
}

int main() {
    // Beispiel: Objekt erstellen und initialisieren mit Konstruktor
    object_t* car = createObject("White", "VW", 140, 60);

    printf("Color: %s\n", car->color);
    printf("Brand: %s\n", car->brand);
    printf("Ps: %d PS\n", car->getObjectPs(car));
    printf("Vmax: %d km/h\n", car->getObjectVmax(car));

    // Objekt freigeben
    destroyObject(car);

    return 0;
}
