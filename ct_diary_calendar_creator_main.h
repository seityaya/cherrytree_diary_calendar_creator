#ifndef CHERRYTREE_DIARY_CALENDAR_CREATOR_MAIN_H_
#define CHERRYTREE_DIARY_CALENDAR_CREATOR_MAIN_H_

#include "ct_diary_calendar_creator_data.h"
#include "ct_diary_calendar_creator_node.h"
#include "ct_diary_calendar_creator_table.h"
#include <stdio.h>

/*HARDCORE DEFINE*/
/************************************************/
#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define UNUSED(x) ((void) (x))

/*DEBAG*/
#define CREATE_TEXT TRUE
#define FILE_WRITE TRUE
#define FILE_OPEN TRUE

#define DIARY_NODE_MAIN
#define DIARY_NODE_YEAR
#define DIARY_NODE_MONTH
#define DIARY_NODE_WEEK
#define DIARY_NODE_DAY

#define DIARY_TABLE_MAIN
#define DIARY_TABLE_YEAR
#define DIARY_TABLE_MONTH
#define DIARY_TABLE_WEEK
#define DIARY_TABLE_DAY

/*TYPE NODE*/
#define NODE_TYPE_MAIN 0
#define NODE_TYPE_YEAR 1
#define NODE_TYPE_MONTH 2
#define NODE_TYPE_WEEK 3
#define NODE_TYPE_DAY 4

/*HARDCORE DEFINE*/
#define TABLE_SIZE 41
#define SIZE_TEXT 1000000
#define FILE_EXTENSION ".ctd"
#define LANG_RU 0
#define LANG_EN 1
/************************************************/

/*CONFIG DEFINE*/
/************************************************/
#define BEG_YEAR 2015
#define END_YEAR 2025
#define BEG_MONTH 1
#define END_MONTH 12
#define LANG_DIARY LANG_RU
#define FILE_NAME "cherrytree_diary_calendar"
#define NAME_DIARY "WELCOME TO YOUR DIARY"
#define MAIN_PAGE_NAME "DIARY" /*5 symbol max*/
/************************************************/

#endif /*CHERRYTREE_DIARY_CALENDAR_CREATOR_MAIN_H_*/
