#include <stdio.h>

int main()  {

 float gradc = 15;
 float gradf = 0;
 float gradk = 0;
 
gradk = gradc + 273,15;
gradf = gradc * 9/5+32;
printf( "Die Temperatur betraegt:\n");
printf( "%.2fGrad Celsius \n" ,gradc);
printf( "%.2fGrad Kelvin \n" ,gradk);
printf( "%.2fGrad Fahrenheit \n" ,gradf);
return 0;
}
