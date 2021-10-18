/* Shuffles a string */

// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Please enter your name: ");
    char name1[100];
    scanf("%[^\n]", name1);

    getchar();

    printf("Please enter another name: ");
    char name2[100];
    scanf("%[^\n]", name2);

    printf("Hello (original) %s and %s\n\n", name1, name2);

    char c1;
    char c2;

    int p1;
    int p2;
    int p3;
    int p4;

    int c = 0;
    while (c < 10) {
        p1 = rand() % strlen(name1);
        p2 = rand() % strlen(name1);

        p3 = rand() % strlen(name2);
        p4 = rand() % strlen(name2);

        if ((name1[p1] != ' ' && name1[p2] != ' ') &&
            (name2[p3] != ' ' && name2[p4] != ' ')) {
            c1 = name1[p1];
            c2 = name2[p3];

            name1[p1] = name2[p1];
            name1[p2] = c2;

            name2[p3] = name1[p3];
            name2[p4] = c1;

            printf("Hello %s and %s\n", name1, name2);
            c++;
        }
    }
}
