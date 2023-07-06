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

extern void ax_log(ax_log_info_t info)
{
    if (info.lvl != NONE)
    {
        fprintf(stderr, "%s%s%s", info.prefix,
                level_name(info.lvl), info.message);
    }
}
