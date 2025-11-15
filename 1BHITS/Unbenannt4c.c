#include <stdio.h>
#include <stdbool.h>

void eratosthenes(int n) {
    bool prime[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    printf("Primzahlen bis %d: \n", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d\n", p);
        }
    }
}

int main(void) {
    int n;
    printf("Bis zu welcher Zahl sollen Primzahlen berechnet werden?\n");
    scanf("%d", &n);
    eratosthenes(n);
    return 0;
}
	
