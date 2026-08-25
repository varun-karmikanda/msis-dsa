#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 7

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialze(Queue *queue){
    queue -> front = 0;
    queue -> rear = -1;
}

bool isEmpty(Queue *queue) {
    if(queue -> rear == -1 || queue -> front > queue -> rear) return true;
    return false;
}

bool isFull(Queue *queue) {
    if(queue -> rear == MAX_SIZE - 1) return true;
    return false;
}

void enqueue(Queue *queue, int value) {
    if(isFull(queue)) {
        printf("\nQueue is full!!");
        return;
    }
    queue -> arr[++queue -> rear] = value;
    printf("\nElement %d added successfully!", value);
}

void dequeue(Queue *queue) {
    if(isEmpty(queue)) {
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nElement %d deleted successfully!", queue -> arr[queue -> front]);
    queue -> front++;
}

int peek(Queue *queue) {
    if(isEmpty(queue)) {
        printf("\nQueue is empty!!");
        return -1;
    }
    return queue -> arr[queue -> front];
}

int peekRear(Queue *queue) {
    if(isEmpty(queue)) {
        printf("\nQueue is empty!!");
        return -1;
    }
    return queue -> arr[queue -> rear];
}

void displayQueue(Queue *queue) {
    printf("\nQUEUE {");

    for(int i = queue -> front; i <= queue -> rear; i++) {
        printf("\n\tqueue[%d] = %d", i, queue -> arr[i]);
    }

    printf("\n}");
}

int main() {
    Queue queue;

    initialze(&queue);

    enqueue(&queue, 67);
    enqueue(&queue, 51);
    enqueue(&queue, 95);
    enqueue(&queue, 63);
    enqueue(&queue, 44);
    enqueue(&queue, 81);
    enqueue(&queue, 55);
    enqueue(&queue, 0);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    int peekFrontEle = peek(&queue);
    printf("\nPEAK VALUE = %d", peekFrontEle);

    int peekRearEle = peekRear(&queue);
    printf("\nPEAK VALUE = %d", peekRearEle);

    displayQueue(&queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}