#ifndef CT_DCC_DATA_H_
#define CT_DCC_DATA_H_

#include <stdint.h>

#define BELONGS_TO_INTERVAL(beg, compare, end) (((compare) >= (beg)) && (((compare) <= (end))) && ((((beg) < (end)) || (beg) == (end)) ? TRUE : FALSE))
#define MODULUS(x) (((x) >= 0) ? (x) : (-(x)))
#define SUGNUM(x) (((x) >= 0) ? (((x) > 0) ? (1) : (0)) : (-1))

/*TYPE NODE*/
#define NODE_TYPE_ROOT 0
#define NODE_TYPE_YEAR 1
#define NODE_TYPE_SEASON 2
#define NODE_TYPE_MONTH 3
#define NODE_TYPE_WEEK 4
#define NODE_TYPE_DAY 5

typedef struct
{
    int32_t jdn;                //номер юлианского дня
    int16_t year;               //григорианский год
    int16_t year_week_overflow; //флаг перехода недели через границу года
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
} ct_dcc_data;

void data_init(ct_dcc_data *d, int16_t year, int16_t month, int16_t week, int16_t day);

void data_month(ct_dcc_data *d);
void data_day_month(ct_dcc_data *d);
void data_week_year(ct_dcc_data *d);
void data_gr_to_jd(ct_dcc_data *d);
void data_jd_to_gr(ct_dcc_data *d);
void data_year_leap(ct_dcc_data *d);
void data_day_max_month(ct_dcc_data *d);
void data_day_max_year(ct_dcc_data *d);
void data_day_num_year(ct_dcc_data *d);
void data_dey_week(ct_dcc_data *d);
void data_week_max_year(ct_dcc_data *d);
void data_week_day_name(ct_dcc_data *d);
void data_year_name(ct_dcc_data *d);
void data_month_name(ct_dcc_data *d);

void data_add(ct_dcc_data *now, int32_t add, int8_t type_interval);
void data_print(ct_dcc_data *now, const char *str);
int32_t data_dif(ct_dcc_data *now, ct_dcc_data *diff);

#endif /*CT_DCC_DATA_H_*/
