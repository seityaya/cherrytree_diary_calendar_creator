#include "ct_diary_calendar_creator_data.h"
#include "ct_diary_calendar_creator_main.h"

#if LANG_DIARY == LANG_RU
const char year_name[13][24] = {"Год"};
const char mount_name[13][24] = {"Мес", "Янв", "Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек"};
const char week_name[9][24] = {"Нд", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс", "Дт"};
#elif LANG_DIARY == LANG_EN
const char year_name[13][24] = {"Year"};
const char month_name[13][24] = {"Mth", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const char week_name[9][24] = {"Wk", "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su", "Dt"};
#endif

/** PARAM: (year, month & day_month) or (year, week & week_day)*/
void data_init(data_st *d, int16_t year, int16_t mount, int16_t week, int16_t day)
{
    if (BELONGS_TO_INTERVAL(0, year, 0)) { /*Если год равен нулю, то всё остальное тоже равно нулю*/
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
        d->day_week = 0;
        d->week_max_year = 0;
    } else if (BELONGS_TO_INTERVAL(0, mount, 0) && BELONGS_TO_INTERVAL(0, week, 0)) { /*Если год не равен нулю, а месяц и неделя равны нулю*/
        /*Вычислить*/
        d->year = year;
        data_year_leap(d);
        data_day_max_year(d);
        data_week_max_year(d);
        /*Занулить*/
        d->jdn = 0;
        d->month = 0;
        d->week_year = 0;
        d->day_month = 0;
        d->day_num_year = 0;
        d->day_max_month = 0;
        d->day_week = 0;
    } else if (BELONGS_TO_INTERVAL(1, mount, 12) && BELONGS_TO_INTERVAL(0, week, 0)) { /*Месяц не равен нулю*/
        if (BELONGS_TO_INTERVAL(0, day, 0)) {
            /**/
            d->year = year;
            d->month = mount;
            d->day_month = day;
            /*Вычислить*/
            data_year_leap(d);
            data_day_max_year(d);
            data_week_max_year(d);
            data_day_max_month(d);
            /*Занулить*/
            d->jdn = 0;
            d->day_num_year = 0;
            d->week_year = 0;
            d->day_week = 0;
        } else if (BELONGS_TO_INTERVAL(1, day, 31)) {
            /**/
            d->year = year;
            d->month = mount;
            d->day_month = day;
            /*Вычислить всё*/
            data_gr_to_jd(d);
            data_day_num_year(d);
            data_year_leap(d);
            data_day_max_month(d);
            data_dey_week(d);
            data_week_year(d);
            data_day_max_year(d);
            data_week_max_year(d);
        } else {
            goto error_else;
        }
    } else if (BELONGS_TO_INTERVAL(0, mount, 0) && BELONGS_TO_INTERVAL(1, week, 53)) { /*Неделя не равна нулю*/
        if (BELONGS_TO_INTERVAL(0, day, 0)) {
            /**/
            d->year = year;
            d->week_year = week;
            d->day_week = day;
            /*Вычислить*/
            data_year_leap(d);
            data_day_max_year(d);
            data_week_max_year(d);
            /*Занулить*/
            d->month = 0;
            d->jdn = 0;
            d->day_month = 0;
            d->day_num_year = 0;
            d->day_max_month = 0;
        } else if (BELONGS_TO_INTERVAL(1, day, 7)) {
            /**/
            d->year = year;
            d->week_year = week;
            d->day_week = day;
            data_month(d);
            data_day_month(d);
            /*Вычислить всё*/
            data_gr_to_jd(d);
            data_day_num_year(d);
            data_year_leap(d);
            data_day_max_month(d);
            data_day_max_year(d);
            data_week_max_year(d);
            data_week_year(d); /*NOTE: ISSUE 1*/
        } else {
            goto error_else;
        }
    } else {
    error_else:
        printf("ERROR: data_init(%d, %d, %d, %d)\n", year, mount, week, day);
        exit(1);
    }
    data_year_name(d);
    data_month_name(d);
    data_week_day_name(d);
}

/** PARAM: year, week, day_week */
void data_month(data_st *d)
{
    data_st t;
    int8_t delta = 0;
    t.year = d->year;
    t.month = 1;
    t.day_month = 1;
    data_gr_to_jd(&t);
    data_dey_week(&t);
    if (t.day_week <= 4) {
        delta += t.day_week;
    } else {
        delta -= (7 - t.day_week);
    }
    t.jdn += ((d->week_year - 1) * 7) + d->day_week - delta;
    data_jd_to_gr(&t);

    d->month = t.month;
}

/** PARAM: year, week, day_week */
void data_day_month(data_st *d)
{
    data_st t;
    int8_t delta = 0;
    t.year = d->year;
    t.month = 1;
    t.day_month = 1;
    data_gr_to_jd(&t);
    data_dey_week(&t);
    if (t.day_week <= 4) {
        delta += t.day_week;
    } else {
        delta -= (7 - t.day_week);
    }
    t.jdn += ((d->week_year - 1) * 7) + d->day_week - delta;
    data_jd_to_gr(&t);

    d->day_month = t.day_month;
}

/** PARAM: year, month, day_month */
void data_week_year(data_st *d)
{
    data_st t_beg, t_end;
    data_week_max_year(d);

    d->year_week_overflow = 0;

    t_beg.year = d->year;
    t_beg.month = 1;
    t_beg.day_month = 1;
    data_gr_to_jd(&t_beg);
    data_dey_week(&t_beg);
    if (t_beg.day_week <= 4) {
        t_beg.jdn -= t_beg.day_week - 1;
    } else {
        t_beg.jdn += (7 - t_beg.day_week) + 1;
    }

    t_end.year = d->year;
    t_end.month = d->month;
    t_end.day_month = d->day_month;
    data_gr_to_jd(&t_end);
    data_dey_week(&t_end);
    t_end.jdn += (7 - t_end.day_week);

    d->week_year = (data_dif(&t_beg, &t_end) / 7) + 1;

    /*NOTE: ISSUE 1*/
    if (d->week_year > d->week_max_year) {
        d->week_year = 1;
        d->year_week_overflow = 1;
    }
}

/** PARAM: year */
void data_week_max_year(data_st *d)
{
    data_st t_beg, t_end;

    t_beg.year = d->year;
    t_beg.month = 1;
    t_beg.day_month = 1;
    data_gr_to_jd(&t_beg);
    data_dey_week(&t_beg);
    if (t_beg.day_week <= 4) {
        t_beg.jdn -= t_beg.day_week - 1;
    } else {
        t_beg.jdn += (7 - t_beg.day_week) + 1;
    }

    t_end.year = d->year;
    t_end.month = 12;
    t_end.day_month = 31;
    data_gr_to_jd(&t_end);
    data_dey_week(&t_end);
    if (t_end.day_week >= 4) {
        t_end.jdn += (7 - t_end.day_week);
    } else {
        t_end.jdn -= t_end.day_week;
    }

    d->week_max_year = (data_dif(&t_beg, &t_end) / 7) + 1;
}

/** PARAM: year, month, day_month*/
void data_gr_to_jd(data_st *d)
{
    int32_t A, Y, M, D;
    A = (14 - d->month) / 12;
    Y = d->year + 4800 - A;
    M = d->month + 12 * A - 3;
    D = d->day_month;
    d->jdn = D + ((153 * M + 2) / 5) + 365 * Y + (Y / 4) - (Y / 100) + (Y / 400) - 32045;
}

/** PARAM: jdn*/
void data_jd_to_gr(data_st *d)
{
    int32_t a, b, c, f, e, m;
    a = (int32_t)(d->jdn + 32044);
    b = (4 * a + 3) / 146097;
    c = a - (146097 * b) / 4;
    f = (4 * c + 3) / 1461;
    e = c - (1461 * f) / 4;
    m = (5 * e + 2) / 153;

    d->year = (100 * b + f - 4800 + (m / 10));
    d->month = (m + 3 - 12 * (m / 10));
    d->day_month = (e - (153 * m + 2) / 5 + 1);
}

/** PARAM: year*/
void data_year_leap(data_st *d)
{
    if (d->year % 4 != 0) {
        d->year_leap = 0;
    } else if (d->year % 100 == 0 && d->year % 400 != 0) {
        d->year_leap = 0;
    } else {
        d->year_leap = 1;
    }
}

/** PARAM: year, month*/
void data_day_max_month(data_st *d)
{
    data_year_leap(d);
    uint8_t t[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d->day_max_month = (d->month != 2) ? (t[d->month]) : ((d->year_leap == 0) ? (t[d->month]) : 29);
}

/** PARAM: year_leap*/
void data_day_max_year(data_st *d)
{
    data_year_leap(d);
    d->day_max_year = 365 + d->year_leap;
}

/** PARAM: year, month, day_month*/
void data_day_num_year(data_st *d)
{
    data_gr_to_jd(d);
    data_st t;
    t.year = d->year;
    t.month = 1;
    t.day_month = 1;
    data_gr_to_jd(&t);
    d->day_num_year = data_dif(&t, d) + 1;
}

/** PARAM: year, month, day_month*/
void data_dey_week(data_st *d)
{
    data_gr_to_jd(d);
    d->day_week = (d->jdn % 7) + 1;
}

/** PARAM: NONE */
void data_year_name(data_st *d)
{
    strcpy((char *) d->year_name, year_name[0]);
}

/** PARAM: month */
void data_month_name(data_st *d)
{
    strcpy((char *) d->month_name, month_name[d->month]);
}

/** PARAM: day_week */
void data_week_day_name(data_st *d)
{
    strcpy((char *) d->week_name, week_name[d->day_week]);
}

/** PARAM: year, month, day_month*/
int32_t data_dif(data_st *now, data_st *diff)
{
    return (diff->jdn - now->jdn);
}

/** PARAM: year, month, day_month*/
void data_add(data_st *now, int32_t add, int8_t type_interval)
{
    if (NODE_TYPE_DAY == type_interval) {
        now->jdn += add;
        data_jd_to_gr(now);
        data_init(now, now->year, now->month, 0, now->day_month);
    } else if (NODE_TYPE_WEEK == type_interval) {
        for (int16_t i = 0; i < MODULUS(add); i++) {
            now->week_year += SUGNUM(add);
            if (now->week_year > now->week_max_year) {
                now->week_year = 1;
                now->year++;
            } else if (now->week_year < 1) {
                data_st t_save;
                t_save = *now;
                data_init(&t_save, t_save.year - 1, 0, t_save.week_year, now->day_week);
                now->week_year = t_save.week_max_year;
                now->year--;
            } else if (BELONGS_TO_INTERVAL(1, now->week_year, now->week_max_year)) {
                /*VOID*/
            } else {
                goto error_else;
            }
        }
        data_init(now, now->year, 0, now->week_year, now->day_week);
    } else if (NODE_TYPE_MONTH == type_interval) {
        for (int16_t i = 0; i < MODULUS(add); i++) {
            now->month += SUGNUM(add);
            if (now->month > 12) {
                now->month = 1;
                now->year++;
            } else if (now->month < 1) {
                now->month = 12;
                now->year--;
            } else if (BELONGS_TO_INTERVAL(1, now->month, 12)) {
                /*VOID*/
            } else {
                goto error_else;
            }
        }
        data_init(now, now->year, now->month, 0, now->day_month);
    } else if (NODE_TYPE_YEAR == type_interval) {
        now->year += SUGNUM(add);
        if (now->month != 0) {
            data_init(now, now->year, now->month, 0, now->day_month);
        } else if (now->week_year != 0) {
            /*необходимо чтобы 53 неделя текущего года указывала на 52 неделю другого года*/ /*TODO подумать ещё*/
            uint16_t temp_weak_year = (now->week_year == 53) ? (now->week_year - 1) : (now->week_year);
            data_init(now, now->year, 0, temp_weak_year, now->day_week);
        } else if ((now->month == 0) || now->week_year == 0) {
            data_init(now, now->year, 0, 0, 0);
        } else {
            goto error_else;
        }
    } else {
    error_else:
        printf("ERROR: data_add(ST, % 2d, %d), ST[Y:%d, M:%d/D:%d, W:%d/D:%d]\n", add, type_interval, now->year, now->month, now->day_month, now->week_year, now->day_week);
        exit(1);
    }
}

/** PARAM: ALL*/
void data_print(data_st *now, const char *str)
{
    printf("%s", str);
    printf("jdn : %d\n", now->jdn);
    printf("data: Y:%d  M:%d    D:%d\n", now->year, now->month, now->day_month);
    printf("day : N:%d  mM:%d  mY:%d n:%d \n", now->day_num_year, now->day_max_month, now->day_max_year, now->day_week);
    printf("week: N:%d  mY:%d\n", now->week_year, now->week_max_year);
}
