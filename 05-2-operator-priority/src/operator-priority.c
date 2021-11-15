// TO DO 1: Think about the expressions: What will be the output of the program?
//          ...only then remove the last line und compile/run the program. Were your predictions correct?
// TO DO 2: With your neighbour: Exchange difficult expressions with each other
//          - can you solve them without running the program?
//          - use brackets to structure the expressions without changing their values

#include <stdio.h>

int main() {
    int a = 1; // 0000 0001
    int b = 2; // 0000 0010
    int c = 3; // 0000 0011
    int d = 4; // 0000 0100

    int result;

    result = a - b - c;
    printf("result is %d\n", result); // -4

    // a    0000 0001
    // << 2 0000 0100
    // << 3 0010 0000
    result = a << b << c;
    printf("result is %d\n", result); // 32

    result = d / b / b;
    printf("result is %d\n", result); // 1

    result = a > b ? b > c ? a : b : c;
    printf("result is %d\n", result); // 3
}
