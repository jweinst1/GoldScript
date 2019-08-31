#ifndef SRC_GOLDSCRIPT_PARSE_H
#define SRC_GOLDSCRIPT_PARSE_H

#include "gs-item.h"

/**
 * @brief Specifies the modes
 */
typedef __gs_parse_bound
{
    GOLDSCRIPT_PARSE_CURLY,
    GOLDSCRIPT_PARSE_SQUARE,
    GOLDSCRIPT_PARSE_ROUND
} golds_prs_mode_t;

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
    golds_prs_mode_t mode;
} golds_parser_t;

#define GOLDSCRIPT_PARSER_INIT(prs, code, md) \
                            prs.stop = 0; \
                            prs.has_err = 0; \
                            prs.err_mes[0] = '\0'; \
                            prs.data = code; \
                            prs.mode = md

golds_item_t* golds_parse_string(const char* code, golds_prs_mode_t mode);

#endif // SRC_GOLDSCRIPT_PARSE_H