#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

#define DEFAULT_BUCKET_DEPTH 5

struct HashRow {
    int row_length;
    int depth;
    unsigned long *row;
};

struct HashMap {
    int bucket_quantity;
    struct HashRow *table;
};


struct HashMap* create_hash_table(int initial_bucket_quantity);

void add_to_hash_table(struct HashMap *hash_table, char* string_to_add);

int is_in_table(struct HashMap *hash_table, char* string_to_add);

/**
 * https://stackoverflow.com/questions/7666509/hash-function-for-string
*/
unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main(int argc, char** argv) {

    struct HashMap *hashtable = create_hash_table(10);

    char* word = "Hello World!";
    char* word1 = "Mashed potatoes";
    char* word2 = "Not in table :(";

    for (int i = 0; i < 50; i++) {
        add_to_hash_table(hashtable, word);
    }
    add_to_hash_table(hashtable, word1);

    assert(TRUE == is_in_table(hashtable, word));
    assert(TRUE == is_in_table(hashtable, word1));
    assert(FALSE == is_in_table(hashtable, word2));

    add_to_hash_table(hashtable, word2);

    assert(TRUE == is_in_table(hashtable, word2));

    return 0;
}

struct HashMap* create_hash_table(int initial_bucket_quantity) {
    struct HashMap* new_table = (struct HashMap*) malloc(sizeof(struct HashMap));
    
    new_table->bucket_quantity = initial_bucket_quantity;
    new_table->table = (struct HashRow*) malloc(sizeof(struct HashRow) * initial_bucket_quantity);

    for (int i = 0; i < initial_bucket_quantity; i++) {
        new_table->table[i].row = (unsigned long*) malloc(sizeof(unsigned long) * DEFAULT_BUCKET_DEPTH); 
        new_table->table[i].row_length = 0;
        new_table->table[i].depth = DEFAULT_BUCKET_DEPTH;
    }

    return new_table;
}

void add_to_hash_table(struct HashMap *hash_table, char* string_to_add) {

    unsigned long hash_to_add = hash(string_to_add);

    int hash_bucket = hash_to_add % hash_table->bucket_quantity;

    printf("Adding %s to hashtable %p as %lu in bucket %d\n", string_to_add, hash_table, hash_to_add, hash_bucket);

    struct HashRow *row = &(hash_table->table[hash_bucket]);

    if (row->row_length >= row->depth) {
        row->row = realloc(row->row, sizeof(unsigned long) * 2 * row->depth);
        row->depth *= 2;
    }

    row->row[row->row_length] = hash_to_add;
    row->row_length += 1;
}

int is_in_table(struct HashMap *hash_table, char* string_to_check) {
    unsigned long hash_to_check = hash(string_to_check);
    int hash_bucket = hash_to_check % (hash_table->bucket_quantity);
    struct HashRow row = hash_table->table[hash_bucket];

    int result = FALSE;
    for (int i = 0; i < row.row_length; i++)
        if (row.row[i] == hash_to_check)
            result = TRUE;
    
    char* console_log = result ? 
        "determined \"%s\" IS in hashtable %p\n" :
        "determined \"%s\" is NOT in hashtable %p\n";

    printf(console_log, string_to_check, hash_table);

    return result;
}
