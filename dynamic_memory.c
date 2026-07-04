// Dynamic Memory Allocation in C - malloc, calloc, realloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demonstrateMalloc() {
    printf("=== malloc ===\n");
    int n = 5;
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) { printf("malloc failed!\n"); return; }

    for (int i = 0; i < n; i++) arr[i] = (i + 1) * 10;
    printf("malloc array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

void demonstrateCalloc() {
    printf("\n=== calloc (zero-initialized) ===\n");
    int* arr = (int*)calloc(5, sizeof(int));
    if (!arr) { printf("calloc failed!\n"); return; }

    printf("calloc array (before assign): ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]); // all zeros
    printf("\n");

    for (int i = 0; i < 5; i++) arr[i] = i * i;
    printf("calloc array (after assign):  ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

void demonstrateRealloc() {
    printf("\n=== realloc ===\n");
    int* arr = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) arr[i] = i + 1;

    arr = (int*)realloc(arr, 6 * sizeof(int));
    if (!arr) { printf("realloc failed!\n"); return; }

    for (int i = 3; i < 6; i++) arr[i] = (i + 1) * 2;
    printf("Expanded array: ");
    for (int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

int main() {
    demonstrateMalloc();
    demonstrateCalloc();
    demonstrateRealloc();
    return 0;
}
