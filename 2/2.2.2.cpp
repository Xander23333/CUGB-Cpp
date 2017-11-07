#include<iostream>
#include<cmath>
using namespace std;
class Complex{
public:
  Complex();
  Complex(double n);
  Complex(double n,double d);
  void setValue(double n,double d);
  double getReal();
  double getImage();
  double getDistance();
  void output();
private:
  double real,image;
};

Complex::Complex():real(0),image(0){
}
Complex::Complex(double n):real(n),image(0){
}
Complex::Complex(double n,double d){
  real=n;image=d;
}
void Complex::setValue(double n,double d){
  real=n;image=d;
}
double Complex::getReal(){
  return real;
}
double Complex::getImage(){
  return image;
}
double Complex::getDistance(){
  return sqrt(image*image+real*real);
}
void Complex::output(){
  cout<<real;
  if (image != 0) {
    if (image>0) cout<<"+";
    cout<<image<<"i";
  }
  cout<<endl;
}


int main(){
  Complex c1,c2(2),c3(3,4);
  c1.output();
  c2.output();
  c3.output();
  c1.setValue(6,4);
  c1.output();
  cout<<c1.getDistance()<<endl;
  return 0;
}