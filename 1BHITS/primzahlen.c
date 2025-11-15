#include <stdio.h>


int main(void)
{
    int zahl = 0;
    int i = 2;


    while (zahl < 2)
    {
        printf("Bitte geben Sie eine Zahl (2 oder größer) ein: ");
        scanf("%i", &zahl);
    }


    while (i <= zahl)
    {
        if (zahl%i == 0)
        {
            printf("%i\r\n", i);
            zahl /= i;
        }
        else
            i++;
    }


    return 0;
}
