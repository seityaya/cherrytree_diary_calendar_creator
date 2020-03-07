#include "ct_dcc_main.h"
#include "ct_dcc_data.h"
#include "ct_dcc_node.h"

uint64_t ct_dcc_start(char *text, ct_dcc_config *conf)
{
    ct_dcc_data d;
    data_init(&d, 0, 0, 0, 0);

    TEXTCAT(text, "<?xml version=\"1.0\"?>\n");
    TEXTCAT(text, "<cherrytree>\n");
    ct_dcc_node_root(d, text, conf);
    TEXTCAT(text, "</cherrytree>\n");
    return strlen(text);
}
