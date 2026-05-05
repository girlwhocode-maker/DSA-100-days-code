/*
Problem Statement:
Given a binary tree, print its vertical order traversal.
Nodes on same vertical line should be printed together
from top to bottom and left to right.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
  representing level-order traversal
  (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost
  to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define OFFSET 500   // to handle negative horizontal distances

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue item for BFS
struct QueueNode {
    struct Node* node;
    int hd; // horizontal distance
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct Node* current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// Vertical order traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QueueNode queue[MAX];
    int front = 0, rear = 0;

    // Store vertical order strings
    int result[MAX][MAX];
    int counts[MAX] = {0};

    int minHD = OFFSET, maxHD = OFFSET;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode current = queue[front++];
        int index = current.hd + OFFSET;

        result[index][counts[index]++] = current.node->data;

        if (index < minHD) minHD = index;
        if (index > maxHD) maxHD = index;

        if (current.node->left)
            queue[rear++] = (struct QueueNode){current.node->left, current.hd - 1};

        if (current.node->right)
            queue[rear++] = (struct QueueNode){current.node->right, current.hd + 1};
    }

    // Print results column by column
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < counts[i]; j++) {
            printf("%d", result[i][j]);
            if (j < counts[i] - 1)
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}