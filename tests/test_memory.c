#include <stdio.h>
#include <stdlib.h>

#include "tinytest/tinytest.h"

#include "../include/ax-memory.h"

typedef struct dummy
{
    char *name;
    unsigned age;
    double weight;
} dummy;

void test_axalloc_macro()
{
    dummy *d = ax_alloc(dummy);

    ASSERT("Couldn't allocate enough memory", d != NULL);

    if (d != NULL)
    {
        d->age = 18;
        d->name = "Jonny";
        d->weight = 20.5;

        ASSERT_EQ(18, d->age);
        ASSERT_STR_EQ("Jonny", d->name);
        ASSERT_EQ(20.5, d->weight);

        ax_free(d);
    }
}

void test_axralloc_macro()
{
    dummy *d = (dummy *)malloc(sizeof(dummy));

    ASSERT("Couldn't allocate enough memory", d != NULL);

    if (d != NULL)
    {
        d->age = 18;
        d->name = "Jonny";
        d->weight = 20.5;

        d = ax_ralloc(d, dummy, sizeof(dummy));

        ASSERT_EQ(18, d->age);
        ASSERT_STR_EQ("Jonny", d->name);
        ASSERT_EQ(20.5, d->weight);

        ax_free(d);
    }
}

void test_axmdup_macro()
{
    dummy *d1 = (dummy *)malloc(sizeof(dummy));

    ASSERT("Couldn't allocate enough memory", d1 != NULL);

    if (d1 != NULL)
    {
        d1->age = 18;
        d1->name = "Jonny";
        d1->weight = 20.5;

        dummy *d2 = ax_mdup(d1, dummy);

        ASSERT_EQ(18, d1->age);
        ASSERT_STR_EQ("Jonny", d1->name);
        ASSERT_EQ(20.5, d1->weight);

        ASSERT_NE(&d1, &d2);
        ASSERT_NE(d1, d2);

        ax_free(d1);

        ASSERT_EQ(18, d2->age);
        ASSERT_STR_EQ("Jonny", d2->name);
        ASSERT_EQ(20.5, d2->weight);

        ax_free(d2);
    }
}

int main(int argc, char **argv)
{
    RUN(test_axalloc_macro);
    RUN(test_axralloc_macro);
    RUN(test_axmdup_macro);
    return TEST_REPORT();
}
