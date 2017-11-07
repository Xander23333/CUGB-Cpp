#include<iostream>
using namespace std;

class Test{
private:
  int x;
public:
  Test(int xx=0):x(xx){}
  Test& operator++(){++x;return *this;}
  Test operator++(int) {Test temp(*this);++x;return temp;}
  int getValue() const 
  {return x;}
};
int main(){
  Test t;
  cout<<t.getValue()<<endl;
  cout<<(t++).getValue()<<endl;
  cout<<(++t).getValue()<<endl;
  return 0;
}
