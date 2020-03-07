#ifndef CT_DCC_MAIN_H_
#define CT_DCC_MAIN_H_

#include "stdint.h"
#include "stdio.h"
#include "string.h"

/*CONFIG DEFINE*/
/************************************************/
#define BEG_YEAR 2020
#define END_YEAR 2026
#define BEG_MONTH 1
#define END_MONTH 12
#define LANG_DIARY LANG_EN
#define FILE_NAME "cherrytree_diary_calendar"
#define NAME_DIARY "WELCOME TO YOUR DIARY"
#define MAIN_PAGE_NAME "DIARY" /*5 symbol max*/
#define NODE_PREFIX ""
/************************************************/

/*CONFIG STRUCTURE*/
/************************************************/

typedef struct
{
    struct
    {
        uint8_t root;
        uint8_t year;
        uint8_t season;
        uint8_t month;
        uint8_t week;
        uint8_t day;
    } node_gen;
    uint8_t temp;
} ct_dcc_config;

/*HARDCORE DEFINE*/
/************************************************/
#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define UNUSED(x) ((void) (x))
#define TEXTCAT(buff, format, ...) snprintf(buff + strlen(buff), SIZE_TEXT_BUFF - strlen(buff), format, ##__VA_ARGS__)

/*DEBAG*/
#define CREATE_TEXT TRUE
#define FILE_WRITE TRUE
#define FILE_OPEN TRUE

#define CREATE_DEBAG_STRING FALSE

#define CREATE_NODE_ROOT TRUE
#define CREATE_NODE_YEAR TRUE
#define CREATE_NODE_MONTH TRUE
#define CREATE_NODE_WEEK TRUE
#define CREATE_NODE_DAY TRUE

#define CREATE_TABLE_ROOT_LIGHT TRUE
#define CREATE_TABLE_YEAR_LIGHT TRUE
#define CREATE_TABLE_MONTH_LIGHT TRUE
#define CREATE_TABLE_WEEK_LIGHT TRUE
#define CREATE_TABLE_DAY_LIGHT TRUE

/*HARDCORE DEFINE*/
#define TABLE_SIZE 41
#define SIZE_TEXT_BUFF 20000000
#define FILE_EXTENSION ".ctd"
#define LANG_RU 0
#define LANG_EN 1
/************************************************/

uint64_t ct_dcc_start(char *text, ct_dcc_config *conf);

#endif /*CT_DCC_MAIN_H_*/
