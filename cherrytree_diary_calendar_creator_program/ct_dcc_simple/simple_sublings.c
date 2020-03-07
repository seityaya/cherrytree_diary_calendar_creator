#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ct_dcc_data.h"
#include "ct_dcc_debug_string.h"
#include "ct_dcc_leaf.h"
#include "ct_dcc_main.h"
#include "ct_dcc_node.h"
#include "simple_main.h"
#include "simple_path.h"

extern char year_name[13][24];
extern char month_name[13][24];
extern char week_name[9][24];

void ct_dcc_simple_sublings_root(ct_dcc_data d, char *text)
{
    UNUSED(d);
    UNUSED(text);
    TEXTCAT(text, "<rich_text>❬Y] ❬M] ❬W] ❬D]            [D❭ [W❭ [M❭ [Y❭</rich_text>");
    TEXTCAT(text, "<rich_text>\n</rich_text>");
}

void ct_dcc_simple_sublings_year(ct_dcc_data d, char *text)
{
    ct_dcc_data t_save;
    t_save = d;
    d = t_save;
    data_add(&d, -1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬Y]</rich_text>", d.year, NODE_TYPE_YEAR, d.day_num_year);
    TEXTCAT(text, "<rich_text>                                   </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y❭</rich_text>", d.year, NODE_TYPE_YEAR, d.day_num_year);
    d = t_save;
    TEXTCAT(text, "<rich_text>\n</rich_text>");
}

void ct_dcc_simple_sublings_month(ct_dcc_data d, char *text)
{
    ct_dcc_data t_save;
    t_save = d;
    d = t_save;
    data_add(&d, -1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬Y]</rich_text>", d.year, NODE_TYPE_MONTH, d.month);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, -1, NODE_TYPE_MONTH);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬M]</rich_text>", d.year, NODE_TYPE_MONTH, d.month);
    TEXTCAT(text, "<rich_text>                            </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_MONTH);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[M❭</rich_text>", d.year, NODE_TYPE_MONTH, d.month);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y❭</rich_text>", d.year, NODE_TYPE_MONTH, d.month);
    d = t_save;
    TEXTCAT(text, "<rich_text>\n</rich_text>");
}

void ct_dcc_simple_sublings_week(ct_dcc_data d, char *text)
{
    ct_dcc_data t_save;
    t_save = d;
    d = t_save;
    data_add(&d, -1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬Y]</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year);
    TEXTCAT(text, "<rich_text>     </rich_text>");
    d = t_save;
    data_add(&d, -1, NODE_TYPE_WEEK);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬W]</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year);
    TEXTCAT(text, "<rich_text>                    </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_WEEK);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[W❭</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year);
    TEXTCAT(text, "<rich_text>     </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y❭</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year);
    d = t_save;
    TEXTCAT(text, "<rich_text>\n</rich_text>");
}

void ct_dcc_simple_sublings_day(ct_dcc_data d, char *text)
{
    ct_dcc_data t_save;
    t_save = d;
    d = t_save;
    data_add(&d, -1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬Y]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, -1, NODE_TYPE_MONTH);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬M]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, -1, NODE_TYPE_WEEK);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬W]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, -1, NODE_TYPE_DAY);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">❬D]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text>            </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_DAY);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[D❭</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_WEEK);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[W❭</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_MONTH);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[M❭</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    TEXTCAT(text, "<rich_text> </rich_text>");
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y❭</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    d = t_save;
    TEXTCAT(text, "<rich_text>\n</rich_text>");
}
