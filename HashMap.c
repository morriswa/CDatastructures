#include "HashMap.h"

void* init_hash_map(int rows) {
    // allocate memory for new hash map
    struct HashMap* new_map = (struct HashMap*) malloc(sizeof(struct HashMap));
    // initialize with given number of rows
    new_map->bucket_quantity = rows;
    // and allocate memory for every row
    new_map->table = (struct HashRow*) malloc(sizeof(struct HashRow) * rows);

    for (int i = 0; i < rows; i++) {
        // allocate memory for every object stored in each row
        new_map->table[i].row = (struct HashedObject*) malloc(sizeof(struct HashedObject) * DEFAULT_BUCKET_DEPTH); 
        // each row will start with 0 entries
        new_map->table[i].row_length = 0;
        // and default allocated memory
        new_map->table[i].depth = DEFAULT_BUCKET_DEPTH;
    }

    return (void*) new_map;
}

int put(void *hash_map, char* key, char* value) {

    struct HashMap* hash_map_ptr = (struct HashMap*) hash_map;

    // return FALSE if the key to be added already exists in list, should use replace
    if (contains(hash_map, key)) return FALSE;

    // hash the key
    unsigned long hash_to_add = hash(key);
    
    // and determine what bucket the value belongs in
    int hash_bucket = hash_to_add % hash_map_ptr->bucket_quantity;

    // printf("Adding %s to hashtable %p as %lu in bucket %d\n", key, hash_map, hash_to_add, hash_bucket);

    // retrieve memory address of the current row
    struct HashRow *row = &(hash_map_ptr->table[hash_bucket]);
    
    // if more memory is required to store all objects in the row
    if (row->row_length >= row->depth) {
        // double the memory allocation
        row->depth *= 2;
        // and reallocate the rows memory
        row->row = realloc(row->row, sizeof(struct HashedObject) * row->depth);
    }

    // retrieve the length of provided value
    int object_length = strlen(value);

    // and determine appropriate mem allocation for value
    int size = DEFAULT_OBJECT_SIZE;
    while(size < object_length) size *= 2;

    // allocate memory for value
    char* final_value = (char*) malloc(sizeof(char) * size);

    // create object structure
    struct HashedObject obj = { hash_to_add, final_value, object_length };

    // save to correct place in row
    row->row[row->row_length] = obj;

    // increment the row length
    row->row_length++;

    // and return TRUE if the object was successfully added
    return TRUE;
}

char* retrieve(void *hash_map, char* key) {
    
    struct HashMap* hash_map_ptr = (struct HashMap*) hash_map;

    // hash the key
    unsigned long hash_to_check = hash(key);
    
    // determine bucket to search
    int hash_bucket = hash_to_check % (hash_map_ptr->bucket_quantity);

    // retrieve row to search
    struct HashRow *row = &(hash_map_ptr->table[hash_bucket]);

    for (int i = 0; i < row->row_length; i++) 
        // search appropriate row for key, return value when found
        if (row->row[i].key == hash_to_check) return row->row[i].value; 
    return NULL;
}

int contains(void* hash_map, char* key) {
    return !(NULL == retrieve(hash_map, key));
}

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}