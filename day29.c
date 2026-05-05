/*
Problem: Rotate Linked List Right by k Places
Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list.
Traverse to (n-k)th node, set next to NULL,
update head to (n-k+1)th node.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (head == NULL || k == 0)
        return head;

    k = k % n;
    if (k == 0)
        return head;

    struct Node* temp = head;

    // Find last node
    while (temp->next != NULL)
        temp = temp->next;

    // Make circular
    temp->next = head;

    int steps = n - k;
    temp = head;

    // Move to (n-k)th node
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

int main() {
    int n, k, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);
    printList(head);

    return 0;
}