/*
Problem Statement:
Using DFS or BFS, count number of connected components.

Input Format:
n m
Next m lines: edges (u v)

Output Format:
Number of connected components.

Sample Input:
6 3
1 2
2 3
5 6

Sample Output:
3

Explanation:
Components are:
{1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

// DFS
void dfs(int u, struct Node* adj[], int visited[]) {
    visited[u] = 1;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->v;
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // build undirected graph
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

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}