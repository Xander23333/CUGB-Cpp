#include<iostream>
using namespace std;

class EE{
public:
  EE(){cout<<"Default Construct!\n";}
  EE(const EE& x){
    cout<<"Copy Construct!\n";
  }
  ~EE(){cout<<"Destruct!\n";}
private:
33};

void fun(EE x){}
void fun2(EE& x){}
int main(){
  EE x;
  cout<<"fun!\n";
  fun(x);
  cout<<"fun over!\n";
  cout<<"fun2\n";
  fun2(x);
  cout<<"fun2 over\n";

  EE* px;
  px = new EE;
  delete px;

  return 0;
}