#ifndef SRC_GOLDSCRIPT_ITEMS_H
#define SRC_GOLDSCRIPT_ITEMS_H

#include "gs-linked.h"
#include "gs-linked-types.h"

#ifndef GOLDSCRIPT_MAX_NAME_LEN
#define GOLDSCRIPT_MAX_NAME_LEN 25
#endif


struct __gs_item
{
    GOLDSCRIPT_LINKED_HEAD;
    double demand;
    double supply;
    char name[GOLDSCRIPT_MAX_NAME_LEN + 1]; // For \0 char
};

typedef struct __gs_item golds_item_t;

golds_item_t* golds_item_new(const char* name, double demand, double supply);
/**
 * @brief Compares names using \c strcmp .
 * @remarks In the future may consider optimized direct comparison .
 */
int golds_item_name_eq(const golds_item_t* lfs, const golds_item_t* rfs);

#endif // SRC_GOLDSCRIPT_ITEMS_H