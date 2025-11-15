#include <stdio.h>

#define NUMBER_LENGTH 5

// Funktion für den Luhn-Algorithmus
int LUHN(int number) {
  int Ziffer;
  int summe = 0;
  int mitte = NUMBER_LENGTH / 2;
  int i;
  
  // Durchläuft jede Ziffer der Zahl
  for (i = 0; i < NUMBER_LENGTH; i++) {
    Ziffer = number % 10;
    number = number / 10;
    
    // Verdoppelt die Ziffer, wenn sie in der Mitte der Zahl ist
    if (i / 2 == mitte) {
      Ziffer = Ziffer * 2;
      
      // Subtrahiert 9, falls das Ergebnis größer als 9 ist
      if (Ziffer > 9) {
        Ziffer = Ziffer - 9;
      }
    }
    
    summe += Ziffer;
  }
	
  // Überprüft, ob die Summe durch 10 teilbar ist
  return (summe % 10 == 0);
}

int main() {
  int Zahlen[] = {18934, 17937, 19837, 13987, 78931};
  int i;
  
  // Testet die Luhn-Funktion für jede Zahl
  for (i = 0; i < 5; i++) {
    int result = LUHN(Zahlen[i]);
    
    // Gibt das Ergebnis aus
    if (result) {
      printf("%d ist VALIDE\n", Zahlen[i]);
    } else {
      printf("%d ist NICHT VALIDE\n", Zahlen[i]);
       
    }
  }
 	
  
  return 0;
}

