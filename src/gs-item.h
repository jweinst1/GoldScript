#ifndef SRC_GOLDSCRIPT_ITEM_H
#define SRC_GOLDSCRIPT_ITEM_H

#include "gs-memory.h"

#ifndef GOLDSCRIPT_MAX_STR_LEN
#define GOLDSCRIPT_MAX_STR_LEN 25
#endif

typedef enum
{
    GOLDS_ITEM_TYPE_BOOL,
    GOLDS_ITEM_TYPE_NUMBER,
    GOLDS_ITEM_TYPE_STR,
    GOLDS_ITEM_TYPE_LST
} golds_item_type_t;

struct __gs_item;

typedef union
{
    char _string[GOLDSCRIPT_MAX_STR_LEN + 1];
    int _boolean;
    double _number;
    struct __gs_item* _lst;
} golds_item_val_t;

struct __gs_item
{
    golds_item_type_t type;
    golds_item_val_t val;
    struct __gs_item* next;
};

typedef struct __gs_item golds_item_t;

#define GOLDSCRIPT_ITEM_HAS_NEXT(it) (it != NULL && it->next != NULL)

#define GOLDSCRIPT_ITEM_STR_AT(it, index) (it->val._string[index])

golds_item_t* golds_item_new_bool(int boolean);
golds_item_t* golds_item_new_num(double number);
golds_item_t* golds_item_new_lst(golds_item_t* insert);
golds_item_t* golds_item_new_str(const char* text);

void golds_item_del(golds_item_t* item);
/**
 * @brief Creates an \c item based on a specified type.
 */
golds_item_t* golds_item_new(golds_item_type_t type, void* data);

#endif // SRC_GOLDSCRIPT_ITEM_H