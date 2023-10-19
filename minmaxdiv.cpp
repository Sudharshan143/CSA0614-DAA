#include <stdio.h>

struct MaxMin {
    int max;
    int min;
};

struct MaxMin findMaxMin(int arr[], int left, int right) {
    struct MaxMin result, leftResult, rightResult;
    int mid;

    if (left == right) {
        result.max = arr[left];
        result.min = arr[left];
        return result;
    }

    if (right == left + 1) {
        if (arr[left] > arr[right]) {
            result.max = arr[left];
            result.min = arr[right];
        } else {
            result.max = arr[right];
            result.min = arr[left];
        }
        return result;
    }

    mid = (left + right) / 2;
    leftResult = findMaxMin(arr, left, mid);
    rightResult = findMaxMin(arr, mid + 1, right);

    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }

    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct MaxMin result = findMaxMin(arr, 0, n - 1);

    printf("Maximum element: %d\n", result.max);
    printf("Minimum element: %d\n", result.min);

    return 0;
}
