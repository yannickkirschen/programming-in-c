#ifndef game_of_life_h
#define game_of_life_h

#include <stdbool.h>

typedef struct Canvas {
    size_t x;
    size_t y;

    int data[50][30];
} Canvas;

void printCanvas(struct Canvas *);

Canvas *initializeCanvas(int);

Canvas *initializeGlider();

void nextGeneration(Canvas *);

#endif // game_of_life_h
