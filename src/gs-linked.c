#include "gs-linked.h"

size_t golds_linked_len(gs_linked_t* lst)
{
    size_t total = 0;
    while(lst != NULL) {
        total++;
        lst = lst->next;
    }
    return total;
}

void golds_linked_put(gs_linked_t* lst, gs_linked_t* item)
{
    if(lst != NULL) {
        if(lst->next != NULL) {
            // Assumes item is a single item, not another list.
            item->next = lst->next;
            lst->next = item;
        } else {
            lst->next = item;
        }
    }
}

void golds_linked_del(gs_linked_t* lst)
{
    while(lst != NULL) {
        free(lst);
        lst = lst->next;
    }
}