#include "ct_diary_calendar_creator_node.h"

static char buff[20000];

void diary_node_beg(char *text, uint16_t year, uint8_t node_type, uint16_t month, uint16_t week_year, uint16_t day)
{
    sprintf(buff,
            "<node custom_icon_id=\"0\" "
            "foreground=\"\" "
            "is_bold=\"False\" "
            "name=\"y%04d n%01d m%02d w%02d d%02d\" "
            "prog_lang=\"custom-colors\" "
            "readonly=\"True\" "
            "tags=\"\" "
            "ts_creation=\"0\" "
            "ts_lastsave=\"0\" "
            "unique_id=\"%04d%01d%02d%02d%02d\">\n",
            year,
            node_type,
            month,
            week_year,
            day,

            year,
            node_type,
            month,
            week_year,
            day);
    strcat(text, buff);
}
void diary_node_end(char *text)
{
    strcat(text, "</node>\n");
}

void diary_node_main(data_st d, char *text)
{
#ifdef DIARY_NODE_MAIN
    data_init(&d, 0, 0, 0, 0);
    diary_node_beg(text, d.year, NODE_TYPE_MAIN, d.month, d.week_year, d.day_month);
    diary_table_main(d, text);
    diary_node_year(d, text);
    diary_node_end(text);
#endif
}

void diary_node_year(data_st d, char *text)
{
#ifdef DIARY_NODE_YEAR
    for (d.year = BEG_YEAR; d.year <= END_YEAR; d.year++) {
        data_init(&d, d.year, 0, 0, 0);
        diary_node_beg(text, d.year, NODE_TYPE_YEAR, d.month, d.week_year, d.day_month);
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
    diary_node_beg(text, d.year, NODE_TYPE_MONTH, d.month, d.week_year, d.day_month);
    for (d.month = BEG_MONTH; d.month <= END_MONTH; d.month++) {
        data_init(&d, d.year, d.month, 0, 0);
        diary_node_beg(text, d.year, NODE_TYPE_MONTH, d.month, d.week_year, d.day_month);
        diary_table_month(d, text);
        diary_node_end(text);
    }
    diary_node_end(text);
#endif
}

void diary_node_week(data_st d, char *text)
{
#ifdef DIARY_NODE_WEEK
    diary_node_beg(text, d.year, NODE_TYPE_WEEK, d.month, d.week_year, d.day_month);
    for (d.week_year = 1; d.week_year <= d.week_max_year; d.week_year++) {
        data_init(&d, d.year, 0, d.week_year, 0);
        diary_node_beg(text, d.year, NODE_TYPE_WEEK, d.month, d.week_year, d.day_month);
        diary_table_week(d, text);
        diary_node_end(text);
    }
    diary_node_end(text);
#endif
}

void diary_node_day(data_st d, char *text)
{
#ifdef DIARY_NODE_DAY
    diary_node_beg(text, d.year, NODE_TYPE_DAY, d.month, d.week_year, d.day_month);
    for (d.month = BEG_MONTH; d.month <= END_MONTH; d.month++) {
        data_init(&d, d.year, d.month, 0, 0);
        for (d.day_month = 1; d.day_month <= d.day_max_month; d.day_month++) {
            data_init(&d, d.year, d.month, 0, d.day_month);
            diary_node_beg(text, d.year, NODE_TYPE_DAY, d.month, d.week_year, d.day_month);
            diary_table_week(d, text);
            diary_node_end(text);
        }
    }
    diary_node_end(text);
#endif
}
