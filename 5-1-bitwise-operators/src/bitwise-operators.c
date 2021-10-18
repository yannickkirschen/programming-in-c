// TO DO 1: Something is wrong with the output
//	        Hint: put the output first into an additional variable m,
//	        use bitwise operators and count the digits
// TO DO 2: A second number should be entered and
//	        both numbers should be combined with the various bitwise
//	        operators before providing the output
// TO DO 3: Use signed integers and see how negative numbers
//          are presented in binary format

#include <stdio.h>

void printBinary(int i) {
    printf("Binary representation of %i: ", i);

    for (int c = sizeof(int) * 8 - 1; c >= 0; c--) {
        printf("%d", i >> c & 1);
    }

    printf("\n");
}

void printUnsignedBinary(unsigned int i) {
    printf("Binary representation of %u: ", i);

    for (int c = sizeof(int) * 8 - 1; c >= 0; c--) {
        printf("%d", i >> c & 1);
    }

    printf("\n");
}

int main() {
    unsigned int n1;
    unsigned int n2;
    int n3;

    printf("Enter an integer number: ");
    scanf("%u", &n1);

    printf("Enter another integer number: ");
    scanf("%u", &n2);

    printf("Enter a negative integer number: ");
    scanf("%i", &n3);

    printUnsignedBinary(n1);
    printUnsignedBinary(n2);
    printBinary(n3);
}
