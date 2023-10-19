#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    return ratioB - ratioA; // Sort in descending order of ratios
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity * (double)items[i].value) / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in the knapsack: %.2lf\n", maxValue);

    return 0;
}
