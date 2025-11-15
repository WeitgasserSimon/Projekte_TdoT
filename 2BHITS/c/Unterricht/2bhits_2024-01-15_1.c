/*
 * @file    2bhits_2024-01-15_1.c
 * @brief   Objekte in C
 * @author  Lothar Schäfer (lothar.schaefer@htl-salzburg.ac.at)
 * @date    2024-01-15
 *
 * cls; gcc -Wall 2bhits_2024-01-15_1.c -o run.exe; .\run.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "triangle.h"




int main() {
	setlocale(LC_ALL, "DE_de.UTF-8");
	printf("\33c");
	triangle_t* t = createTriangle(5.0, 10.0);
	t->setBasis(t, 10.0);
	t->setHoehe(t, 20.0);
	printf("c = %.2f\n", t->getBasis(t));
	printf("h = %.2f\n", t->getHoehe(t));
	return EXIT_SUCCESS;
}