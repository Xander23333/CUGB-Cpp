#include<iostream>
using namespace std;

class EE{
public:
  EE(int i):i(i){cout<<"Construct!\n";}
  ~EE(){cout<<"Destruct!\n";}
private:
  int i=0;
};

void fun(EE x){}//copy construct.destruct
void fun2(EE& x){}//no construct
int main(){
  EE x(100);//
  cout<<"fun!\n";
  fun(x);
  cout<<"fun over!\n";
  return 0;
}