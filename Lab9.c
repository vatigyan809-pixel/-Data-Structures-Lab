 
#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {

    // Base case: move one disk directly
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n",
               source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the largest disk to destination
    printf("Move disk %d from %c to %c\n",
           n, source, destination);

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Main function
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Check whether the number of disks is valid
    if (n <= 0) {
        printf("Please enter a positive number of disks.\n");
        return 0;
    }

    // Call the recursive function
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
