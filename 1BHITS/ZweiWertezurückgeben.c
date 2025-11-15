#include <stdio.h>
#include <stdlib.h>

void calcCircAndArea(double length, double height, double* pCirc, double* pArea) {
    *pCirc = 2 * (length + height);
    *pArea = length * height;
}

void calcCircAndAreaOfCircle(double radius, const float pi, double* pCirc, double* pArea) {
    *pCirc = 2 * radius * pi;
    *pArea = radius * radius * pi;
}

int main(void) {
    double circumference, area;
    double length, height;
    double radius, pi;

    length = 3.14;
    height = 7.18;
    radius = 13;
    pi = 3.14159265358979323846;

    calcCircAndArea(length, height, &circumference, &area);
    printf("Der Umfang beträgt = %.3f\n", circumference);
    printf("Die Fläche beträgt = %.3f\n", area);

    calcCircAndAreaOfCircle(radius, pi, &circumference, &area);
    printf("Der Umfang beträgt = %.3f\n", circumference);
    printf("Die Fläche beträgt = %.3f\n", area);

    return 0;
}

