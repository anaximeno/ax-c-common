#include <stdlib.h>
#include <stdio.h>

#include "../include/ax-result.h"
#include "../include/ax-memory.h"

extern ax_result_p ax_result_ok(void *value)
{
    ax_result_p result = axlocate(ax_result_t);

    if (result != NULL)
    {
        result->type = OK;
        result->to.ok.value = value;
    }

    return result;
}

extern ax_result_p ax_result_err(int errnum, char *message)
{
    ax_result_p result = axlocate(ax_result_t);

    if (result != NULL)
    {
        result->type = ERR;
        result->to.err.errnum = errnum;
        result->to.err.message = message;
    }

    return result;
}

extern void ax_free_result(ax_result_p *result)
{
    if (result != NULL && *result != NULL)
    {
        if ((*result)->type == OK && (*result)->to.ok.value != NULL)
            axfree((*result)->to.ok.value);
        axfree(*result);
    }
}
