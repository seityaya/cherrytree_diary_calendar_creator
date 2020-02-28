#ifndef CHERRYTREE_DIARY_CALENDAR_CREATOR_TABLE_H_
#define CHERRYTREE_DIARY_CALENDAR_CREATOR_TABLE_H_

#include "ct_diary_calendar_creator_data.h"
#include "ct_diary_calendar_creator_main.h"
#include "ct_diary_calendar_creator_node.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void diary_table_main(data_st d, char *text);
void diary_table_year(data_st d, char *text);
void diary_table_month(data_st d, char *text);
void diary_table_week(data_st d, char *text);
void diary_table_day(data_st d, char *text);

#endif /*CHERRYTREE_DIARY_CALENDAR_CREATOR_TABLE_H_*/
