
#include <stdio.h>
#include <stdlib.h>

// Structure to create a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to insert at the beginning
void insertBeginning(int data) {
    struct Node *newNode = createNode(data);

    // Link the new node with the first node
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    // Update the head pointer
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Function to insert at the end
void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    // If the list is empty
    if (head == NULL) {
        head = newNode;
        printf("Node inserted at end.\n");
        return;
    }

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the last node with the new node
    temp->next = newNode;
    newNode->prev = temp;

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

    // Move to the node before the position
    for (i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode = createNode(data);

    // Adjust previous and next links
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

// Function to delete from the beginning
void deleteBeginning() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Move head to the next node
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Node deleted from beginning.\n");
}

// Function to delete from the end
void deleteEnd() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If only one node exists
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Disconnect the last node
    temp->prev->next = NULL;

    free(temp);
    printf("Node deleted from end.\n");
}

// Function to delete from a given position
void deletePosition(int pos) {
    struct Node *temp = head;
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

    // Move to the node at the given position
    for (i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Connect the previous node to the next node
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted from position %d.\n", pos);
}

// Function to display the list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
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
                // Release all allocated memory
                while (head != NULL) {
                    deleteBeginning();
                }
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
