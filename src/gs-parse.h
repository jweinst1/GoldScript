#ifndef SRC_GOLDSCRIPT_PARSE_H
#define SRC_GOLDSCRIPT_PARSE_H

#include "gs-item.h"


#define GOLDSCRIPT_PARSER_MAX_ERR_LEN 256
/**
 * @brief Acts as a parser container and state based object.
 */
typedef struct
{
    char err_mes[GOLDSCRIPT_PARSER_MAX_ERR_LEN];
    const char* data;
    int stop;
    int has_err;
} golds_parser_t;

#define GOLDSCRIPT_PARSER_INIT(prs, code, md) \
                            prs.stop = 0; \
                            prs.has_err = 0; \
                            prs.err_mes[0] = '\0'; \
                            prs.data = code
                            


golds_item_t* golds_parse_string(const char* code);

#endif // SRC_GOLDSCRIPT_PARSE_H