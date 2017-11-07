#include<iostream>
using namespace std;

class Test{
public:
  Test():x(0){
    cout<<"Construct!\n";
    cout<<"x = "<<x<<"\n";
  }
  void output() const{cout<<"x:"<<x<<endl;}
private:
  int x;
};
int main(){
  Test t;
  t.output();
  t=5;//error! because Test(int) is not declare! Even there is only one int member in the class!
  t.output();

  t=Test(4,6);
  t.output();
  return 0;
}