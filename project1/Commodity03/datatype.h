#ifndef DATATYPE_H
#define DATATYPE_H
#include<string>//ʹ�ñ�׼���е� string �����ַ���
struct CommodityInfo{
 long id; //��Ʒ���
 std::string name; //��Ʒ���ƣ�ͷ�ļ��б���ʹ�� using namespace ����
 double price; //����
 int num; //����
 double discount; //�ۿ�
};
//const int MAX_COMMODITY_NUM=100; //����������Ʒ��������
#endif // DATATYPE_H
