 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int inStack[SIZE];
    int outStack[SIZE];
    int inTop;
    int outTop;
} MyQueue;

// Create an empty queue
MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));

    if (q == NULL) {
        return NULL;
    }

    q->inTop = -1;
    q->outTop = -1;

    return q;
}

// Insert an element into the queue
void myQueuePush(MyQueue* q, int x) {
    if (q->inTop < SIZE - 1) {
        q->inStack[++q->inTop] = x;
    } else {
        printf("Input stack is full!\n");
    }
}

// Transfer elements when output stack is empty
void transfer(MyQueue* q) {
    if (q->outTop == -1) {
        while (q->inTop != -1) {
            q->outStack[++q->outTop] =
                q->inStack[q->inTop--];
        }
    }
}

// Remove and return the front element
int myQueuePop(MyQueue* q) {
    transfer(q);

    if (q->outTop == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    return q->outStack[q->outTop--];
}

// Return the front element
int myQueuePeek(MyQueue* q) {
    transfer(q);

    if (q->outTop == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    return q->outStack[q->outTop];
}

// Check whether the queue is empty
bool myQueueEmpty(MyQueue* q) {
    return q->inTop == -1 && q->outTop == -1;
}

// Free the allocated memory
void myQueueFree(MyQueue* q) {
    free(q);
}

// Main function for testing in VS Code
int main() {
    MyQueue *q = myQueueCreate();

    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    myQueuePush(q, 10);
    myQueuePush(q, 20);
    myQueuePush(q, 30);

    printf("Front element: %d\n", myQueuePeek(q));
    printf("Removed element: %d\n", myQueuePop(q));
    printf("Front element after removal: %d\n",
           myQueuePeek(q));
    printf("Is queue empty? %s\n",
           myQueueEmpty(q) ? "Yes" : "No");

    myQueueFree(q);

    return 0;
}

