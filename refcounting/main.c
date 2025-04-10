#include <stdlib.h>

#include "filler.h"
#include "munit.h"
#include "snekobject.h"

MunitResult test_inc_refcount(const MunitParameter* pointer, void* key)
{
    snek_object_t* obj = new_snek_integer(10);
    munit_assert_int(obj->refcount, ==, 1);

    refcount_inc(obj);
    munit_assert_int(obj->refcount, ==, 2);

    free(obj);
    return MUNIT_OK;
}

MunitResult test_inc_refcount_more(const MunitParameter* pointer, void* key)
{
    snek_object_t* obj = new_snek_float(4.20);
    munit_assert_int(obj->refcount, ==, 1);

    refcount_inc(obj);
    refcount_inc(obj);
    refcount_inc(obj);
    refcount_inc(obj);
    refcount_inc(obj);
    munit_assert_int(obj->refcount, ==, 6);

    free(obj);
    return MUNIT_OK;
}

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

MunitResult test_null_obj(const MunitParameter* pointer, void* key)
{
    refcount_inc(NULL);
    munit_assert(1);
    return MUNIT_OK;
}

MunitResult test_dec_refcount(const MunitParameter* pointer, void* key)
{
    snek_object_t* obj = new_snek_float(4.20);

    refcount_inc(obj);
    munit_assert_int(obj->refcount, ==, 2);

    refcount_dec(obj);
    munit_assert_int(obj->refcount, ==, 1);

    // Object is still alive, so we will free manually.
    free(obj);
    return MUNIT_OK;
}

MunitResult test_refcount_free_is_called(const MunitParameter* pointer,
                                         void*                 key)
{
    snek_object_t* obj = new_snek_float(4.20);

    refcount_inc(obj);
    munit_assert_int(obj->refcount, ==, 2);

    refcount_dec(obj);
    munit_assert_int(obj->refcount, ==, 1);

    refcount_dec(obj);
    return MUNIT_OK;
}

MunitResult test_allocated_string_is_freed(const MunitParameter* pointer,
                                           void*                 key)
{
    snek_object_t* obj = new_snek_string("Hello @wagslane!");

    refcount_inc(obj);
    munit_assert_int(obj->refcount, ==, 2);

    refcount_dec(obj);
    munit_assert_int(obj->refcount, ==, 1);
    munit_assert_string_equal(obj->data.v_string, "Hello @wagslane!");

    refcount_dec(obj);
    return MUNIT_OK;
}

int main(void)
{
    MunitTest tests[] = {
        munit_test("test_int_has_refcount", test_int_has_refcount),
        munit_test("test_float_has_refcount", test_float_has_refcount),
        munit_test("test_null_obj", test_null_obj),
        munit_test("test_inc_refcount", test_inc_refcount),
        munit_test("/dec_refcount", test_dec_refcount),
        munit_test("/free_refcount", test_refcount_free_is_called),
        munit_test("/string_freed", test_allocated_string_is_freed),
        munit_null_test,
    };

    MunitSuite suite = munit_suite("refcount", tests);

    munit_suite_main(&suite, NULL, 0, NULL);
    return EXIT_SUCCESS;
}
