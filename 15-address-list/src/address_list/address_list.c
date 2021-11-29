#include "address_list.h"
#include "address_list_objects.h"
#include "../utils/utils.h"

void address_list_person_choose_and_print(ArrayList *list) {
    int i = address_list_person_choose(list) - 1;

    if (i == -1) {
        utils_input_error();
        return;
    }

    Person *person = collection_array_list_get(list, i);
    address_list_person_print(person);
}

void address_list_person_choose_and_delete(ArrayList *list) {
    int i = address_list_person_choose(list) - 1;

    if (i == -1) {
        utils_input_error();
        return;
    }

    collection_array_list_remove(list, i);
}
