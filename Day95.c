#include <stdio.h>
#include <stdlib.h>

// Node for the linked list in each bucket
struct Node {
    float data;
    struct Node* next;
};

// Function to insert a node into a linked list in sorted order (Insertion Sort)
struct Node* sortedInsert(struct Node* head, float val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // Case 1: Empty list or value smaller than head
    if (head == NULL || val < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Case 2: Traverse to find correct position
    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data < val) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // 2. Put elements into different buckets based on range
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Map [0,1) to bucket index [0, n-1]
        buckets[bucketIndex] = sortedInsert(buckets[bucketIndex], arr[i]);
    }

    // 3. Concatenate all buckets into original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Free memory
        }
    }
    free(buckets);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    float* arr = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.4f", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    free(arr);
    return 0;
}