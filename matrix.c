// Matrix Operations in C
#include <stdio.h>
#define MAX 10

void inputMatrix(int mat[][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void printMatrix(int mat[][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}

void multiplyMatrix(int a[][MAX], int b[][MAX], int res[][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

void transposeMatrix(int mat[][MAX], int res[][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[j][i] = mat[i][j];
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter Matrix A:\n");
    inputMatrix(a, r1, c1);

    printf("Enter dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    printf("Enter Matrix B:\n");
    inputMatrix(b, r2, c2);

    multiplyMatrix(a, b, res, r1, c1, c2);
    printf("Product of A x B:\n");
    printMatrix(res, r1, c2);

    transposeMatrix(a, res, r1, c1);
    printf("Transpose of A:\n");
    printMatrix(res, c1, r1);

    return 0;
}
