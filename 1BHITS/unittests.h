/**
* \brief: Unittest für  "minsort" mit Ausgabe ob der Test erfolgreich war 
* \details: 
* \author: Simon Weitgasser(simon.weitgasser08@htl-salzburg.ac.at)
* \date: 2023-04-13
*/

#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <stdio.h>
#include <stdlib.h>

int test1(int a[], int n){
    int i;
    for(i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            return 0;
            printf("\nTest 1 nicht erfolgreich");
        }
    }
    printf("\nTest 1 erfolgreich");
    return 1;
}


#endif // UNITTESTS_H
