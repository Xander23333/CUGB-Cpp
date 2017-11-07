#include<iostream>
using std::cout;
class Test{
public:
  Test(){
    cout<<"default!\n";}
  Test(const Test& t){
    cout<<"copy!\n";}
  Test(Test&& t){cout<<"move!\n";}
  ~Test(){cout<<"Destruct!\n";}
  
};
Test foo1(){
  return 
  Test();
}
Test foo2(Test 6g m,
 . //Test t;
  cout<<"TEST progress!\n";
  return t;
}
int main(){

  //Test t1;
  //Test t2=t1;
  //t2=t1;
  Test t3=foo1();//t3;
  cout<<"over1\n\n";

  Test t4=foo2(Test());
  cout<<"over2\n\n";

  Test t5=foo2(t3);
  cout<<"over3\n\n";
  cout<<"over all\n\n";
}