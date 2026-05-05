/*
Problem Statement:
Using BFS or DFS, check if the entire graph is connected.

Input Format:
n m
Next m lines: edges (u v)

Output Format:
CONNECTED
NOT CONNECTED

Sample Input:
4 2
1 2
3 4

Sample Output:
NOT CONNECTED
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

    // start DFS from node 1 (assumption nodes are 1..n)
    dfs(1, adj, visited);

    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}