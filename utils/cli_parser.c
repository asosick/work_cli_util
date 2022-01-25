#include "cli_parser.h"

struct CLI_PAIR {
    char flag;
    char* value;
    bool hasVal;
};

const char* CLI_SETTINGS = "w:s";


struct CLI_PAIR** parse_args(int argc, char** argv){
    struct CLI_PAIR** larry = findFlags();
    larry = insertFlagValues(larry, argv);
    return larry;
}

//need a hashset implementation to make this way faster...
//this will assume args are passed the same way they are defined which is obviously not ideal
struct CLI_PAIR** insertFlagValues(struct CLI_PAIR** flags, char** argv){
    struct CLI_PAIR** ptr_flags = flags;
    char** ptr_args = argv + 2;
    uint16_t index_flags = 0;
    while(*ptr_args){
        if(ptr_flags[index_flags]->hasVal == true){
            ptr_flags[index_flags]->value = strdup(*ptr_args);
            ptr_args+=2;
        }else{
            ptr_args++;
        }
        ++index_flags;
    }
    return flags;
}

struct CLI_PAIR** findFlags(){
    const char* ptr = CLI_SETTINGS;
    u_int32_t count = num_of_chars_in_str(CLI_SETTINGS, ':');
    struct CLI_PAIR** pairs = malloc(sizeof(struct CLI_PAIR) * (count + 1));
    u_int16_t index = 0;
    while(*ptr){
        if(*(ptr + 1) && *(ptr + 1) == ':'){
            pairs[index] = &(struct CLI_PAIR){.hasVal = true, .flag = *ptr};
            ptr += 2;
        }
        else {
            pairs[index] = &(struct CLI_PAIR){.hasVal = false, .flag = *ptr};
            ptr += 1;
        }
        index++;
    }
    return pairs;
}