#include "gs-items.h"

golds_item_t* golds_item_new(const char* name, double demand, double supply)
{
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->demand = demand;
    item->supply = supply;
    item->type = GOLDSCRIPT_LINKED_T_ITEM;
    item->next = NULL;
    golds_item_STRNCPY(item->name, name);
    return item;
}