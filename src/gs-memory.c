#include "gs-memory.h"

#define _GOLDSCRIPT_MEM_CHECK(ptr, caller) if((ptr) == NULL) { \
	fprintf(stderr, "Memory Error: Got NULL on call to '%s', exiting.\n", caller);\
	exit(GOLDSCRIPT_MEM_ERR_EXIT);\
}

void* golds_mem_malloc(size_t size)
{
	void* ptr = malloc(size);
	_GOLDSCRIPT_MEM_CHECK(ptr, "goldscript_mem_malloc")
	return ptr;
}

void* golds_mem_calloc(size_t size)
{
	void* ptr = calloc(1, size);
	_GOLDSCRIPT_MEM_CHECK(ptr, "goldscript_mem_calloc")
	return ptr;
}

void golds_mem_new(size_t size, void** ptr, size_t* len, size_t* cap)
{
	*ptr = calloc(0, size);
	_GOLDSCRIPT_MEM_CHECK(*ptr, "goldscript_mem_new")
	*cap = size;
}

void golds_mem_grow(size_t size, void** ptr, size_t* len, size_t* cap)
{
	*cap += size;
	*ptr = realloc(*ptr, *cap);
	_GOLDSCRIPT_MEM_CHECK(*ptr, "goldscript_mem_grow")
}