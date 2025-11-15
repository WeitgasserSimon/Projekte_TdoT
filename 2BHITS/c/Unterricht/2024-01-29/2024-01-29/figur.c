/**
 * @brief   The parent class für Kreis und Rechteck
 * @author  Lothar Schäfer
 * @date    29.01.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "figur.h"

// Konstruktor
 struct figur* newFigur() {
   struct figur* f = malloc(sizeof(struct figur));

   return figur;
}

// Destruktor
void destroyFigur(struct object* this) {
   free(this);
}



