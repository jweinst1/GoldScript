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

static const char* TEST_STR = "test";

static void test_golds_item_new_str(void)
{
    golds_item_t* i1;
    i1 = golds_item_new_str(TEST_STR);
    CHECK(i1 != NULL);
    CHECK(i1->type == GOLDS_ITEM_TYPE_STR);
    CHECK(GOLDSCRIPT_ITEM_STR_AT(i1, 0) == 't');
    CHECK(GOLDSCRIPT_ITEM_STR_AT(i1, 1) == 'e');
    CHECK(GOLDSCRIPT_ITEM_STR_AT(i1, 2) == 's');
    CHECK(GOLDSCRIPT_ITEM_STR_AT(i1, 3) == 't');
    CHECK(GOLDSCRIPT_ITEM_STR_AT(i1, 4) == '\0');
    golds_item_del(i1);
}
    
int main(void) {
    test_golds_item_new_num();
    test_golds_item_new_str();
    return failures ? 3 : 0;
}