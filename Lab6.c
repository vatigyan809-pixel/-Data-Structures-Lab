
#include <stdio.h>
#include <stdlib.h>

// Structure to store a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Function to create a new term
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Function to add a term at the end
void insertTerm(struct Node **head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
    struct Node *temp;

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

// Function to input a polynomial
struct Node* inputPolynomial() {
    struct Node *head = NULL;
    int n, coeff, exp, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);

        insertTerm(&head, coeff, exp);
    }

    return head;
}

// Function to add two polynomials
struct Node* addPolynomial(struct Node *p1,
                           struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        // Add coefficients with equal exponents
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;

            if (sum != 0) {
                insertTerm(&result, sum, p1->exp);
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        // Copy the term with the larger exponent
        else if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Copy remaining terms of the first polynomial
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Copy remaining terms of the second polynomial
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node *head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL) {
            printf(" + ");
        }

        head = head->next;
    }

    printf("\n");
}

// Main function
int main() {
    struct Node *p1, *p2, *result;

    printf("Enter first polynomial:\n");
    p1 = inputPolynomial();

    printf("\nEnter second polynomial:\n");
    p2 = inputPolynomial();

    // Add both polynomials
    result = addPolynomial(p1, p2);

    printf("\nFirst Polynomial: ");
    displayPolynomial(p1);

    printf("Second Polynomial: ");
    displayPolynomial(p2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}
