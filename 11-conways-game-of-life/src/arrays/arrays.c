#include "arrays.h"

bool arrayContains(const int *a, int e, size_t s) {
    for (int i = 0; i < s; i++) {
        if (a[i] == e) {
            return true;
        }
    }

    return false;
}
