#ifndef address_list_objects_h
#define address_list_objects_h

#include "../date/date.h"

typedef enum Sex {
    MALE,
    FEMALE,
    OTHER
} Sex;

typedef struct Address {
    char street1[51];
    char street2[51];
    char zip[21];
    char city[51];
} Address;

typedef struct Person {
    char firstName[31];
    char lastName[31];
    Sex sex;
    Date *birthday;
    Address *address;
} Person;

typedef enum MenuAction {
    ADD_PERSON,
    VIEW_PERSON,
    DELETE_PERSON,
    LIST_ALL_PERSONS,
    QUIT,
    ERROR
} MenuAction;

#endif // address_list_objects_h
