#include <stdio.h>

void actualBubbleSort(int arr[], int size);
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

    // Run actual bubble sort function
    printf("ACTUAL BUBBLE SORT:\n");
    actualBubbleSort(arr, size);
    printArr(arr, size);
    printf("\n");

    return 0;
}

// Prints the array
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Actual Bubble Sort
void actualBubbleSort(int arr[], int size) {
    int passCount = 0;         
    int swapCount = 0;        
    int comparisonCount = 0;  

    // Outer loop controls the number of passes through the array
    for (int i = 0; i < size - 1; i++) {
        passCount++;  

        // Inner loop handles the comparisons and swaps
        for (int j = 0; j < size - 1 - i; j++) {  
            comparisonCount++;  

            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapCount++; 
            }
        }
    }

    // Print final counts (swaps, comparisons, and passes)
    printf("Swap Count: %d\n", swapCount);
    printf("Comparison Count: %d\n", comparisonCount);
    printf("Pass Count: %d\n", passCount);
}
