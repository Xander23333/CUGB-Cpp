#ifndef HELP_HEADER
#define HELP_HEADER
#include "datatype.h"
CommodityInfo *findCommodityById(CommodityInfo *pCommodities,
 int num, long id);
void showCommodityInfo(CommodityInfo *pCommodity);
void setCommodityInfo(CommodityInfo *pCommodity);
double getCommodityPrice(CommodityInfo *pCommodity);
#endif
