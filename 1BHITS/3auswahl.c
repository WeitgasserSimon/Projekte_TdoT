#include <stdio.h>

void CalcTriangleArea(void){
    float base;
    float height;
    float TriangleArea;

    printf("Bitte geben Sie die Länge Ihrer Grundfläche ihres Dreiecks in cm an:");
    scanf("%f",&base);
    printf("Bitte geben Sie die Höhe Ihres Dreiecks in cm an: ");
    scanf("%f",&height);
    TriangleArea = (base * height) / 2.0;
    printf("Die Fläche Ihres Dreiecks beträgt: %.2f Quadratzentimeter\n",TriangleArea);
}

void CalcRectangleArea(void){
    float length;
    float width; 
    float RectangleArea;
    printf("Bitte geben Sie die Länge und Breite Ihres Rechtecks in cm an:");
    scanf("%f%f",&length,&width);
    RectangleArea = length * width;
    printf("Die Fläche Ihres Rechtecks beträgt: %.2f Quadratzentimeter\n",RectangleArea);
}

void CalcCircleArea(void){
    float radius;
    const float pi=3.14159265358979323846;
    float CircleArea;

    printf("Bitte geben Sie den Radius Ihres Kreises in cm an:");
    scanf("%f",&radius);
    CircleArea = pi * radius * radius;
    printf("Die Fläche Ihres Kreises beträgt: %.2f Quadratzentimeter\n",CircleArea);
}

int main(){
    char selection;
    printf("Bitte geben Sie die Form Ihres an (Dreieck: D, Rechteck: R, Kreis: K): ");
    scanf("%c",&selection);

    if(selection=='D'){
        CalcTriangleArea();
    }
    else if(selection=='R'){
        CalcRectangleArea();
    }
    else if(selection=='K'){
        CalcCircleArea();
    }
    else{
        printf("Sie haben keine gültige Auswahl getroffen. Bitte wählen Sie D, R oder K\n");
        
    }
    return 0;
}

