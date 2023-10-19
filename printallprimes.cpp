#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    bool isPrime[n + 1];
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    printf("Prime numbers in the range 2 to %d:\n", n);
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            printf("%d ", i);
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the upper limit: ");
    scanf("%d", &limit);
    sieveOfEratosthenes(limit);
    return 0;
}
