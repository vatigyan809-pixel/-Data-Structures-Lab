
#include <stdio.h>

// Function for sequential search
int sequentialSearch(int arr[], int n, int key) {
    int i;

    // Check each element one by one
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    // Element not found
    return -1;
}

// Function for binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int mid;

    // Search while the range is valid
    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Element not found
    return -1;
}

int main() {
    int arr[100], n, key, i;
    int result1, result2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid array size!\n");
        return 1;
    }

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Perform sequential search
    result1 = sequentialSearch(arr, n, key);

    // Perform binary search
    result2 = binarySearch(arr, n, key);

    if (result1 != -1) {
        printf("Sequential Search: Element found at position %d\n",
               result1 + 1);
    } else {
        printf("Sequential Search: Element not found\n");
    }

    if (result2 != -1) {
        printf("Binary Search: Element found at position %d\n",
               result2 + 1);
    } else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}
