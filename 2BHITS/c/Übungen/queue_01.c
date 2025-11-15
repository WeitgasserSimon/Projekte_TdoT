/**
 * @file    queue_01.c
 * @brief	Implementation of a queue as data structure
 * @author  Lothar Schäfer (lothar.schaefer@htl-salzburg.ac.at)
 * @date	2023-09-21
 *
 * The queue is implemented with a data structure containing an array of MAX_SIZE elements.
 * The empty stack is signaled with counter == -1
 * The checking has to be done by the user of the stack.
 * + easy to implement
 * + the functions work for more than one stack
 *
 * powershell: cls; gcc queue_01.c -o run.exe; .\run.exe
 * bash:       clear; gcc queue_01.c -o run.out; .\run.out
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef struct queue {
	int items[MAX_SIZE];
	int counter;
} queue_t;

void init(queue_t *q);
int isEmpty(queue_t *q);
int isFull(queue_t *q); 
void enqueue(queue_t *q, int x);
int dequeue(queue_t *q);
int peek(queue_t *q);

int main() {
	queue_t q;
	init(&q);

	int x = 10;

	// Check if the queue is empty
	if (isEmpty(&q)) {
		printf("The queue is empty.\n");
	} else {
		printf("The queue is not empty.\n");
	}

	// Enqueue the first element
	if (!isFull(&q)) {
		printf("Enqueue %i.\n", x);
		enqueue(&q, x);
	} else {
		printf("The queue is full, cannot enqueue %i.\n", x);
	}

	// Peek the next element
	if (!isEmpty(&q)) {
		printf("Peek %i.\n", peek(&q));
	} else {
		printf("The queue is empty, cannot peek.\n");
	}

	// Enqueue further elements
	for (x = 20; x <= 40; x+=10) {
		if (!isFull(&q)) {
			printf("Enqueue %i.\n", x);
			enqueue(&q, x);
		} else {
			printf("The queue is full, cannot enqueue %i.\n", x);
		}
	}

	// Peek the next element
	if (!isEmpty(&q)) {
		printf("Peek %i.\n", peek(&q));
	} else {
		printf("The queue is empty, cannot peek.\n");
	}

	// Dequeue elements from the queue until it is empty
	while (!isEmpty(&q)) {
		printf("Dequeue %i.\n", dequeue(&q));
	}

	// Check if the queue is empty
	if (isEmpty(&q)) {
		printf("The queue is empty.\n");
	} else {
		printf("The queue is not empty.\n");
	}

	return 0;
}

void init(queue_t *q) {
	q->counter = -1;
}

int isEmpty(queue_t *q) {
	return q->counter == -1;
}

int isFull(queue_t *q) {
	return q->counter == MAX_SIZE - 1;
}

void enqueue(queue_t *q, int x) {
	q->items[++q->counter] = x;
}

int dequeue(queue_t *q) {
	int x = q->items[0];
	int i;
	for ( i = 1; i < q->counter; i++) {
		printf("%i <- %i\n", i-1, i);	
		q->items[i - 1] = q->items[i];
	}
	q->counter--;
	return x;
}

int peek(queue_t *q) {
	return q->items[0];
}
