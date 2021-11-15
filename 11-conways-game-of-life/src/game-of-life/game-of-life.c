#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../arrays/arrays.h"
#include "game-of-life.h"

void gol_print_canvas(struct GolCanvas *canvas) {
    system("clear"); // Linux/UNIX only!

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            printf("%c", " x"[canvas->data[x][y]]);
        }

        printf("\n");
    }
}

GolCanvas *gol_initialize_canvas(int length, int height) {
    GolCanvas *canvas = malloc(sizeof(GolCanvas));
    canvas->x = length;
    canvas->y = height;
    canvas->historyLength = 0;
    canvas->firstHistory = NULL;
    canvas->lastHistory = NULL;

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            canvas->data[x][y] = rand() % 5 == 1 ? 1 : 0;
        }
    }

    return canvas;
}

GolCanvas *gol_initialize_glider(int length, int height) {
    GolCanvas *canvas = malloc(sizeof(GolCanvas));
    canvas->x = length;
    canvas->y = height;
    canvas->historyLength = 0;
    canvas->firstHistory = NULL;
    canvas->lastHistory = NULL;

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

int calculateNeighbours(struct GolCanvas *canvas, int x, int y) {
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

    return neighbours;
}

void gol_next_generation(GolCanvas *canvas) {
    int data[canvas->x][canvas->y];

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            int neighbours = calculateNeighbours(canvas, x, y);

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

int gol_hash(struct GolCanvas *canvas) {
    int hash = 0;

    for (int y = 0; y < canvas->y; y++) {
        for (int x = 0; x < canvas->x; x++) {
            if (canvas->data[x][y]) {
                hash += (x + 1) * (10 * y + 7);
            }
        }
    }

    return hash;
}

void gol_add_to_history(GolCanvas *canvas, int hash, int threshold) {
    if (canvas->historyLength >= threshold) {
        GolHistory *tmp = canvas->firstHistory;
        canvas->firstHistory = tmp->next;

        if (canvas->firstHistory == NULL) {
            canvas->lastHistory = NULL;
        }

        free(tmp);
        canvas->historyLength--;
    }

    GolHistory *history = malloc(sizeof(GolHistory));
    history->hash = hash;

    if (canvas->firstHistory == NULL) {
        canvas->firstHistory = history;
        canvas->lastHistory = history;
        history->next = NULL;
    } else {
        canvas->lastHistory->next = history;
        canvas->lastHistory = history;
    }

    canvas->historyLength++;

    printf("\n\n");
    GolHistory *h = canvas->firstHistory;
    int i = 0;
    while (h) {
        printf("%i) Hash: %i\n", ++i, h->hash);

        h = h->next;
    }
}
