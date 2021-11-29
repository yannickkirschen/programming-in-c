#include <stdio.h>

typedef struct Test {
	char a;
	int b;
	char c;
	int d;
} Test;

const int GLOBAL_INT = 1000;

int fib(int n) {
    printf("Address of n (fib): %p\n", &n);
    return n <= 1 ? n: fib(n - 1) + fib(n - 2);
}

int main() {
    printf("sizeof(char)  : %lu Byte\n", sizeof(char));
    printf("sizeof(short) : %lu Byte\n", sizeof(short));
    printf("sizeof(int)   : %lu Byte\n", sizeof(int));
    printf("sizeof(float) : %lu Byte\n", sizeof(float));
    printf("sizeof(long)  : %lu Byte\n", sizeof(long));
    printf("sizeof(double): %lu Byte\n", sizeof(double));
    printf("sizeof(Test) [char, int, char, int]: %lu Byte\n", sizeof(Test));
    printf("sizeof(int[10]): %lu Byte\n", sizeof(int[10]));

    int i = 100;
    printf("Address of i: %p\n", &i);

    Test t = {'B', 100, 'C', 200};
    printf("Address of t: %p\n", &t);

    printf("Address of GLOBAL_INT: %p\n", &GLOBAL_INT);

    int n = fib(10);
    printf("Address of n      : %p\n", &n);
}
