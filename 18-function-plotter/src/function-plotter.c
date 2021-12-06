#include <math.h>
#include <stdio.h>

typedef struct Range {
    double x;
    double y;

    double stepX;
    double stepY;
} Range;

void draw_function(double (*f)(double), Range *range) {
    for (double y = range->y; y >= -range->y; y -= range->stepY) {
        for (double x = -range->x; x < range->x; x += range->stepX) {
            printf("%c", (f(x) >= y && f(x) < y + range->stepY) ? '*' : ' ');
        }
        printf("\n");
    }
}

void
draw_two_functions(double (*f1)(double), double (*f2)(double), Range *range) {
    for (double y = range->y; y >= -range->y; y -= range->stepY) {
        for (double x = -range->x; x < range->x; x += range->stepX) {
            printf("%c", ((f1(x) >= y && f1(x) < y + range->stepY) ||
                          (f2(x) >= y && f2(x) < y + range->stepY)) ? '*'
                                                                    : ' ');
        }
        printf("\n");
    }
}

int main() {
    Range range = {10, 1, 0.1, 0.1};

    double (*f1)(double) = sin;
    double (*f2)(double) = cos;
//    draw_function(f1, &range);
    draw_two_functions(f1, f2, &range);
}
