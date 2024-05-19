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

#include <stdlib.h>
#include <stdio.h>

#include "../include/ax-result.h"
#include "../include/ax-memory.h"

extern ax_result_t *ax_result_ok(void *value)
{
    ax_result_t *result = ax_alloc(ax_result_t);

    if (result != NULL)
    {
        result->type = AX_RESULT_OK;
        result->to.ok.value = value;
    }

    return result;
}

extern ax_result_t *ax_result_err(int errnum, char *message)
{
    ax_result_t *result = ax_alloc(ax_result_t);

    if (result != NULL)
    {
        result->type = AX_RESULT_ERR;
        result->to.err.errnum = errnum;
        result->to.err.message = message;
    }

    return result;
}

extern void ax_free_result(ax_result_t **result)
{
    if (result != NULL && *result != NULL)
    {
        if ((*result)->type == AX_RESULT_OK && (*result)->to.ok.value != NULL)
            ax_free((*result)->to.ok.value);
        ax_free(*result);
    }
}
