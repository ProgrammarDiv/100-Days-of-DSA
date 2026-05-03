#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparison function for qsort to sort strings lexicographically
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for n strings
    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = (char *)malloc(100 * sizeof(char)); // Assume max name length 100
        scanf("%s", votes[i]);
    }

    // Step 1: Sort the names
    qsort(votes, n, sizeof(char *), compareStrings);

    // Step 2: Count frequencies in the sorted list
    char *winner = votes[0];
    int max_votes = 0;
    
    int current_count = 0;
    for (int i = 0; i < n; i++) {
        current_count++;

        // If we reach the end of the array or the next name is different
        if (i == n - 1 || strcmp(votes[i], votes[i + 1]) != 0) {
            if (current_count > max_votes) {
                max_votes = current_count;
                winner = votes[i];
            } 
            // Note: Because the array is sorted, the first name encountered 
            // during a tie-break is naturally the lexicographically smallest.
            else if (current_count == max_votes) {
                if (strcmp(votes[i], winner) < 0) {
                    winner = votes[i];
                }
            }
            current_count = 0; // Reset for next unique name
        }
    }

    printf("%s %d\n", winner, max_votes);

    // Free memory
    for (int i = 0; i < n; i++) free(votes[i]);
    free(votes);

    return 0;
}