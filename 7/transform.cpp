#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define all(x) x.begin(),x.end()

int main(){
  vector<int> vec1(10,10),vec2(10,11);
  for_each(all(vec1),[](int x){cout<<x<<" ";});cout<<endl;
  cout<<0<<endl;
  transform(all(vec1),vec1.begin(),[](int x){return x*x;});
  cout<<1<<endl;
  for_each(all(vec1),[](int x){cout<<x<<" ";});cout<<endl;
  cout<<2<<endl;
  transform(all(vec1),vec2.begin(),vec1.begin(),[](int x,int y){return x*y;});
  cout<<3<<endl;
  for_each(all(vec1),[](int x){cout<<x<<" ";});cout<<endl;
  cout<<4<<endl;
}