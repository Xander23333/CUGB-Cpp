#include<iostream>
using namespace std;
const float P=1; 
int main(){
  std::cout<<R"(\r\n\r\n\\\r\\n)"<<std::endl;
  float f=1.0;
  cout<<f+P/2<<endl;

  const int Pi=3;
  const_cast<int&>(Pi);
  Pi=2;
  cout<<Pi<<endl;
//去除常量？？？

  return 0;
  
}