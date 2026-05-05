/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    stack[++top] = ch;
}

// Pop operation
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

// Peek top element
char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Right parenthesis
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];

    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}