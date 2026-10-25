
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack to store operators
char stack[MAX];
int top = -1;

// Function to push an operator
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

// Function to pop an operator
char pop() {
    if (top == -1) {
        return '\0';
    }

    return stack[top--];
}

// Function to return the top element
char peek() {
    if (top == -1) {
        return '\0';
    }

    return stack[top];
}

// Function to check operator precedence
int precedence(char ch) {
    if (ch == '^') {
        return 3;
    }

    if (ch == '*' || ch == '/') {
        return 2;
    }

    if (ch == '+' || ch == '-') {
        return 1;
    }

    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char ch;

    // Read the expression one character at a time
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // Ignore spaces
        if (ch == ' ') {
            continue;
        }

        // Add operands directly to postfix
        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }

        // Push opening parenthesis
        else if (ch == '(') {
            push(ch);
        }

        // Pop operators until opening parenthesis
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(') {
                pop();
            }
        }

        // Handle operators according to precedence
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch)
                    && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        if (peek() == '(') {
            printf("Invalid expression!\n");
            return;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

// Main function
int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove newline character
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix);

    return 0;
}
