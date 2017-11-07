#include<iostream>
using namespace std;

class Matrix{
private:
  double *elem;
  int row,col;
public:
  Matrix(int r,int e):row(r),col(e){
    elem=new double[row*col]{};
  }
  double& operator()(int x,int y){
    return elem[col*(x-1)+y-1];
  }
  const double& operator()(int x,int y) const {
    return elem[col*(x-1)+y-1];
  }
  ~Matrix(){
    delete[] elem;
  }
};
int main(){
  Matrix m(5,8);
  for(int i=1;i<6;++i){
    m(i,1)=i+5;
  }
  for (int i=1;i<6;++i){
    cout<<m(i,1)<<",";
  }cout<<endl;
  return 0;
}
