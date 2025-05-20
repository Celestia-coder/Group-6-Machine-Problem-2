#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

void optimizedSelectionSort(int arr[], int size);
void printArr(int arr[], int size);
void swap(int *a, int *b);

int main() {
    // int size;
    // printf("Enter array size: ");
    // scanf("%d", &size);
    // int arr[size];
    // for (int i = 0; i < size; i++) {
    //     printf("Enter element: ");
    //     scanf("%d", &arr[i]);
    // }

    // Predefined array (for testing)
    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 0};
    int size = 10;


    printf("\nBEFORE SORTING:\n");
    printArr(arr, size);

    printf("\nOPTIMIZED SELECTION SORT:\n");
    optimizedSelectionSort(arr, size);
    printArr(arr, size);

    getch();
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void optimizedSelectionSort(int arr[], int size) {
    // Early check for already sorted array
    bool isSorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    if (isSorted) {
        printf("Array already sorted. No operations needed.\n");
        return;
    }

    // Use insertion sort for small arrays
    if (size < 10) {
        printf("Using insertion sort for small array.\n");
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }

    int swapCount = 0;
    int comparisonCount = 0;
    int passCount = 0;
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;
        passCount++;

        // Find min and max in one pass with reduced comparisons
        for (int i = start; i <= end; i++) {
            comparisonCount++;
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            } else if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // Swap min with start
        if (minIndex != start && arr[minIndex] != arr[start]) {
            swap(&arr[start], &arr[minIndex]);
            swapCount++;
            if (maxIndex == start)
                maxIndex = minIndex;
        }

        // Swap max with end
        if (maxIndex != end && arr[maxIndex] != arr[end]) {
            swap(&arr[end], &arr[maxIndex]);
            swapCount++;
        }

        start++;
        end--;
    }

    printf("Swap Count: %d\n", swapCount);
    printf("Comparison Count: %d\n", comparisonCount);
    printf("Pass Count: %d\n", passCount);
}
