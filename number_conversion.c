// Number System Conversion in C
// Binary, Octal, Decimal, Hexadecimal conversions
#include <stdio.h>
#include <string.h>

void decToBinary(int n) {
    if (n == 0) { printf("0"); return; }
    int bits[32], count = 0;
    while (n > 0) { bits[count++] = n % 2; n /= 2; }
    for (int i = count - 1; i >= 0; i--) printf("%d", bits[i]);
}

void decToOctal(int n) { printf("%o", n); }
void decToHex(int n) { printf("%X", n); }

int binaryToDec(long long bin) {
    int dec = 0, base = 1;
    while (bin > 0) {
        int rem = bin % 10;
        dec += rem * base;
        base *= 2;
        bin /= 10;
    }
    return dec;
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    printf("Binary:      "); decToBinary(n); printf("\n");
    printf("Octal:       "); decToOctal(n);  printf("\n");
    printf("Hexadecimal: "); decToHex(n);    printf("\n");

    long long bin;
    printf("\nEnter binary number: ");
    scanf("%lld", &bin);
    printf("Decimal equivalent: %d\n", binaryToDec(bin));

    return 0;
}
