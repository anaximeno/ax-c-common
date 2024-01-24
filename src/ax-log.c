#include <stdio.h>
#include <stdlib.h>

#include "../include/ax-log.h"

static inline const char *level_name(enum ax_log_level_t lvl)
{
    switch (lvl)
    {
    case INFO:
        return "info";

    case WARN:
        return "warning";

    case ERROR:
        return "error";

    case NONE:
    default:
        return "";
    }
}

extern void ax_log(enum ax_log_level_t level, const char *message)
{
    ax_named_log(NULL, level, message);
}

void ax_named_log(const char* name, enum ax_log_level_t level, const char* message)
{
    if (name != NULL)
        fprintf(stderr, "%s: ", name);

    if (level != NONE)
        fprintf(stderr, "%s: ", level_name(level));

    if (message != NULL)
        fprintf(stderr, "%s\n", message);
}