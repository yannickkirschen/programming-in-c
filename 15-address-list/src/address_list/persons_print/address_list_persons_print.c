#include <stdio.h>

#include "../address_list_objects.h"
#include "../../array_list/array_list.h"

void address_list_persons_print(ArrayList *list) {
    printf("  -- All persons --\n");

    for (int i = 0; i < list->size; i++) {
        Person *person = &list->data[i];
        printf("%i.) %s, %s\n", i + 1, person->lastName, person->firstName);
    }

    printf("\n");
}
