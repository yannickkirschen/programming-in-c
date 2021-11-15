#include "string-utils.h"

void insertIntoString(char *a, const char *b, int maxLength) {
    int indexA = 0;
    int indexB = 0;

    while (a[indexA]) {
        indexA++;
    }

    while (b[indexB] && indexB < maxLength) {
        a[indexA] = b[indexB];
        indexA++;
        indexB++;
    }
}
