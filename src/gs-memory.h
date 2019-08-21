#ifndef SRC_GOLDSCRIPT_MEMORY_H
#define SRC_GOLDSCRIPT_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOLDSCRIPT_MEM_ERR_EXIT 3

void* goldscript_mem_malloc(size_t size);

void* goldscript_mem_calloc(size_t size);

void goldscript_mem_new(size_t size, void** ptr, size_t* len, size_t* cap);

void goldscript_mem_grow(size_t size, void** ptr, size_t* len, size_t* cap);

#endif // SRC_GOLDSCRIPT_MEMORY_H