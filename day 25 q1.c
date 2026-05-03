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

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    
    return count;
}

int main() {
    int n, value, key;
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
    
    scanf("%d", &key);
    printf("%d\n", countOccurrences(head, key));
    return 0;
}
