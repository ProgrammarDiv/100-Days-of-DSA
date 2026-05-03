#include <stdio.h>

#define INF 1e9 // Using a large value to represent infinity

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int dist[n][n];

    // Step 1: Read Input and Initialize Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            scanf("%d", &weight);
            if (i == j) {
                dist[i][j] = 0;
            } else if (weight == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = weight;
            }
        }
    }

    // Step 2: Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) { // Intermediate vertex
        for (int i = 0; i < n; i++) { // Source vertex
            for (int j = 0; j < n; j++) { // Destination vertex
                // Only update if k provides a path between i and j
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Step 3: Print Output Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("-1%s", (j == n - 1) ? "" : " ");
            } else {
                printf("%d%s", dist[i][j], (j == n - 1) ? "" : " ");
            }
        }
        printf("\n");
    }

    return 0;
}