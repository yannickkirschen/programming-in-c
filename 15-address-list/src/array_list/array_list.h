#ifndef array_list_h
#define array_list_h

#include "../address_list/address_list_objects.h"

typedef struct ArrayList {
    Person *data;

    int size;
    int threshold;
} ArrayList;

ArrayList *collection_array_list_initialize();

void collection_array_list_append(ArrayList *, Person *);

Person *collection_array_list_get(ArrayList *, int);

Person *collection_array_list_remove(ArrayList *, int);

#endif // array_list_h
