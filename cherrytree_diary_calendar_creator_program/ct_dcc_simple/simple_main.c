#include "simple_main.h"
#include "ct_dcc_main.h"
#include "simple_path.h"
#include "simple_sublings.h"
#include "simple_table.h"

void ct_dcc_simple_root(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_path_root(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_sublings_root(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_table_root(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n➤</rich_text>");
}

void ct_dcc_simple_year(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_path_year(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_sublings_year(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_table_year(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n➤</rich_text>");
}

void ct_dcc_simple_month(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_path_month(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_sublings_month(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_table_month(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n➤</rich_text>");
}

void ct_dcc_simple_week(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_path_week(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_sublings_week(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_table_week(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n➤</rich_text>");
}

void ct_dcc_simple_day(ct_dcc_data d, char *text)
{
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_path_day(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_sublings_day(d, text);
    TEXTCAT(text, "<rich_text>──────────────────────────────────────────\n</rich_text>");
    ct_dcc_simple_table_day(d, text);
    TEXTCAT(text, "<rich_text>➤</rich_text>");
}
