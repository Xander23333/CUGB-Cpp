#include<iostream>
#include"header.h"
using std::cin;using std::cout;

int main(){
    cout<<"��ӭʹ�ù���������ϵͳ!\n";
    readData("commodity2.dat");
    char choice;
    while(true){
        choice=menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            addCommodity (pCommodities,commodityNum);
            break;
        case '2':
            removeCommodity(pCommodities,commodityNum);
            break;
        case '3':
            viewCommodity(pCommodities,commodityNum);
            break;
        case '4':
            displayCommodities(pCommodities,commodityNum);
            break;
        case '5':
            checkOut(pCommodities,commodityNum);
            break;
        default:
            cout<<"��Ч����! ������!\n";
            break;
        }
    }
    writeData("commodity2.dat");
    delete[] pCommodities;
    cout<<"�ټ�!\n";
    return 0;
}
