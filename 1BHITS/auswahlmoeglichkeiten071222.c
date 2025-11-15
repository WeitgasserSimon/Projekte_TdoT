#include <stdio.h>

void calcTriangle(void)
{
    //lokale Variablen in calcTriangle
    float h;
    float c;
    float areaT;

    printf("Bitte geben Sie nun ihre Höhe ein: ");
    scanf("%f", &h);
    printf("Bitte geben Sie ihre Seitenlänge ein: ");
    scanf("%f", &c);
    areaT = (c * h)/2;
    printf("Die Fläche ihres Dreiecks ist %.2f Quadratzentimeter groß", areaT);
}

void calcRect(void)
{
    //lokale Variablen in calcRect
    float length;
    float width;
    float areaR;

    printf("Bitte geben Sie die Länge ihres Rechtecks ein: ");
    scanf("%f", &length);
    printf("Bitte geben Sie die Breite ihres Rechtecks ein: ");
    scanf("%f", &width);
    areaR = length * width;
    printf("Ihr Rechteck ist %.2f Quadratzentimeter groß", areaR);
}

int main(){
    float select;

    printf("Wollen Sie ein Rechteck(1) oder ein Dreieck(2) berechnen? ");
    scanf("%f", &select);

    if(select == 1){
        calcRect();
    }
    else if(select == 2){
        calcTriangle();
    }
    else{
        printf("Sie haben weder 1 noch 2 eingegeben", select);
    }

    return 0;
}
