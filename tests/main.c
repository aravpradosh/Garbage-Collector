#include "munit.h"
#include "sneknew.h"
#include "snekobject.h"
#include "vm.h"
#include <stdlib.h>



static MunitResult test_simple(const MunitParameter params[], void *data) {
    vm_t *vm = vm_new();
    frame_t *f1 = vm_new_frame(vm);

    snek_object_t *s = new_snek_string(vm, "I wish I knew how to read.");
    frame_reference_object(f1, s);

    vm_collect_garbage(vm);

    /* Still referenced by frame → must still exist */
    munit_assert_int(vm->objects->count, ==, 1);

    frame_free(vm_frame_pop(vm));
    vm_collect_garbage(vm);

    /* Now unreachable → should be collected */
    munit_assert_int(vm->objects->count, ==, 0);

    vm_free(vm);
    return MUNIT_OK;
}

static MunitResult test_full(const MunitParameter params[], void *data) {
    vm_t *vm = vm_new();
    frame_t *f1 = vm_new_frame(vm);
    frame_t *f2 = vm_new_frame(vm);
    frame_t *f3 = vm_new_frame(vm);

    snek_object_t *s1 = new_snek_string(vm, "Frame 1");
    frame_reference_object(f1, s1);

    snek_object_t *s2 = new_snek_string(vm, "Frame 2");
    frame_reference_object(f2, s2);

    snek_object_t *s3 = new_snek_string(vm, "Frame 3");
    frame_reference_object(f3, s3);

    snek_object_t *i1 = new_snek_integer(vm, 69);
    snek_object_t *i2 = new_snek_integer(vm, 420);
    snek_object_t *i3 = new_snek_integer(vm, 1337);
    snek_object_t *v = new_snek_vector3(vm, i1, i2, i3);

    frame_reference_object(f2, v);
    frame_reference_object(f3, v);

    munit_assert_int(vm->objects->count, ==, 7);

    /* Free top frame (f3) */
    frame_free(vm_frame_pop(vm));
    vm_collect_garbage(vm);

    /* Only s3 should be gone */
    munit_assert_int(vm->objects->count, ==, 6);

    /* Free remaining frames */
    frame_free(vm_frame_pop(vm));
    frame_free(vm_frame_pop(vm));
    vm_collect_garbage(vm);

    /* Everything should be gone */
    munit_assert_int(vm->objects->count, ==, 0);

    vm_free(vm);
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { "/test_simple", test_simple, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_full", test_full, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/mark_and_sweep_gc",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
