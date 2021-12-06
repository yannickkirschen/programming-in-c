#include "address_list/address_list.h"
#include "address_list/address_list_objects.h"
#include "array_list/array_list.h"
#include "utils/utils.h"

int main() {
    ArrayList *list = collection_array_list_initialize();

    while (1) {
        utils_clear();
        MenuAction action = address_list_menu();

        switch (action) {
            case ADD_PERSON:
                utils_clear();
                address_list_person_add(list);
                break;
            case VIEW_PERSON:
                utils_clear();
                address_list_person_choose_and_print(list);
                utils_pause();
                break;
            case DELETE_PERSON:
                utils_clear();
                address_list_person_choose_and_delete(list);
                break;
            case LIST_ALL_PERSONS:
                utils_clear();
                address_list_persons_print(list);
                utils_pause();
                break;
            case QUIT:
                return 0;
            case ERROR:
                utils_input_error();
                break;
            default:
        }
    }
}
