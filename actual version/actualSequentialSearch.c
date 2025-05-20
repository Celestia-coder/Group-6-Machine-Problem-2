#include <stdio.h>

int actualSequentialSearch(int arr[], int size, int key, int *passes);

int main()
{
    // USER INPUT
    /*
        int size, key, passes = 0;

        printf("Enter array size: ");
        scanf("%d", &size);

        int arr[size];
        int i;
        for (i = 0; i < size; i++) {
            printf("Enter element at index %d: ", i);
            scanf("%d", &arr[i]);
        }

        printf("Enter the key to be searched: ");
        scanf("%d", &key);
    */
    // PREDEFINED ARRAY (for testing without user input)
    int arr[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    int size = 10;
    int key = 7;
    int passes = 0;

    int result = actualSequentialSearch(arr, size, key, &passes);

    // Output result
    printf("\nACTUAL SEQUENTIAL SEARCH:\n");
    printf("Number of passes: %d\n", passes);

    if (result != -1)
    {
        printf("Key %d is FOUND at index %d.\n", key, result);
    }
    else
    {
        printf("Key %d is NOT FOUND in the array.\n", key);
    }

    return 0;
}

// Actual Sequential Search Function (with number of passes)
int actualSequentialSearch(int arr[], int size, int key, int *passes)
{
    int i;
    for (i = 0; i < size; i++)
    {
        (*passes)++; // This counts each comparison as a pass.
        if (arr[i] == key)
        {
            return i; // If the key entered is found.
        }
    }
    return -1; // If the key entered is not found.
}