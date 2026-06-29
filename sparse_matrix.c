// Sparse Matrix representation and addition in C
#include <stdio.h>
#define MAX 100

struct SparseElement {
    int row, col, val;
};

void toSparse(int mat[][MAX], int r, int c, struct SparseElement sparse[], int* count) {
    *count = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0) {
                sparse[*count].row = i;
                sparse[*count].col = j;
                sparse[*count].val = mat[i][j];
                (*count)++;
            }
}

void printSparse(struct SparseElement sparse[], int count, int r, int c) {
    printf("Sparse representation (%d x %d, %d non-zero):\n", r, c, count);
    printf("Row  Col  Value\n");
    for (int i = 0; i < count; i++)
        printf("%3d  %3d  %5d\n", sparse[i].row, sparse[i].col, sparse[i].val);
}

int main() {
    int mat[MAX][MAX] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {5, 0, 0, 7},
        {0, 0, 0, 0}
    };
    int r = 4, c = 4;

    printf("Original Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%3d ", mat[i][j]);
        printf("\n");
    }

    struct SparseElement sparse[MAX];
    int count;
    toSparse(mat, r, c, sparse, &count);
    printf("\n");
    printSparse(sparse, count, r, c);

    double sparsity = (double)(r * c - count) / (r * c) * 100;
    printf("\nSparsity: %.1f%%\n", sparsity);

    return 0;
}
