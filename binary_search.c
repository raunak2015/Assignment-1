// Binary Search in C - Iterative and Recursive
#include <stdio.h>

int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, high, target);
    else return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Enter number to search: ");
    scanf("%d", &target);

    int idx1 = binarySearchIterative(arr, n, target);
    if (idx1 != -1)
        printf("Iterative: Found %d at index %d\n", target, idx1);
    else
        printf("Iterative: %d not found\n", target);

    int idx2 = binarySearchRecursive(arr, 0, n - 1, target);
    if (idx2 != -1)
        printf("Recursive: Found %d at index %d\n", target, idx2);
    else
        printf("Recursive: %d not found\n", target);

    return 0;
}
