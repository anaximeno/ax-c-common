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