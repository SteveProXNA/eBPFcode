#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "Dual BSD/GPL";

int my_pid = 0;
unsigned long long dev;
unsigned long long ino;

SEC("tp/syscalls/sys_enter_write")
int handle_tp(void *ctx)
{
    struct bpf_pidns_info ns;

    bpf_get_ns_current_pid_tgid(dev, ino, &ns, sizeof(ns));
    if (ns.pid != my_pid)
        return 0;

    bpf_printk("BPF triggered from PID %d.\n", ns.pid);

    return 0;
}