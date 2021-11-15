#include <string.h>
#include <unistd.h>

#include "game-of-life/game-of-life.h"

int main(int argc, char *argv[]) {
    Canvas *canvas;

    if (argc == 2 && strcmp(argv[1], "glider") == 0) {
        canvas = initializeGlider();
    } else {
        canvas = initializeCanvas(100);
    }

    while (true) {
        printCanvas(canvas);
        sleep(1);
        nextGeneration(canvas);
    }
}
