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
#include "simple_sublings.h"

extern char year_name[13][24];
extern char month_name[13][24];
extern char week_name[9][24];

void ct_dcc_simple_table_root(ct_dcc_data d, char *text)
{
    for (int16_t t = 1; t <= ((END_YEAR - BEG_YEAR) + 1); t++) {
        data_init(&d, ((t + BEG_YEAR) - 1), 0, 0, 0);
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
        if (0 == t % 7) {
            TEXTCAT(text, "<rich_text >\n</rich_text>");
        }
    }
    TEXTCAT(text, "<rich_text >\n</rich_text>");
}

void ct_dcc_simple_table_year(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text>⌊Mn⌋       ⌊Wk⌋\n</rich_text>");
    data_init(&d, d.year, 0, 1, 4);
    for (int16_t t = BEG_MONTH; t <= END_MONTH; t++) {
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d'%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
        TEXTCAT(text, "<rich_text>   </rich_text>");
        for (;;) {
            TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d]</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year, d.week_year);
            data_add(&d, 7, NODE_TYPE_DAY);
            if (t != d.month) {
                TEXTCAT(text, "<rich_text>\n</rich_text>");
                break;
            }
        }
    }
}

void ct_dcc_simple_table_month(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text >⌊%s⌋   </rich_text>", week_name[0]);
    for (int16_t t = 1; t <= 7; t++) {
        TEXTCAT(text, "<rich_text >⌊%s⌋</rich_text>", week_name[t]);
    }
    TEXTCAT(text, "<rich_text >\n</rich_text>");

    data_init(&d, d.year, d.month, 0, 1);
    data_init(&d, d.year, 0, d.week_year, 1);
    if (BELONGS_TO_INTERVAL(2, d.day_month, 8)) {
        data_add(&d, -1, NODE_TYPE_WEEK);
    }
    for (int16_t t = 0; t < 7 * 6; t++) {
        if (0 == t % 7) {
            TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d]   </rich_text>", d.year, NODE_TYPE_WEEK, d.week_year, d.week_year);
        }
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year, d.day_month);
        if ((6 == t % 7)) {
            TEXTCAT(text, "<rich_text >\n</rich_text>");
        }
        data_add(&d, 1, NODE_TYPE_DAY);
    }
}

void ct_dcc_simple_table_week(ct_dcc_data d, char *text)
{
    ct_dcc_data t_d;
    t_d = d;
    data_init(&d, d.year, 0, d.week_year, 1);
    uint16_t mount_tmp_beg = d.month;
    data_init(&d, d.year, 0, d.week_year, 7);
    uint16_t mount_tmp_end = d.month;
    TEXTCAT(text, "<rich_text>⌊Mn⌋</rich_text>");
    if (mount_tmp_beg == mount_tmp_end) {
        TEXTCAT(text, "<rich_text>              </rich_text>");
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d'%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
    } else {
        data_init(&d, d.year, 0, d.week_year, 1);
        TEXTCAT(text, "<rich_text>          </rich_text>");
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d'%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
        data_init(&d, d.year, 0, d.week_year, 7);
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d'%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
    }
    TEXTCAT(text, "<rich_text >\n</rich_text>");

    d = t_d;
    for (int16_t t = 0; t <= 7; t++) {
        if (0 == t) {
            TEXTCAT(text, "<rich_text>⌊%s⌋   </rich_text>", week_name[0]);
            t++;
        }
        data_init(&d, d.year, 0, d.week_year, t);
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%s]</rich_text>", d.year - d.year_week_overflow, NODE_TYPE_DAY, d.day_num_year + t_d.year_leap, d.week_name);
        if (0 == t % 7) {
            TEXTCAT(text, "<rich_text >\n</rich_text>");
        }
    }
    for (int16_t t = 0; t <= 7; t++) {
        if (0 == t) {
            TEXTCAT(text, "<rich_text>⌊%s⌋   </rich_text>", week_name[8]);
            t++;
        }
        data_init(&d, d.year, 0, d.week_year, t);
        TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[%02d]</rich_text>", d.year - d.year_week_overflow, NODE_TYPE_DAY, d.day_num_year + t_d.year_leap, d.day_month);
        if (0 == t % 7) {
            TEXTCAT(text, "<rich_text >\n</rich_text>");
        }
    }
}

void ct_dcc_simple_table_day(ct_dcc_data d, char *text)
{
    UNUSED(d);
    UNUSED(text);
}
