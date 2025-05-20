#include <stdio.h>

int optimizedSequentialSearch(int arr[], int size, int key, int *passes);

int main()
{
    // USER INPUT
    int size, key, passes = 0;

    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    // PREDEFINED ARRAY (for testing without user input)
    // int arr[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    // int size = 10;
    // int key = 7;
    // int passes = 0;

    int result = optimizedSequentialSearch(arr, size, key, &passes);

    // Output result
    printf("\nOPTIMIZED SEQUENTIAL SEARCH:\n");
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

// Optimized Sequential Search Function (with number of passes)
int optimizedSequentialSearch(int arr[], int size, int key, int *passes)
{
    int left = 0;         // The search starts at the beginning of the array
    int right = size - 1; // The search starts at the end of the array

    while (left <= right)
    {                // A while loop that continues until both pointers cross each other. This ensures every element is checked once.
        (*passes)++; // This counts each comparison as a pass.

        if (arr[left] == key)
        {
            return left; // The element at the left index is checked and returned if found.
        }

        if (arr[right] == key)
        {
            return right; // The element at the right index is checked and returned if found.
        }
        left++;
        right--;
        // left goes forward, right goes backward. This effectively narrows the search space from both ends.
    }
    return -1; // If the key is not found.
}