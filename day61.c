/*
Problem:
Build a graph with n vertices and m edges
using adjacency matrix representation.

The graph may be directed or undirected.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: pairs (u, v)

Output:
- Print n x n adjacency matrix

Example:
Input:
4
4
0 1
0 2
1 2
2 3

Output:
0 1 1 0
0 0 1 0
0 0 0 1
0 0 0 0
*/

#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d", &n);
    scanf("%d", &m);

    int adj[n][n];

    // Initialize matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        // Uncomment below line for undirected graph
        // adj[v][u] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", adj[i][j]);

            if (j < n - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}