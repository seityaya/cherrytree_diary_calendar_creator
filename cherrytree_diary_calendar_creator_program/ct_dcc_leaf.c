#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ct_dcc_data.h"
#include "ct_dcc_debug_string.h"
#include "ct_dcc_leaf.h"
#include "ct_dcc_main.h"
#include "ct_dcc_node.h"
#include "ct_dcc_simple/simple_main.h"

void ct_dcc_leaf_root(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    UNUSED(conf);
    diary_debug_string(d, text, NODE_TYPE_ROOT);
    ct_dcc_simple_root(d, text);
}

void ct_dcc_leaf_year(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    UNUSED(conf);
    diary_debug_string(d, text, NODE_TYPE_YEAR);
    ct_dcc_simple_year(d, text);
}

void ct_dcc_leaf_month(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    UNUSED(conf);
    diary_debug_string(d, text, NODE_TYPE_MONTH);
    ct_dcc_simple_month(d, text);
}

void ct_dcc_leaf_week(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    UNUSED(conf);
    diary_debug_string(d, text, NODE_TYPE_WEEK);
    ct_dcc_simple_week(d, text);
}

void ct_dcc_leaf_day(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    UNUSED(conf);
    diary_debug_string(d, text, NODE_TYPE_DAY);
    ct_dcc_simple_day(d, text);
}
