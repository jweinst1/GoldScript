#include "gs-parse.h"

#define CASES_WHITE_SPACE \
             case ' ':  \
             case '\n': \
             case '\t': 


static golds_item_t* _golds_parse_item(golds_parser_t* prs)
{
    golds_item_t* parsed = NULL;
    while(!prs->stop && !prs->has_err) {
        switch(*(prs->data)) {
            CASES_WHITE_SPACE
                prs->data++;
                break;
            case '\0':
                prs->stop =1;
                goto end_parsing;
            case '(':
                break;
            case '{':
                break;
            case '[':
                break;
            default:
                sprintf(prs->err_mes, 
                        "Expected item, found '%c'\n", 
                        *(prs->data));
                prs->has_err = 1;
                return NULL;
        }
    }
end_parsing:
    return parsed;
}

#undef CASES_WHITE_SPACE


golds_item_t* golds_parse_string(const char* code)
{
    golds_item_t* item_prsd;
    golds_parser_t parser;
    GOLDSCRIPT_PARSER_INIT(parser, code);
    item_prsd = _golds_parse_item(&parser);
    return item_prsd;
}