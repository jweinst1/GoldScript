#ifndef SRC_GOLDSCRIPT_LINKED_H
#define SRC_GOLDSCRIPT_LINKED_H

#include "gs-memory.h"

/**
 * @file This file provides an inheritable interface of a singly linked list.
 */

#define GOLDSCRIPT_LINKED_SYMBOL __gs_link

#define GOLDSCRIPT_LINKED_HEAD \
                int type; \
                struct GOLDSCRIPT_LINKED_SYMBOL* next

/**
 * @brief Represents the base struct used in constructing linked list
 *        interfaces.
 */
struct GOLDSCRIPT_LINKED_SYMBOL
{
    GOLDSCRIPT_LINKED_HEAD;
};

typedef struct GOLDSCRIPT_LINKED_SYMBOL gs_linked_t;

#define GOLDSCRIPT_LINKED_HAS_NEXT(node) (node->next != NULL)

#define GOLDSCRIPT_LINKED_CAST(node) ((gs_linked_t*)node)

#define GOLDSCRIPT_LINKED_CONN(n1, n2) (n1->next = n2)
/**
 * @brief Macro that consumes a ptr to a \c gs_linked_t* to advance it to
 *        the end.
 */
#define GOLDSCRIPT_LINKED_ADV_END(node) while(node != NULL && node->next != NULL) node = node->next

size_t golds_linked_len(gs_linked_t* lst);

void golds_linked_put(gs_linked_t* lst, gs_linked_t* item);

void golds_linked_del(gs_linked_t* lst);

#endif // SRC_GOLDSCRIPT_LINKED_H