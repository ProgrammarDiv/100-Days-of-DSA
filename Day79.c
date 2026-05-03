#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int v, weight;
} Edge;

typedef struct Node {
    int dest, weight;
    struct Node* next;
} Node;

typedef struct {
    int vertex, dist;
} HeapNode;

// Adjacency list add function
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min-Heap Functions
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode heap[], int size, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < size && heap[left].dist < heap[smallest].dist) smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void push(HeapNode heap[], int* size, int v, int d) {
    heap[*size].vertex = v;
    heap[*size].dist = d;
    int i = (*size)++;
    while (i != 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(HeapNode heap[], int* size) {
    HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
    return root;
}

int main() {
    int n, m, source;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node* adj[n + 1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w); // Remove if graph is directed
    }
    scanf("%d", &source);

    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;

    HeapNode* heap = (HeapNode*)malloc(m * 10 * sizeof(HeapNode));
    int heapSize = 0;
    push(heap, &heapSize, source, 0);

    while (heapSize > 0) {
        HeapNode top = pop(heap, &heapSize);
        int u = top.vertex;

        if (top.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            if (dist[u] != INF && dist[u] + temp->weight < dist[temp->dest]) {
                dist[temp->dest] = dist[u] + temp->weight;
                push(heap, &heapSize, temp->dest, dist[temp->dest]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d%s", dist[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}