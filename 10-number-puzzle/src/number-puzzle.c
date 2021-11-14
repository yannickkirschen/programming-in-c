// number_puzzle.c

//  Write a number puzzle program by completing the TO DOs
//  TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
//           -1 should mark the empty field.
//  TO DO 2: get key and move pieces accordingly (if keystroke is valid)
//  TO DO 3: Check, if puzzle is in correct order -> set sorted=1
//  TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
//               (Use a special character e.g. a block rather than '*')
//               (Also, mark the empty field rather than showing -1)
//
//           *********************
//           *  1 *  2 *  3 *  4 *
//           *********************
//           *  5 *  6 *  7 *  8 *
//           *********************
//           *  9 * 10 * 11 * 12 *
//           *********************
//           * 13 * 14 * 15 ******
//           *********************
//
//  TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

bool puzzleContains(int puzzle[4][4], int number) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == number) {
                return true;
            }
        }
    }

    return false;
}

bool puzzleIsSorted(int puzzle[4][4]) {
    int last = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n = puzzle[i][j];

            if (last < n) {
                last = n;
            } else {
                return false;
            }
        }
    }

    return true;
}

void printPuzzle(int puzzle[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n = puzzle[i][j];
            if (n == -1) {
                printf("__ ");
            } else {
                printf("%2d ", n);
            }
        }
        printf("\n");
    }
}

void initializePuzzle(int puzzle[4][4]) {
    for (int i = 0; i < 4; i++) {
        int j = 0;

        while (j < 4) {
            int number = rand() % 16;
            if (number == 0) {
                number = -1;
            }

            if (!puzzleContains(puzzle, number)) {
                puzzle[i][j] = number;
                j++;
            }
        }
    }
}

void moveInPuzzle(int puzzle[4][4], enum Direction direction) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n = puzzle[i][j];

            if (n == -1) {
                int newI = -1;
                int newJ = -1;

                switch (direction) {
                    case UP:
                        newI = i - 1;
                        newJ = j;
                        if (newI < 0) {
                            printf("Cannot move up!\n");
                        }
                        break;
                    case DOWN:
                        newI = i + 1;
                        newJ = j;
                        if (newI > 3) {
                            printf("Cannot move down!\n");
                        }
                        break;
                    case LEFT:
                        newJ = j - 1;
                        newI = i;
                        if (newJ < 0) {
                            printf("Cannot move left!\n");
                        }
                        break;
                    case RIGHT:
                        newJ = j + 1;
                        newI = i;
                        if (newJ > 3) {
                            printf("Cannot move right!\n");
                        }
                        break;
                    default:
                        printf("No direction specified.");
                }

                if (newI != -1 && newJ != -1) {
                    puzzle[i][j] = puzzle[newI][newJ];
                    puzzle[newI][newJ] = -1;
                }
                return;
            }
        }
    }
}

int main() {
    srand(time(0));

    int puzzle[4][4] = {0};
    initializePuzzle(puzzle);

    char key;

    while (!puzzleIsSorted(puzzle)) {
        system("clear"); // Linux/UNIX only!
        printPuzzle(puzzle);

        printf("(wasd)");
        scanf("%c", &key);
        getchar();

        switch (key) {
            case 'w':
                moveInPuzzle(puzzle, UP);
                break;
            case 'a':
                moveInPuzzle(puzzle, LEFT);
                break;
            case 's':
                moveInPuzzle(puzzle, DOWN);
                break;
            case 'd':
                moveInPuzzle(puzzle, RIGHT);
                break;
            case 'q':
                return 0;
            default:
                printf("Wrong input! Use WASD.\n");
        }
    }
}
