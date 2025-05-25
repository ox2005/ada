#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two halves
void merge(long int arr[], long int left, long int mid, long int right) {
    long int i = left;       // Start index of the left subarray
    long int j = mid + 1;    // Start index of the right subarray
    long int k = 0;          // Index for the temporary array

    long int size = right - left + 1;
    long int temp[size];     // Temporary array to hold merged elements

    // Compare elements from both halves and store the smaller one
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy any remaining elements from left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy any remaining elements from right half
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy sorted elements back into original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}


// Recursive Merge Sort
void mergeSort(long int arr[], long int left, long int right) {
    if (left < right) {
        long int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Main function
int main() {
    long int n = 60000;   // Starting size
    int iterations = 5;  // Number of tests
    clock_t start, end;
    double timeTaken;

    printf("Input Size\tTime Taken (ms)\n");

    for (int i = 0; i < iterations; i++) {
        long int arr[n];

        // Generate random numbers
        for (long int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        // Start timing
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        // Calculate time in milliseconds
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("%ld\t\t%.2f ms\n", n, timeTaken);

        n += 10000; // Increase for next round
    }
    
    return 0;
}
