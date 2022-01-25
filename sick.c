#include <stdio.h>

int main(int argc, char **argv){
    char** s = argv + 1;
    while(*s != NULL){
        printf("Args: %s\n", *s);
        ++s;
    }

    return 0;
}