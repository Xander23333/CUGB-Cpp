#include<bits/stdc++.h>
using namespace std;

int getMax(int (&array)[7],int size){
  int Max=INT_MIN;
  for(int i:array){
    Max=max(i,Max);
  }
  return Max;
}

int main(){
  int a(5);
  int *arr = new int[7]{1,2,3,3,44};
  cout<<getMax(arr,6)<<endl;
}