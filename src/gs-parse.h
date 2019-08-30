#ifndef SRC_GOLDSCRIPT_PARSE_H
#define SRC_GOLDSCRIPT_PARSE_H

#include "gs-item.h"

typedef __gs_parse_bound
{
    GOLDSCRIPT_PARSE_CURLY,
    GOLDSCRIPT_PARSE_SQUARE,
    GOLDSCRIPT_PARSE_ROUND
} golds_prs_mode_t;

typedef struct
{
    const char** data;
} golds_parse_iter_t;

int golds_parse_string(const char* code, golds_prs_mode_t mode);

#endif // SRC_GOLDSCRIPT_PARSE_H