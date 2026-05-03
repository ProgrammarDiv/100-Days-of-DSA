#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

// Add edge to an undirected graph
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Depth First Search to mark all reachable nodes
void dfs(int u, struct Node* adj[], bool visited[]) {
    visited[u] = true;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(temp->dest, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Adjacency list and visited array
    struct Node* adj[n + 1];
    bool visited[n + 1];
    for (int i = 0; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int components = 0;

    // Iterate through all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++; // New component found
            dfs(i, adj, visited); // Mark all nodes in this component
        }
    }

    printf("%d\n", components);

    return 0;
}