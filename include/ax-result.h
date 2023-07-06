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
void *ax_free_result(ax_result_p result);

/** Returns the wrapped value in the ok RESULT of the type TYPE. */
#define axunwrap_ok(result, type) axmemdup(result->to.ok.value, type)

#endif