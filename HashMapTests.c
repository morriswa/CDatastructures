#include <assert.h>

#include "HashMap.h"

int main(int argc, char** argv) {

    void* hashmap = init_hash_map(100);

    char* key = "hello";
    char* val = "world!";

    put(hashmap, key, val);

    // printf("key: [%s]; val: [%s];\n", retrieve(hashmap, key), val);

    assert(strings_are_equal(retrieve(hashmap, key), val));
    // assert(0 != strcmp(retrieve(hashmap, val), key));
 
    assert(!contains(hashmap, val));

    put(hashmap, val, key);
    assert(strings_are_equal(retrieve(hashmap, val), key));
    assert(contains(hashmap, val));

    for (int i = 0; i < 100000; i++) {
        char new_val[100], new_key[100], bad_key[100];
        sprintf(new_key, "my-key-%d", i);
        sprintf(new_val, "my-value-%d", i);
        sprintf(bad_key, "my-key-%d", i+1);

        put(hashmap, new_key, new_val);

        if (i % 10 == 0) {
            assert(strings_are_equal(retrieve(hashmap, new_key), new_val));
            assert(!contains(hashmap, bad_key));
            assert(!contains(hashmap, new_val));
            assert(contains(hashmap, new_key));
        };
    }

    return 0;
}