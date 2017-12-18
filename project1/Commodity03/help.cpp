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
void setCommodityInfo (CommodityInfo *pCommodity){ //��ȡ��Ʒ��Ϣ
    fflush(stdin); //ȷ��֮ǰ�����Ļس���������Ʒ����ȡ����
    cout<<" ������Ʒ����: ";
    getline(cin,pCommodity->name);
    cout<<" ������Ʒ�۸�: ";
    cin>>pCommodity->price;
    cout<<" ������Ʒ����: ";
    cin>>pCommodity->num;
    cout<<" ������Ʒ�ۿ�: ";
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
    cout<<"��Ʒ���(id):"<<pCommodity->id<<endl;
    cout<<" ��Ʒ����:"<<pCommodity->name<<endl;
    cout<<" ��Ʒ�ܼ�:"<<getCommodityPrice(*pCommodity)
       <<" (�۸�:"<<pCommodity->price<<", ����:"
      <<pCommodity->num<<", �ۿ�:"<<pCommodity->discount<<" )\n";
}
