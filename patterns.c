// Pattern Printing in C
#include <stdio.h>

void starTriangle(int n) {
    printf("Right Triangle:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }
}

void numberPyramid(int n) {
    printf("\nNumber Pyramid:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf("  ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("%d ", i);
        printf("\n");
    }
}

void diamondPattern(int n) {
    printf("\nDiamond Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
}

void pascalTriangle(int n) {
    printf("\nPascal's Triangle:\n");
    for (int i = 0; i < n; i++) {
        int c = 1;
        for (int j = 0; j <= n - i; j++) printf("   ");
        for (int j = 0; j <= i; j++) {
            printf("%6d", c);
            c = c * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter rows: ");
    scanf("%d", &n);
    starTriangle(n);
    numberPyramid(n);
    diamondPattern(n);
    pascalTriangle(n);
    return 0;
}
