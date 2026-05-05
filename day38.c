/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion
and deletion from both front and rear.

Supported Operations:
1. push_front value
2. push_back value
3. pop_front
4. pop_back
5. front
6. back
7. size
8. empty
9. display

Input:
- First line: integer n (number of operations)
- Next n lines: operations

Output:
- Print results of front, back, size, empty
  or popped elements when required.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Push front
void push_front(int value) {
    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
}

// Push back
void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

// Pop front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front
void getFront() {
    if (isEmpty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

// Get back
void getBack() {
    if (isEmpty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

// Size
void getSize() {
    if (isEmpty())
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

// Empty
void empty() {
    if (isEmpty())
        printf("1\n");
    else
        printf("0\n");
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d", deque[i]);
        if (i < rear)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int n, value;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &value);
            push_front(value);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &value);
            push_back(value);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            getFront();
        }
        else if (strcmp(op, "back") == 0) {
            getBack();
        }
        else if (strcmp(op, "size") == 0) {
            getSize();
        }
        else if (strcmp(op, "empty") == 0) {
            empty();
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}