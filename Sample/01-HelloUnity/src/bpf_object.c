#include "bpf_object.h"
#include "libbpf.h"

int get_num_cpus()
{
    int cpus = libbpf_num_possible_cpus();
    return cpus;
}