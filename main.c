#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/cli_parser.h"
#include "utils/str_util.h"


const char* getCurrentBranch();
void autoCommit(const char* branch, const char* commitMsg);


int main(int argc, char **argv){
    parse_args(argc, argv);
    return 0;

    char** s = argv + sizeof(char);
    char* commitMsg = *(++argv);
    printf("Your commit message is %s\n", commitMsg);
    getCurrentBranch();
    const char* branch = getCurrentBranch();
    printf("Your current branch is %s\n", branch);

    autoCommit(branch, commitMsg);

    free(branch);
    return 0;
}

void autoCommit(const char* branch, const char* commitMsg){
    char* buffer[strlen(branch) + strlen(commitMsg) + 25];
    sprintf(buffer, "git commit -m \'%s %s\'", branch, commitMsg);
    printf("running: %s\n", buffer);
    system(buffer);
}

const char* getCurrentBranch(){
    FILE* fp;
    char buffer[128];
    fp = popen("git branch --show-current", "r");
    if(fp == NULL){
        printf("Failed to fetch git branch");
        fclose(fp);
        exit(1);
    }
    
    char* ans;
    if(fgets(buffer, sizeof(buffer), fp) != NULL){
        ans = strdup( buffer);
    }
    ans = replace_char(ans, '\n', ' ');
    fclose(fp);
    return ans;
}