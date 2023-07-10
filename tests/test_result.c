#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinytest/tinytest.h"

#include "../ax-c-common.h"

typedef struct dummy
{
    char *name;
    unsigned age;
    double weight;
} dummy;

void test_result_ok()
{
    dummy *d = axlocate(dummy);

    d->age = 18;
    d->name = "Jonny";
    d->weight = 20.5;

    ax_result_p result = ax_result_ok(d);

    ASSERT_EQ(OK, result->type);

    dummy *z = axunwrap_ok(result, dummy);

    ASSERT_EQ(18, d->age);
    ASSERT_STR_EQ("Jonny", d->name);
    ASSERT_EQ(20.5, d->weight);

    ASSERT_EQ(18, z->age);
    ASSERT_STR_EQ("Jonny", z->name);
    ASSERT_EQ(20.5, z->weight);

    ASSERT_NE(&d, &z);
    ASSERT_NE(d, z);

    ax_free_result(&result);

    /* z should still work */
    ASSERT_EQ(18, z->age);
    ASSERT_STR_EQ("Jonny", z->name);
    ASSERT_EQ(20.5, z->weight);

    free(z);
}

void test_result_err()
{
    ax_result_p result = ax_result_err(1, "Test error message");

    ASSERT_EQ(1, result->to.err.errnum);
    ASSERT_STR_EQ("Test error message", result->to.err.message);

    ax_free_result(&result);
}

int main(int argc, char **argv)
{
    RUN(test_result_ok);
    RUN(test_result_err);
    return TEST_REPORT();
}