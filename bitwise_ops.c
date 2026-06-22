// Bitwise Operations in C
#include <stdio.h>

void printBinary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--)
        printf("%d", (n >> i) & 1);
}

void setBit(int* n, int pos) { *n |= (1 << pos); }
void clearBit(int* n, int pos) { *n &= ~(1 << pos); }
void toggleBit(int* n, int pos) { *n ^= (1 << pos); }
int checkBit(int n, int pos) { return (n >> pos) & 1; }
int countSetBits(int n) {
    int count = 0;
    while (n) { count += n & 1; n >>= 1; }
    return count;
}

int main() {
    int a = 60, b = 13;
    printf("a = %d (", a); printBinary(a, 8); printf(")\n");
    printf("b = %d (", b); printBinary(b, 8); printf(")\n\n");

    printf("a AND b  = %d\n", a & b);
    printf("a OR  b  = %d\n", a | b);
    printf("a XOR b  = %d\n", a ^ b);
    printf("NOT a    = %d\n", ~a);
    printf("a << 2   = %d\n", a << 2);
    printf("a >> 2   = %d\n", a >> 2);

    int x = 0b10101010;
    printf("\nSet bit 0:   "); setBit(&x, 0); printBinary(x, 8); printf("\n");
    printf("Clear bit 1: "); clearBit(&x, 1); printBinary(x, 8); printf("\n");
    printf("Toggle bit 4:"); toggleBit(&x, 4); printBinary(x, 8); printf("\n");
    printf("Set bits in %d: %d\n", a, countSetBits(a));

    return 0;
}
