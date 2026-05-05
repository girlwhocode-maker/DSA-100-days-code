/*
Problem: Circular Queue Using Array

Implement circular queue using array.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations,
  space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers.
Rear wraps around to start after reaching array end.
Dequeue removes elements from front.
Display remaining elements in correct order.
*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue operation
void enqueue(int value) {
    if (size == MAX)
        return; // Queue full

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

// Dequeue operation
void dequeue() {
    if (size == 0)
        return; // Queue empty

    front = (front + 1) % MAX;
    size--;
}

// Display circular queue
void display() {
    int i = front;

    for (int count = 0; count < size; count++) {
        printf("%d", queue[i]);
        if (count < size - 1)
            printf(" ");
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Number of dequeues
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}