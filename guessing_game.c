// Number Guessing Game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;
    int maxAttempts = 7;

    printf("===== Number Guessing Game =====\n");
    printf("Guess the number between 1 and 100\n");
    printf("You have %d attempts!\n\n", maxAttempts);

    while (attempts < maxAttempts) {
        printf("Attempt %d/%d - Your guess: ", attempts + 1, maxAttempts);
        scanf("%d", &guess);
        attempts++;

        if (guess == secret) {
            printf("Correct! You guessed it in %d attempt(s)!\n", attempts);
            if (attempts == 1) printf("Lucky! First try!\n");
            else if (attempts <= 3) printf("Excellent!\n");
            else printf("Good job!\n");
            return 0;
        } else if (guess < secret) {
            printf("Too low!");
        } else {
            printf("Too high!");
        }

        int remaining = maxAttempts - attempts;
        if (remaining > 0)
            printf(" %d attempts remaining.\n", remaining);
        else
            printf("\n");
    }

    printf("Game over! The number was %d\n", secret);
    return 0;
}
