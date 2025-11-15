/**
* \brief: MinSort Algorithmus mit Ausgabe
* \details: 
* \author: Lukas Winkler (lukas.winkler08@htl-salzburg.ac.at)
* \date: 2023-04-13
*/

#ifndef SORTING_H
#define SORTING_H

int minsort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for (i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }
    return 0;
    
}

#endif // SORTING_H
