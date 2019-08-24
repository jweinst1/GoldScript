#ifndef SRC_GOLDSCRIPT_MEMORY_H
#define SRC_GOLDSCRIPT_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOLDSCRIPT_MEM_ERR_EXIT 3
/**
 * @brief Cross compiler macro for advancing a void pointer.
 */
#define GOLDSCRIPT_MEM_ADV(ptr, amnt) ((unsigned char*)(ptr) + amnt)

void* golds_mem_malloc(size_t size);

void* golds_mem_calloc(size_t size);

void golds_mem_new(size_t size, void** ptr, size_t* len, size_t* cap);

void golds_mem_grow(size_t size, void** ptr, size_t* len, size_t* cap);

#endif // SRC_GOLDSCRIPT_MEMORY_H