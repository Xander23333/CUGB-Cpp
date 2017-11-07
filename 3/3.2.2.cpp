#include<bits/stdc++.h>
using namespace std;

class Complex{
public:
  Complex();
  Complex(double n);
  Complex(double n,double d);
  void setValue(double n,double d);
  double getReal() const;
  double getImage() const;
  double getDistance() const;
  void output() const;
  Complex add(const Complex& c) const;
  void multiply(double coe);
private:
  double real;
  double image;
};

Complex::Complex():real(0),image(0){
}
Complex::Complex(double n):real(n),image(0){
}
Complex::Complex(double n,double d):real(n),image(d){}
void Complex::setValue(double n,double d){
  real=n;image=d;
}
double Complex::getReal() const{
  return real;
}
double Complex::getImage() const{
  return image;
}
double Complex::getDistance() const{
  return sqrt(image*image+real*real);
}
void Complex::output() const{
  cout<<real;
  if (image != 0) {
    if (image>0) cout<<"+";
    cout<<image<<"i";
  }
  cout<<endl;
}
Complex Complex::add(const Complex& c) const{
  return Complex(c.real+real,c.image+image);
}
void Complex::multiply(double coe){
  real*=coe;image*=coe;
}

int main(){
  Complex c1,c2(2),c3(3,4);
  c1.output();
  c2.output();
  c3.output();
  c1.setValue(6,4);
  c1.output();
  cout<<c1.getDistance()<<endl;

  c3.multiply(2);
  c3.output();

  (c1.add(c2)).output();

  return 0;
}
