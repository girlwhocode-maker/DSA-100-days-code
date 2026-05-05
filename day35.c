/*
Problem: Queue Using Array

Implement queue using array.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers.
Enqueue inserts at rear, dequeue removes from front.
Display from front to rear.
*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        return; // Queue overflow ignored
    }
    queue[++rear] = value;
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) {
            printf(" ");
        }
    }
}

int main() {
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}