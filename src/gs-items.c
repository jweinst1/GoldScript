#include "gs-items.h"
#include "compiler-info.h"

golds_item_t* golds_item_new(const char* name, double demand, double supply)
{
    golds_item_t* item = golds_mem_calloc(sizeof(golds_item_t));
    item->demand = demand;
    item->supply = supply;
    item->type = GOLDSCRIPT_LINKED_T_ITEM;
    item->next = NULL;
#ifdef GOLDSCRIPT_CVERS_11
    strncpy_s(item->name, name, GOLDSCRIPT_MAX_NAME_LEN);
#else
    strncpy(item->name, name, GOLDSCRIPT_MAX_NAME_LEN);
#endif
    return item;
}