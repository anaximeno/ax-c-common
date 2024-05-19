/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * MIT License                                                                       *
 *                                                                                   *
 * Copyright (c) 2023-2024 Anaxímeno Brito                                           *
 *                                                                                   *
 * Permission is hereby granted, free of charge, to any person obtaining a copy      *
 * of this software and associated documentation files (the "Software"), to deal     *
 * in the Software without restriction, including without limitation the rights      *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell         *
 * copies of the Software, and to permit persons to whom the Software is             *
 * furnished to do so, subject to the following conditions:                          *
 *                                                                                   *
 * The above copyright notice and this permission notice shall be included in all    *
 * copies or substantial portions of the Software.                                   *
 *                                                                                   *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR        *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,          *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE       *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER            *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,     *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     *
 * SOFTWARE.                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _AX_MEMORY
#define _AX_MEMORY

#include <stdlib.h>
#include <string.h>

/** Allocates memory for the given TYPE. */
#define ax_alloc(type) (type *)malloc(sizeof(type))

/** Used to reallocate memory from VALUE of the given TYPE to a given SIZE. */
#define ax_ralloc(value, type, size) (type *)realloc(value, size)

/** Used to allocate a sequential block of values of a given LENGTH for a given TYPE. */
#define ax_calloc(length, type) (type *)calloc(length, sizeof(type))

/** Frees the VALUE of a given variable then sets it to NULL. */
#define ax_free(value) ({ free(value); value = NULL; })

/** Returns a copy of the VALUE of its given TYPE*/
#define ax_mdup(value, type) ({           \
    type *tmp = ax_alloc(type);           \
                                          \
    if (tmp != NULL)                      \
        memcpy(tmp, value, sizeof(type)); \
                                          \
    tmp;                                  \
})

#endif