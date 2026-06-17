// GCD and LCM using Euclidean Algorithm
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int gcdRecursive(int a, int b) {
    return b == 0 ? a : gcdRecursive(b, a % b);
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("LCM(%d, %d) = %d\n", a, b, lcm(a, b));
    printf("GCD Recursive(%d, %d) = %d\n", a, b, gcdRecursive(a, b));

    // GCD of array
    int arr[] = {12, 18, 24, 36};
    int n = 4;
    int g = arr[0];
    for (int i = 1; i < n; i++) g = gcd(g, arr[i]);
    printf("\nGCD of {12,18,24,36} = %d\n", g);

    return 0;
}
