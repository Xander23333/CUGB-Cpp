#include<iostream>
using namespace std;

int *getDig(int ** matrix, int n){
  int *arr=new int[n];
  for (int i=0;i<n;++i){
    *(arr+i) = *(*(matrix+i)+i);
  }
  return arr;
}

int main(){
  int ** data,n=5;
  data = new int *[n];
  for(int i=0;i<n;++i){
    data[i]=new int [n];
  }
  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j)
      data[i][j]=i+j;
  }
  int *diagonal = getDig(data,n);
  for (int i=0;i<n;++i){
    cout<<diagonal[i]<<" ";
  }cout<<endl;

  delete[] diagonal;
  for (int i=0;i<n;++i) delete[] data[i];
  delete[] data;
}