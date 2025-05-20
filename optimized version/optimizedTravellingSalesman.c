#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10

int distance[MAX][MAX];
int n; // number of cities
int startCity = 0;
int bestCost = INT_MAX;
bool visited[MAX];

// Nearest Neighbor to estimate shortest path
int nearestNeighborEstimate() {
    bool tempVisited[MAX] = {false};
    int current = startCity;
    int totalCost = 0;

    tempVisited[current] = true;

    for (int step = 1; step < n; step++) {
        int nearest = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!tempVisited[i] && distance[current][i] < minDist) {
                minDist = distance[current][i];
                nearest = i;
            }
        }

        totalCost += minDist;
        current = nearest;
        tempVisited[current] = true;
    }

    totalCost += distance[current][startCity]; // return to start
    return totalCost;
}

// Optimized recursive TSP with pruning
void tsp(int currentCity, int count, int currentCost) {
    if (count == n) {
        currentCost += distance[currentCity][startCity]; // return to start
        if (currentCost < bestCost) {
            bestCost = currentCost;
        }
        return;
    }

    if (currentCost >= bestCost) return; // prune bad paths

    for (int next = 0; next < n; next++) {
        if (!visited[next]) {
            visited[next] = true;
            tsp(next, count + 1, currentCost + distance[currentCity][next]);
            visited[next] = false;
        }
    }
}

int main() {
    printf("Enter number of cities: "); // user-defined
    scanf("%d", &n);

    printf("Enter the distance matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &distance[i][j]);

    bestCost = nearestNeighborEstimate(); // initialize with an estimate

    visited[startCity] = true;
    tsp(startCity, 1, 0);

    printf("\nOptimized TSP shortest path cost: %d\n", bestCost);

    return 0;
}