/*
Problem:
Perform BFS from a given source using queue.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: edges (u, v)
- Last line: source vertex s

Output:
- Print BFS traversal order

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
0 2 1 4 3
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

    int source;
    scanf("%d", &source);

    // Queue for BFS
    int queue[MAX];
    int front = 0, rear = 0;

    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    return 0;
}