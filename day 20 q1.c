#include <stdio.h>

int main() {
    int n;
    int arr[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int count = 0;
    
    // Brute force: check all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}
