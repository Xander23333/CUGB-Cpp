#include<iostream>
#include<vector>
using namespace std;
class Ele{
private:
  int a;
public:
  Ele(int e=0):a(e){cout<<"default!\n";}
  Ele(const Ele& e):a(e.a){cout<<"copy!\n";}
  Ele(Ele&& e):a(e.a){cout<<"move!\n";}
  ~Ele(){cout<<"destruct!\n";}
};
int main(){
  vector<Ele> vec;
  cout<<vec.size()<<endl;//size=0
  vec.reserve(10);
  cout<<vec.size()<<endl;//after reserve, size = 0 still
  vec.push_back(Ele(3));//tem stru. , move , tem dest.
  Ele e(5);
  vec.push_back(move(e));
  return 0;
}