 
#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode *newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the end
void insertEnd(struct ListNode **head, int val) {
    struct ListNode *newNode = createNode(val);
    struct ListNode *temp;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(
    struct ListNode *list1,
    struct ListNode *list2
) {
    // Dummy node simplifies the merging process
    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    dummy.next = NULL;

    // Compare nodes from both lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        // Move tail to the last merged node
        tail = tail->next;
    }

    // Attach the remaining nodes
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// Function to display the linked list
void display(struct ListNode *head) {
    while (head != NULL) {
        printf("%d", head->val);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf(" -> NULL\n");
}

// Main function
int main() {
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    struct ListNode *result;

    // Create first sorted list: 1 -> 3 -> 5
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);

    // Create second sorted list: 2 -> 4 -> 6
    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);

    printf("First List: ");
    display(list1);

    printf("Second List: ");
    display(list2);

    // Merge both sorted lists
    result = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    display(result);

    return 0;
}
