
#include <stdio.h>
#define MAX 5

// Array to store stack elements
int stack[MAX];
int top = -1;

// Function to insert an element
void push(int value) {
    // Check whether the stack is full
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    // Increase top and insert the element
    top++;
    stack[top] = value;

    printf("%d pushed into stack.\n", value);
}

// Function to remove an element
void pop() {
    // Check whether the stack is empty
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    // Remove the top element
    printf("Popped element: %d\n", stack[top]);
    top--;
}

// Function to display stack elements
void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");

    // Display elements from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Array ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
