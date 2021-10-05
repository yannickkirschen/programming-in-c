/* Investigate the precision and borders of floating point numbers */

// TO DO 1: The program doesn't seem to stop. Maybe f and d should be increased faster?
// TO DO 2: How does the 'limit behaviour' differ from integer numbers?
// TO DO 3: Insert a comparison to check when the float and double values are different from each other,
//          print the difference
// TO DO 4: Related to TO-DO 1: How can you find the maximum number fast, but also with high precision?
// TO DO 5: (Optional) Competition: Who generates the highest float number?
//          (But not NaN, and without using predefined limit-constants)

// There is no floating point overflow in C!

#include <float.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Maximum float: %f\n", FLT_MAX);
    printf("Maximum double: %f\n", DBL_MAX);

    float f = 0;
    double d = 0;

    while (1) {
        f++;
        d++;

        if (f != d) {
            printf("Difference! float: %f vs double: %f\n", f, d);
            break;
        }
    }
}


