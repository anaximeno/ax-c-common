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

#include <stdio.h>
#include <stdlib.h>

#include "../include/ax-log.h"

static inline const char *log_text(enum ax_log_t type)
{
    switch (type)
    {
    case AX_LOG_INFO:
        return "info";

    case AX_LOG_WARN:
        return "warning";

    case AX_LOG_ERROR:
        return "error";

    case AX_LOG_NONE:
    default:
        return "";
    }
}

extern void ax_log(enum ax_log_t type, const char *message)
{
    ax_nlog(NULL, type, message);
}

extern void ax_nlog(const char *name, enum ax_log_t type, const char *message)
{
    if (name != NULL)
        fprintf(stderr, "%s: ", name);

    if (type != AX_LOG_NONE)
        fprintf(stderr, "%s: ", log_text(type));

    if (message != NULL)
        fprintf(stderr, "%s\n", message);
}