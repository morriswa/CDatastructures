
// The User-defined method
int str_length(char* str) {
    // initializing count variable (stores the length of the string)
    int count; 
    
    // incrementing the count till the end of the string
    for (count = 0; str[count] != '\0'; ++count);
    
    // returning the character count of the string
    return count; 
}