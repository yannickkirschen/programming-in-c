#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address_list_person_add.h"
#include "../../utils/utils.h"

void address_list_person_add(ArrayList *list) {
    printf("  -- Add a person --\n");

    printf("First name: ");
    char firstName[31];
    scanf("%[^\n]", firstName);
    getchar();

    printf("Last name: ");
    char lastName[31];
    scanf("%[^\n]", lastName);
    getchar();

    printf("Sex ([m]ale, [f]emale, [o]ther): ");
    char s[2];
    scanf("%[^\n]", s);
    getchar();

    printf("Birthday (DD.MM.YYYY): ");
    char birthdayString[11];
    scanf("%[^\n]", birthdayString);
    getchar();

    printf("Street 1: ");
    char street1[51];
    scanf("%[^\n]", street1);
    getchar();

    printf("Street 2: ");
    char street2[51];
    scanf("%[^\n]", street2);
    getchar();

    printf("Zip code: ");
    char zip[21];
    scanf("%[^\n]", zip);
    getchar();

    printf("City: ");
    char city[51];
    scanf("%[^\n]", city);
    getchar();

    Sex sex;
    switch (s[0]) {
        case 'm':
            sex = MALE;
            break;
        case 'f':
            sex = FEMALE;
            break;
        default:
            sex = OTHER;
    }

    Date *birthday = string_to_date(birthdayString);

    if (birthday == NULL) {
        utils_input_error();
    }

    Address *address = malloc(sizeof(Address));
    strcpy(address->street1, street1);
    strcpy(address->street2, street2);
    strcpy(address->zip, zip);
    strcpy(address->city, city);

    Person *person = malloc(sizeof(Person));
    strcpy(person->firstName, firstName);
    strcpy(person->lastName, lastName);
    person->sex = sex;
    person->birthday = birthday;
    person->address = address;

    collection_array_list_append(list, person);
}
