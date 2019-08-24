#ifndef SRC_GOLDSCRIPT_ITEMS_H
#define SRC_GOLDSCRIPT_ITEMS_H

#include "gs-linked.h"
#include "gs-linked-types.h'

#ifndef GOLDSCRIPT_MAX_NAME_LEN
#define GOLDSCRIPT_MAX_NAME_LEN 25
#endif

#define golds_item_STRNCPY(dest, src) (strncpy(dest, src, GOLDSCIRPT_MAX_NAME_LEN))

typedef struct __gs_item
{
    GOLDSCIRPT_LINKED_HEAD;
    double demand;
    double supply;
    char name[GOLDSCRIPT_MAX_NAME_LEN + 1]; // For \0 char
} golds_item_t;

golds_item_t* golds_item_new(const char* name, double demand, double supply);

#endif // SRC_GOLDSCRIPT_ITEMS_H