#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ct_dcc_data.h"
#include "ct_dcc_leaf.h"
#include "ct_dcc_main.h"
#include "ct_dcc_node.h"

void ct_dcc_node_beg(char *text, ct_dcc_data d, uint8_t node_type)
{
    int32_t temp = 0;
    char node_type_symbol = ' ';
    if (NODE_TYPE_ROOT == node_type) {
        temp = 0;
        node_type_symbol = 'R';
    } else if (NODE_TYPE_YEAR == node_type) {
        temp = 0;
        node_type_symbol = 'Y';
    } else if (NODE_TYPE_MONTH == node_type) {
        temp = d.month;
        node_type_symbol = 'M';
    } else if (NODE_TYPE_WEEK == node_type) {
        temp = d.week_year;
        node_type_symbol = 'W';
    } else if (NODE_TYPE_DAY == node_type) {
        temp = d.day_num_year;
        node_type_symbol = 'D';
    } else {
        exit(0);
    }

    TEXTCAT(text,
            "<node custom_icon_id=\"0\" "
            "foreground=\"\" "
            "is_bold=\"False\" "
            "name=\"%sY%04d %c%03d\" "
            "prog_lang=\"custom-colors\" "
            "readonly=\"False\" "
            "tags=\"\" "
            "ts_creation=\"0\" "
            "ts_lastsave=\"0\" "
            "unique_id=\"%04d%01d%03d\">\n",
            NODE_PREFIX,
            d.year,
            node_type_symbol,
            temp,

            d.year,
            node_type,
            temp);
}
void ct_dcc_node_end(char *text)
{
    TEXTCAT(text, "</node>\n");
}

void ct_dcc_node_root(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    data_init(&d, 0, 0, 0, 0);
    ct_dcc_node_beg(text, d, NODE_TYPE_ROOT);
    ct_dcc_leaf_root(d, text, conf);
    ct_dcc_node_year(d, text, conf);
    ct_dcc_node_end(text);
}

void ct_dcc_node_year(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    for (d.year = BEG_YEAR; d.year <= END_YEAR; d.year++) {
        data_init(&d, d.year, 0, 0, 0);
        ct_dcc_node_beg(text, d, NODE_TYPE_YEAR);
        ct_dcc_leaf_year(d, text, conf);
        ct_dcc_node_month(d, text, conf);
        ct_dcc_node_week(d, text, conf);
        ct_dcc_node_day(d, text, conf);
        ct_dcc_node_end(text);
    }
}

void ct_dcc_node_month(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    ct_dcc_node_beg(text, d, NODE_TYPE_MONTH);
    for (d.month = BEG_MONTH; d.month <= END_MONTH; d.month++) {
        data_init(&d, d.year, d.month, 0, 0);
        ct_dcc_node_beg(text, d, NODE_TYPE_MONTH);
        ct_dcc_leaf_month(d, text, conf);
        ct_dcc_node_end(text);
    }
    ct_dcc_node_end(text);
}

void ct_dcc_node_week(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    ct_dcc_node_beg(text, d, NODE_TYPE_WEEK);
    for (d.week_year = 1; d.week_year <= d.week_max_year; d.week_year++) {
        data_init(&d, d.year, 0, d.week_year, 0);
        ct_dcc_node_beg(text, d, NODE_TYPE_WEEK);
        ct_dcc_leaf_week(d, text, conf);
        ct_dcc_node_end(text);
    }
    ct_dcc_node_end(text);
}

void ct_dcc_node_day(ct_dcc_data d, char *text, ct_dcc_config *conf)
{
    ct_dcc_node_beg(text, d, NODE_TYPE_DAY);
    for (d.month = BEG_MONTH; d.month <= END_MONTH; d.month++) {
        data_init(&d, d.year, d.month, 0, 0);
        for (d.day_month = 1; d.day_month <= d.day_max_month; d.day_month++) {
            data_init(&d, d.year, d.month, 0, d.day_month);
            ct_dcc_node_beg(text, d, NODE_TYPE_DAY);
            ct_dcc_leaf_day(d, text, conf);
            ct_dcc_node_end(text);
        }
    }
    ct_dcc_node_end(text);
}
