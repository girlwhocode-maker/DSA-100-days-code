/*
Problem:
Detect cycle in directed graph
using DFS and recursion stack.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: directed edges (u, v)

Output:
- Print YES if cycle exists
- Otherwise print NO

Example:
Input:
4
4
0 1
1 2
2 3
3 1

Output:
YES
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function for cycle detection
int dfs(int current, struct Node* adj[], int visited[], int recStack[]) {
    visited[current] = 1;
    recStack[current] = 1;

    struct Node* temp = adj[current];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // Cycle found
        }

        temp = temp->next;
    }

    recStack[current] = 0;
    return 0;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    int visited[n], recStack[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Input directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}