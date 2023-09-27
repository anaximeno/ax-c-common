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

ax_result(dummy) create_dummy(unsigned age, char* name, double weight)
{
    dummy *d = axlocate(dummy);

    if (d != NULL) {
        d->age = age;
        d->name = name;
        d->weight = weight;

        return ax_result_ok(d);
    }

    return ax_result_err(1, "Error");
}

void test_result_ok()
{
    ax_result_p result = create_dummy(18, "Jonny", 20.5);

    ASSERT_EQ(OK, result->type);

    dummy *d = (dummy *)result->to.ok.value;
    dummy *z = axunwrap_ok(result, dummy);

    ASSERT_EQ(18, d->age);
    ASSERT_STR_EQ("Jonny", d->name);
    ASSERT_EQ(20.5, d->weight);

    ASSERT_EQ(18, z->age);
    ASSERT_STR_EQ("Jonny", z->name);
    ASSERT_EQ(20.5, z->weight);

    ASSERT_NE(&d, &z);
    ASSERT_EQ(z->age, d->age);
    ASSERT_STR_EQ(z->name, d->name);
    ASSERT_EQ(z->weight, d->weight);
    ASSERT_NE(d, z);

    ax_free_result(&result);

    /* z should still work */
    ASSERT_EQ(18, z->age);
    ASSERT_STR_EQ("Jonny", z->name);
    ASSERT_EQ(20.5, z->weight);

    axfree(z);
}

void test_result_err()
{
    ax_result_p result = ax_result_err(1, "Test error message");

    ASSERT_EQ(ERR, result->type);
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
