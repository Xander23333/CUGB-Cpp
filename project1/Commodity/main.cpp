#include<iostream>
#include"header.h"
using std::cin;using std::cout;

int main(){
    cout<<"欢迎使用购物篮管理系统!\n";
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
            cout<<"无效输入! 请重试!\n";
            break;
        }
    }
    writeData("commodity.dat");
    cout<<"再见!\n";
    return 0;
}
