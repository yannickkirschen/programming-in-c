/* Compare two strings */

// TO DO 1: This program does not always give the correct results. What is the problem? Correct it!
// TO DO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books

#include <stdbool.h>
#include <stdio.h>

/**
 * This will check two strings on equality based on their characters.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return true, if both strings are equal. Otherwise false.
 */
bool equals(const char *s1, const char *s2) {
    int i = 0;

    char c1;
    char c2;

    do {
        c1 = s1[i];
        c2 = s2[i];

        if (c1 != c2) {
            return false;
        }

        i++;
    } while (c1 && c2);

    return !c1 && !c2;
}

/**
 * Compares two strings lexicographical.
 *
 * 0: equal (s1 = s2)
 * 1: ordered as input (s1, s2)
 * -1: not ordered as input (s2, s1)
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return 0, if both strings are equal. 1, if the order is s1 -> s2.
 * -1, if the order is s2 -> s1.
 */
int compare(const char *s1, const char *s2) {
    int i = 0;

    unsigned char c1;
    unsigned char c2;

    do {
        c1 = s1[i];
        c2 = s2[i];

        if (c1 < c2) {
            return 1;
        } else if (c1 > c2) {
            return -1;
        }

        i++;
    } while (c1 && c2);

    // Both strings are the same length.
    // As we made it here, we know they're equal.
    if (!c1 && !c2) {
        return 0;
    }

    // When the first string reached its end and the second doesn't, we know the
    // second is longer and as we made it here, it has to be ordered after the
    // first one.
    return c2 ? 1 : -1;
}

int main() {
    char s1[100];
    char s2[100];

    printf("Please enter string 1: ");
    scanf("%[^\n]", s1);

    getchar();

    printf("Please enter string 2: ");
    scanf("%[^\n]", s2);

    if (equals(s1, s2)) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are different!\n");
    }

    int comparison = compare(s1, s2);
    if (comparison == 0) {
        printf("Strings are equal.\n");
    } else if (comparison > 0) {
        printf("s1, s2: %s, %s\n", s1, s2);
    } else {
        printf("s2, s1: %s, %s\n", s2, s1);
    }
}
