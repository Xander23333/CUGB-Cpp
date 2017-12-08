#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back

int product(int num1,int num2){
  return num1*num2;
}
double geoMean(const list<int>& nums){
  double mult=accumulate(all(nums),1,product);
  return pow(mult,1.0/nums.size());
}

int main(){
  list<int> data;
  data.pb(1);data.pb(2);data.pb(4);
  cout<<geoMean(data)<<endl;
}