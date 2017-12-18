#include<iostream>
#include<algorithm>
#include<functional>
#include<fstream>
#include<string>
using std::function;
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
    cout<<" 5) 修改指定商品\n";
    cout<<" 6) 结算\n";
    cout<<"请输入功能选项:";
    char choice;
    cin>>choice;
    return choice;
}

void editData(CommodityInfo *pCommodities, int num){
    //增加 1 个功能模块，修改商品信息。首先输入商品 id，查找商品是否存在。
    //若商品存在，提示用户选择要修改的商品信息项，可以修改商品的数量、价格和折扣。
    int id;
    cout<<" 输入商品编号(id): ";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos == -1){
        cout<<"编号为"<<id<<"的商品不存在!\n\n";
        return;
    }
    showCommodityInfo(pCommodity);

    fflush(stdin); //确保之前残留的回车被清理，商品名称取整行

    cout<<" 请输入修改信息：\n";
    cout<<" 输入商品价格: ";
    cin>>pCommodity->price;
    cout<<" 输入商品数量: ";
    cin>>pCommodity->num;
    cout<<" 输入商品折扣: ";
    cin>>pCommodity->discount;
    cout<<endl;
}

void displayCommodities(CommodityInfo *pCommodities, int num){
    //按商品 Id、按商品名称、按价格、按折扣、按总价格等
    cout<<" 1) Id\n";
    cout<<" 2) 名称\n";
    cout<<" 3) 价格\n";
    cout<<" 4) 数量\n";
    cout<<" 5) 折扣\n";
    cout<<" 6) 总价格\n";
    cout<<"请输入排序方式:";
    char choice;
    cin>>choice;


    function<bool(CommodityInfo,CommodityInfo)> sort_key;
    switch(choice){
    case '1':
        sort_key =
           [](CommodityInfo a,CommodityInfo b){return a.id<b.id;};
        break;
    case '2':
        sort_key =
           [](CommodityInfo a,CommodityInfo b){return a.name<b.name;};
        break;
    case '3':
        sort_key =
           [](CommodityInfo a,CommodityInfo b){return a.price<b.price;};
        break;
    case '4':
        sort_key =
           [](CommodityInfo a,CommodityInfo b){return a.num<b.num;};
        break;
    case '5':
        sort_key =
           [](CommodityInfo a,CommodityInfo b){return a.discount<b.discount;};
        break;
    case '6':
        sort_key =
           [](CommodityInfo a,CommodityInfo b){return getCommodityPrice(a)<getCommodityPrice(b);};
        break;
    default:
        break;
    }

    sort(pCommodities,pCommodities+num,sort_key);

    cout<<"商品种类: "<<num<<endl;
    for(int i=0;i<num;i++) {
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo *&pCommodities, int &num){
    int id;
    cout<<" 输入商品编号(id): ";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos != -1){//找到商品，累加数量
        cout<<"编号为"<<id<<"的商品已经存在!\n";
        cout<<"请输入增加的商品数量: ";
        int number;
        cin>>number;
        pCommodity->num+=number;
        return;
    }
    if(num==maxCommodityNum){
        reAllocMemory(pCommodities,num);
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
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos != -1){
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
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos == -1){
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
        double price=getCommodityPrice(*(pCommodities+i));
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
    cout<<endl;
}
void readData(std::string filename){
    ifstream in(filename);
    if(in){
        in>>maxCommodityNum;
        pCommodities=new CommodityInfo[maxCommodityNum];
        in>>commodityNum;
        if(commodityNum> maxCommodityNum)
            commodityNum= maxCommodityNum;
        string buf;
        for(int i=0;i<commodityNum;++i){
            in>> pCommodities [i].id;
            getline(in,buf);
            getline(in, pCommodities [i].name);
            in>> pCommodities [i].price>> pCommodities [i].num
              >> pCommodities [i].discount;
        }
    }
    else
        pCommodities=new CommodityInfo[maxCommodityNum];

}
void writeData(std::string filename){
    ofstream out(filename);
    if(out){
        out<<maxCommodityNum<<endl;
        out<<commodityNum<<endl;
        for(int i=0;i<commodityNum;++i){
            out<< pCommodities [i].id<<endl;
            out<< pCommodities [i].name<<endl;
            out<< pCommodities [i].price<<" "<< pCommodities [i].num
               <<" "<< pCommodities [i].discount<<endl;
        }
    }
}
