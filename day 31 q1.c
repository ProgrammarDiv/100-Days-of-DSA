#include <stdio.h>
#include 

#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, op, value;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {
            int popped = pop();
            if (popped != -1) {
                printf("%d\n", popped);
            }
        } else if (op == 3) {
            display();
        }
    }
    
    return 0;
}
