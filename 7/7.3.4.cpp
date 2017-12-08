#include<bits/stdc++.h>
using namespace std;



int main(){
  map<string,int> count;//save as pair
  string word;
  int n;cin>>n;
  while(n--) {
    cin>>word;
    ++count[word];
  }
  for(auto e:count){//what inside map ??????
    cout<<e.first<<"\t"<<e.second<<"\n";//it's sorted as pair
  }
}