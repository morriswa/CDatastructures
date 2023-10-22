#include "Utils.h"

/**
 * SOURCE:
 *  https://stackoverflow.com/questions/7666509/hash-function-for-string
*/
unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

// The User-defined method
int str_length(char* str) {
    // initializing count variable (stores the length of the string)
    int count; 
    
    // incrementing the count till the end of the string
    for (count = 0; str[count] != '\0'; ++count);
    
    // returning the character count of the string
    return count; 
}

int strings_are_equal(char* str1, char* str2) {
    return 0 == strcmp(str1, str2);
}