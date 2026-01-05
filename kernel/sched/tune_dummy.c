// SPDX-License-Identifier: GPL-2.0
#include <linux/cgroup.h>

static int schedtune_css_online(struct cgroup_subsys_state *css)
{
    return 0;
}

static void schedtune_css_offline(struct cgroup_subsys_state *css)
{
}

struct cgroup_subsys schedtune_cgrp_subsys = {
    .css_online  = schedtune_css_online,
    .css_offline = schedtune_css_offline,
};
