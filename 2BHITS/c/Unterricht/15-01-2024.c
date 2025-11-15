#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct triangle {
    float c; // Basis
    float h; // Höhe

    // Setter-Methoden
    void (*setObjectBasis)(struct triangle* t, float c);
    void (*setObjectHeight)(struct triangle* t, float h);
    // Getter-Methoden
    float (*getObjectBasis)(struct triangle* t);
    float (*getObjectHeight)(struct triangle* t);
} triangle_t;

// Konstruktor-Funktion
triangle_t* createTriangle(float basis, float hoehe);

// Setter-Methoden
void setObjectBasis(triangle_t* t, float c);
void setObjectHeight(triangle_t* t, float h);
// Getter-Methoden
float getObjectBasis(triangle_t* t);
float getObjectHeight(triangle_t* t);

int main() {
    setlocale(LC_ALL, "DE_de.UTF-8"); 

    triangle_t* t = createTriangle(3.0, 4.0);

    printf("Basis: %f\n", t->getObjectBasis(t));
    printf("Höhe: %f\n", t->getObjectHeight(t));

    // Freigabe des Speichers
    free(t);

    return EXIT_SUCCESS;
}

void setObjectBasis(triangle_t* t, float c) {
    t->c = c;
}

void setObjectHeight(triangle_t* t, float h) {
    t->h = h;
}

float getObjectBasis(triangle_t* t) {
    return t->c;
}

float getObjectHeight(triangle_t* t) {
    return t->h;
}
// Destruktor
void destroyTriangle(triangle_t* t){
    free(t);
}
triangle_t* createTriangle(float basis, float hoehe) {
    triangle_t* t = malloc(sizeof(triangle_t));
    if (NULL == t) {
        printf("malloc failed for triangle_t");
        exit(EXIT_FAILURE);
    }
    t->setObjectBasis = &setObjectBasis;
    t->setObjectHeight = &setObjectHeight;
    t->getObjectBasis = &getObjectBasis;
    t->getObjectHeight = &getObjectHeight;

    t->setObjectBasis(t, basis);
    t->setObjectHeight(t, hoehe);

    return t;
}
