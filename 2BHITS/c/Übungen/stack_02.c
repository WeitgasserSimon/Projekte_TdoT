/**
 * @file    stack_02.c
 * @brief	Implementation of a push down stack memory as data structure
 * @author  Lothar Schäfer (lothar.schaefer@htl-salzburg.ac.at)
 * @date	2023-09-21
 *
 * The stack is implemented with a data structure containing an array of MAX_SIZE elements.
 * The empty stack is signaled with counter == -1
 * The checking has to be done by the user of the stack.
 * + easy to implement
 * + the functions work for more than one stack
 *
 * powershell: cls; gcc stack_02.c -o run.exe; .\run.exe
 * bash:       clear; gcc stack_02.c -o run.out; .\run.out
 */

#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
// In case of override a stack overflow occurs
#define MAX_SIZE 3

// Define the stack structure
typedef struct stack {
	int items[MAX_SIZE];
	int counter;
} stack_t;

// The function prototypes for the stack
void init(stack_t* s);
int isEmpty(stack_t* s);
int isFull(stack_t* s);
void push(stack_t* s, int x);
int pop(stack_t* s);
int peek(stack_t* s);

int main() {
	// Declare and intialize a variable holding the stack
	stack_t s;
	init(&s);

	int x = 10;

	// Check if the stack is empty
	if (isEmpty(&s)) {
		printf("The stack is empty.\n");
	} else {
		printf("The stack is not empty.\n");
	}

	// Push the first element on the stack
	if (!isFull(&s)) {
		printf("Push %i.\n", x);
		push(&s, x);
	} else {
		printf("The stack is , cafullnnot push %i.\n", x);
	}

	// Peek the top element
	if (!isEmpty(&s)) {
		printf("Peek %i.\n", peek(&s));
	} else {
		printf("The stack is empty, cannot peek.\n");
	}

	// Push further elements on the stack
	for (x = 20; x <= 40; x+=10) {
		if (!isFull(&s)) {
			printf("Push %i.\n", x);
			push(&s, x);
		} else {
			printf("The stack is full, cannot push %i.\n", x);
		}
	}

	// Peek the top element
	if (!isEmpty(&s)) {
		printf("Peek %i.\n", peek(&s));
	} else {
		printf("The stack is empty, cannot peek.\n");
	}

	// Pop elements from the stack until it is empty
	while (!isEmpty(&s)) {
		printf("Pop %i.\n", pop(&s));
	}

	// Check if the stack is empty
	if (isEmpty(&s)) {
		printf("The stack is empty.\n");
	} else {
		printf("The stack is not empty.\n");
	}

	return EXIT_SUCCESS;
}

// Function to initialize the stack
void init(stack_t* s) {
	s->counter = -1; // Initialize the top index to -1 (empty stack)
}

// Function to check if the stack is empty
int isEmpty(stack_t* s) {
	return s->counter == -1;
}

// Function to check if the stack is full
int isFull(stack_t* s) {
	return s->counter == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(stack_t* s, int x) {
	s->items[++s->counter] = x;
}

// Function to pop an element from the stack
int pop(stack_t* s) {
	return s->items[s->counter--];
}

// Function to peek at the top element of the stack without removing it
int peek(stack_t* s) {
	return s->items[s->counter];
}
