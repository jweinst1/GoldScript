#include "gs-item.h"
#include <stdlib.h>

static unsigned failures = 0;

#define CHECK(cond) if(!(cond) && ++failures) \
    fprintf(stderr, "FAILURE: expression '%s', line %u\n", #cond, (unsigned)__LINE__)
    
    
static void test_golds_item_new_num(void)
{
    golds_item_t* i1;
    i1 = golds_item_new_num(45.6);
    CHECK(i1 != NULL);
    golds_item_del(i1);
}
    
int main(void) {
    test_golds_item_new_num();
    return failures ? 3 : 0;
}