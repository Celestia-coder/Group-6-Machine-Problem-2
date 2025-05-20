#include <stdio.h>
#include <conio.h>

void basicSelectionSort(int arr[], int size);
void printArr(int arr[], int size);

int main() {
    // int size;

    // printf("Enter array size: ");
    // scanf("%d", &size);

    // int arr[size];

    // for (int i = 0; i < size; i++) {
    //     printf("Enter element: ");
    //     scanf("%d", &arr[i]);
    // }

    // PREDEFINED ARRAY FOR QUICK TESTING
    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 0};
    int size = 10;

    printf("\nBEFORE SORTING:\n");
    printArr(arr, size);

    printf("\nBASIC SELECTION SORT:\n");
    basicSelectionSort(arr, size);

    printArr(arr, size);

    getch();
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void basicSelectionSort(int arr[], int size) {
    int comparisonCount = 0;
    int swapCount = 0;
    int passCount = 0;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        passCount++;

        for (int j = i + 1; j < size; j++) {
            comparisonCount++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount++;
        }
    }

    printf("Swap Count: %d\n", swapCount);
    printf("Comparison Count: %d\n", comparisonCount);
    printf("Pass Count: %d\n", passCount);
}