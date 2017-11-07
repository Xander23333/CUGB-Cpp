#include<iostream>
class Test{
private:
  int a;
public:
  Test(const Test& t) = default;//???
  Test():a(0){};
  void output(){
    printf("a=%d\n",a);
  }
};
int main(){
  Test t1;
  t1.output();
  Test t2(t1);
  t2.output();
  return 0;
}