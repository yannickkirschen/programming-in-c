/* prime sieve of Eratosthenes */

// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably?

#include <stdio.h>

int main() {
    int maxPrime;
    printf("Enter the maximum prime number to calculate to: ");
    scanf("%d", &maxPrime);

    char isPrime[maxPrime];
    for (int i = 0; i < maxPrime; i++) {
        isPrime[i] = 1;
    }

    for (int i = 2; i < maxPrime; i++) {
        for (int j = 2 * i; j < maxPrime; j = j + i) {
            isPrime[j] = 0;
        }
    }

    printf("Prime numbers are: ");
    for (int i = 2; i < maxPrime; i++) {
        if (isPrime[i] > 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
}
