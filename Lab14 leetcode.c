
#include <stdio.h>

// Remove duplicates from a sorted array
int removeDuplicates(int nums[], int numsSize) {
    int i, k = 1;

    // Handle empty or single-element array
    if (numsSize <= 1) {
        return numsSize;
    }

    // Store unique elements at the beginning
    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Return the count of unique elements
    return k;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k, i;

    k = removeDuplicates(nums, n);

    printf("Number of unique elements: %d\n", k);
    printf("Array after removing duplicates: ");

    for (i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    return 0;
}
