#include<iostream>
#include<functional>
using namespace std;

template<typename T>
T use_f(T x,function<T(T)> f){
  static int count=0;
  ++count;
  cout<<"count = "<<count
      <<" &count = "<<&count<<endl;
  return f(x); 
}

class Fp{
private:
  double p;
public:
  Fp(double _p):p(_p){}
  double operator()(double x){return x*p;}
};

double dub(double u){
  return u*u;
}

int main(){

//lambda
  cout<<use_f<double>(0.5,[](double u){return u*u;})<<endl;
//class
  cout<<use_f<double>(0.5,Fp(0.5))<<endl;
//function
  cout<<use_f<double>(0.5,dub)<<endl;
}