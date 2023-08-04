#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>
#include "bootstrap.h"

char LICENSE[] SEC("license") = "Dual BSD/GPL";

struct
{
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 8192);
    __type(key, pid_t);
    __type(value, u64);
} exec_start SEC(".maps");

struct
{
    __uint(type, BPF_MAP_TYPE_RINGBUF);
    __uint(max_entries, 256 * 1024);
} rb SEC(".maps");

const volatile unsigned long long min_duration_ns = 0;

SEC("tp/sched/sched_process_exec")
int handle_exec(struct trace_event_raw_sched_process_exec *ctx)
{
    struct task_struct *task;
    unsigned fname_off;
    struct event *e;
    pid_t pid;
    u64 ts;

    // Remember time exec() was executed for this PID
    pid = bpf_get_current_pid_tgid() >> 32;
    ts = bpf_ktime_get_ns();
    bpf_map_update_elem(&exec_start, &pid, &ts, BPF_ANY);

    // Don't emit exec events when minimum duration is specified
    if (min_duration_ns)
    {
        return 0;
    }

    // Reserve sample from BPF ringbuf
    e = bpf_ringbuf_reserve(&rb, sizeof(*e), BPF_ANY);
    if (!e)
    {
        return 0;
    }

    // File out the sample with data
    task = (struct task_struct *)bpf_get_current_task();

    e->exit_event = false;
    e->pid = pid;
    e->ppid = BPF_CORE_READ(task, real_parent, tgid);
    e->exit_code = ( BPF_CORE_READ(task, exit_code) >> 8) &0xff;
    bpf_get_current_comm(&e->comm, sizeof(e->comm));

    // Send data to user space for post processing
    bpf_ringbuf_submit(e, 0);
    return 8;
}