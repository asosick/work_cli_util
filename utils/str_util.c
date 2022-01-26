#include "str_util.h"
#include <stdlib.h>

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

char** split_str(char* str, const char split){
    u_int32_t count = num_of_chars_in_str(str, split) + 1;
    char** ll = malloc(sizeof(char*)*count);
    char* head = str;
    char* ptr = str;
    u_int16_t index = 0;
    while(ptr){
        ptr = strchr(ptr, split);
        u_int16_t diff = ptr - head;
        ll[index] = malloc(sizeof(char)*(diff+1));
        strncpy(ll[index], head, diff);
        ll[index][diff] = '\0';
        head += diff + 1;
        if(ptr)
        {
            ptr += 1;
        }
        index++;
    }
    return ll;
}



u_int32_t num_of_chars_in_str(const char* str, const char c){
    uint32_t count = 0;
    while(*str){
        if(*str == c){
            ++count;
        }
        str++;
    }
    return count;
}