#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../arrays/arrays.h"
#include "game-of-life.h"

void printCanvas(struct Canvas *canvas) {
    system("clear"); // Linux/UNIX only!

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            printf("%c", " x"[canvas->data[x][y]]);
        }

        printf("\n");
    }
}

Canvas *initializeCanvas(int n) {
    Canvas *canvas = malloc(sizeof(Canvas));
    canvas->x = 50;
    canvas->y = 30;

    int aliveCells[n];
    size_t mod = canvas->x * canvas->y;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        int r;
        do {
            r = rand() % mod;
        } while (arrayContains(aliveCells, r, n));

        aliveCells[i] = r;
    }

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            canvas->data[x][y] = arrayContains(aliveCells, x * y, n) ? 1 : 0;
        }
    }

    return canvas;
}

Canvas *initializeGlider() {
    Canvas *canvas = malloc(sizeof(Canvas));
    canvas->x = 50;
    canvas->y = 30;

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            canvas->data[x][y] = 0;
        }
    }

    canvas->data[1][0] = 1;
    canvas->data[2][1] = 1;
    canvas->data[0][2] = 1;
    canvas->data[1][2] = 1;
    canvas->data[2][2] = 1;

    return canvas;
}

void nextGeneration(Canvas *canvas) {
    int data[canvas->x][canvas->y];

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            int neighbours = 0;

            // Right
            if (x + 1 < canvas->x && canvas->data[x + 1][y]) {
                neighbours++;
            }

            // Left
            if (x - 1 < canvas->x && canvas->data[x - 1][y]) {
                neighbours++;
            }

            // Top
            if (y + 1 < canvas->y && canvas->data[x][y + 1]) {
                neighbours++;
            }

            // Bottom
            if (y - 1 < canvas->y && canvas->data[x][y - 1]) {
                neighbours++;
            }

            // Top Left
            if (x - 1 < canvas->x &&
                y + 1 < canvas->y &&
                canvas->data[x - 1][y + 1]) {
                neighbours++;
            }

            // Top Right
            if (x + 1 < canvas->x &&
                y + 1 < canvas->y &&
                canvas->data[x + 1][y + 1]) {
                neighbours++;
            }

            // Bottom Left
            if (x - 1 < canvas->x &&
                y - 1 < canvas->y &&
                canvas->data[x - 1][y - 1]) {
                neighbours++;
            }

            // Bottom Left
            if (x + 1 < canvas->x &&
                y - 1 < canvas->y &&
                canvas->data[x + 1][y - 1]) {
                neighbours++;
            }

            if (!canvas->data[x][y] && neighbours == 3) { // reproduction
                data[x][y] = 1;
            } else if (canvas->data[x][y]) {
                if (neighbours < 2 || neighbours > 3) { // under-/overpopulation
                    data[x][y] = 0;
                } else if (neighbours == 2 || neighbours == 3) { // live
                    data[x][y] = 1;
                }
            } else {
                data[x][y] = 0;
            }
        }
    }

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            canvas->data[x][y] = data[x][y];
        }
    }
}
