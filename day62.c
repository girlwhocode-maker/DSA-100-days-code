/*
Problem:
Build a graph with adjacency list representation.
Use linked lists or dynamic arrays.

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: edges (u, v)

Output:
- Print adjacency list for each vertex

Example:
Input:
4
4
0 1
0 2
1 2
2 3

Output:
0: 2 1
1: 2
2: 3
3:
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

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Array of linked lists
    struct Node* adj[n];

    // Initialize all heads as NULL
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment below for undirected graph
        /*
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d:", i);

        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}