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

void test_axlocate_macro()
{
    dummy *d = axlocate(dummy);

    ASSERT("Couldn't allocate enough memory", d != NULL);

    if (d != NULL)
    {
        d->age = 18;
        d->name = "Jonny";
        d->weight = 20.5;

        ASSERT_EQ(18, d->age);
        ASSERT_STR_EQ("Jonny", d->name);
        ASSERT_EQ(20.5, d->weight);

        axfree(d);
    }
}

void test_axreallocate_macro()
{
    dummy *d = (dummy *)malloc(sizeof(dummy));

    ASSERT("Couldn't allocate enough memory", d != NULL);

    if (d != NULL)
    {
        d->age = 18;
        d->name = "Jonny";
        d->weight = 20.5;

        d = axreallocate(d, dummy, sizeof(dummy));

        ASSERT_EQ(18, d->age);
        ASSERT_STR_EQ("Jonny", d->name);
        ASSERT_EQ(20.5, d->weight);

        axfree(d);
    }
}

void test_axmemdup_macro()
{
    dummy *d1 = (dummy *)malloc(sizeof(dummy));

    ASSERT("Couldn't allocate enough memory", d1 != NULL);

    if (d1 != NULL)
    {
        d1->age = 18;
        d1->name = "Jonny";
        d1->weight = 20.5;

        dummy* d2 = axmemdup(d1, dummy);

        ASSERT_EQ(18, d1->age);
        ASSERT_STR_EQ("Jonny", d1->name);
        ASSERT_EQ(20.5, d1->weight);

        ASSERT_NE(&d1, &d2);
        ASSERT_NE(d1, d2);

        axfree(d1);

        ASSERT_EQ(18, d2->age);
        ASSERT_STR_EQ("Jonny", d2->name);
        ASSERT_EQ(20.5, d2->weight);

        axfree(d2);
    }
}

int main(int argc, char **argv)
{
    RUN(test_axlocate_macro);
    RUN(test_axreallocate_macro);
    RUN(test_axmemdup_macro);
    return TEST_REPORT();
}
