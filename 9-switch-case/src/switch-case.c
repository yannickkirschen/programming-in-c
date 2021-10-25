// Switch case: Order your burger...

// TO DO 1: Replace the if-statements with switch case and add a default case for invalid input
// TO DO 2: Add support for extra-large and fish burgers
// TO DO 3: Extend the program such that is executed in a loop, which can be aborted by entering 'q' as size
// TO DO 4: If there is a much longer list of options: How can long if-else-chains / switch-case-statements be avoided?
// TO DO 5: Optional: Any further ideas for additional sizes and options?

#include <stdio.h>

int chooseABurger() {
    char size;
    char specials;

    printf("Size (s=small, m=medium, l=large, x=extra-large): ");
    scanf(" %c", &size);

    printf("Specials (r=regular beef, v=veggie, c=cheese, f=fish): ");
    scanf(" %c", &specials);

    int height;
    float price;

    switch (size) {
        case 's':
            height = 1;
            price = 2.5f;
            break;
        case 'l':
            height = 4;
            price = 5.9f;
            break;
        case 'x':
            height = 6;
            price = 8.5f;
            break;
        case 'q':
            return 0;
        default:  // 'm'
            height = 2;
            price = 3.5f;
    }

    printf("\n\n.-\"\"\"\"-.\n");

    while (height--) {
        switch (specials) {
            case 'c':
                printf(" ------ \n");
                break;
            case 'v':
                printf("(xxxxxx)\n");
                break;
            case 'f':
                printf("(~~~~~~)\n");
                break;
            default: // 'r'
                printf("(mmmmmm)\n");
        }
    }

    printf("\\______/\n");
    printf("\n\n%.2f Euro - Enjoy!\n", price);

    return 1;
}

int main() {
    while (chooseABurger());
}
