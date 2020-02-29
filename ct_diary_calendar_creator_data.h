#ifndef CT_DIARY_CALENDAR_CREATOR_DATA_H_
#define CT_DIARY_CALENDAR_CREATOR_DATA_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTER(beg, compare, end) ((((compare) > (beg)) || ((compare) == (beg))) && (((compare) <= (end))) && ((((beg) < (end)) || (beg) == (end)) ? TRUE : FALSE))

typedef struct
{
    uint32_t jdn;           //номер юлианского дня
    uint16_t year;          //григорианский год
    uint16_t year_leap;     //высокосный флаг
    uint16_t month;         //месяц
    uint16_t day_month;     //номер дня в месяце
    uint16_t day_num_year;  //номер дня в году
    uint16_t day_max_year;  //количество дней в году
    uint16_t day_max_month; //количество дней в месяце
    uint16_t day_week;      //номер дня в недели
    uint16_t week_year;     //номер недели в году
    uint16_t week_max_year; //количество недель в году

    uint8_t year_name[24];
    uint8_t month_name[24];
    uint8_t week_name[24];
} data_st;

void data_init(data_st *d, uint16_t year, uint16_t month, uint16_t week, uint16_t day);

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

void data_add(data_st *now, int32_t add);
void data_print(data_st *now, const char *str);
uint32_t data_dif(data_st *now, data_st *diff);

#endif /*CT_DIARY_CALENDAR_CREATOR_DATA_H_*/
