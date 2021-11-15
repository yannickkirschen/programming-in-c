#include <string.h>
#include <unistd.h>

#include "game-of-life/game-of-life.h"

int main(int argc, char *argv[]) {
    GolCanvas *canvas;

    if (argc == 2 && strcmp(argv[1], "glider") == 0) {
        canvas = gol_initialize_glider();
    } else {
        canvas = gol_initialize_canvas(100);
    }

    while (true) {
        gol_print_canvas(canvas);
        sleep(1);
        gol_next_generation(canvas);
    }
}
