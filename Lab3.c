
#include <stdio.h>
#include <stdlib.h>

// Structure to create a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode;

    // Allocate memory for the new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Store data and initialize the next pointer
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the beginning
void insertBeginning(struct Node **head)
{
    int value;
    struct Node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    // Create a new node
    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // Link the new node to the current first node
    newNode->next = *head;

    // Update head to the new first node
    *head = newNode;

    printf("Node inserted at beginning.\n");
}

// Function to insert a node at the end
void insertEnd(struct Node **head)
{
    int value;
    struct Node *newNode, *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    // Create a new node
    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newNode;
        printf("Node inserted at end.\n");
        return;
    }

    // Traverse to the last node
    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect the last node to the new node
    temp->next = newNode;

    printf("Node inserted at end.\n");
}

// Function to insert a node at any position
void insertPosition(struct Node **head)
{
    int value, pos, i;
    struct Node *newNode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Use the beginning insertion function for position 1
    if (pos == 1)
    {
        insertBeginning(head);
        return;
    }

    // Move to the node just before the required position
    temp = *head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Check whether the position exists
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    // Create and link the new node
    newNode = createNode(value);

    if (newNode == NULL)
        return;

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

// Function to delete the first node
void deleteBeginning(struct Node **head)
{
    struct Node *temp;

    // Check whether the list is empty
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // Store the first node temporarily
    temp = *head;

    // Move head to the second node
    *head = (*head)->next;

    // Release memory of the deleted node
    free(temp);

    printf("First node deleted.\n");
}

// Function to delete the last node
void deleteEnd(struct Node **head)
{
    struct Node *temp, *prev;

    // Check whether the list is empty
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // Handle a list containing only one node
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        printf("Last node deleted.\n");
        return;
    }

    // Traverse to the last node
    temp = *head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // Disconnect the last node and free its memory
    prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

// Function to delete a node at any position
void deletePosition(struct Node **head)
{
    int pos, i;
    struct Node *temp, *prev;

    // Check whether the list is empty
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Use beginning deletion for position 1
    if (pos == 1)
    {
        deleteBeginning(head);
        return;
    }

    // Move to the node that must be deleted
    temp = *head;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // Check whether the position exists
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // Connect the previous node to the next node
    prev->next = temp->next;

    // Free memory of the deleted node
    free(temp);

    printf("Node deleted successfully.\n");
}

// Function to display all nodes
void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");

    // Traverse and print each node
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Function to release all remaining nodes
void freeList(struct Node **head)
{
    struct Node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int n, i, value, choice;

    // Input the initial number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes!\n");
        return 0;
    }

    // Create the initial linked list
    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        // Create a node and append it to the list
        struct Node *newNode = createNode(value);

        if (newNode == NULL)
        {
            freeList(&head);
            return 1;
        }

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display the menu until the user exits
    do
    {
        printf("\n--- LINKED LIST OPERATIONS ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Display List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function
        if (choice == 1)
            insertBeginning(&head);
        else if (choice == 2)
            insertEnd(&head);
        else if (choice == 3)
            insertPosition(&head);
        else if (choice == 4)
            deleteBeginning(&head);
        else if (choice == 5)
            deleteEnd(&head);
        else if (choice == 6)
            deletePosition(&head);
        else if (choice == 7)
            display(head);
        else if (choice == 0)
            printf("Program terminated.\n");
        else
            printf("Invalid choice!\n");

    } while (choice != 0);

    // Free all dynamically allocated memory
    freeList(&head);

    return 0;
}
