#include <stdio.h>

#include "address_list_menu.h"
#include "../address_list_objects.h"

MenuAction address_list_menu() {
    printf("  -- Menu --\n");
    printf("[1] Add person\n");
    printf("[2] View person\n");
    printf("[3] Delete person\n");
    printf("[4] List all persons\n");
    printf("[q] Quit\n");

    printf("\nYour choice: ");
    char c[2];
    scanf("%[^\n]", c);
    getchar();

    switch (c[0]) {
        case '1':
            return ADD_PERSON;
        case '2':
            return VIEW_PERSON;
        case '3':
            return DELETE_PERSON;
        case '4':
            return LIST_ALL_PERSONS;
        case 'q':
            return QUIT;
        default:
            return ERROR;
    }
}
