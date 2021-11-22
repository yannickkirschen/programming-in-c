#include <libc.h>
#include <stdio.h>
#include <stdlib.h>

long get_first_non_zero_index(const int a[], long n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return i;
        }
    }

    return n;
}

void hanoi_display(long n, int towers[3][n]) {
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif

    for (int i = 0; i < n; i++) {
        printf("  %i  %i  %i\n", towers[0][i], towers[1][i], towers[2][i]);
    }

    sleep(1);
}

void hanoi_move_sticks(long n, int towers[3][n], int start, int goal) {
    int disc;

    long indexStart;
    int *stickStart = towers[start];
    indexStart = get_first_non_zero_index(stickStart, n);
    disc = stickStart[indexStart];
    stickStart[indexStart] = 0;

    int *stickEnd = towers[goal];
    stickEnd[get_first_non_zero_index(stickEnd, n) - 1] = disc;


}

void hanoi(long n, int start, int goal, int helper, long l, int towers[3][l]) {
    if (n > 0) {
        hanoi(n - 1, start, helper, goal, l, towers);
        hanoi_move_sticks(l, towers, start, goal);
        hanoi_display(l, towers);
        hanoi(n - 1, helper, goal, start, l, towers);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: hanoi <number of disks>\n");
        return -1;
    }

    long n = strtol(argv[1], NULL, 10);

    int towers[3][n];
    for (int i = 0; i < n; i++) {
        towers[0][i] = i + 1;
        towers[1][i] = 0;
        towers[2][i] = 0;
    }

    hanoi_display(n, towers);
    hanoi(n, 0, 1, 2, n, towers);
}
