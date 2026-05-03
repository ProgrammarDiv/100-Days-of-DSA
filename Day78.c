#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

// Structure for Adjacency List Node
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

// Add edge to undirected weighted graph
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = u;
    newNode->weight = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n + 1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int key[n + 1];      // Min weight to reach node
    bool inMST[n + 1];   // Track nodes included in MST
    for (int i = 0; i <= n; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    // Start Prim's from Node 1
    key[1] = 0;
    long long totalWeight = 0;

    for (int count = 0; count < n; count++) {
        // Pick the minimum key vertex not yet in MST
        int minKey = INF, u = -1;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // If no vertex can be added, graph is disconnected
        if (u == -1) break;

        inMST[u] = true;
        totalWeight += key[u];

        // Update neighbors
        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->dest;
            int w = temp->weight;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    printf("%lld\n", totalWeight);

    return 0;
}