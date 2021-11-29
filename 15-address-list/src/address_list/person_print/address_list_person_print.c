#include <stdio.h>
#include <string.h>

#include "address_list_person_print.h"
#include "../../utils/utils.h"

void address_list_person_print(Person *person) {
    printf("%i\n", person->sex);
    char sex[6];
    switch (person->sex) {
        case MALE:
            strcpy(sex, "male");
            break;
        case FEMALE:
            strcpy(sex, "female");
            break;
        default:
            strcpy(sex, "other");
    }

    utils_clear();
    printf("  -- Person data --\n\n");
    printf("First name: %s\n", person->firstName);
    printf("Last name: %s\n", person->lastName);
    printf("Sex: %s\n", sex);
    printf("Birthday: %s\n", date_to_string(person->birthday));
    printf("\n");
    printf("%s\n", person->address->street1);
    printf("%s\n", person->address->street2);
    printf("%s %s\n", person->address->zip, person->address->city);
    printf("\n");
}
