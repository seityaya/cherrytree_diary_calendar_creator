#ifndef CT_DIARY_CALENDAR_CREATOR_DATA_H_
#define CT_DIARY_CALENDAR_CREATOR_DATA_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BELONGS_TO_INTERVAL(beg, compare, end) (((compare) >= (beg)) && (((compare) <= (end))) && ((((beg) < (end)) || (beg) == (end)) ? TRUE : FALSE))

typedef struct
{
    int32_t jdn;                //номер юлианского дня
    int16_t year;               //григорианский год
    int16_t year_week_overflow; //флаг перехода недели через границу года //NOTE: ISSUE 1
    int16_t year_leap;          //високосный флаг
    int16_t month;              //месяц
    int16_t day_month;          //номер дня в месяце
    int16_t day_num_year;       //номер дня в году
    int16_t day_max_year;       //количество дней в году
    int16_t day_max_month;      //количество дней в месяце
    int16_t day_week;           //номер дня в недели
    int16_t week_year;          //номер недели в году
    int16_t week_max_year;      //количество недель в году

    uint8_t year_name[24];
    uint8_t month_name[24];
    uint8_t week_name[24];
} data_st;

void data_init(data_st *d, int16_t year, int16_t month, int16_t week, int16_t day);

void data_month(data_st *d);
void data_day_month(data_st *d);
void data_week_year(data_st *d);

void data_gr_to_jd(data_st *d);
void data_jd_to_gr(data_st *d);
void data_year_leap(data_st *d);
void data_day_max_month(data_st *d);
void data_day_max_year(data_st *d);
void data_day_num_year(data_st *d);
void data_dey_week(data_st *d);

void data_week_max_year(data_st *d);

void data_week_day_name(data_st *d);
void data_year_name(data_st *d);
void data_month_name(data_st *d);

void data_add(data_st *now, int32_t add, int8_t type_interval);
void data_print(data_st *now, const char *str);
int32_t data_dif(data_st *now, data_st *diff);

#endif /*CT_DIARY_CALENDAR_CREATOR_DATA_H_*/
