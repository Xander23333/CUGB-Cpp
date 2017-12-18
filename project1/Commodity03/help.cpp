#include <iostream>
using std::cout;using std::cin;using std::endl;
#include "header.h"
void reAllocMemory(CommodityInfo *&pCommodities,int num){
    maxCommodityNum*=2;
    CommodityInfo *temp=pCommodities;
    pCommodities=new CommodityInfo[maxCommodityNum];
    for(int i=0;i<num;++i)
        pCommodities[i]=temp[i];
    delete[] temp;
}
void setCommodityInfo (CommodityInfo *pCommodity){ //读取商品信息
    fflush(stdin); //确保之前残留的回车被清理，商品名称取整行
    cout<<" 输入商品名称: ";
    getline(cin,pCommodity->name);
    cout<<" 输入商品价格: ";
    cin>>pCommodity->price;
    cout<<" 输入商品数量: ";
    cin>>pCommodity->num;
    cout<<" 输入商品折扣: ";
    cin>>pCommodity->discount;
}
int findCommodityById(CommodityInfo *pCommodities,
                                 int num, long id){
    for(int i=0;i<num;++i){
        if ((pCommodities+i)->id == id) return i;
    }
    return -1;
}
double getCommodityPrice(const CommodityInfo &commodity){
    return commodity.price*commodity.num*commodity.discount;
}
void showCommodityInfo(CommodityInfo *pCommodity){
    cout<<"商品编号(id):"<<pCommodity->id<<endl;
    cout<<" 商品名称:"<<pCommodity->name<<endl;
    cout<<" 商品总价:"<<getCommodityPrice(*pCommodity)
       <<" (价格:"<<pCommodity->price<<", 数量:"
      <<pCommodity->num<<", 折扣:"<<pCommodity->discount<<" )\n";
}
