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
    cout<<"��ӭʹ�ù���������ϵͳ!\n";
    cout<<" 0) �˳�ϵͳ\n";
    cout<<" 1) �����������Ʒ\n";
    cout<<" 2) �ӹ������Ƴ���Ʒ\n";
    cout<<" 3) �鿴ָ����Ʒ\n";
    cout<<" 4) �鿴������Ʒ\n";
    cout<<" 5) �޸�ָ����Ʒ\n";
    cout<<" 6) ����\n";
    cout<<"�����빦��ѡ��:";
    char choice;
    cin>>choice;
    return choice;
}

void editData(CommodityInfo *pCommodities, int num){
    //���� 1 ������ģ�飬�޸���Ʒ��Ϣ������������Ʒ id��������Ʒ�Ƿ���ڡ�
    //����Ʒ���ڣ���ʾ�û�ѡ��Ҫ�޸ĵ���Ʒ��Ϣ������޸���Ʒ���������۸���ۿۡ�
    int id;
    cout<<" ������Ʒ���(id): ";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos == -1){
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n\n";
        return;
    }
    showCommodityInfo(pCommodity);

    fflush(stdin); //ȷ��֮ǰ�����Ļس���������Ʒ����ȡ����

    cout<<" �������޸���Ϣ��\n";
    cout<<" ������Ʒ�۸�: ";
    cin>>pCommodity->price;
    cout<<" ������Ʒ����: ";
    cin>>pCommodity->num;
    cout<<" ������Ʒ�ۿ�: ";
    cin>>pCommodity->discount;
    cout<<endl;
}

void displayCommodities(CommodityInfo *pCommodities, int num){
    //����Ʒ Id������Ʒ���ơ����۸񡢰��ۿۡ����ܼ۸��
    cout<<" 1) Id\n";
    cout<<" 2) ����\n";
    cout<<" 3) �۸�\n";
    cout<<" 4) ����\n";
    cout<<" 5) �ۿ�\n";
    cout<<" 6) �ܼ۸�\n";
    cout<<"����������ʽ:";
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

    cout<<"��Ʒ����: "<<num<<endl;
    for(int i=0;i<num;i++) {
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo *&pCommodities, int &num){
    int id;
    cout<<" ������Ʒ���(id): ";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos != -1){//�ҵ���Ʒ���ۼ�����
        cout<<"���Ϊ"<<id<<"����Ʒ�Ѿ�����!\n";
        cout<<"���������ӵ���Ʒ����: ";
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
    cout<<"��Ʒ��ӳɹ�!\n\n";
}
void removeCommodity(CommodityInfo *pCommodities, int &num){
    int id;
    cout<<" ������Ʒ���(id): ";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos != -1){
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n\n";
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
    cout<<"��Ʒ�Ƴ��ɹ�!\n\n";
}
void viewCommodity(CommodityInfo *pCommodities, int num){
    int id;
    cout<<" ������Ʒ�ı��(id): ";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    CommodityInfo *pCommodity=
            pCommodities+pos;
    if(pos == -1){
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n\n";
        return;
    }
    showCommodityInfo(pCommodity);
    cout<<endl;
}
void checkOut(CommodityInfo *pCommodities, int num){
    double totalPrice=0;
    int totalNum=0;
    cout<<"��Ʒ����: "<<num<<endl;
    cout<<" ��Ʒ����\t\t"<<"�۸�\t"<<"����\t"<<"�ۿ�\t"<<"�ܼ�\n";
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
    cout<<"��������Ʒ�ܼ���: "<<totalNum<<"\n";
    cout<<"�����������ܼ�: "<<totalPrice<<endl;
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
