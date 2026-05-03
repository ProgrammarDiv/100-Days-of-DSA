#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0) return head;
    
    // Find length and last node
    int length = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    
    k = k % length;
    if (k == 0) return head;
    
    // Find new tail
    struct Node* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }
    
    struct Node* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    
    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value, k;
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
            tail = newNode;
        }
    }
    
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}
