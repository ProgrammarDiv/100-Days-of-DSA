#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" ");
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    printForward(head);
    return 0;
}
