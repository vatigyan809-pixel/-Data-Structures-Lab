
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize all positions as empty
void initialize() {
    int i;

    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Insert an element using linear probing
void insert(int key) {
    int index = key % SIZE;
    int i;

    // Check for an empty position
    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1) {
            hashTable[pos] = key;
            printf("%d inserted at index %d\n", key, pos);
            return;
        }
    }

    printf("Hash table is full! Cannot insert %d\n", key);
}

// Search for an element
void search(int key) {
    int index = key % SIZE;
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        // Stop if an empty slot is reached
        if (hashTable[pos] == -1) {
            break;
        }

        if (hashTable[pos] == key) {
            printf("%d found at index %d\n", key, pos);
            return;
        }
    }

    printf("%d not found in the hash table\n", key);
}

// Display the hash table
void display() {
    int i;

    printf("\nHash Table:\n");
    printf("Index\tValue\n");

    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("%d\tEmpty\n", i);
        } else {
            printf("%d\t%d\n", i, hashTable[i]);
        }
    }
}

int main() {
    initialize();

    // Insert elements into the hash table
    insert(12);
    insert(22);
    insert(32);
    insert(15);

    // Display stored elements
    display();

    // Search for an element
    search(22);
    search(45);

    return 0;
}
