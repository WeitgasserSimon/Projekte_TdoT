/**
 * @file    2023-10-09SWE2.c
 * @brief   Der Stack oder Stapelspeicher
 * @author  Simon Weitgasser
 * @date	2023-10-09
 *
 * compile with gcc 2bhits_2023-10-09_2.c -o run
 * run with .\run when powershell
 * run with run when command prompt
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct stack {
	int items[MAX_SIZE];
	int counter;
} stack;

void init(stack*s);
void push(stack* s, int x);
int pop(stack *s);
int peek(stack *s);
int isempty(stack* s);
int isfull(stack *s);

int main() {
	stack s1;
	stack s2;

	init(&s1);
	push(&s1, 4);
	push(&s1, 2);
	printf("s1 = %i\n", pop(&s1));
	printf("s1 = %i\n", pop(&s1));
	push(&s2, 1);
	push(&s2, 3);
	printf("s2 = %i\n", pop(&s2));
	printf("s2 = %i\n", pop(&s2));

	return EXIT_SUCCESS;
}

void init(stack*s) {
	s->counter = 0;
}

void push(stack* s, int x) {
	s->items[s->counter++] = x;
}

int pop(stack* s) {
	return s->items[--s->counter];
}

int peek(stack* s) {
	return s->items[s->counter-1];
}

int isempty(stack* s) {
	return s->counter == 0;
}

int isfull(stack* s) {
	return s->counter == MAX_SIZE;
}
