#include <stdio.h>

// Function to check if it's possible to allocate books such that 
// no student gets more than 'maxPagesAllowed'
int isPossible(int arr[], int n, int m, int maxPagesAllowed) {
    int studentsCount = 1;
    int currentPagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than our limit, it's impossible
        if (arr[i] > maxPagesAllowed) return 0;

        if (currentPagesSum + arr[i] <= maxPagesAllowed) {
            currentPagesSum += arr[i];
        } else {
            // Assign this book to the next student
            studentsCount++;
            currentPagesSum = arr[i];
            
            // If we need more students than available, return false
            if (studentsCount > m) return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int books[n];
    int sum = 0;
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        sum += books[i];
        if (books[i] > maxVal) maxVal = books[i];
    }

    // If students are more than books, allocation is impossible 
    // (since each student needs at least one book)
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    // Binary Search Range:
    // low: The largest single book (minimum possible max pages)
    // high: Sum of all books (if one student takes everything)
    int low = maxVal;
    int high = sum;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;      // This limit works, try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;  // Limit is too small, increase it
        }
    }

    printf("%d\n", ans);

    return 0;
}