#include <assert.h>

#include "HashMap.h"

int main(int argc, char** argv) {

    void* hashmap = init_hash_map(100);

    char* key = "hello";
    char* val = "world!";

    put(hashmap, key, val);
    assert(strcmp(retrieve(hashmap, key), val));
    assert(FALSE == contains(hashmap, val));

    put(hashmap, val, key);
    assert(strcmp(retrieve(hashmap, val), key));
    assert(TRUE == contains(hashmap, val));

    for (int i = 0; i < 100000; i++) {
        char new_val[100], new_key[100], bad_key[100];
        sprintf(new_key, "my-key-%d", i);
        sprintf(new_val, "my-value-%d", i);
        sprintf(bad_key, "my-key-%d", i+1);

        put(hashmap, new_key, new_val);

        if (i % 10 == 0) {
            assert(strcmp(retrieve(hashmap, new_key), new_val));
            assert(FALSE == contains(hashmap, bad_key));
            assert(TRUE == contains(hashmap, new_key));
        };
    }

    assert(strcmp(retrieve(hashmap, "my-key-999"), "my-value-999"));
    assert(FALSE == contains(hashmap, "my-value-999"));


    return 0;
}