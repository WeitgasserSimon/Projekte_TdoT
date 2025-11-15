#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int array[10];
	int cnt;
}queue;

void enqueue(queue* q, int value){
	if(q->cnt == 10){
		return;
	}
	q->array[cnt] = value;
	q->cnt++;
}

int dequeue(queue* q){
	if(q->cnt == 0){
		return -1;
	}
	int val = q->array[0];
	int i;
	for( i = 0; i <q->cnt;i++){
		q->array[i] = q->array[i+1];
	}
	q->cnt--;
	return val;
}

int main(int argc, char const *argv[]){
	
	queue q1;
	q1.cnt = 0;
	
	enqueue(&q1, 5);
	enqueue(&q1, 7);
	enqueue(&q1, 3);
	
	printf("%d ", deque(&q1));
	return 0;
}
