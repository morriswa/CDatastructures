#include <assert.h>

#include "ArrayList.h"
#include "Utils.h"

int main(int argc, char** argv) {

    void* arr = init_array_list(10);

    for(int i = 0; i < 1000; i++) {
        char buffer[100];

        sprintf(buffer, "hello-%d", i);

        push_back(arr, buffer);
    }

    for(int i = 999; i > 0; i--) {
        char buffer[100];

        sprintf(buffer, "hello-%d", i);

        assert(strings_are_equal(buffer, pop(arr)));
    }

    return 0;
}