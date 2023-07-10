/* MIT License
 *
 * Copyright (c) 2023 Anaxímeno Brito
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _AX_MEMORY
#define _AX_MEMORY

#include <stdlib.h>
#include <string.h>

/** Allocates memory for the given TYPE. */
#define axlocate(type) (type *)malloc(sizeof(type))

/** Used to reallocate memory from VALUE of the given TYPE to a given SIZE. */
#define axreallocate(value, type, size) (type *)realloc(value, size)

/** Used to allocate a sequential block of values of a given LENGTH for a given TYPE. */
#define axcallocate(length, type) (type *)calloc(length, sizeof(type))

/** Frees the VALUE of a given variable then sets it to NULL. */
#define axfree(value) ({ free(value); value = NULL; })

/** Returns a copy of the VALUE of its given TYPE*/
#define axmemdup(value, type) ({            \
    type *_tmp_ = axlocate(type);           \
    if (_tmp_ != NULL)                      \
        memcpy(_tmp_, value, sizeof(type)); \
    _tmp_;                                  \
})

#endif