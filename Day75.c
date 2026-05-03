#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100003

typedef struct {
    int key;   // The prefix sum
    int value; // The first index where this sum occurred
    int occupied;
} HashEntry;

HashEntry hash_table[TABLE_SIZE];

int hash(int key) {
    int h = key % TABLE_SIZE;
    return (h < 0) ? h + TABLE_SIZE : h;
}

void insert(int key, int index) {
    int h = hash(key);
    while (hash_table[h].occupied) {
        if (hash_table[h].key == key) return; // Only store the FIRST occurrence
        h = (h + 1) % TABLE_SIZE;
    }
    hash_table[h].key = key;
    hash_table[h].value = index;
    hash_table[h].occupied = 1;
}

int find(int key) {
    int h = hash(key);
    while (hash_table[h].occupied) {
        if (hash_table[h].key == key) return hash_table[h].value;
        h = (h + 1) % TABLE_SIZE;
    }
    return -2; // Not found
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (prefix_sum == 0) {
            max_len = i + 1;
        } else {
            int prev_index = find(prefix_sum);
            if (prev_index != -2) {
                int current_len = i - prev_index;
                if (current_len > max_len) max_len = current_len;
            } else {
                insert(prefix_sum, i);
            }
        }
    }

    printf("%d\n", max_len);
    return 0;
}