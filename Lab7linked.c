
#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct Node {
    int data;
    struct Node *next;
};

// Top pointer of the stack
struct Node *top = NULL;

// Function to insert an element
void push(int value) {
    struct Node *newNode;

    // Create memory for a new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }

    // Store data in the new node
    newNode->data = value;

    // Connect new node to the previous top
    newNode->next = top;

    // Update top pointer
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

// Function to remove the top element
void pop() {
    struct Node *temp;

    // Check whether the stack is empty
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    // Store the current top node
    temp = top;

    printf("Popped element: %d\n", top->data);

    // Move top to the next node
    top = top->next;

    // Free memory of the removed node
    free(temp);
}

// Function to display stack elements
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");

    // Traverse the stack
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Linked List ---\n");
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
                // Release remaining nodes
                while (top != NULL) {
                    struct Node *temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
