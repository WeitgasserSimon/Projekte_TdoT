#include <stdio.h>

int main() {
	char WilliWuselTable[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	int dezimal;
	
	printf("Bitte geben Sie Ihre dezimale Zahl ein: ");
	scanf("%d", &dezimal);
	
	char output[100]; 
	
	int i = 0;
	while (dezimal > 0) {
		int rest = dezimal % 36;
		output[i] = WilliWuselTable[rest];
		dezimal  = dezimal/36;
		i++;
	}
	
	printf("Das Ergebnis in der WilliWusel-Zahl ist: ");
	int j;
	for ( j = i - 1; j >= 0; j--) {
		printf("%c", output[j]);
	}
	
	return 0;
}

