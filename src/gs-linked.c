#include "gs-linked.h"

size_t golds_linked_len(golds_linked_t* lst)
{
    size_t total = 0;
    while(lst != NULL) {
        total++;
        lst = lst->next;
    }
    return total;
}

void golds_linked_put(golds_linked_t* lst, golds_linked_t* item)
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

void golds_linked_append(golds_linked_t* lst, golds_linked_t* item)
{
    if(lst == NULL)
        return;
    while(lst->next != NULL)
        lst = lst->next;
    lst->next = item;
}

golds_linked_t* golds_linked_find(golds_linked_t* lst, golds_linked_check fn)
{
    while(lst != NULL) {
        if(fn(lst)) {
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}

void golds_linked_apply_each(golds_linked_t* lst, golds_linked_op fn)
{
    while(lst != NULL) {
        fn(lst);
        lst = lst->next;
    }
}

void golds_linked_del(golds_linked_t* lst)
{
    while(lst != NULL) {
        free(lst);
        lst = lst->next;
    }
}