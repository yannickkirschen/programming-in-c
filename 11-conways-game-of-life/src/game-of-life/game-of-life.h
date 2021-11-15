#ifndef game_of_life_h
#define game_of_life_h

#include <stdbool.h>

typedef struct GolCanvas {
    size_t x;
    size_t y;

    int data[50][30];
} GolCanvas;

void gol_print_canvas(struct GolCanvas *);

GolCanvas *gol_initialize_canvas(int);

GolCanvas *gol_initialize_glider();

void gol_next_generation(GolCanvas *);

#endif // game_of_life_h
