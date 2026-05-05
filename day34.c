/*
Problem: Evaluate Postfix Expression
Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands,
push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL)
        return 0;

    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    struct Node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '%': result = a % b; break;
                default: result = 0;
            }

            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char exp[200];

    fgets(exp, sizeof(exp), stdin);

    // Remove newline if present
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);
    printf("%d\n", result);

    return 0;
}