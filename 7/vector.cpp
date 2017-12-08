#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back

template<typename T>
void out(T x){
  cout<<x<<" ";
}

int fun(int x,int y){
  return x*y;
}
bool mod2(int x){
  return x%2==0;
}

class Test{
public:
  bool operator()(int x) {
    return x%2==0;
  }
};

int main(){
  srand((unsigned)time(NULL));

  vector<int> vec;
  cout<<vec.capacity()<<endl;
  cout<<vec.max_size()<<endl;
  //1e9 is the max_size
  vec.reserve(100);
  cout<<vec.size()<<endl;
  //reserve doesn't make the size
  vec.resize(100);
  cout<<vec.size()<<endl;
  //resize will make the size

  vec.clear();
  cout<<vec.capacity()<<endl;
  cout<<vec.size()<<endl;

  vec.pb(1);
    vec.pb(3);
      vec.pb(2);
  for_each(all(vec),out<int>);
  cout<<endl;
  vector<int> vec2(vec);
  reverse(all(vec));
  for_each(all(vec),out<int>);
  cout<<endl;

  vec.clear();
  vec.resize(3);
  swap_ranges(all(vec2),vec.begin());//will be 
  
  for_each(all(vec),out<int>);
  cout<<endl;
  cout<<accumulate(all(vec),1,fun)<<endl;

  Test t;
  cout<<t.operator()(2)<<endl;

  generate(all(vec),rand);
  cout<<endl;
  for_each(all(vec),out<int>);
  cout<<endl;
  cout<<"numbers can divide 2 are "<<count_if(all(vec),mod2)<<endl;
}