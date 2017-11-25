#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.14;
class Shape{
public:
  virtual double getArea() const =0;
  virtual double getPerimeter() const =0; //virtual must be totally same, including "const" 
  virtual ~Shape(){}
};// the virtual destruction????
class Circle:public Shape{
public:
  Circle(double r):radius(r){}
  virtual double getArea() const;// what if there is no virtual and a derived class use this func? 
  virtual double getPerimeter() const;
  virtual ~Circle(){}
  // will the virtual destruction func be default?
  // no! if not virtual, will just des the base class
private:
  double radius;
};
double Circle::getArea() const{
  return PI*radius*radius;
}
double Circle::getPerimeter() const{
  return PI*radius*2;
}
class Rectangle:public Shape{
public:
  Rectangle(double w,double h):width(w),height(h){}
  virtual double getArea() const;
  virtual double getPerimeter() const;
  virtual Rectangle(){}
private:
  double width,height;  
};
double Rectangle::getArea() const{
  return width*height;
}
double Rectangle::getPerimeter() const{
  return (width+height)*2;
}
class Triangle:public Shape{
public:
  Triangle(double ,double ,double );
  virtual double getArea() const;
  virtual double getPerimeter() const;
  virtual Triangle(){}
private:
  double a,b,c;
};
Triangle::Triangle(double newA,double newB,double newC):a(newA),b(newB),c(newC) {}
double Triangle::getArea() const{
  double p=(a+b+c)/2;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triangle::getPerimeter() const{
  return a+b+c;
}
void outputInfo(const Shape& sh);
int main(){
  Rectangle shape1(3,4);
  Circle shape2(1.0);
  Triangle shape3(3,4,5);
  outputInfo(shape1);
  outputInfo(shape2);
  outputInfo(shape3);
  return 0;
}
void outputInfo(const Shape& sh){
  cout<<"Area:"<<sh.getArea()<<endl;
  cout<<"Perimeter:"<<sh.getPerimeter()<<endl;
}




