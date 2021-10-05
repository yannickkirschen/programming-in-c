/* Draw a table of all asci characters */

// TO DO 1: Extend the program to suppress special characters which derange the table
// TO DO 2: Find out, which ASCII character is the beep and (OPTIONAL...:) write a
// program which produces 'beep-music' (use large loops to produce pauses between beeps.) */

#include <ctype.h>
#include <stdio.h>

void beep() {
    printf("\a\n");
}

int main(int argc, char *argv[]) {
    beep();

    unsigned char c;

    for (int i = 0; i < 256; i = i + 16) {
        printf("%3d ", i);

        for (int j = 0; j < 16; j = j + 1) {
            c = i + j;

            if (isprint(c)) {
                printf("%c", c);
            }
        }

        printf("\n");
    }
}
