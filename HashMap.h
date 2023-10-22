#ifndef WMA_C_HASH_MAP__
#define WMA_C_HASH_MAP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

/**
 * default memory allocation for rows (measured in object size)
*/
#define DEFAULT_BUCKET_DEPTH 5

/**
 * default memory allocation for stored values (measured in chars)
*/
#define DEFAULT_OBJECT_SIZE 100

/**
 * store all information about an object that has been hashed
*/
struct HashedObject {
    /**
     * hash key, used to retrieve the value from the map
    */
    unsigned long key;

    /**
     * value stored in the map
    */
    char* value;

    /**
     * size of the value (in chars)
    */
    int length;
};

/**
 * store all information for row of Hash Map 
*/
struct HashRow {
    /**
     * number of items in the row
    */
    int row_length;

    /**
     * current size of memory allocated to row
    */
    int depth;

    /**
     * row containing all objects stored in the map
    */
    struct HashedObject* row;
};

/**
 * store entirety of Hash Map
*/
struct HashSet {
    /**
     * number of buckets (rows) the table will have
    */
    int bucket_quantity;

    /**
     * a table containing desired number of rows
    */
    struct HashRow *table;
};

/**
 * initializes a hash map with desired quantity of buckets
*/
void* init_hash_map(int initial_bucket_quantity);

/**
 * stores a provided value in specified key in map
*/
int put(void *hash_map, char* key, char* value);

/**
 * retrieve a value at the specified key in map
*/
char* retrieve(void *hash_map, char* key);

/**
 * returns true if a key exists in the map, false otherwise
*/
int contains(void *hash_map, char* key);

#endif