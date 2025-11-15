/**
 * @file    2hits_2023-10-09_1.c
 * @brief   Der Stack oder Stapelspeicher
 * @author  Simon Weitgasser 
 * @date	2023-10-09
 *
 * compile with gcc 2bhits_2023-10-09_1.c -o run
 * run with .\run when powershell
 * run with run when command prompt
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Globale Variablen für den Stack und den Stackcounter
int stack[MAX_SIZE];
int counter = 0;

// Die Stack-Funktionen
void push(int x);
int pop();
int peek();
int isempty();
int isfull();

int main() {

	int n, i, x;
	printf("Wie viele Zahlen wollen Sie eingeben?\n");
	printf("n = ");
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		printf("x = ");
		scanf("%i", &x);
		if (!isfull()) {
			push(x);
		} else {
			printf("Der Stack ist voll!\n");
		}
	}

	// Alle Zahlen ausgeben
	while (!isempty()) {
		printf("x = %i\n", pop());
	}

	return EXIT_SUCCESS;
}

void push(int x) {
	stack[counter++] = x;
}

int pop() {
	return stack[--counter];
}

int peek() {
	return stack[counter-1];
}

int isempty() {
	if (counter == 0) {
		return 1;
	} else {
		return 0;
	}
}

int isfull() {
	if (counter == MAX_SIZE) {
		return 1;
	} else {
		return 0;
	}
}
