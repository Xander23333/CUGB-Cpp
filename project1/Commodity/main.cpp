#include<iostream>
#include"header.h"
using std::cin;using std::cout;

int main(){
    cout<<"��ӭʹ�ù���������ϵͳ!\n";
    readData("commodity.dat");
    char choice;
    while(true){
        choice=menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            addCommodity (commodities,commodityNum);
            break;
        case '2':
            removeCommodity(commodities,commodityNum);
            break;
        case '3':
            viewCommodity(commodities,commodityNum);
            break;
        case '4':
            displayCommodities(commodities,commodityNum);
            break;
        case '5':
            checkOut(commodities,commodityNum);
            break;
        default:
            cout<<"��Ч����! ������!\n";
            break;
        }
    }
    writeData("commodity.dat");
    cout<<"�ټ�!\n";
    return 0;
}
