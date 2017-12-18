#ifndef HELP_HEADER
#define HELP_HEADER
#include "datatype.h"
void reAllocMemory(CommodityInfo *&pCommodities,int num);
int findCommodityById(CommodityInfo *pCommodities,
 int num, long id);
void showCommodityInfo(CommodityInfo *pCommodity);
void setCommodityInfo(CommodityInfo *pCommodity);
double getCommodityPrice(const CommodityInfo& commodity);
#endif
