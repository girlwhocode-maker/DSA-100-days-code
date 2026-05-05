/*
Problem:
Using DFS and parent tracking,
detect if an undirected graph has a cycle.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: edges (u, v)

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
3 0

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

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function for cycle detection
int dfs(int current, int parent, struct Node* adj[], int visited[]) {
    visited[current] = 1;

    struct Node* temp = adj[current];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor, current, adj, visited))
                return 1;
        }
        else if (neighbor != parent) {
            return 1; // Cycle found
        }

        temp = temp->next;
    }

    return 0;
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

    // Input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
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