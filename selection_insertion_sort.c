// Selection Sort and Insertion Sort
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        if (minIdx != i) {
            int temp = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = temp;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int a[] = {64, 25, 12, 22, 11};
    int b[] = {64, 25, 12, 22, 11};
    int n = 5;

    printf("Original: "); printArr(a, n);

    selectionSort(a, n);
    printf("Selection Sort: "); printArr(a, n);

    insertionSort(b, n);
    printf("Insertion Sort: "); printArr(b, n);

    return 0;
}
