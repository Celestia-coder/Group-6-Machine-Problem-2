#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10

int distance[MAX][MAX] = {
    {0, 10, 100, 20, 80},
    {10, 0, 90, 25, 70},
    {100, 90, 0, 30, 60},
    {20, 25, 30, 0, 50},
    {80, 70, 60, 50, 0}
};

int n = 5; // number of cities
int startCity = 0;
int bestCost = INT_MAX;
bool visited[MAX];

// (for optimization demonstration)
int totalPathsChecked = 0;
int completePathsChecked = 0;
int prunedPaths = 0;

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
    totalPathsChecked++; // count every recursive call

    if (count == n) {
        completePathsChecked++; // count complete tours
        currentCost += distance[currentCity][startCity]; // return to start
        if (currentCost < bestCost) {
            bestCost = currentCost;
        }
        return;
    }

    if (currentCost >= bestCost) {
        prunedPaths++; // count pruned paths
        return; // prune bad paths
    }

    for (int next = 0; next < n; next++) {
        if (!visited[next]) {
            visited[next] = true;
            tsp(next, count + 1, currentCost + distance[currentCity][next]);
            visited[next] = false;
        }
    }
}

int main() {
    bestCost = nearestNeighborEstimate(); // initialize with an estimate

    visited[startCity] = true;
    tsp(startCity, 1, 0);

    printf("\nOptimized TSP shortest path cost: %d\n", bestCost);
    printf("Total recursive calls: %d\n", totalPathsChecked);
    printf("Completed paths (full tours): %d\n", completePathsChecked);
    printf("Paths pruned early: %d\n", prunedPaths);

    return 0;
}