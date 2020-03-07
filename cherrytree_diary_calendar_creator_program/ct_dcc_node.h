#ifndef CT_DCC_NODE_H_
#define CT_DCC_NODE_H_

#include "ct_dcc_data.h"
#include "ct_dcc_main.h"

#include <stdint.h>

void ct_dcc_node_beg(char *text, ct_dcc_data d, uint8_t type_node);
void ct_dcc_node_end(char *text);

void ct_dcc_node_root(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_node_year(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_node_month(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_node_week(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_node_day(ct_dcc_data d, char *text, ct_dcc_config *conf);

#endif /*CT_DCC_NODE_H_*/
