#include<iostream>
using std::cout;using std::endl;

class Test{
private:
  int b;
public:
  Test()=default;
 // Test(const Test&)=default;
//  Test(int x)=default;
};
//Test::Test(const Test& t)=default;
int twice(const & rx){
  return 2*rx;
}
int main(){
  int m=6;
  int n=twice(m);cout<<n<<endl;
  int k=twice(21);cout<<k<<endl;
  Test t1,t2(t1);
}