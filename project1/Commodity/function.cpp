#include<iostream>
#include<fstream>
#include<string>
using std::cout;using std::cin;using std::endl;using std::string;
using std::ifstream;using std::ofstream;
#include"header.h"
char menu(){
    cout<<"欢迎使用购物篮管理系统!\n";
    cout<<" 0) 退出系统\n";
    cout<<" 1) 向购物篮添加商品\n";
    cout<<" 2) 从购物篮移除商品\n";
    cout<<" 3) 查看指定商品\n";
    cout<<" 4) 查看所有商品\n";
    cout<<" 5) 结算\n";
    cout<<"请输入功能选项:";
    char choice;
    cin>>choice;
    return choice;
}

void displayCommodities(CommodityInfo *pCommodities, int num){
    int i;
    cout<<"商品种类: "<<num<<endl;
    for(i=0;i<num;i++) {
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo *pCommodities, int &num){
    int id;
    cout<<" 输入商品编号(id): ";
    cin>>id;
    CommodityInfo *pCommodity=
            findCommodityById(pCommodities,num,id);
    if(pCommodity!=nullptr){//找到商品，累加数量
        cout<<"编号为"<<id<<"的商品已经存在!\n";
        cout<<"请输入增加的商品数量: ";
        int number;
        cin>>number;
        pCommodity->num+=number;
        return;
    }
    if(num==MAX_COMMODITY_NUM){
        cout<<"没有足够空间了!\n\n";
        return;
    }
    pCommodity = &pCommodities[num];
    pCommodity->id=id;
    setCommodityInfo(pCommodity);
    num++;
    cout<<"商品添加成功!\n\n";
}
void removeCommodity(CommodityInfo *pCommodities, int &num){
    int id;
    cout<<" 输入商品编号(id): ";
    cin>>id;
    CommodityInfo *pCommodity=
            findCommodityById(pCommodities,num,id);
    if(pCommodity==nullptr){
        cout<<"编号为"<<id<<"的商品不存在!\n\n";
        return;
    }
    num--;
    CommodityInfo *pNext=pCommodity+1;
    while(pCommodity < pCommodities + num){
        pCommodity->id=pNext->id;
        pCommodity->name=pNext->name;
        pCommodity->price=pNext->price;
        pCommodity->num=pNext->num;
        pCommodity->discount=pNext->discount;
        pCommodity++;
        pNext++;
    }
    cout<<"商品移除成功!\n\n";
}
void viewCommodity(CommodityInfo *pCommodities, int num){
    int id;
    cout<<" 输入商品的编号(id): ";
    cin>>id;
    CommodityInfo *pCommodity=
            findCommodityById(pCommodities,num,id);
    if(pCommodity==nullptr){
        cout<<"编号为"<<id<<"的商品不存在!\n\n";
        return;
    }
    showCommodityInfo(pCommodity);
    cout<<endl;
}
void checkOut(CommodityInfo *pCommodities, int num){
    double totalPrice=0;
    int totalNum=0;
    cout<<"商品种类: "<<num<<endl;
    cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"折扣\t"<<"总价\n";
    for(int i=0;i<num;++i){
        double price=getCommodityPrice(pCommodities+i);
        cout<<" "<<pCommodities[i].name<<"\t";
        cout<<pCommodities[i].price<<"\t"
           <<pCommodities[i].num<<"\t"
          <<pCommodities[i].discount<<"\t"
         <<price<<endl;
        totalPrice+=price;
        totalNum+=pCommodities[i].num;
    }
    cout<<"购物篮商品总件数: "<<totalNum<<"\n";
    cout<<"购物篮结算总价: "<<totalPrice<<endl;
}
void readData(std::string filename){
    ifstream in(filename);
    if(in){
        in>>commodityNum;
        if(commodityNum>MAX_COMMODITY_NUM)
            commodityNum=MAX_COMMODITY_NUM;
        string buf;
        for(int i=0;i<commodityNum;++i){
            in>>commodities[i].id;
            getline(in,buf);
            getline(in,commodities[i].name);
            in>>commodities[i].price>>commodities[i].num
             >>commodities[i].discount;
        }
    }
}
void writeData(std::string filename){
    ofstream out(filename);
    if(out){
        out<<commodityNum<<endl;
        for(int i=0;i<commodityNum;++i){
            out<<commodities[i].id<<endl;
            out<<commodities[i].name<<endl;
            out<<commodities[i].price<<" "<<commodities[i].num
              <<" "<<commodities[i].discount<<endl;
        }
    }
}
