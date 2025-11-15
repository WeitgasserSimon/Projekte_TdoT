/*
 * @brief einfache Pointer außerhalb der main
 * @author Weitgasser Simon
 */
#include <stdio.h>
#include <stdlib.h>

int getMaximum(int* a, int* b){
    int max;
    if(*a > *b){
        max = *a; // Dereferenzieren
    }else{
        max = *b; // Dereferenzieren
    }
    return max;
};
int main(){

    int a = 5;
    int b = 10;

    printf("Das Maximum von %d und %d ist %d",a,b,getMaximum(&a,&b));

    return 0;
};