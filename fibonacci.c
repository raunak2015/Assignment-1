// Fibonacci Series in C
// Generates Fibonacci numbers using both iterative and recursive methods

#include <stdio.h>

// Recursive approach
long long fibRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative approach
void fibIterative(int n) {
    long long a = 0, b = 1, temp;
    printf("Fibonacci Series (Iterative): ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    // Iterative method
    fibIterative(n);

    // Recursive method
    printf("Fibonacci Series (Recursive): ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibRecursive(i));
    }
    printf("\n");

    // Check if a number is Fibonacci
    int num;
    printf("\nEnter a number to check if it's a Fibonacci number: ");
    scanf("%d", &num);

    int found = 0;
    long long a = 0, b = 1;
    while (a <= num) {
        if (a == num) { found = 1; break; }
        long long temp = a + b;
        a = b;
        b = temp;
    }
    printf("%d is %sa Fibonacci number.\n", num, found ? "" : "NOT ");

    return 0;
}
