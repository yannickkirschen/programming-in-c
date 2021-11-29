#ifndef address_list_h
#define address_list_h

#include "../array_list/array_list.h"

#include "address_list_objects.h"

#include "person_add/address_list_person_add.h"
#include "person_choose/address_list_person_choose.h"
#include "person_print/address_list_person_print.h"
#include "persons_print/address_list_persons_print.h"

#include "csv/csv.h"
#include "menu/address_list_menu.h"

void address_list_person_choose_and_print(ArrayList *);

void address_list_person_choose_and_delete(ArrayList *);

#endif // address_list_h
