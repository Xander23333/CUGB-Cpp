#include<iostream>
using namespace std;
int main(){
//  int a[100]{};
  int* a = new int[100]{};//two sentence equal
  for(int i=0;i<100;++i){//????
    *a++ = i;
  }
  for(int i=0;i<100;++i){
    cout<<*(a+i)<<" ";
  }cout<<endl;
}