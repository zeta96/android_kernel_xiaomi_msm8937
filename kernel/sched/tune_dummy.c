// SPDX-License-Identifier: GPL-2.0
#include <linux/cgroup.h>

/*
 * Dummy schedtune for Android userspace compatibility.
 * Does NOT affect scheduler behavior.
 */

static s64 boost_read(struct cgroup_subsys_state *css,
                      struct cftype *cft)
{
    return 0;
}

static int boost_write(struct cgroup_subsys_state *css,
                       struct cftype *cft, s64 val)
{
    return 0;
}

static u64 prefer_idle_read(struct cgroup_subsys_state *css,
                            struct cftype *cft)
{
    return 0;
}

static int prefer_idle_write(struct cgroup_subsys_state *css,
                             struct cftype *cft, u64 val)
{
    return 0;
}

static struct cftype schedtune_files[] = {
    {
        .name       = "boost",
        .read_s64   = boost_read,
        .write_s64  = boost_write,
    },
    {
        .name       = "prefer_idle",
        .read_u64   = prefer_idle_read,
        .write_u64  = prefer_idle_write,
    },
    { }
};

struct cgroup_subsys schedtune_cgrp_subsys = {
    .legacy_cftypes = schedtune_files,
};
