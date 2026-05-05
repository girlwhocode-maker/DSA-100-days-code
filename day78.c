/*
Problem Statement:
Given weighted undirected graph,
compute total weight of Minimum Spanning Tree
using Prim’s Algorithm.

Input Format:
n m
Next m lines: u v w

Output Format:
Total weight of MST.

Sample Input:
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output:
6

Explanation:
One possible MST edges:
(2-3), (3-4), (1-2)
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

    // input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        cost[u][v] = w;
        cost[v][u] = w;
    }

    int visited[MAX] = {0};
    int minCost = 0;

    visited[1] = 1; // start from node 1

    for (int edges = 0; edges < n - 1; edges++) {

        int min = INT_MAX;
        int x = -1, y = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;
        minCost += min;
    }

    printf("%d\n", minCost);

    return 0;
}