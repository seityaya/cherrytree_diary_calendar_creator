#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ct_dcc_data.h"
#include "ct_dcc_main.h"

void ct_dcc_simple_path_root(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[R~%s]</rich_text>", d.year, NODE_TYPE_ROOT, 0, MAIN_PAGE_NAME);
    TEXTCAT(text, "<rich_text >[Y~yyyy][M~mm'mmm][W~ww][D~dd'dd]\n</rich_text>");
}

void ct_dcc_simple_path_year(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[R~%s]</rich_text>", 0, NODE_TYPE_ROOT, 0, MAIN_PAGE_NAME);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y~%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    TEXTCAT(text, "<rich_text >\n</rich_text>");
}

void ct_dcc_simple_path_month(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[R~%s]</rich_text>", 0, NODE_TYPE_ROOT, 0, MAIN_PAGE_NAME);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y~%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[M~%02d'%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
    TEXTCAT(text, "<rich_text >\n</rich_text>");
}

void ct_dcc_simple_path_week(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[R~%s]</rich_text>", 0, NODE_TYPE_ROOT, 0, MAIN_PAGE_NAME);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y~%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">         [W~%02d]</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year, d.week_year);
    TEXTCAT(text, "<rich_text >\n</rich_text>");
}

void ct_dcc_simple_path_day(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[R~%s]</rich_text>", 0, NODE_TYPE_ROOT, 0, MAIN_PAGE_NAME);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[Y~%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[M~%02d'%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[W~%02d]</rich_text>", d.year + d.year_week_overflow, NODE_TYPE_WEEK, d.week_year, d.week_year);
    TEXTCAT(text, "<rich_text link=\"node %04d%01d%03d\">[D~%02d'%s]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year, d.day_month, d.week_name);
    TEXTCAT(text, "<rich_text >\n</rich_text>");
}
