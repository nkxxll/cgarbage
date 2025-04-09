#include <stdlib.h>

#include "filler.h"
#include "munit.h"
#include "snekobject.h"

MunitResult test_int_has_refcount(const MunitParameter* pointer, void* key)
{
    snek_object_t* obj = new_snek_integer(10);
    munit_assert_int(obj->refcount, ==, 1);
    free(obj);
    return MUNIT_OK;
}

MunitResult test_float_has_refcount(const MunitParameter* pointer, void* key)
{
    snek_object_t* obj = new_snek_float(42.0);
    munit_assert_int(obj->refcount, ==, 1);
    free(obj);
    return MUNIT_OK;
}

int main(void)
{
    MunitTest tests[] = {
        munit_test("test_int_has_refcount", test_int_has_refcount),
        munit_test("test_float_has_refcount", test_float_has_refcount),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("refcount", tests);

    munit_suite_main(&suite, NULL, 0, NULL);
    return EXIT_SUCCESS;
}
