#ifndef WMA_C_ARRAY_LIST__
#define WMA_C_ARRAY_LIST__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrayObj {
    int size;
    char* object;
};

struct ArrayList {
    int length;
    int array_depth;
    struct ArrayObj* list;
};

void* init_array_list(int buffer_size);

int push_back(void* arr, char* content);

int push_front(void* arr, char* content);

int replace(void* arr, int index, char* content);

char* pop(void* arr);

char* pop_front(void* arr);

char* remove_at_index(void* arr, int index);

#endif