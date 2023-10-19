#include <stdio.h>
#include <stdbool.h>

#define V 10  // Maximum number of vertices in the graph

void printSolution(int path[], int numVertices);

bool isSafe(int v, bool graph[V][V], int path[], int pos, int numVertices) {
    if (!graph[path[pos - 1]][v]) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool hamiltonianUtil(bool graph[V][V], int path[], int pos, int numVertices) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]]) {
            return true;
        }
        return false;
    }

    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, graph, path, pos, numVertices)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1, numVertices)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(bool graph[V][V], int numVertices) {
    int path[V];
    for (int i = 0; i < numVertices; i++) {
        path[i] = -1;
    }

    path[0] = 0;

    if (!hamiltonianUtil(graph, path, 1, numVertices)) {
        printf("No Hamiltonian cycle exists.\n");
        return false;
    }

    printf("Hamiltonian cycle:\n");
    printSolution(path, numVertices);

    return true;
}

void printSolution(int path[], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

int main() {
    int numVertices;
    bool graph[V][V];

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hamiltonianCycle(graph, numVertices)) {
        printf("Hamiltonian cycle found.\n");
    } else {
        printf("No Hamiltonian cycle found.\n");
    }

    return 0;
}
