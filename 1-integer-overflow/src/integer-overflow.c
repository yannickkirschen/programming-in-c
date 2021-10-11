/* Check when integer numbers are overflowing */

// TO DO 1: complete the overflow detection for other types
// TO DO 2: extend this to unsigned integers
// TO DO 3: stop counting after first overflow
// TO DO 4: estimate how many operations are performed per second.
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe?

#include <stdio.h>
#include <time.h>

void iterChar() {
    char c = 0;
    char tmp;

    while (1) {
        tmp = c;
        c++;

        if (tmp > c) {
            printf("char overflow %d -> %d\n", tmp, c);
            break;
        }
    }
}

void iterShort() {
    short s = 0;
    short tmp;

    while (1) {
        tmp = s;
        s++;

        if (tmp > s) {
            printf("short overflow %d -> %d\n", tmp, s);
            break;
        }
    }
}

void iterInt() {
    int i = 0;
    int tmp;

    while (1) {
        tmp = i;
        i++;

        if (tmp > i) {
            printf("int overflow %d -> %d\n", tmp, i);
            break;
        }
    }
}

void iterUnsignedInt() {
    unsigned int i = 0;
    unsigned int tmp;

    while (1) {
        tmp = i;
        i++;


        if (tmp == -1) {
            printf("unsigned int overflow %u -> %u\n", tmp, i);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    iterChar();
    iterShort();

    unsigned long start = (unsigned long) time(NULL);
    printf("Start int calculation: %lu\n", start);
    iterInt();
    unsigned long end = (unsigned long) time(NULL);
    printf("End int calculation: %lu (time needed: %lu)\n", end, end - start);

    iterUnsignedInt();
}


