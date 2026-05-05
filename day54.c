/*
Problem Statement:
Perform zigzag (spiral) level order traversal
of a binary tree.

Alternate levels should be traversed
left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal
  (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right,
level 2 right-to-left, and so on.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int levelSize = rear - front;
        int level[MAX];

        for (int i = 0; i < levelSize; i++) {
            struct Node* current = queue[front++];

            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = current->data;

            if (current->left)
                queue[rear++] = current->left;

            if (current->right)
                queue[rear++] = current->right;
        }

        for (int i = 0; i < levelSize; i++) {
            printf("%d", level[i]);
            printf(" ");
        }

        leftToRight = !leftToRight;
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
    zigzagTraversal(root);

    return 0;
}