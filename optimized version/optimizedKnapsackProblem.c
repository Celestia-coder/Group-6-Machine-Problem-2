#include <stdio.h>
#include <stdlib.h>

// a function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// a function that solves the knapsack problem and tracks which items are selected
int optimizedKnapsack(int W, int val[], int wt[], int n, int selected[]) {
	// dp (dynamic program) array stores the maximum value that can be achieved for every knapsack capacity from 0 to W
    int *dp = (int *)calloc(W + 1, sizeof(int)); // calloc (contiguous allocation) allocates memory and automatically sets all values to zero
    int *keep = (int *)calloc(W + 1, sizeof(int)); // not really used but reserved
    
    // itemUsed keeps track of which items are included in the optimal solution
    int **itemUsed = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        itemUsed[i] = (int *)calloc(W + 1, sizeof(int));
    }

	// loop through all items 
    for (int i = 0; i < n; i++) {
    	// loop from max capacity down to the weight of current item
        for (int w = W; w >= wt[i]; w--) {
        	// if including item i gives a better value, take it
            if (dp[w] < dp[w - wt[i]] + val[i]) {
                dp[w] = dp[w - wt[i]] + val[i];
                itemUsed[i + 1][w] = 1; // mark that item i was used for this capacity
            }
        }
    }

    int w = W;
    // backtrack to find which items were included
    for (int i = n; i > 0; i--) {
        if (itemUsed[i][w]) {
            selected[i - 1] = 1; // mark the item as selected
            w -= wt[i - 1]; // reduce remaining capacity
        }
    }

    int result = dp[W];

	// free memory 
    free(dp);
    free(keep);
    for (int i = 0; i <= n; i++) {
        free(itemUsed[i]);
    }
    free(itemUsed);

    return result;
}

int main() {
    int n, W;

   printf("-------------------------------------\n");
    printf("|     Optimized Knapsack Solver     |\n");
    printf("-------------------------------------\n");

    printf("\nKindly enter the number of items: ");
    scanf("%d", &n);

    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));
    int *selected = (int *)calloc(n, sizeof(int));

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

	// call the knapsack function to compute the result 
    int result = optimizedKnapsack(W, val, wt, n, selected);

    printf("\nMaximum value in knapsack of capacity W = %d\n", result);
    printf("Items that are selected (1-based index): ");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

	// free allocated memory 
    free(val);
    free(wt);
    free(selected);

    return 0;
}