/*
Problem:
Given a weighted graph with n vertices,
implement Floyd-Warshall algorithm to compute
shortest distances between every pair of vertices.

Graph may contain positive or negative weights,
but no negative weight cycles.

Input:
- First line: n (number of vertices)
- Next n lines: adjacency matrix
  (-1 means no direct edge)

Output:
- Print shortest distance matrix

Example:
Input:
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Output:
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0

Explanation:
Each vertex is used as an intermediate node
to relax all pairs shortest paths.
*/

#include <stdio.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            // convert -1 to INF (except diagonal)
            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = 1000000000;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != 1000000000 &&
                    dist[k][j] != 1000000000 &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == 1000000000)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}