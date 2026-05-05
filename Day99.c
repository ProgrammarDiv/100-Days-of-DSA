#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

// Sort cars by position in descending order (closest to target first)
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

int countCarFleets(int target, int position[], int speed[], int n) {
    if (n == 0) return 0;

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        // Time = (Distance to target) / Speed
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // 1. Sort cars by position descending
    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double slowestTimeSoFar = 0.0;

    // 2. Iterate through cars
    for (int i = 0; i < n; i++) {
        // If the current car takes MORE time than the fleet in front of it,
        // it cannot catch up. Therefore, it starts a NEW fleet.
        if (cars[i].time > slowestTimeSoFar) {
            fleets++;
            slowestTimeSoFar = cars[i].time;
        }
        // If current car's time <= slowestTimeSoFar, it catches up 
        // and becomes part of the existing fleet.
    }

    free(cars);
    return fleets;
}

int main() {
    int target, n;
    if (scanf("%d %d", &target, &n) != 2) return 0;

    int* pos = (int*)malloc(n * sizeof(int));
    int* speed = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &pos[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    printf("%d\n", countCarFleets(target, pos, speed, n));

    free(pos);
    free(speed);
    return 0;
}