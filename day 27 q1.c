#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    // Advance longer list
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            ptr2 = ptr2->next;
        }
    }
    
    // Find intersection
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return NULL;
}
