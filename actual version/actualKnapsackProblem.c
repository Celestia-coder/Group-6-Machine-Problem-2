#include <stdio.h>
#include <stdlib.h>

// a function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// a recursive function that solves the knapsack problem 
int recursiveKnapsack(int W, int val[], int wt[], int n) {
	// base case, meaning, no items left or no remaining capacity 
    if (n == 0 || W == 0)
        return 0;

    int include = 0;
    // if the weight of the current item is less than or equal to remaining capacity, we can choose to include it 
    if (wt[n - 1] <= W)
        include = val[n - 1] + recursiveKnapsack(W - wt[n - 1], val, wt, n - 1);

	// an option to exclude the current item
    int exclude = recursiveKnapsack(W, val, wt, n - 1);

	// return maximum value between including and excluding the item 
    return max(include, exclude);
}

// a wrapper function for the recursive solution
int knapsack(int W, int val[], int wt[], int n) {
    return recursiveKnapsack(W, val, wt, n);
}

int main() {
    int n, W;

	printf("-------------------------------------\n");
	printf("|       Actual Knapsack Solver      |\n");
	printf("-------------------------------------\n"); 
	
	
    printf("\nKindly enter the number of items: ");
    scanf("%d", &n);

    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));

    printf("\nKindly enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("\nKindly enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("\nKindly enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

	// call the knapsack wrapper function and store the result
    int result = knapsack(W, val, wt, n);
    printf("\nMaximum value in knapsack of capacity W = %d\n", result);

	// free the allocated memory 
    free(val);
    free(wt);

    return 0;
}