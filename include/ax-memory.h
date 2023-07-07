#ifndef _AX_MEMORY
#define _AX_MEMORY

#include <stdlib.h>
#include <string.h>

/** Allocates memory for the TYPE. */
#define axlocate(type) (type *)malloc(sizeof(type))
#define axreallocate(value, type, size) (type *)realloc(value, size)
#define axcallocate(length, type) (type *)calloc(length, sizeof(type))
#define axfree(value) ({ free(value); value = NULL; })

/** Returns a copy of the VALUE of its given TYPE*/
#define axmemdup(value, type) ({            \
    type *_tmp_ = axlocate(type);           \
    if (_tmp_ != NULL)                      \
        memcpy(_tmp_, value, sizeof(type)); \
    _tmp_;                                  \
})

#endif