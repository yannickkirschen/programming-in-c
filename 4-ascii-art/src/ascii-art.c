// TO DO 1: Can you explain why a circle is displayed?
// TO DO 2: Play around with the operators to create beautiful ascii art
//          - use different arithmetics
//          - use different comparisons
//          - use different characters (e.g. more than two)

#include <stdio.h>

int main(int argc, char *argv[]) {
    int x;
    int y;
    int v;

    for (y = 0; y < 30; y++) {
        for (x = 0; x < 30; x++) {
            v = (x - 15) * (x - 15) + (y - 15) * (y - 15); // radius ^ 2

//            if (v > 60) {
            if ((v % 100) > 10) {
                printf(" ");
            } else {
                printf("o");
            }
        }

        printf("\n");
    }
}
