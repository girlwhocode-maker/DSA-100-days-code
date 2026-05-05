/*
Problem:
Implement topological sorting using
in-degree array and queue
(Kahn's Algorithm).

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: directed edges (u, v)

Output:
- Print topological ordering

Example:
Input:
6
6
5 2
5 0
4 0
4 1
2 3
3 1

Output:
4 5 2 0 3 1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Node structure for adjacency list
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

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    int indegree[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Kahn's Algorithm
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    return 0;
}