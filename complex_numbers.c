// Complex Number Operations using Structures
#include <stdio.h>
#include <math.h>

struct Complex {
    double real;
    double imag;
};

struct Complex add(struct Complex a, struct Complex b) {
    return (struct Complex){a.real + b.real, a.imag + b.imag};
}

struct Complex subtract(struct Complex a, struct Complex b) {
    return (struct Complex){a.real - b.real, a.imag - b.imag};
}

struct Complex multiply(struct Complex a, struct Complex b) {
    return (struct Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

struct Complex divide(struct Complex a, struct Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    return (struct Complex){
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    };
}

double magnitude(struct Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

void print(struct Complex c) {
    if (c.imag >= 0) printf("%.2f + %.2fi", c.real, c.imag);
    else printf("%.2f - %.2fi", c.real, -c.imag);
}

int main() {
    struct Complex a = {3.0, 4.0};
    struct Complex b = {1.0, -2.0};

    printf("a = "); print(a); printf("\n");
    printf("b = "); print(b); printf("\n\n");

    printf("a + b = "); print(add(a, b)); printf("\n");
    printf("a - b = "); print(subtract(a, b)); printf("\n");
    printf("a * b = "); print(multiply(a, b)); printf("\n");
    printf("a / b = "); print(divide(a, b)); printf("\n");
    printf("|a|   = %.2f\n", magnitude(a));

    return 0;
}
