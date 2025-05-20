#include <stdio.h>
#include <limits.h>
#define MAX 10 // maximum number of cities

int graph[MAX][MAX] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};
int visited[MAX];
int minCost = INT_MAX;
int cityCount = 4; // pre-defined number of cities

void tsp(int currentCity, int count, int cost, int startCity)
{
    // Base case: if all cities are visited
    if (count == cityCount)
    {
        cost += graph[currentCity][startCity]; // return to start
        if (cost < minCost)
        {
            minCost = cost;
        }
        return;
    }
    // Try all unvisited cities
    for (int nextCity = 0; nextCity < cityCount; nextCity++)
    {
        if (!visited[nextCity] && graph[currentCity][nextCity] > 0)
        {
            visited[nextCity] = 1;
            tsp(nextCity, count + 1, cost + graph[currentCity][nextCity], startCity);
            visited[nextCity] = 0; // backtrack
        }
    }
}
int main()
{
    for (int i = 0; i < cityCount; i++)
    {
        visited[i] = 0; // mark all as unvisited
    }

    int startCity = 0;

    visited[startCity] = 1; // start from city 0
    tsp(startCity, 1, 0, startCity);
    printf("Shortest path cost: %d\n", minCost);

    return 0;
}