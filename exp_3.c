#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;

        // If key is greater, ignore the left half
        else if (arr[mid] < key)
            low = mid + 1;

        // If key is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // If key is not present in the array
    return -1;
}

int main() {
    int n, key;

    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the sorted array elements from the user
    printf("Enter the sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Get the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    // Print the result
    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
