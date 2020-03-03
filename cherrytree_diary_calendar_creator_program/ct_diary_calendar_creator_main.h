#ifndef CHERRYTREE_DIARY_CALENDAR_CREATOR_MAIN_H_
#define CHERRYTREE_DIARY_CALENDAR_CREATOR_MAIN_H_

#include "ct_diary_calendar_creator_data.h"
#include "ct_diary_calendar_creator_node.h"
#include "ct_diary_calendar_creator_table.h"
#include <stdlib.h>

/*HARDCORE DEFINE*/
/************************************************/
#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define UNUSED(x) ((void) (x))

/*DEBAG*/
#define CREATE_TEXT TRUE
#define FILE_WRITE TRUE
#define FILE_OPEN TRUE

#define DIARY_NODE_ROOT
#define DIARY_NODE_YEAR
#define DIARY_NODE_MONTH
#define DIARY_NODE_WEEK
#define DIARY_NODE_DAY

#define DIARY_TABLE_ROOT_D
#define DIARY_TABLE_YEAR_D
#define DIARY_TABLE_MONTH_D
#define DIARY_TABLE_WEEK_D
#define DIARY_TABLE_DAY_D

/*TYPE NODE*/
#define NODE_TYPE_ROOT 0
#define NODE_TYPE_YEAR 1
#define NODE_TYPE_MONTH 2
#define NODE_TYPE_WEEK 3
#define NODE_TYPE_DAY 4

/*HARDCORE DEFINE*/
#define TABLE_SIZE 41
#define SIZE_TEXT 20000000
#define FILE_EXTENSION ".ctd"
#define LANG_RU 0
#define LANG_EN 1
/************************************************/

/*CONFIG DEFINE*/
/************************************************/
#define BEG_YEAR 2011
#define END_YEAR 2030
#define BEG_MONTH 1
#define END_MONTH 12
#define LANG_DIARY LANG_EN
#define FILE_NAME "cherrytree_diary_calendar"
#define NAME_DIARY "WELCOME TO YOUR DIARY"
#define MAIN_PAGE_NAME "DIARY" /*5 symbol max*/
#define NODE_PREFIX "DIARY"
/************************************************/

#endif /*CHERRYTREE_DIARY_CALENDAR_CREATOR_MAIN_H_*/
