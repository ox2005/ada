#include <stdio.h>


int s[10], x[10], n, d;

void sumOfSubsets(int currentSum, int currentIndex) {
    if (currentSum == d) {
        // Print the subset
        printf("Subset: ");
        for (int i = 0; i < currentIndex; i++) {
            if (x[i]) {
                printf("%d ", s[i]);
            }
        }
        printf("\n");
        return;
    }
    if (currentSum > d || currentIndex == n) {
        // No need to proceed further
        return;
    }

    // Include the current element
    x[currentIndex] = 1;
    sumOfSubsets(currentSum + s[currentIndex], currentIndex + 1);

    // Exclude the current element
    x[currentIndex] = 0;
    sumOfSubsets(currentSum, currentIndex + 1);
}

int main() {
    int totalSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the set elements (in increasing order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        totalSum += s[i];
    }

    printf("Enter the target sum value: ");
    scanf("%d", &d);

    if (totalSum < d || s[0] > d) {
        printf("No subset possible.\n");
    } else {
        sumOfSubsets(0, 0);
    }

    return 0;
}
