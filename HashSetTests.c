#include <assert.h>

#include "HashSet.h"

int main(int argc, char** argv) {

    void* hashtable = init_hash_set(10);

    char* word = "Hello World!";
    char* word1 = "Mashed potatoes";
    char* word2 = "Not in table :(";

    for (int i = 0; i < 50; i++) {
        add(hashtable, word);
    }
    add(hashtable, word1);

    assert(TRUE == contains(hashtable, word));
    assert(TRUE == contains(hashtable, word1));
    assert(FALSE == contains(hashtable, word2));

    add(hashtable, word2);

    assert(TRUE == contains(hashtable, word2));

    return 0;
}