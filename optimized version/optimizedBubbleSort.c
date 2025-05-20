#include <stdio.h>
#include <stdbool.h>

void optimizedBubbleSort(int arr[], int size);
void swap(int *a, int *b);
void printArr(int arr[], int size);

int main() {
    // USER INPUT
    // int size;

    // printf("Enter array size: ");
    // scanf("%d", &size);

    // int arr[size];

    // for (int i = 0; i < size; i++) {
    //     printf("Enter element: ");
    //     scanf("%d", &arr[i]);
    // }

    // PREDEFINED ARRAY (for testing without user input)
    int arr[] = {1, 4, 8, 0, 2, 3, 9, 5, 7, 6};
    int size = 10;

    // Print array before sorting
    printf("\nBEFORE SORTING:\n");
    printArr(arr, size);
    printf("\n");

    // Run optimized bubble sort function
    printf("OPTIMIZED BUBBLE SORT:\n");
    optimizedBubbleSort(arr, size);
    printArr(arr, size);
    printf("\n");

    return 0;
}

// Print the array
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Swaps elements
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Optimized bubble sort
void optimizedBubbleSort(int arr[], int size) {
    int passCount = 0;         
    int swapCount = 0;        
    int comparisonCount = 0;

    // While loop controls the number of passes through the array
    while (size > 0) {
        int lastSwapIndex = 0; // Stores the index of the last swapped element
        bool swapped = false; // Tracks if a swap occurred during this pass

        passCount++;

        // For loop handles the comparisons and swaps
        for (int i = 0; i < size - 1; i++) {
            comparisonCount++;

            // Swap adjacent elements if they are in the wrong order
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapCount++;
                swapped = true;

                lastSwapIndex = i + 1; // Update new limit for the next pass
            }
        }

        // Stop if no swaps occurred (already sorted)
        if (!swapped) {
            break; 
        }

        size = lastSwapIndex; // Reduce the range for next pass
    }

    // Print final counts (swaps, comparisons, and passes)
    printf("Swap Count: %d\n", swapCount);
    printf("Comparison Count: %d\n", comparisonCount);
    printf("Pass Count: %d\n", passCount);
}
