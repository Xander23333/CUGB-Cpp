#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

using namespace std::placeholders;

int main(){
  auto divd=[](auto x,auto y){return x/y;};
  auto dint=bind<int>(divd,_1,_2);
  auto rddou=bind(divd,_2,_1);
  cout<<dint(20,6)<<endl;
  cout<<rddou((double)20,(double)6)<<endl;
}