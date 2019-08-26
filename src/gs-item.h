#ifndef SRC_GOLDSCRIPT_ITEM_H
#define SRC_GOLDSCRIPT_ITEM_H

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
};

typedef struct __gs_item golds_item_t;

#endif // SRC_GOLDSCRIPT_ITEM_H