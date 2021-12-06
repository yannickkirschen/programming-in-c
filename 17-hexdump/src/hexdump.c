#include <stdio.h>
#include <stdlib.h>

typedef struct MyStruct {
    int a;
    double b;
    char c[13];
} MyStruct;

void hexdump(void *adr, int length) {
    unsigned char *c_adr = adr;

    for (int i = 0; i < length; i++) {
        if (i % 16 == 0) {
            printf("%p ", c_adr);
        }

        printf("%02x ", *c_adr);

        if (i % 16 == 15) {
            printf("\n");
        }

        c_adr++;
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 4, 5, -1, -2};
    hexdump(a, sizeof(a));

//    MyStruct s = {1024, 3.1415926, "hello, world"};
//    hexdump(&s, sizeof(s));

//    void *m = malloc(1000000);
//    hexdump(m, 1000000);
}

