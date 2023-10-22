#include "HashSet.h"

void* init_hash_set(int row) {
    struct HashSet* new_table = (struct HashSet*) malloc(sizeof(struct HashSet));
    
    new_table->bucket_quantity = row;
    new_table->table = (struct HashRow*) malloc(sizeof(struct HashRow) * row);

    for (int i = 0; i < row; i++) {
        new_table->table[i].row = (unsigned long*) malloc(sizeof(unsigned long) * DEFAULT_BUCKET_DEPTH); 
        new_table->table[i].row_length = 0;
        new_table->table[i].depth = DEFAULT_BUCKET_DEPTH;
    }

    return (void*) new_table;
}

void add(void *hash_set, char* str) {

    struct HashSet* hash_set_ptr = (struct HashSet*) hash_set;

    unsigned long hash_to_add = hash(str);

    int hash_bucket = hash_to_add % hash_set_ptr->bucket_quantity;

    struct HashRow *row = &(hash_set_ptr->table[hash_bucket]);

    if (row->row_length >= row->depth) {
        row->row = realloc(row->row, sizeof(unsigned long) * 2 * row->depth);
        row->depth *= 2;
    }

    row->row[row->row_length] = hash_to_add;
    row->row_length++;
}

int contains(void *hash_set, char* str) {

    struct HashSet* hash_set_ptr = (struct HashSet*) hash_set;

    unsigned long hash_to_check = hash(str);
    int hash_bucket = hash_to_check % (hash_set_ptr->bucket_quantity);
    struct HashRow row = hash_set_ptr->table[hash_bucket];

    for (int i = 0; i < row.row_length; i++)
        if (row.row[i] == hash_to_check)
            return TRUE;

    return FALSE;
}
