/**
* \brief: Datei zum Ausfuehren der Fuktionen Minsort
* \details: 
* \author: Lukas Winkler (lukas.winkler08@htl-salzburg.ac.at)
* \date: 2023-04-13
*/

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"
#include "unittests.h"

#define N 10

int main (){
    system("CHCP 1250");
    system("color");
    system("CLS");

    int a[N] = { 5, 3, 2, 1, 4, 6, 7, 8, 9, 10 };
    minsort(a, N);
    test1(a, N);
    
    
    return EXIT_SUCCESS;
}
