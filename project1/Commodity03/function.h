#ifndef FUNCTION_H
#define FUNCTION_H
#include"datatype.h"
char menu();
void displayCommodities(CommodityInfo *pCommodities, int num);
void addCommodity(CommodityInfo *&pCommodities, int &num);
void removeCommodity(CommodityInfo *pCommodities, int &num);
void viewCommodity(CommodityInfo *pCommodities, int num);
void checkOut(CommodityInfo *pCommodities, int num);
void editData(CommodityInfo *pCommodities, int num);
//增加 1 个功能模块，修改商品信息。首先输入商品 id，查找商品是否存在。
//若商品存在，提示用户选择要修改的商品信息项，可以修改商品的数量、价格和折扣。
void readData(std::string filename);
void writeData(std::string filename);

#endif // FUNCTION_H
