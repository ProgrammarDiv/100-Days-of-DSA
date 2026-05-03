#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int count;
} CircularQueue;

CircularQueue* createQueue(int n) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->size = n;
    q->arr = (int*)malloc(sizeof(int) * n);
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    if (q->count == q->size) return;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
    q->count++;
}

void dequeue(CircularQueue* q) {
    if (q->count == 0) return;
    q->front = (q->front + 1) % q->size;
    q->count--;
}

void display(CircularQueue* q) {
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % q->size]);
    }
}

int main() {
    int n, m, x;
    scanf("%d", &n);

    CircularQueue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    free(q->arr);
    free(q);
    return 0;
}
