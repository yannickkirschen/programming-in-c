#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void utils_clear() {
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void utils_pause() {
    printf("Press enter to continue ...\n");
    getchar();
}

void utils_input_error() {
    printf("Wrong input.\n");
    printf("\n");
    utils_pause();
}
