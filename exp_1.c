// W.A.P. to implement insertion and bubble sort.

#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Perform insertion sort
    insertionSort(arr, n);
    printf("\nSorted array using Insertion Sort: ");
    printArray(arr, n);

    // Perform bubble sort
    bubbleSort(arr, n);
    printf("\nSorted array using Bubble Sort: ");
    printArray(arr, n);

    return 0;
}
