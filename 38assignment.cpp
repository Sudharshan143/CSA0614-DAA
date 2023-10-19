#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5 // Number of workers and jobs (adjust as needed)

// Function to initialize the cost matrix
void initializeCostMatrix(int cost[N][N]) {
    // Fill in your cost matrix based on the assignment problem
}

// Function to find the minimum cost in the given row
int findMinInRow(int cost[N][N], int row, int excludedCol) {
    int minCost = INT_MAX;
    for (int col = 0; col < N; col++) {
        if (col != excludedCol && cost[row][col] < minCost) {
            minCost = cost[row][col];
        }
    }
    return minCost;
}

// Function to find the minimum cost in the given column
int findMinInCol(int cost[N][N], int col, int excludedRow) {
    int minCost = INT_MAX;
    for (int row = 0; row < N; row++) {
        if (row != excludedRow && cost[row][col] < minCost) {
            minCost = cost[row][col];
        }
    }
    return minCost;
}

// Function to reduce the cost matrix and update the row and column reductions
void reduceMatrix(int cost[N][N], int rowReduc[N], int colReduc[N]) {
    for (int row = 0; row < N; row++) {
        int minInRow = findMinInRow(cost, row, -1);
        if (minInRow < INT_MAX) {
            rowReduc[row] = minInRow;
            for (int col = 0; col < N; col++) {
                if (cost[row][col] != INT_MAX) {
                    cost[row][col] -= minInRow;
                }
            }
        }
    }

    for (int col = 0; col < N; col++) {
        int minInCol = findMinInCol(cost, col, -1);
        if (minInCol < INT_MAX) {
            colReduc[col] = minInCol;
            for (int row = 0; row < N; row++) {
                if (cost[row][col] != INT_MAX) {
                    cost[row][col] -= minInCol;
                }
            }
        }
    }
}

// Function to assign jobs to workers using branch and bound
void assignJobs(int cost[N][N], int rowReduc[N], int colReduc[N], int assignment[N], int worker, int totalCost, int& minCost) {
    if (worker == N) {
        if (totalCost < minCost) {
            minCost = totalCost;
            // Update the best assignment
            for (int i = 0; i < N; i++) {
                // Store the assignment in the 'assignment' array
            }
        }
        return;
    }

    for (int job = 0; job < N; job++) {
        if (cost[worker][job] == 0) {
            // If the worker can be assigned to the job
            if (rowReduc[worker] + colReduc[job] < minCost) {
                int prevRowReduc = rowReduc[worker];
                int prevColReduc = colReduc[job];
                int prevCost = cost[worker][job];
                
                rowReduc[worker] = INT_MAX; // Mark as visited
                colReduc[job] = INT_MAX;   // Mark as visited

                reduceMatrix(cost, rowReduc, colReduc);

                assignJobs(cost, rowReduc, colReduc, assignment, worker + 1, totalCost + prevCost, minCost);

                // Restore the previous values
                rowReduc[worker] = prevRowReduc;
                colReduc[job] = prevColReduc;
                cost[worker][job] = prevCost;
            }
        }
    }
}

int main() {
    int cost[N][N];
    int rowReduc[N] = {0}; // Row reductions
    int colReduc[N] = {0}; // Column reductions
    int assignment[N];    // To store the final assignment
    int minCost = INT_MAX; // Initialize with a large value

    initializeCostMatrix(cost);
    reduceMatrix(cost, rowReduc, colReduc);

    assignJobs(cost, rowReduc, colReduc, assignment, 0, 0, minCost);

    // Output the optimal assignment and minimum cost
    printf("Optimal Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Job %d\n", i, assignment[i]);
    }
    printf("Minimum Cost: %d\n", minCost);

    return 0;
}
