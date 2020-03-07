#ifndef CT_DCC_TABLE_H_
#define CT_DCC_TABLE_H_

#include "ct_dcc_data.h"
#include "ct_dcc_main.h"
#include <stdint.h>

void ct_dcc_leaf_root(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_leaf_year(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_leaf_month(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_leaf_week(ct_dcc_data d, char *text, ct_dcc_config *conf);
void ct_dcc_leaf_day(ct_dcc_data d, char *text, ct_dcc_config *conf);

#endif /*CT_DCC_TABLE_H_*/
