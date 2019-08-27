#include "gs-item.h"

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

golds_item_t* golds_item_new_lst(golds_item_t* insert)
{
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->type = GOLDS_ITEM_TYPE_LST;
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
    return item;
}