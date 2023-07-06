#ifndef _AX_LOG
#define _AX_LOG

#define AX_DEBUG_ACTIVE 0

/** The level of the log, can be:
 * - NONE: won't be printed to the terminal,
 * - INFO: will be printed with aa info notice,
 * - WARN: will be printed with an warning notice,
 * - ERROR: will be printed with an error notice
 */
enum ax_log_level_t
{
    NONE,
    INFO,
    WARN,
    ERROR,
};

typedef struct ax_log_info_t ax_log_info_t;

/** Prints a log message to stderr. */
void ax_log(enum ax_log_level_t, char *message);

#endif