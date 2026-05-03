#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
