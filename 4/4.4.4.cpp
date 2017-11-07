#include<iostream>
#include<vector>
using namespace std;

class Fraction{
private:
  int num,den;
public:
  // explicit is 显式
  Fraction(int n=0,int d=1):num(n),den(d){}
  explicit operator double() const {
    return 1.0*num/den;
  } 
  Fraction operator +(const Fraction& f) const{
    return Fraction(this->num*f.den+f.num*(this->den),this->den*f.den);
  }
  friend ostream& operator<<(ostream& out,const Fraction& f);
};

ostream& operator<<(ostream& out,const Fraction& f){
  out<<f.num<<"/"<<f.den;
  return out;
}

int main(){
  Fraction f1(1,3);
  cout<<f1<<endl;
  Fraction f2=f1+(1);
  cout<<f2<<endl;
  cout<<1+static_cast<double>(f1)<<endl;
  return 0;
}