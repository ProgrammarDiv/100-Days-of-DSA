#include <stdio.h>
#include <stdlib.h>
#include 

int compare(const void* a, const void* b) {
    return ((int)a - (int)b);
}

int main() {
    int n;
    int arr[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);
    
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int resLeft = 0, resRight = 0;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            resLeft = arr[left];
            resRight = arr[right];
        }
        
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    printf("%d %d\n", resLeft, resRight);
    return 0;
}
