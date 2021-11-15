// Generate 'bullshit sentences'

// TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12?
// TO DO 2: Create more complex sentences e.g. by using more adjectives together or by concatenating several phrases.
// TO DO 3: Generalize the 'You should' by allowing other random introductions, e.g. "we have to", "our company must"
// TO DO 4: Don't write the output to the screen but copy the whole phrase into a separate string.
// Source of words see: http://dack.com/web/bullshit.html

#include <stdio.h>
#include <stdlib.h>

#include "string-utils.h"

int main() {
    char introductions[][20] = {"You should", "We have to", "Out company must"};
    char verbs[][20] = {"benchmark", "exploit", "facilitate", "generate",
                        "implement", "leverage", "maximize",
                        "mesh", "monetize", "optimize", "orchestrate",
                        "redefine"};
    char nouns[][20] = {"action-items", "applications", "bandwidth",
                        "communities", "e-business", "experiences",
                        "infrastructures", "methodologies", "partnerships",
                        "synergies", "solutions", "technologies"};
    char adjectives[][20] = {"bleeding-edge", "collaborative", "cross-platform",
                             "distributed", "efficient",
                             "global", "holistic", "innovative",
                             "mission-critical", "next-generation",
                             "out-of-the-box", "user-centric"};
    int number;
    int i;
    int v;
    int n;
    int a;

    printf("How much bullshit do you need? ");
    scanf("%d", &number);

    while (number > 0) {
        i = rand() % 3;
        v = rand() % 12;
        n = rand() % 12;
        a = rand() % 12;

        char phrase[66];

        for (int c = 0; c < 66; c++) {
            phrase[c] = 0;
        }

        insertIntoString(phrase, "Your boss says: ", 66);
        insertIntoString(phrase, introductions[i], 66);
        insertIntoString(phrase, " ", 66);
        insertIntoString(phrase, verbs[v], 66);
        insertIntoString(phrase, " ", 66);
        insertIntoString(phrase, adjectives[a], 66);
        insertIntoString(phrase, " ", 66);
        insertIntoString(phrase, nouns[n], 66);
        insertIntoString(phrase, "!", 66);
        phrase[65] = 0;

        printf("%s\n", phrase);
        number--;
    }
}
