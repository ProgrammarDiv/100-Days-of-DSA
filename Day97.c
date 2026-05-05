#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Compare function to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Simple Min-Heap structure for end times
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

void insertHeap(int heap[], int* size, int value) {
    heap[*size] = value;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n == 0) { printf("0\n"); return 0; }

    Interval intervals[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    // 1. Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Min-Heap stores the end times of meetings currently in rooms
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    // Add the first meeting's end time
    insertHeap(heap, &heapSize, intervals[0].end);

    for (int i = 1; i < n; i++) {
        // If the room with the earliest end time is free
        if (intervals[i].start >= heap[0]) {
            // Reuse the room: remove the old end time
            heap[0] = heap[heapSize - 1];
            heapSize--;
            minHeapify(heap, heapSize, 0);
        }
        
        // Add current meeting's end time (either to a new room or reused)
        insertHeap(heap, &heapSize, intervals[i].end);
    }

    // The size of the heap represents the rooms needed
    printf("%d\n", heapSize);

    free(heap);
    return 0;
}