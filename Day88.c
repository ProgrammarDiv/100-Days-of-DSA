#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort stall positions
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if it is possible to place k cows with at least 'dist' gap
int canPlaceCows(int arr[], int n, int k, int dist) {
    int count = 1; // Place the first cow in the first stall
    int last_position = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last_position >= dist) {
            count++;
            last_position = arr[i]; // Place next cow here
            if (count >= k) return 1; // Successfully placed all cows
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary Search on the answer (distance)
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;     // This distance works, save it...
            low = mid + 1; // ...and try to find a larger one
        } else {
            high = mid - 1; // Too far apart, need to reduce distance
        }
    }

    printf("%d\n", ans);

    return 0;
}