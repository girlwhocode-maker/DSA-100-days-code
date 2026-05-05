/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1, top = -1;

// Enqueue
void enqueue(int value) {
    queue[++rear] = value;
}

// Push to stack
void push(int value) {
    stack[++top] = value;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Reverse queue using stack
void reverseQueue() {
    // Move queue elements to stack
    for (int i = front; i <= rear; i++) {
        push(queue[i]);
    }

    // Put back reversed elements into queue
    front = 0;
    rear = -1;

    while (top != -1) {
        enqueue(pop());
    }
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear)
            printf(" ");
    }
}

int main() {
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    reverseQueue();
    display();

    return 0;
}