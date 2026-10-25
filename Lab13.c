
#include <stdio.h>

#define MAX 100

// Display the array
void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Iterative Quick Sort
void quickSort(int a[], int n) {
    int stack[MAX], top = -1;
    int low, high, i, j, pivot, temp;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivot = a[high];
        i = low - 1;

        for (j = low; j < high; j++) {
            if (a[j] <= pivot) {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        j = i + 1;

        if (j - 1 > low) {
            stack[++top] = low;
            stack[++top] = j - 1;
        }

        if (j + 1 < high) {
            stack[++top] = j + 1;
            stack[++top] = high;
        }
    }
}

// Shell Sort
void shellSort(int a[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = a[i];
            for (j = i; j >= gap &&
                 a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

// Radix Sort: for non-negative integers
int getMax(int a[], int n) {
    int max = a[0], i;
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void countSort(int a[], int n, int exp) {
    int output[MAX], count[10] = {0};
    int i, digit;

    for (i = 0; i < n; i++) {
        digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        digit = (a[i] / exp) % 10;
        output[--count[digit]] = a[i];
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int exp, max = getMax(a, n);

    for (exp = 1; max / exp > 0; exp *= 10) {
        countSort(a, n, exp);

        // Avoid overflow when moving to the next digit
        if (exp > max / 10)
            break;
    }
}

// Iterative Merge Sort
void mergeSort(int a[], int n) {
    int temp[MAX];
    int width, left, mid, right, i, j, k;

    for (width = 1; width < n; width *= 2) {
        for (left = 0; left < n; left += 2 * width) {
            mid = left + width;
            right = left + 2 * width;

            if (mid > n) mid = n;
            if (right > n) right = n;

            i = left;
            j = mid;
            k = left;

            while (i < mid && j < right) {
                if (a[i] <= a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while (i < mid)
                temp[k++] = a[i++];

            while (j < right)
                temp[k++] = a[j++];
        }

        for (i = 0; i < n; i++)
            a[i] = temp[i];
    }
}

// Main function
int main() {
    int original[MAX], a[MAX];
    int n, i, choice;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter non-negative integers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &original[i]);
        if (original[i] < 0) {
            printf("Negative numbers are not supported.\n");
            return 1;
        }
    }

    printf("\n1. Bubble Sort");
    printf("\n2. Selection Sort");
    printf("\n3. Insertion Sort");
    printf("\n4. Quick Sort");
    printf("\n5. Shell Sort");
    printf("\n6. Radix Sort");
    printf("\n7. Merge Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for (i = 0; i < n; i++)
        a[i] = original[i];

    switch (choice) {
        case 1: bubbleSort(a, n); break;
        case 2: selectionSort(a, n); break;
        case 3: insertionSort(a, n); break;
        case 4: quickSort(a, n); break;
        case 5: shellSort(a, n); break;
        case 6: radixSort(a, n); break;
        case 7: mergeSort(a, n); break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Sorted array: ");
    display(a, n);

    return 0;
}
