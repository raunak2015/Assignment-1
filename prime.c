// Prime Numbers - Sieve of Eratosthenes and primality check
#include <stdio.h>
#include <string.h>
#define MAX 1000

int isPrime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

void sieveOfEratosthenes(int limit) {
    int sieve[MAX];
    memset(sieve, 1, sizeof(sieve));
    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i <= limit; i++)
        if (sieve[i])
            for (int j = i * i; j <= limit; j += i)
                sieve[j] = 0;

    printf("Primes up to %d: ", limit);
    for (int i = 2; i <= limit; i++)
        if (sieve[i]) printf("%d ", i);
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number to check if prime: ");
    scanf("%d", &n);
    printf("%d is %s prime.\n", n, isPrime(n) ? "a" : "not a");

    int limit;
    printf("Enter limit for Sieve of Eratosthenes: ");
    scanf("%d", &limit);
    if (limit < MAX) sieveOfEratosthenes(limit);
    else printf("Limit too large (max %d)\n", MAX - 1);

    return 0;
}
