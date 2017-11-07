#include<iostream>
#include<cmath>
//using namespace std;

class Complex{
  friend std::ostream& operator << (std::ostream& out,const Complex& f);
  friend Complex operator - (const Complex& f1,const Complex& f2);
public:
  Complex();
  Complex(double n);
  Complex(double n,double d);
  Complex(const Complex& c);
  ~Complex();
  void setValue(double n,double d);
  double getReal() const;
  double getImage() const;
  double getDistance() const;
//  void output() const;
  Complex operator + (const Complex& f) const;
  Complex operator * (const Complex& f) const;
  Complex & operator += (const Complex& f);
  Complex& operator -= (const Complex& f);  
  Complex & operator *= (const Complex& f);
  Complex & operator ++();
  Complex operator ++(int);
private:
  double real;
  double image;
};


int main(){
  Complex c1,c2(2),c3(3,4);
  c1+=c2;
  Complex c4=c1+c3,c5=c1*c3;
  std::cout<<c1<<" "<<c4<<" "<<c5<<std::endl;
  //c1.output();
  //c4.output();
  //c5.output();
  c5++;std::cout<<c5<<std::endl;
  ++c5;std::cout<<c5<<std::endl;
  
  c5-=c3;std::cout<<c5<<std::endl;
  return 0;
}

std::ostream& operator<<(std::ostream& out,const Complex& f){
  out<<f.real;
  if (f.image != 0) {
    if (f.image>0) out<<"+";
    out<<f.image<<"i";
  }
  return out;
}
Complex operator - (const Complex& f1,const Complex& f2){
  return Complex(f1.real-f2.real,f1.image-f2.image);
}
Complex& Complex::operator -= (const Complex& f){
  real-=f.real;image-=f.image;
  return (*this);
}

Complex::Complex():real(0),image(0){
}
Complex::Complex(double n):real(n),image(0){
}
Complex::Complex(double n,double d):real(n),image(d){}
void Complex::setValue(double n,double d){
  real=n;image=d;
}
Complex::Complex(const Complex& c):real(c.real),image(c.image){}
Complex::~Complex(){}
double Complex::getReal() const{
  return real;
}
double Complex::getImage() const{
  return image;
}
double Complex::getDistance() const{
  return sqrt(image*image+real*real);
}
/*void Complex::output() const{
  cout<<real;
  if (image != 0) {
    if (image>0) cout<<"+";
    cout<<image<<"i";
  }
  cout<<endl;
}*/
Complex Complex::operator + (const Complex& f) const{
  return Complex(f.real+real,f.image+image);
}
Complex Complex::operator * (const Complex& f) const{
  return Complex(f.real*real - f.image*image , f.image*real + f.real*image);
}
Complex& Complex::operator += (const Complex& f){
  real+=f.real;
  image+=f.image;
  return (*this);
  //return (*this)+f; error!! cause T& must return a global lvalue!
}
Complex& Complex::operator *= (const Complex& f){
  real = f.real*real - f.image*image;
  image = f.image*real + f.real*image;
  return (*this);
}
Complex& Complex::operator ++(){
  ++real;
  return (*this);
}
Complex Complex::operator++ (int){//++ is so special and even if you write int x=1 ,in the function x still x=0
  Complex tmp(*this);
  ++(*this);
  return tmp;
}
