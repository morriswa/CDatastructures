#ifndef WMA_C_UTILS__
#define WMA_C_UTILS__

#define TRUE 1
#define FALSE 0


/**
 * hashes a char* as an unsigned long
 * 
 * SOURCE:
 *  https://stackoverflow.com/questions/7666509/hash-function-for-string
*/
unsigned long hash(char *str);

/**
 * returns the length of provided string
 * 
 * SOURCE:
 *  https://www.scaler.com/topics/string-length-in-c/
*/
int str_length(char* str);

#endif