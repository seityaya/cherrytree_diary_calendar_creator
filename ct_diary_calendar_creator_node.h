#ifndef CHERRYTREE_DIARY_CALENDAR_CREATOR_NODE_H_
#define CHERRYTREE_DIARY_CALENDAR_CREATOR_NODE_H_

#include "ct_diary_calendar_creator_main.h"
#include "ct_diary_calendar_creator_table.h"
#include "ct_diary_calendar_creator_data.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void diary_node_beg(char *text, data_st d, uint8_t node_type);
void diary_node_end(char *text);

void diary_node_root(data_st d, char *text);
void diary_node_year(data_st d, char *text);
void diary_node_month(data_st d, char *text);
void diary_node_week(data_st d, char *text);
void diary_node_day(data_st d, char *text);

#endif /*CHERRYTREE_DIARY_CALENDAR_CREATOR_NODE_H_*/
