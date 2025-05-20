#include <stdio.h>
#include <stdbool.h>
void optimizedSelectionSort(int arr[], int size);
void printArr(int arr[], int size);
void swap(int *a, int *b);
int main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    // PREDEFINED ARRAY
    // int arr[]= {5, 7, 2, 4, 9, 3, 1, 6, 8};
    // int size = 10;
    printf("\nBEFORE SORTING:\n");
    printArr(arr, size);
    printf("\nOPTIMIZED SELECTION SORT:\n");
    optimizedSelectionSort(arr, size);
    printArr(arr, size);
    return 0;
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void optimizedSelectionSort(int arr[], int size)
{
    int swapCount = 0;
    int comparisonCount = 0;
    int passCount = 0;
    int start = 0;

    int end = size - 1;
    while (start < end)
    {
        int minIndex = start;
        int maxIndex = start;
        passCount++;
        // Find min and max in one pass
        for (int i = start; i <= end; i++)
        {
            comparisonCount += 2;
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }
        // Swap min with start
        if (minIndex != start)
        {
            swap(&arr[start], &arr[minIndex]);
            swapCount++;
            // If maxIndex was at start, it moved with min, update it
            if (maxIndex == start)
                maxIndex = minIndex;
        }
        // Swap max with end
        if (maxIndex != end)
        {
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