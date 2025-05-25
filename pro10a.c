#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two values
void swap(long int *a, long int *b) {
    long int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using the FIRST element as pivot
long int partition(long int arr[], long int low, long int high) {
    long int pivot = arr[low];     // ✅ First element as pivot
    long int i = low + 1;
    long int j = high;

    while (1) {
        // Find an element greater than the pivot from the left
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // Find an element less than the pivot from the right
        while (j >= low && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    // Place pivot at its correct position
    swap(&arr[low], &arr[j]);
    return j;   // New pivot position
}

// Recursive Quick Sort function
void quickSort(long int arr[], long int low, long int high) {
    if (low < high) {
        long int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main function to run performance test
int main() {
    long int n = 60000;       // Starting size
    int iterations = 5;      // Number of test runs
    clock_t start, end;
    double timeTaken;

    printf("Input Size\tTime Taken (ms)\n");

    for (int i = 0; i < iterations; i++) {
        long int arr[n];

        // Fill array with random numbers
        for (long int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;
        }

        // Measure time taken by Quick Sort
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;  // milliseconds
        printf("%ld\t\t%.2f ms\n", n, timeTaken);

        n += 10000;  // Increase input size
    }

    return 0;
}
