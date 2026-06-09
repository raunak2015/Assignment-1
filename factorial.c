// Factorial using recursion and iteration
#include <stdio.h>

long long factRecursive(int n) {
    if (n <= 1) return 1;
    return n * factRecursive(n - 1);
}

long long factIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

// Tail recursive version
long long factTail(int n, long long acc) {
    if (n <= 1) return acc;
    return factTail(n - 1, n * acc);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    printf("Factorial(%d) [Iterative] = %lld\n", n, factIterative(n));
    printf("Factorial(%d) [Recursive] = %lld\n", n, factRecursive(n));
    printf("Factorial(%d) [Tail Rec]  = %lld\n", n, factTail(n, 1));

    return 0;
}
