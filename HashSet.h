#ifndef WMA_C_HASH_SET__
#define WMA_C_HASH_SET__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

#define DEFAULT_BUCKET_DEPTH 5

struct HashRow {
    int row_length;
    int depth;
    unsigned long *row;
};

struct HashSet {
    int bucket_quantity;
    struct HashRow *table;
};


void* init_hash_set(int rows);

void add(void *hash_set, char* str);

int contains(void *hash_set, char* str);

#endif