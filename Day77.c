#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

// Global variables for simplicity in recursion
struct Node* adj[100005];
bool visited[100005];
int visited_count = 0;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int u) {
    visited[u] = true;
    visited_count++;
    
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(temp->dest);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Edge case: A graph with no nodes (though constraints usually say n >= 1)
    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    // Initialize adjacency list
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Ensure indices are within bounds
        if (u <= n && v <= n) addEdge(u, v);
    }

    // Start DFS from node 1
    dfs(1);

    // If we visited all n nodes, it's connected
    if (visited_count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}