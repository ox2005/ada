#include <stdio.h>

int main() {
    int n, i, capacity;
    float totalValue = 0;

    int weight[20], value[20], index[20];
    float ratio[20];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value of each item:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = (float)value[i] / weight[i];
        index[i] = i + 1; // Store original item number (1-based)
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Greedy sort by value/weight ratio (descending)
    for(i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                // Swap all values including index
                float tempRatio = ratio[i]; ratio[i] = ratio[j]; ratio[j] = tempRatio;
                int tempWeight = weight[i]; weight[i] = weight[j]; weight[j] = tempWeight;
                int tempValue = value[i]; value[i] = value[j]; value[j] = tempValue;
                int tempIndex = index[i]; index[i] = index[j]; index[j] = tempIndex;
            }
        }
    }

    // Greedy selection of items
    for(i = 0; i < n && capacity > 0; i++) {
        if(weight[i] <= capacity) {
            capacity -= weight[i];
            totalValue += value[i];
            printf("Added item %d fully (w=%d, v=%d), remaining capacity = %d\n", index[i], weight[i], value[i], capacity);
        } else {
            float frac = (float)capacity / weight[i];
            totalValue += value[i] * frac;
            printf("Added %.2f%% of item %d (w=%d, v=%d)\n", frac * 100, index[i], weight[i], value[i]);
            capacity = 0;
        }
    }

    printf("Total value in knapsack = %.2f\n", totalValue);

    return 0;
}
