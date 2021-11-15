#ifndef game_of_life_h
#define game_of_life_h

#include <stdbool.h>

typedef struct GolCanvas {
    size_t x;
    size_t y;

    int data[50][30];

    int historyLength;
    struct GolHistory *firstHistory;
    struct GolHistory *lastHistory;
} GolCanvas;

typedef struct GolHistory {
    int hash;

    struct GolHistory *next;
} GolHistory;

void gol_print_canvas(struct GolCanvas *);

GolCanvas *gol_initialize_canvas(int, int);

GolCanvas *gol_initialize_glider(int, int);

void gol_next_generation(GolCanvas *);

int gol_hash(struct GolCanvas *);

void gol_add_to_history(GolCanvas *, int, int);

bool is_oscillating(int);

#endif // game_of_life_h
