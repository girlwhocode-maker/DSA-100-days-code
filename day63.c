/*
Problem:
Perform DFS starting from a given source vertex
using recursion.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: edges (u, v)
- Last line: starting vertex s

Output:
- Print DFS traversal order

Example:
Input:
5
5
0 1
0 2
1 3
1 4
2 4
0

Output:
0 2 4 1 3
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    int visited[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment for undirected graph
        /*
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    int start;
    scanf("%d", &start);

    dfs(start, adj, visited);

    return 0;
}