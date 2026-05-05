#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int original_idx;
} Element;

void merge(Element arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Element* L = (Element*)malloc(n1 * sizeof(Element));
    Element* R = (Element*)malloc(n2 * sizeof(Element));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    int right_smaller_count = 0;
    
    while (i < n1 && j < n2) {
        if (R[j].value < L[i].value) {
            // Element from right is smaller. 
            // This element will be to the right of all remaining L elements.
            right_smaller_count++;
            arr[k++] = R[j++];
        } else {
            // Element from left is moved.
            // It is larger than 'right_smaller_count' elements processed so far from R.
            count[L[i].original_idx] += right_smaller_count;
            arr[k++] = L[i++];
        }
    }
    
    // Clean up remaining elements
    while (i < n1) {
        count[L[i].original_idx] += right_smaller_count;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
    
    free(L);
    free(R);
}

void solve(Element arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        solve(arr, left, mid, count);
        solve(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    Element* arr = (Element*)malloc(n * sizeof(Element));
    int* count = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].original_idx = i;
    }
    
    solve(arr, 0, n - 1, count);
    
    for (int i = 0; i < n; i++) {
        printf("%d", count[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    free(arr);
    free(count);
    return 0;
}