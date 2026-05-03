#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int freq[1001] = {0}; 
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }
    
    
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > 0) {
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0; 
        }
    }
    printf("\n");
    
    return 0;
}
