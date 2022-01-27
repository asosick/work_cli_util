//
// Created by August Sosick on 2022-01-25.
//

#ifndef CMDUTIL_CLI_PARSER_H
#define CMDUTIL_CLI_PARSER_H

#include "str_util.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

struct CLI_PAIR** parse_args(int argc, char** argv);
struct CLI_PAIR** insertFlagValues(struct CLI_PAIR** flags, char** argv);
struct CLI_PAIR** findFlags();

struct CLI_PAIR;


#endif //CMDUTIL_CLI_PARSER_H
