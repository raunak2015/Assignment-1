// Linear Search and its variations
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// Returns all occurrences
int linearSearchAll(int arr[], int n, int key, int results[]) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) results[count++] = i;
    return count;
}

// Sentinel linear search (slightly faster)
int sentinelSearch(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key) i++;
    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) return i;
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 3, 7, 8, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Enter key to search: ");
    scanf("%d", &key);

    int idx = linearSearch(arr, n, key);
    if (idx != -1) printf("First occurrence at index %d\n", idx);
    else printf("Not found\n");

    int results[50], count;
    count = linearSearchAll(arr, n, key, results);
    if (count > 0) {
        printf("All occurrences at: ");
        for (int i = 0; i < count; i++) printf("%d ", results[i]);
        printf("(%d total)\n", count);
    }

    printf("Sentinel search: index %d\n", sentinelSearch(arr, n, key));

    return 0;
}
