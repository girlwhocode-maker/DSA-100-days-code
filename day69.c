/*
Problem:
Given weighted graph with non-negative edges,
compute shortest path from source using
priority queue (Dijkstra's Algorithm).

Input:
- First line: n (number of vertices)
- Second line: m (number of edges)
- Next m lines: u v w (edge from u to v with weight w)
- Last line: source vertex s

Output:
- Print shortest distance from source to all nodes

Example:
Input:
5
6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
0

Output:
0 2 3 9 6
*/

#include <stdio.h>
#include <limits.h>

#define MAX 1000

// adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// create node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// get min distance vertex (priority queue simulation)
int getMinVertex(int dist[], int visited[], int n) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // input edges (directed weighted graph)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        // If undirected graph, uncomment below:
        /*
        newNode = createNode(u, w);
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    int src;
    scanf("%d", &src);

    int dist[n], visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = getMinVertex(dist, visited, n);
        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // print result
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}