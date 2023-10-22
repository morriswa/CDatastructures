#include "ArrayList.h"

void* init_array_list(int buffer_size) {
    struct ArrayList* list = (struct ArrayList*) malloc(sizeof(struct ArrayList));

    list->array_depth = buffer_size;
    list->length = 0;
    list->list = (struct ArrayObj*) malloc(sizeof(struct ArrayObj) * list->array_depth);
    
    return (void*) list;
}

int push_back(void* arr, char* content) {
    struct ArrayList* array = (struct ArrayList*) arr;

    if (array->length >= array->array_depth) {
        array->array_depth *= 2;
        array->list = realloc(array->list, sizeof(struct ArrayObj) * array->array_depth);
    }

    int content_length = strlen(content);

    char* address = (char*) malloc(sizeof(char) * content_length);

    strcpy(address, content);

    struct ArrayObj new_object = { content_length, address };

    memcpy(&(array->list[array->length]), &new_object, sizeof(struct ArrayObj));

    array->length++;

    return 1;
}

int push_front(void* arr, char* content) {
    return 0;
}

int replace(void* arr, int index, char* content) {
    return 0;
}

char* pop(void* arr) {
    struct ArrayList* array = (struct ArrayList*) arr;

    struct ArrayObj row_to_pop = array->list[array->length - 1];

    // char* return_str = (char*) malloc(sizeof(char) * row_to_pop.size);

    // memcpy(return_str, row_to_pop.object, sizeof(char) * row_to_pop.size);

    // printf("string to return: %s\n", return_str);

    // // free(array->list[array->length - 1]);

    array->length--;

    return row_to_pop.object;
}

char* pop_front(void* arr) {
    return NULL;
}

char* remove_at_index(void* arr, int index) {
    return NULL;
}
