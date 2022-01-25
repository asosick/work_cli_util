#include "str_util.h"

const char* replace_char(char* str, const char find, const char replace){
    char* ptr = str;
    while(*ptr){
        if(*ptr == find){
            *ptr = replace;
        }
        ++ptr;
    }
    return str;
}  