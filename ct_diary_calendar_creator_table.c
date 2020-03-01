#include "ct_diary_calendar_creator_table.h"

static char buff[20000];

void diary_table_root(data_st d, char *text)
{
#ifdef DIARY_TABLE_ROOT_D
    //HEADER BEG
    sprintf(buff, "<rich_text>THIS Y%04d  M%02d/D%02d  W%02d/D%02d\n</rich_text>", d.year, d.month, d.day_month, d.week_year, d.day_week);
    strcat(text, buff);
    //HEADER END

    //MOVING ALONG PATH BEG
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">[ROOT]</rich_text>", 0, NODE_TYPE_ROOT, 0);
    strcat(text, buff);
    //MOVING ALONG PATH END

    //MOVING ALONG SIBLINGS BEG
    //VOID
    //MOVING ALONG SIBLINGS END

    //TABLE BEG
    sprintf(buff, "<rich_text >\nY:\n</rich_text>");
    strcat(text, buff);
    for (int16_t t = BEG_YEAR; t <= END_YEAR; t++) {
        data_init(&d, t, 0, 0, 0);
        sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">%d%c</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year, (0 == t % 5) ? '\n' : ' ');
        strcat(text, buff);
    }
    //TABLE END

    //FOOTER BEG
    sprintf(buff, "<rich_text style=\"italic\">\n\n\n\n\n=================================================================\n</rich_text>");
    strcat(text, buff);
    //FOOTER END
#endif
}

void diary_table_year(data_st d, char *text)
{
#ifdef DIARY_TABLE_YEAR_D
    //HEADER BEG
    sprintf(buff, "<rich_text>THIS Y%04d  M%02d/D%02d  W%02d/D%02d\n</rich_text>", d.year, d.month, d.day_month, d.week_year, d.day_week);
    strcat(text, buff);
    //HEADER END

    //MOVING ALONG PATH BEG
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">[ROOT]</rich_text>", 0, NODE_TYPE_ROOT, 0);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [Y%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    strcat(text, buff);
    //MOVING ALONG PATH END

    //MOVING ALONG SIBLINGS BEG
    data_st t_save;
    t_save = d;
    sprintf(buff, "<rich_text>\n</rich_text>");
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬Y </rich_text>", d.year, NODE_TYPE_YEAR, d.day_num_year);
    strcat(text, buff);

    sprintf(buff, "<rich_text>             @              </rich_text>");
    strcat(text, buff);

    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">Y❭❭ </rich_text>", d.year, NODE_TYPE_YEAR, d.day_num_year);
    strcat(text, buff);
    //MOVING ALONG SIBLINGS END

    //TABLE BEG
    sprintf(buff, "<rich_text>\nM:\n</rich_text>");
    strcat(text, buff);
    for (int16_t t = BEG_MONTH; t <= END_MONTH; t++) {
        data_init(&d, d.year, t, 0, 0);
        sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">%02d </rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month);
        strcat(text, buff);
    }
    sprintf(buff, "<rich_text >\nW:\n</rich_text>");
    strcat(text, buff);
    for (int16_t t = 1; t <= d.week_max_year; t++) {
        data_init(&d, d.year, 0, t, 0);
        sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">%02d%c</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year, d.week_year, (0 == t % 12) ? '\n' : ' ');
        strcat(text, buff);
    }
    //TABLE END

    //FOOTER BEG
    sprintf(buff, "<rich_text style=\"italic\">\n=================================================================\n</rich_text>");
    strcat(text, buff);
    //FOOTER END
#endif
}

void diary_table_month(data_st d, char *text)
{
#ifdef DIARY_TABLE_MONTH_D
    //HEADER BEG
    sprintf(buff, "<rich_text>THIS Y%04d  M%02d/D%02d  W%02d/D%02d\n</rich_text>", d.year, d.month, d.day_month, d.week_year, d.day_week);
    strcat(text, buff);
    //HEADER END

    //MOVING ALONG PATH BEG
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">[ROOT]</rich_text>", 0, NODE_TYPE_ROOT, 0);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [Y%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [M%02d-%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
    strcat(text, buff);
    //MOVING ALONG PATH END

    //MOVING ALONG SIBLINGS BEG
    data_st t_save;
    t_save = d;
    sprintf(buff, "<rich_text>\n</rich_text>");
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬Y </rich_text>", d.year, NODE_TYPE_MONTH, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_MONTH);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬M </rich_text>", d.year, NODE_TYPE_MONTH, d.day_num_year);
    strcat(text, buff);

    sprintf(buff, "<rich_text>         @          </rich_text>");
    strcat(text, buff);

    d = t_save;
    data_add(&d, 1, NODE_TYPE_MONTH);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">M❭❭ </rich_text>", d.year, NODE_TYPE_MONTH, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">Y❭❭ </rich_text>", d.year, NODE_TYPE_MONTH, d.day_num_year);
    strcat(text, buff);
    //MOVING ALONG SIBLINGS END

    //TABLE BEG
    sprintf(buff, "<rich_text >\nD:\n</rich_text>");
    strcat(text, buff);
    for (int16_t t = 1; t <= d.day_max_month; t++) {
        data_init(&d, d.year, d.month, 0, t);
        sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">%02d%c</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year, d.day_month, (0 == t % 7) ? '\n' : ' ');
        strcat(text, buff);
    }
    //TABLE END

    //FOOTER BEG
    sprintf(buff, "<rich_text style=\"italic\">\n\n\n=================================================================\n</rich_text>");
    strcat(text, buff);
    //FOOTER END
#endif
}

void diary_table_week(data_st d, char *text)
{
#ifdef DIARY_TABLE_WEEK_D
    //HEADER BEG
    sprintf(buff, "<rich_text>THIS Y%04d  M%02d/D%02d  W%02d/D%02d\n</rich_text>", d.year, d.month, d.day_month, d.week_year, d.day_week);
    strcat(text, buff);
    //HEADER END

    //MOVING ALONG PATH BEG
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">[ROOT]</rich_text>", 0, NODE_TYPE_ROOT, 0);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [Y%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [W%02d]</rich_text>", d.year, NODE_TYPE_WEEK, d.week_year, d.week_year);
    strcat(text, buff);
    //MOVING ALONG PATH END

    //MOVING ALONG SIBLINGS BEG
    data_st t_save;
    t_save = d;
    data_init(&t_save, t_save.year, 0, t_save.week_year, t_save.day_week);
    sprintf(buff, "<rich_text>\n</rich_text>");
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬Y </rich_text>", d.year, NODE_TYPE_WEEK, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    //        data_add(&d, 1, -NODE_TYPE_MONTH);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬M </rich_text>", d.year, NODE_TYPE_WEEK, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_WEEK);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬W </rich_text>", d.year, NODE_TYPE_WEEK, d.day_num_year);
    strcat(text, buff);

    sprintf(buff, "<rich_text>     @      </rich_text>");
    strcat(text, buff);

    d = t_save;
    data_add(&d, 1, NODE_TYPE_WEEK);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">W❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, NODE_TYPE_MONTH);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">M❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">Y❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    //MOVING ALONG SIBLINGS END

    //TABLE BEG
    data_st t_d;
    t_d = d;
    data_init(&t_d, t_d.year - 1, t_d.month, 0, t_d.day_month);
    sprintf(buff, "<rich_text >\nW:\n</rich_text>");
    strcat(text, buff);
    for (int16_t t = 1; t <= 7; t++) {
        data_init(&d, d.year, 0, d.week_year, t);
        sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">%s%c</rich_text>", d.year - d.year_week_overflow, NODE_TYPE_DAY, d.day_num_year + t_d.year_leap, d.week_name, (0 == t % 7) ? '\n' : ' ');
        strcat(text, buff);
    }
    //TABLE END

    //FOOTER BEG
    sprintf(buff, "<rich_text style=\"italic\">\n\n\n\n\n\n=================================================================\n</rich_text>");
    strcat(text, buff);
    //FOOTER END
#endif
}

void diary_table_day(data_st d, char *text)
{
#ifdef DIARY_TABLE_DAY_D
    //HEADER BEG
    sprintf(buff, "<rich_text>THIS Y%04d  M%02d/D%02d  W%02d/D%02d\n</rich_text>", d.year, d.month, d.day_month, d.week_year, d.day_week);
    strcat(text, buff);
    //HEADER END

    //MOVING ALONG PATH BEG
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">[ROOT]</rich_text>", 0, NODE_TYPE_ROOT, 0);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [Y%04d]</rich_text>", d.year, NODE_TYPE_YEAR, 0, d.year);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [M%02d-%s]</rich_text>", d.year, NODE_TYPE_MONTH, d.month, d.month, d.month_name);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [W%02d]</rich_text>", d.year + d.year_week_overflow, NODE_TYPE_WEEK, d.week_year, d.week_year);
    strcat(text, buff);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\"> [D%02d-%s]</rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year, d.day_month, d.week_name);
    strcat(text, buff);
    //MOVING ALONG PATH END

    //MOVING ALONG SIBLINGS BEG
    data_st t_save;
    t_save = d;
    sprintf(buff, "<rich_text>\n</rich_text>");
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬Y </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_MONTH);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬M </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_WEEK);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬W </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, -NODE_TYPE_DAY);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">❬❬D </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);

    sprintf(buff, "<rich_text> @  </rich_text>");
    strcat(text, buff);

    d = t_save;
    data_add(&d, 1, NODE_TYPE_DAY);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">D❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, NODE_TYPE_WEEK);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">W❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, NODE_TYPE_MONTH);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">M❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    d = t_save;
    data_add(&d, 1, NODE_TYPE_YEAR);
    sprintf(buff, "<rich_text link=\"node %04d%01d%03d\">Y❭❭ </rich_text>", d.year, NODE_TYPE_DAY, d.day_num_year);
    strcat(text, buff);
    //MOVING ALONG SIBLINGS END

    //FOOTER BEG
    sprintf(buff, "<rich_text style=\"italic\">\n\n\n\n\n\n\n\n\n=================================================================\n</rich_text>");
    strcat(text, buff);
    //FOOTER END
#endif
}
