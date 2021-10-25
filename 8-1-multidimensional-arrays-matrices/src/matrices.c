/* matrices */

// TO DO 1: Extend the programm such that the result is printed
// TO DO 2: Extend the programm such that it also calculates the matriceProduct of the two 3x3 matrices.
// TO DO 3: What happens when you make a mistake with the indices, e.g. read/write m1[3][0], m1[4][0], m1[0][4] etc.?

#include <stdio.h>

#include "matrices.h"

int main() {
    float m1[3][3] = {{12, 5.3f,  10.0f},
                      {5,  10.2f, -2},
                      {1,  -1,    3}};
    float m2[3][3] = {{2.1f, -3,   1.5f},
                      {10,   -12,  3.1f},
                      {4,    8.2f, -2}};

    matrixSum(m1, m2);
    printf("\n");

    matrixProduct(m1, m2);
}

void printMatrix(float m[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", m[i][j]);
        }

        printf("\n");
    }
}

void matrixSum(float m1[3][3], float m2[3][3]) {
    float sum[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i][j] = m1[i][j] + m1[i][j];
        }
    }

    printMatrix(sum);
}

void matrixProduct(float m1[3][3], float m2[3][3]) {
    float product[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    printMatrix(product);
}
