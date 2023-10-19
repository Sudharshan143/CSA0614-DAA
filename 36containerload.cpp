#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items and containers
#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

// Define the container capacity
#define CONTAINER_CAPACITY 1000

// Define a structure for an item
struct Item {
    int id;
    int weight;
};

// Function to compare two items for sorting (decreasing order)
int compareItems(const void* a, const void* b) {
    return ((struct Item*)b)->weight - ((struct Item*)a)->weight;
}

// Function to load items into containers using the First Fit Decreasing algorithm
int loadItems(int items[], int numItems, int capacity) {
    int containers[MAX_CONTAINERS] = {0};
    int numContainers = 0;

    // Sort items in decreasing order of weight
    qsort(items, numItems, sizeof(struct Item), compareItems);

    for (int i = 0; i < numItems; i++) {
        int j;
        for (j = 0; j < numContainers; j++) {
            if (containers[j] >= items[i]) {
                containers[j] -= items[i];
                break;
            }
        }
        if (j == numContainers) {
            containers[numContainers++] = capacity - items[i];
        }
    }

    return numContainers;
}

int main() {
    int items[MAX_ITEMS];
    int numItems;

    // Example: Input items
    numItems = 10;
    struct Item itemArray[] = {
        {1, 250}, {2, 600}, {3, 100}, {4, 300},
        {5, 550}, {6, 200}, {7, 400}, {8, 600},
        {9, 150}, {10, 450}
    };

    for (int i = 0; i < numItems; i++) {
        items[i] = itemArray[i].weight;
    }

    int numContainers = loadItems(items, numItems, CONTAINER_CAPACITY);

    printf("Number of containers required: %d\n", numContainers);

    return 0;
}
