#ifndef STR_UTIL
#define STR_UTIL

#include <string.h>

const char* replace_char(char* str, const char find, const char replace);
char** split_str(char* str, const char split);
u_int32_t num_of_chars_in_str(const char* str, const char c);


#endif