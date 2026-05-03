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

struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
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
    int n, m, value;
    struct Node *list1 = NULL, *list2 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list1 == NULL) {
            list1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list2 == NULL) {
            list2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    
    struct Node* merged = mergeSortedLists(list1, list2);
    printList(merged);
    return 0;
}
