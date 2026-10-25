
#include <stdio.h>
#include <stdlib.h>

// Structure to create a circular linked list node
struct Node {
    int data;
    struct Node *next;
};

// Pointer to the first node
struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to insert at the beginning
void insertBeginning(int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    // If the list is empty, node points to itself
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        // Connect the new node at the beginning
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning.\n");
}

// Function to insert at the end
void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    // If the list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        // Connect the last node to the new node
        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at end.\n");
}

// Function to insert at a given position
void insertPosition(int data, int pos) {
    struct Node *newNode, *temp = head;
    int i;

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    // Position 1 means beginning
    if (pos == 1) {
        insertBeginning(data);
        return;
    }

    if (head == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Move to the node before the position
    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // Check whether the position is valid
    if (i != pos - 1) {
        printf("Invalid position!\n");
        return;
    }

    newNode = createNode(data);

    // Insert the new node into the list
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

// Function to delete from the beginning
void deleteBeginning() {
    struct Node *temp = head;
    struct Node *last = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If only one node exists
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        // Find the last node
        while (last->next != head) {
            last = last->next;
        }

        // Move head to the next node
        head = head->next;
        last->next = head;

        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

// Function to delete from the end
void deleteEnd() {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If only one node exists
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        // Move to the last node
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        // Make the previous node the last node
        prev->next = head;

        free(temp);
    }

    printf("Node deleted from end.\n");
}

// Function to delete from a given position
void deletePosition(int pos) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    int i;

    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list!\n");
        return;
    }

    // Position 1 means beginning
    if (pos == 1) {
        deleteBeginning();
        return;
    }

    // Find the node at the given position
    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos) {
        printf("Invalid position!\n");
        return;
    }

    // Remove the selected node
    prev->next = temp->next;
    free(temp);

    printf("Node deleted from position %d.\n", pos);
}

// Function to display the circular linked list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Circular Linked List: ");

    // Traverse until we return to the first node
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main function
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d%d", &data, &pos);
                insertPosition(data, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                // Free all nodes before exiting
                while (head != NULL) {
                    deleteBeginning();
                }
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
