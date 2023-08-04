#include "bpf_object.h"
#include <unity.h>

void test_get_num_cpus()
{
    int cpus = get_num_cpus();
    TEST_ASSERT_GREATER_OR_EQUAL(8, cpus);
}