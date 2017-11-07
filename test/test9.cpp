#include<iostream>
using std::cout;
class Test{
public:
  int a;
  Test(){
    a=0;
    cout<<"default!\n";}
  Test(const Test& t){
    cout<<"copy!\n";}
  //Test(Test&& t){cout<<"move!\n";}
  ~Test(){cout<<"Destruct!\n";}
   Test operator+(int y){
    Test temp(*this);
    temp.a+=y;
    return temp; 
    
   }
};
Test foo(){
  Test r;
  return r+4;
}
int main(){

  //Test t1;
  //Test t2=t1;
  //t2=t1;
  Test t3=foo();
  Test t2;
}