#include <stdio.h>
#define nV 5
#define INF 999
void printMatrix(int matrix[][nV]);
void floydWarshall(int graph[][nV]) {
int matrix[nV][nV], i, j, k;

for (i = 0; i < nV; i++)
for (j = 0; j < nV; j++)
matrix[i][j] = graph[i][j];
for (k = 0; k < nV; k++) {
for (i = 0; i < nV; i++) {
for (j = 0; j < nV; j++) {
if (matrix[i][k] + matrix[k][j] < matrix[i][j])
matrix[i][j] = matrix[i][k] + matrix[k][j];
}
}
}
printMatrix(matrix);
}
void printMatrix(int matrix[][nV]) {
for (int i = 0; i < nV; i++) {
for (int j = 0; j < nV; j++) {
if (matrix[i][j] == INF)
printf("%5s", "INF");
else
printf("%5d", matrix[i][j]);
}
printf("\n");
}
}
int main() {
int graph[nV][nV] = {{0 , 5, INF,6,2},
{INF,0,1,INF, 7},
{3,INF, 0,4, INF},
{INF, INF, 2, 0,3},
{INF,INF,INF,5,0}
};
floydWarshall(graph);
}