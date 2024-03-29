#include "gs-item.h"
#include <assert.h>

golds_item_t* golds_item_new_bool(int boolean)
{
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->type = GOLDS_ITEM_TYPE_BOOL;
    item->val._boolean = boolean;
    item->next = NULL;
    return item;
}


golds_item_t* golds_item_new_num(double number)
{
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->type = GOLDS_ITEM_TYPE_NUMBER;
    item->val._number = number;
    item->next = NULL;
    return item;
}

golds_item_t* golds_item_new_lst(golds_item_t* insert, golds_item_type_t kind)
{
    assert(GOLDSCRIPT_ITEM_TYPE_IS_LST(kind));
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->type = kind;
    item->val._lst = insert;
    item->next = NULL;
    return item;
}

golds_item_t* golds_item_new_str(const char* text)
{
    unsigned i;
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->type = GOLDS_ITEM_TYPE_STR;
    item->next = NULL;
    for(i=0; i <= GOLDSCRIPT_MAX_STR_LEN && text[i] != '\0'; i++) {
        item->val._string[i] = text[i];
    }
    item->val._string[i] = '\0';
    return item;
}

void golds_item_del(golds_item_t* item)
{
    if(item != NULL) {
        if(item->next != NULL)
            golds_item_del(item->next);
        if(GOLDSCRIPT_ITEM_TYPE_IS_LST(item->type))
            golds_item_del(item->val._lst);
        free(item);
    }
}



golds_item_t* golds_item_new(golds_item_type_t type, void* data)
{
    switch(type) {
        case GOLDS_ITEM_TYPE_BOOL:
            return golds_item_new_bool(*(int*)data);
        case GOLDS_ITEM_TYPE_NUMBER:
            return golds_item_new_num(*(double*)data);
        case GOLDS_ITEM_TYPE_STR:
            return golds_item_new_str((const char*)data);
        case GOLDS_ITEM_TYPE_LST_RULE:
        case GOLDS_ITEM_TYPE_LST_CMD:
        case GOLDS_ITEM_TYPE_LST_COMP:
            return golds_item_new_lst((golds_item_t*)data, type);
    }
    return NULL;
}