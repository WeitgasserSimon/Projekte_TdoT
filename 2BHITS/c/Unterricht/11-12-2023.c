// Wiederholung Rekursion (auf sich selbst zurückführen)
// Idee: Die Selbstähnlichkeit einer Datenstruktur ausnutzen
// z.B. Ein Baum besteht aus Subbäumen, die Verfahren die man auf den Baum anwendet
// funktionieren genauso auf den Subbäumen
// n! = 1*2*3....*n = n!´* (n-1)!
// weiteres Bsp. Mergesort, Türme von Hanoi

#include <stdio.h>
#include <stdlib.h>

long long fact(long long n);

int main(){
    printf("%ul", fact(10));
    return EXIT_SUCCESS;
}

// Berechnung der Fakultät in rekursiver Form
// Recurrere -> auf sich selbst beziehen
long long fact(long long n){
    // 1. WICHTIG: Die Abbruchbedingung formulieren 
    if(n <= 1){
        // Verlassen der Rekursion => gibt 1 zurück
        return 1;   
    }
    // fact(3) => return 3*fact(2) => fact(2) => return 2*fact(1) => fact(1) => return 1;
    //  1 fließt zurück zu fact(1), 2 fließt in fact(2), 6 fließt in die Ausgabe
    return n*fact(n-1);
}

void traverseInOrder(treenode_t* treenode) {
	if (treenode == NULL) {
        return;
    }
		traverseInOrder(treenode->left);
		printf("%i ", treenode->data);
		traverseInOrder(treenode->right);
	}
