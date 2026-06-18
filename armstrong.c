// Armstrong Number and Perfect Number checker
#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    int count = 0;
    while (n > 0) { count++; n /= 10; }
    return count;
}

int isArmstrong(int n) {
    int original = n, digits = countDigits(n), sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += (int)pow(digit, digits);
        n /= 10;
    }
    return sum == original;
}

int isPerfect(int n) {
    if (n <= 1) return 0;
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum == n;
}

int main() {
    printf("Armstrong numbers up to 10000:\n");
    for (int i = 1; i <= 10000; i++)
        if (isArmstrong(i)) printf("%d ", i);
    printf("\n");

    printf("\nPerfect numbers up to 10000:\n");
    for (int i = 1; i <= 10000; i++)
        if (isPerfect(i)) printf("%d ", i);
    printf("\n");

    int n;
    printf("\nEnter a number to check: ");
    scanf("%d", &n);
    printf("%d is %san Armstrong number\n", n, isArmstrong(n) ? "" : "NOT ");
    printf("%d is %sa Perfect number\n", n, isPerfect(n) ? "" : "NOT ");

    return 0;
}
