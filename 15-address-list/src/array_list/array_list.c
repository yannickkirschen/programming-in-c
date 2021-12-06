#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"

// TODO: destroy function
// TODO: store reserved space
ArrayList *collection_array_list_initialize() {
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL) {
        return NULL;
    }

    list->data = malloc(sizeof(Person) * 10);
    if (list->data == NULL) {
        return NULL;
    }

    list->size = 0;
    list->threshold = 10;
    return list;
}

void collection_array_list_append(ArrayList *list, Person *value) {
    if (list->size % list->threshold == 0) {
        Person *newData = malloc(
                sizeof(Person) * (list->size + list->threshold));
        if (newData == NULL) {
            return;
        }

        for (int i = 0; i < list->size; i++) {
            newData[i] = list->data[i];
        }

        free(list->data);
        list->data = newData;
    }

    list->data[list->size] = *value;
    list->size++;
}

Person *collection_array_list_get(ArrayList *list, int index) {
    if (list->size < index) {
        return NULL;
    }

    return &list->data[index];
}

Person *collection_array_list_remove(ArrayList *list, int index) {
    if (list->size < index) {
        return NULL;
    }

    Person *person = &list->data[index];

    if ((list->size - 1) % list->threshold == 0) {
        Person *newData = malloc(sizeof(Person) * list->size - 1 - list->threshold);
        if (newData == NULL) {
            return;
        }

        for (int i = 0; i < list->size - 1; i++) {
            newData[i] = list->data[i];
        }

        free(list->data);
        list->data = newData;
    } else {
        for (int i = index; i < list->size - 1;i++) {
            list->data[i] = list->data[i + 1];
        }
    }

    list->size--;
    return person;
}
