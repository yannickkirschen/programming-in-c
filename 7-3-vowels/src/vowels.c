// devowelizer / revowelizer

// TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
// TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
//          Hint: List the vowels in an additional array ...
//                Use rand() to generate random numbers
// TO DO 3: Modify the program such that it removes all vowels (and shortens the text accordingly)
// TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
//         in a table how each character shall be replaced by another one.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char vowels[] = {'a', 'e', 'i', 'o', 'u'};
int vowelsCount = 5;

bool contains(const char *array, char c) {
    int i = 0;

    while (array[i] != 0) {
        if (array[i] == c) {
            return true;
        }

        i++;
    }

    return false;
}

char *randomVowels(char *txt) {
    int i = 0;

    while (txt[i] != 0) {
        if (contains(vowels, txt[i])) {
            txt[i] = vowels[rand() % vowelsCount];
        }

        i++;
    }

    return txt;
}

char *removeVowels(char *txt) {
    int i = 0;

    while (txt[i] != 0) {
        if (contains(vowels, txt[i])) {
            int j = i;

            while (txt[j] != 0) {
                txt[j] = txt[j + 1];
                j++;
            }
        }

        i++;
    }

    return txt;
}

int main() {
    printf("Please enter your text: ");
    char txt[1000];
    scanf("%[^\n]", txt);

    printf("Random vowels: %s\n", randomVowels(txt));
    printf("Removed vowels: %s\n", removeVowels(txt));
}
