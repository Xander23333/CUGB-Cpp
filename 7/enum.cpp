#include<iostream>
using namespace std;

int main(){
  enum week{Monday,Tuesday,Wednesday};

  week a=Monday;
  a=(week)1;
  cout<<&a<<endl;
  cout<<(int)a<<endl;
  cout<<a<<endl;
}