/*
Problem:
Print topological ordering of a
Directed Acyclic Graph (DAG) using DFS.

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
5 4 2 3 1 0
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

// Stack for topological sort
int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

// DFS function
void dfs(int current, struct Node* adj[], int visited[]) {
    visited[current] = 1;

    struct Node* temp = adj[current];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }

        temp = temp->next;
    }

    push(current);
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

    // Input directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // Run DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }

    // Print topological order
    while (top != -1) {
        printf("%d ", pop());
    }

    return 0;
}