
#include <stdio.h>
#define MAX 5

// Array to store queue elements
int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element
void enqueue(int value) {
    // Check whether the queue is full
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    // Initialize front for the first element
    if (front == -1) {
        front = 0;
    }

    // Insert the element at the rear
    rear++;
    queue[rear] = value;

    printf("%d inserted into queue.\n", value);
}

// Function to delete an element
void dequeue() {
    // Check whether the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }

    // Remove the front element
    printf("Deleted element: %d\n", queue[front]);
    front++;

    // Reset the queue when it becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to display queue elements
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    // Display elements from front to rear
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Array ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
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
