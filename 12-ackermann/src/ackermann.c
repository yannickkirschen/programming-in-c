#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ackermann(long m, long n) {
    return m == 0 ? n + 1 : ackermann(m - 1, n == 0 ? 1 : ackermann(m, n - 1));
}

long verbose_ackermann(long m, long n) {
    static int depth = 0;
    static int totalCounter = 0;

    depth++;
    totalCounter++;

    printf("%i) [depth=%i] m=%ld  n=%ld  ", totalCounter, depth, m, n);
    for (int i = 0; i < depth; i++) {
        printf(".");
    }
    printf("\n");

    long a;
    if (m == 0) {
        a = n + 1;
    } else {
        if (n == 0) {
            a = verbose_ackermann(m - 1, 1);
        } else {
            a = verbose_ackermann(m - 1, verbose_ackermann(m, n - 1));
        }
    }

    depth--;
    return a;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ackermann <m>, <n>\n");
        return -1;
    }

    long m = strtol(argv[1], NULL, 10);
    long n = strtol(argv[2], NULL, 10);
    long a;

    if (argc == 4 && strcmp(argv[3], "-v") == 0) {
        a = verbose_ackermann(m, n);
    } else {
        a = ackermann(m, n);
    }

    printf("A(%ld, %ld) = %ld\n", m, n, a);
}
