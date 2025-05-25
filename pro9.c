#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(long int *a, long int *b) {
    long int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort function
void selectionSort(long int arr[], long int n) {
    for (long int i = 0; i < n - 1; i++) {
        long int minIndex = i;
        for (long int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

// Main function
int main() {
    long int n = 6000;   // Start with size > 5000
    int iterations = 5;  // Number of different input sizes
    clock_t start, end;
    double timeTaken;

    printf("Input Size\tTime Taken (ms)\n");

    for (int i = 0; i < iterations; i++) {
        long int arr[n];

        // Generate random numbers
        for (long int j = 0; j < n; j++) {
            arr[j] = rand() % 100000;  // Random numbers between 0 and 99999
        }

        start = clock();
        selectionSort(arr, n);
        end = clock();

        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Convert to milliseconds
        printf("%ld\t\t%.2f ms\n", n, timeTaken);

        n += 1000; // Increase size for next iteration
    }

    return 0;
}
