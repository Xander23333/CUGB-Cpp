#include<iostream>
using namespace std;

class TestClass{
public:
  TestClass(int a){
      aa=a;
      cout<<aa<<" Constructed!\n";
  }
  ~TestClass(){
    cout<<aa<<" Destructed!\n";
  }
private:
  int aa;
};
TestClass AA(3);
int main(){
  cout<<"Main"<<endl;
  TestClass CC(6);

  TestClass *p;
  p=new TestClass(8);
  delete p;

  TestClass DD(7);//局部变量，按栈的顺序销毁
  static TestClass BB(5);//成为全局变量，程序结束时销毁
  
  // cout<<"Mainover"<<endl;
  //销毁顺序是 7,6,5,3

}