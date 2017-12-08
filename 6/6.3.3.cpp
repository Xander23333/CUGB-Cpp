#include<iostream>
#include<string>
using namespace std;

template<typename T1, typename T2>
auto sum(const T1& a,const T2& b)->decltype(a+b){
  return a+b;
}
int main(){
  char str[]{"helloworld"};
  cout<<"first:"<<sum(string("hello"),"world")<<endl;
  cout<<"second:"<<sum(10,'a')<<endl;
  cout<<"third:"<<sum(string("hello"),'w')<<endl;
  cout<<str<<endl;
  cout<<"fourth:"<<sum(str,3)<<endl;
  return 0;
}