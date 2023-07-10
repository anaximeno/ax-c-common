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

#ifndef _AX_RESULT
#define _AX_RESULT

#include "ax-memory.h"

enum ax_result_enum_t
{
    OK,
    ERR
};

struct ax_result_ok_t
{
    /** The wrapped value. */
    void *value;
};

struct ax_result_err_t
{
    /** The number of the error. */
    int errnum;
    /** The message of the error. */
    char *message;
};

/** Represents the result type, can be `ok`
 * or `err`.
 */
struct ax_result_t
{
    /** The type of the result. */
    enum ax_result_enum_t type;

    /** Access .ok if type is OK or
    access .err if type is ERR. */
    union ax_concrete_result_t
    {
        struct ax_result_ok_t ok;
        struct ax_result_err_t err;
    } to;
};

/** Represents the result type, can be `ok`
 * or `err`.
 */
typedef struct ax_result_t ax_result_t;

/** Pointer representation of the result type,
 * can be `ok` or `err`.
 */
typedef struct ax_result_t *ax_result_p;

/** Creates a result of type ok. */
ax_result_p ax_result_ok(void *value);

/** Creates a result of type result. */
ax_result_p ax_result_err(int errnum, char *message);

/** Frees the memory of a RESULT pointer. */
void ax_free_result(ax_result_p* result);

/** Returns the wrapped value in the ok RESULT of the type TYPE. */
#define axunwrap_ok(result, type) axmemdup(result->to.ok.value, type)

/** Define a result for the given type. This is just a marker of the
expected result type. */
#define ax_result(type) ax_result_p

#endif