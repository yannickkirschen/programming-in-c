#include <stdio.h>
#include <stdlib.h>

#include "../address_list_objects.h"
#include "address_list_person_choose.h"

int address_list_person_choose(ArrayList *list) {
    printf("  -- Choose a person --\n");
    for (int i = 0; i < list->size; i++) {
        Person *person = list->data+i;
        printf("%i.) %s, %s\n", i + 1, person->lastName, person->firstName);
    }

    printf("\nYour choice: ");
    char c[2];
    scanf("%[^\n]", c);
    getchar();

    int person;
    sscanf(c, "%d", &person);

    if (person > list->size || person < 1) {
        return -1;
    }

    return person;
}
