#include <stdio.h>
#include <stdlib.h>


typedef struct konto {
    int number;
    float balance;
} konto_c;

typedef struct bank {
    konto_c* konto;
}bank_c;

typedef struct kunde {
    char name[50];
    konto_c* konto;

    
} kunde_c; 

int main(){

};