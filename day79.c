/*
Problem Statement:
Find shortest distances from source vertex
in a weighted graph with non-negative weights.

Input Format:
n m
Next m lines: u v w
source

Output Format:
Distances to all vertices.

Sample Input:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output:
0 2 3 9 6

Explanation:
Shortest distances computed via priority queue idea.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 1000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cost[MAX][MAX];

    // initialize cost matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INT_MAX;
        }
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        cost[u][v] = w;
        cost[v][u] = w; // undirected graph
    }

    int dist[MAX], visited[MAX] = {0};

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    int src;
    scanf("%d", &src);

    dist[src] = 0;

    // Dijkstra main loop
    for (int count = 1; count <= n - 1; count++) {

        int min = INT_MAX, u = -1;

        // pick minimum distance vertex
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // update distances
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && cost[u][v] != INT_MAX &&
                dist[u] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v]) {

                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}