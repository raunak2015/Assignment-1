// Pointers in C - basics, pointer arithmetic, arrays
#include <stdio.h>
#include <stdlib.h>

void swapUsingPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sumArray(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(arr + i);
    return sum;
}

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;
    while (start < end) {
        swapUsingPointers(start, end);
        start++; end--;
    }
}

int main() {
    // Basic pointer
    int x = 42;
    int* ptr = &x;
    printf("Value: %d, Address: %p\n", x, (void*)ptr);
    printf("Via pointer: %d\n", *ptr);

    // Swap using pointers
    int a = 10, b = 20;
    printf("\nBefore swap: a=%d, b=%d\n", a, b);
    swapUsingPointers(&a, &b);
    printf("After swap:  a=%d, b=%d\n", a, b);

    // Array with pointer arithmetic
    int arr[] = {3, 7, 1, 9, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nSum of array: %d\n", sumArray(arr, n));

    reverseArray(arr, n);
    printf("Reversed: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Dynamic allocation
    int* dynArr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) dynArr[i] = (i + 1) * 10;
    printf("Dynamic array: ");
    for (int i = 0; i < 5; i++) printf("%d ", dynArr[i]);
    printf("\n");
    free(dynArr);

    return 0;
}
