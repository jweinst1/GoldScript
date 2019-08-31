#include "gs-parse.h"


static golds_item_t* _golds_parse_item(golds_parser_t* prs)
{
    return NULL;
}


golds_item_t* golds_parse_string(const char* code)
{
    golds_item_t* item_prsd;
    golds_parser_t parser;
    GOLDSCRIPT_PARSER_INIT(parser, code);
    item_prsd = _golds_parse_item(&parser);
    return item_prsd;
}