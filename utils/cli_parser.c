#include "cli_parser.h"

void parse_args(int argc, char** argv);

const char* CLI_SETTINGS = "w:s";

struct CLI_PAIR;

struct CLI_PAIR {
    char flag;
    char* value;
    bool hasVal;
};

void parse_args(int argc, char** argv){
    struct CLI_PAIR** larry = findFlags();
    larry = insertFlagValues(larry);
}


//need a hashset implementation to make this way faster...
struct CLI_PAIR** insertFlagValues(struct CLI_PAIR** flags, char** argv){

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
    }
    return pairs;
}