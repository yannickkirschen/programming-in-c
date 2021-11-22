#include <stdio.h>

#define square(x) (x) * (x)
#define incorrect_square(x) x * x

#define double_sum(x) ((x) + (x))
#define incorrect_double_sum(x) (x) + (x)

int main() {
    int correctSquare = square(4 + 5);
    printf("%i\n", correctSquare);

    int incorrectSquare = incorrect_square(4 + 5);
    printf("%i\n", incorrectSquare);

    int correctDoubleSum = 2 * double_sum(3);
    printf("%i\n", correctDoubleSum);

    int incorrectDoubleSum = 2 * incorrect_double_sum(3);
    printf("%i\n", incorrectDoubleSum);
}
