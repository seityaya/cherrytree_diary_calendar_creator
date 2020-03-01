#include "ct_diary_calendar_creator_node.h"

static char buff[20000];

void diary_node_beg(char *text, data_st d, uint8_t node_type)
{
    int32_t temp = 0;
    char node_name = ' ';
    if (NODE_TYPE_ROOT == node_type) {
        temp = 0;
        node_name = 'R';
    } else if (NODE_TYPE_YEAR == node_type) {
        temp = 0;
        node_name = 'Y';
    } else if (NODE_TYPE_MONTH == node_type) {
        temp = d.month;
        node_name = 'M';
    } else if (NODE_TYPE_WEEK == node_type) {
        temp = d.week_year;
        node_name = 'W';
    } else if (NODE_TYPE_DAY == node_type) {
        temp = d.day_num_year;
        node_name = 'D';
    } else {
        exit(0);
    }

    sprintf(buff,
            "<node custom_icon_id=\"0\" "
            "foreground=\"\" "
            "is_bold=\"False\" "
            "name=\"Y%04d %c%03d\" "
            "prog_lang=\"custom-colors\" "
            "readonly=\"False\" "
            "tags=\"\" "
            "ts_creation=\"0\" "
            "ts_lastsave=\"0\" "
            "unique_id=\"%04d%01d%03d\">\n",
            d.year,
            node_name,
            temp,

            d.year,
            node_type,
            temp);
    strcat(text, buff);
}
void diary_node_end(char *text)
{
    strcat(text, "</node>\n");
}

void diary_node_root(data_st d, char *text)
{
#ifdef DIARY_NODE_ROOT
    data_init(&d, 0, 0, 0, 0);
    diary_node_beg(text, d, NODE_TYPE_ROOT);
    diary_table_root(d, text);
    diary_node_year(d, text);
    diary_node_end(text);
#endif
}

void diary_node_year(data_st d, char *text)
{
#ifdef DIARY_NODE_YEAR
    for (d.year = BEG_YEAR; d.year <= END_YEAR; d.year++) {
        data_init(&d, d.year, 0, 0, 0);
        diary_node_beg(text, d, NODE_TYPE_YEAR);
        diary_table_year(d, text);
        diary_node_month(d, text);
        diary_node_week(d, text);
        diary_node_day(d, text);
        diary_node_end(text);
    }
#endif
}

void diary_node_month(data_st d, char *text)
{
#ifdef DIARY_NODE_MONTH
    diary_node_beg(text, d, NODE_TYPE_MONTH);
    for (d.month = BEG_MONTH; d.month <= END_MONTH; d.month++) {
        data_init(&d, d.year, d.month, 0, 0);
        diary_node_beg(text, d, NODE_TYPE_MONTH);
        diary_table_month(d, text);
        diary_node_end(text);
    }
    diary_node_end(text);
#endif
}

void diary_node_week(data_st d, char *text)
{
#ifdef DIARY_NODE_WEEK
    diary_node_beg(text, d, NODE_TYPE_WEEK);
    for (d.week_year = 1; d.week_year <= d.week_max_year; d.week_year++) {
        data_init(&d, d.year, 0, d.week_year, 0);
        diary_node_beg(text, d, NODE_TYPE_WEEK);
        diary_table_week(d, text);
        diary_node_end(text);
    }
    diary_node_end(text);
#endif
}

void diary_node_day(data_st d, char *text)
{
#ifdef DIARY_NODE_DAY
    diary_node_beg(text, d, NODE_TYPE_DAY);
    for (d.month = BEG_MONTH; d.month <= END_MONTH; d.month++) {
        data_init(&d, d.year, d.month, 0, 0);
        for (d.day_month = 1; d.day_month <= d.day_max_month; d.day_month++) {
            data_init(&d, d.year, d.month, 0, d.day_month);
            diary_node_beg(text, d, NODE_TYPE_DAY);
            diary_table_day(d, text);
            diary_node_end(text);
        }
    }
    diary_node_end(text);
#endif
}
