#include "ct_diary_calendar_creator_data.h"
#include "ct_diary_calendar_creator_main.h"

#if LANG_DIARY == LANG_RU
static uint8_t year_name[13][24] = {"Год"};
static uint8_t mount_name[13][24] = {"Мес", "Янв", "Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек"};
static uint8_t week_name[8][24] = {"Нд", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
#elif LANG == LANG_EN

#endif

/** PARAM: (year, month & day_month) or (year, week & week_day)*/
void data_init(data_st *d, uint16_t year, uint16_t mount, uint16_t week, uint16_t day)
{
    if (0 == year) { /*Если год равен нулю, то всё остальное тоже равно нулю*/
        /*Занулить всё*/
        d->jdn = 0;
        d->year = 0;
        d->year_leap = 0;
        d->month = 0;
        d->day_month = 0;
        d->day_num_year = 0;
        d->day_max_year = 0;
        d->day_max_month = 0;
        d->week_year = 0;
        d->week_day = 0;
        d->week_max_year = 0;
    } else if (0 == mount && 0 == week) { /*Если год не равен нулю, а месяц и неделя равны нулю*/
        /*Вычислить*/
        d->year = year;
        d->year_leap = 0;
        d->day_max_year = 365;
        d->week_max_year = 52;
        d->jdn = 0;
        /*Занулить*/
        d->month = 0;
        d->week_year = 0;
        d->day_month = 0;
        d->day_num_year = 0;
        d->day_max_month = 0;
        d->week_day = 0;
    } else if (0 != mount && 0 != week) { /*Ошибка, два параметра сразу не указываются*/
        printf("ERORR: data_init (0 != mount && 0 != week)\n");
        exit(1);
    } else if (0 != mount && 0 == week) { /*Месяц не равен нулю*/
        if (0 == day) {
            /**/
            d->year = year;
            d->month = mount;
            d->day_month = 0;
            /*Вычислить*/
            d->year_leap = 0;
            d->day_max_year = 0;
            d->day_max_month = 30;
            d->week_max_year = 0;
            /*Занулить*/
            d->jdn = 0;
            d->day_num_year = 0;
            d->week_year = 0;
            d->week_day = 0;
        } else {
            /**/
            d->year = year;
            d->month = mount;
            d->day_month = day;
            /*Вычислить всё*/
            d->jdn = 0;
            d->year_leap = 0;
            d->day_num_year = 0;
            d->day_max_year = 0;
            d->day_max_month = 0;
            d->week_year = 0;
            d->week_day = 0;
            d->week_max_year = 0;
        }
    } else if (0 == mount && 0 != week) { /*Неделя не равна нулю*/
        d->month = mount;
        d->week_year = 0;
        if (0 == day) {
            /**/
            d->year = year;
            d->week_year = week;
            d->week_day = 0;
            /*Вычислить*/
            d->year_leap = 0;
            d->day_max_year = 0;
            d->day_max_month = 0;
            d->week_max_year = 0;
            /*Занулить*/
            d->month = mount;
            d->jdn = 0;
            d->day_month = 0;
            d->day_num_year = 0;

        } else {
            /**/
            d->year = year;
            d->week_year = week;
            d->day_month = day;
            /*Вычислить всё*/
            d->week_day = 0;
            d->jdn = 0;
            d->year_leap = 0;
            d->month = 0;
            d->day_num_year = 0;
            d->day_max_year = 0;
            d->day_max_month = 30;
            d->week_max_year = 0;
        }
    } else {
        printf("ERORR: data_init(%d %d %d %d)\n", year, mount, week, day);
        exit(1);
    }

    //TODO DEL BEG
    d->year_leap = 0;
    d->day_num_year = 0;
    d->week_max_year = 365;
    d->day_max_month = 30;
    d->week_day = 1;
    d->week_max_year = 52;
    //TODO DEL END

    //data_set_data(d);
}

void data_set(data_st *d)
{
    data_gr_to_jd(d);
    data_day_num_year(d);
    data_month_name(d);
    data_year_leap(d);
    data_day_max_month(d);
    data_week_dey(d);
    data_week_day_name(d);
    data_week_year(d);
}

/** PARAM: year, week, week_day */
uint16_t data_month(data_st *d)
{
    UNUSED(d);
    //TODO

    data_st t;
    data_init(&t, d->year, 1, 0, 1);      /*вычисление параметров для первого января*/
    if (t.week_day <= 4) {                /*первая неделя года*/
    } else {                              /*неделя предыдущего года*/
    }

    d->month = 0;
    return d->month;
}

/** PARAM: @@@ */
uint16_t data_week_year(data_st *d)
{
    UNUSED(d);
    //TODO

    d->week_year = 0;
    return d->week_year;
}

/** PARAM: @@@ */
uint16_t data_week_max_year(data_st *d)
{
    UNUSED(d);
    //TODO

    d->week_max_year = 52;
    return d->week_max_year;
}

/** PARAM: year, month, day_month*/
uint32_t data_gr_to_jd(data_st *d)
{
    uint32_t A, Y, M, D;
    A = (14 - d->month) / 12;
    Y = d->year + 4800 - A;
    M = d->month + 12 * A - 3;
    D = d->day_month;
    d->jdn = D + ((153 * M + 2) / 5) + 365 * Y + (Y / 4) - (Y / 100) + (Y / 400) - 32045;
    return d->jdn;
}

/** PARAM: year*/
uint16_t data_year_leap(data_st *d)
{
    if (d->year % 4 != 0) {
        d->year_leap = 0;
    } else if (d->year % 100 == 0 && d->year % 400 != 0) {
        d->year_leap = 0;
    } else {
        d->year_leap = 1;
    }
    return d->year_leap;
}

/** PARAM: month*/
uint16_t data_day_max_month(data_st *d)
{
    data_year_leap(d);
    d->day_max_month = (28 + (d->month + d->month / 8) % 2 + 2 % d->month + 1 / d->month * 2) + d->year_leap;
    return d->day_max_month;
}

/** PARAM: year_leap*/
uint16_t data_day_max_year(data_st *d)
{
    data_year_leap(d);
    d->day_max_year = 365 + d->year_leap;
    return d->day_max_year;
}

/** PARAM: year, month, day_month*/
uint16_t data_day_num_year(data_st *d)
{
    data_gr_to_jd(d);
    data_st t;
    data_init(&t, d->year, 1, 0, 1);
    d->day_num_year = data_dif(&t, d);
    return d->day_num_year;
}

/** PARAM: year, month, day_month*/
uint16_t data_week_dey(data_st *d)
{
    data_gr_to_jd(d);
    d->week_day = (d->jdn % 7) + 1;
    return d->week_day;
}

/** PARAM: 0 */
uint8_t *data_year_name(data_st *d)
{
    strcpy((char *) d->year_name, (char *) year_name[0]);
    return d->year_name;
}

/** PARAM: month */
uint8_t *data_month_name(data_st *d)
{
    strcpy((char *) d->month_name, (char *) mount_name[d->month]);
    return d->month_name;
}

/** PARAM: week_day */
uint8_t *data_week_day_name(data_st *d)
{
    strcpy((char *) d->week_name, (char *) week_name[d->week_day]);
    return d->week_name;
}

/** PARAM: year, month, day_month*/
uint32_t data_dif(data_st *now, data_st *diff)
{
    return (diff->jdn - now->jdn);
}

/** PARAM: year, month, day_month*/
uint32_t data_add(data_st *now, int32_t *add)
{
    now->jdn += *add;
    //TODO update
    return now->jdn;
}

/** PARAM: ALL*/
uint32_t data_print(data_st *now)
{
    printf("jdn : %d\n", now->jdn);
    printf("data: %d %d %d\n", now->year, now->month, now->day_month);
    printf("day : %d %d %d\n", now->day_num_year, now->day_max_month, now->day_max_year);
    printf("week: %d %d %d\n", now->week_day, now->week_year, now->week_max_year);
    return 0;
}
