#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ct_dcc_data.h"
#include "ct_dcc_debug_string.h"
#include "ct_dcc_leaf.h"
#include "ct_dcc_main.h"
#include "ct_dcc_node.h"
#include "ct_dcc_simple/simple_main.h"

void diary_debug_string(ct_dcc_data d, char *text, uint8_t node_type)
{
    UNUSED(d);
    UNUSED(text);
    UNUSED(node_type);
#if CREATE_DEBAG_STRING == TRUE
    char node_type_string[30] = "";
    if (NODE_TYPE_ROOT == node_type) {
        strcat(node_type_string, "ROOT     ");
    } else if (NODE_TYPE_YEAR == node_type) {
        strcat(node_type_string, "YEAR     ");
    } else if (NODE_TYPE_MONTH == node_type) {
        strcat(node_type_string, "MONTH    ");
    } else if (NODE_TYPE_WEEK == node_type) {
        strcat(node_type_string, "WEEK     ");
    } else if (NODE_TYPE_DAY == node_type) {
        strcat(node_type_string, "DAY      ");
    } else {
        exit(0);
    }

    TEXTCAT(text, "<rich_text>%s Y%04d  M%02d/D%02d  W%02d/D%02d\n</rich_text>", node_type_string, d.year, d.month, d.day_month, d.week_year, d.day_week);
#endif
}
