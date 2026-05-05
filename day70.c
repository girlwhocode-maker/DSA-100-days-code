/*
Problem:
Compute shortest path from source
and detect negative weight cycles
using Bellman-Ford Algorithm.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: u v w (edge with weight)
- Last line: source vertex s

Output:
- Print shortest distances from source
- OR print "NEGATIVE CYCLE" if detected

Example:
Input:
5
6
0 1 2
0 2 4
1 2 -3
1 3 2
2 4 3
3 4 2
0

Output:
0 2 -1 4 2
*/

#include <stdio.h>
#include <limits.h>

#define MAX 1000

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Edge edges[MAX];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // Relax edges (n-1 times)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Print distances
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}