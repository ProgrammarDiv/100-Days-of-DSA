#include <stdio.h>

/**
 * Check if it's possible to paint all boards within 'timeLimit' 
 * using 'k' painters.
 */
int canPaint(int boards[], int n, int k, int timeLimit) {
    int paintersUsed = 1;
    int currentTimeSpent = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than the time limit, impossible
        if (boards[i] > timeLimit) return 0;

        if (currentTimeSpent + boards[i] <= timeLimit) {
            currentTimeSpent += boards[i];
        } else {
            // Assign this board to a new painter
            paintersUsed++;
            currentTimeSpent = boards[i];

            // If we exceed the number of available painters
            if (paintersUsed > k) return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    long long totalLength = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        totalLength += boards[i];
        if (boards[i] > maxLength) maxLength = boards[i];
    }

    // Binary Search on the Answer (Time)
    long long low = maxLength; // Minimum possible time is the longest board
    long long high = totalLength; // Maximum possible time is one painter doing everything
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, (int)mid)) {
            ans = mid;        // This time works, try to find a smaller (better) time
            high = mid - 1;
        } else {
            low = mid + 1;    // Need more time to accommodate all boards with k painters
        }
    }

    printf("%lld\n", ans);

    return 0;
}