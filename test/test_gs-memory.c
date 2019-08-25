#include "gs-memory.h"
#include <stdlib.h>

static unsigned failures = 0;

#define CHECK(cond) if(!(cond) && ++failures) \
    fprintf(stderr, "FAILURE: expression '%s', line %u\n", #cond, (unsigned)__LINE__)
    
static void test_golds_mem_alloc(void)
{
    void* p1 = NULL;
    void* p2 = NULL;
    p1 = golds_mem_malloc(50);
    p2 = golds_mem_calloc(30);
    CHECK(p1 != NULL);
    CHECK(p2 != NULL);
    CHECK(*((unsigned char*)p2) == 0);
    free(p1);
    free(p2);
}

int main(void)
{
    test_golds_mem_alloc();
    return failures ? 3 : 0;
}

#undef CHECK
