// Recursion examples - Tower of Hanoi, Power, Sum of digits
#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

long long power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long half = power(base, exp / 2);
        return half * half;
    }
    return base * power(base, exp - 1);
}

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int digitalRoot(int n) {
    if (n < 10) return n;
    return digitalRoot(sumDigits(n));
}

int main() {
    int n;
    printf("Tower of Hanoi (enter disks): ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');

    printf("\n2^10 = %lld\n", power(2, 10));
    printf("3^5  = %lld\n", power(3, 5));

    int num;
    printf("\nEnter number for digit sum: ");
    scanf("%d", &num);
    printf("Sum of digits: %d\n", sumDigits(num));
    printf("Digital root:  %d\n", digitalRoot(num));

    return 0;
}
