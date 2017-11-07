#include<bits/stdc++.h>
using namespace std;
class Point{
private:
  double x,y;
public:
  Point(double,double);
  Point(const Point&);
  ~Point();
  void setValue(double,double);
  double getX() const;
  double getY() const;
//1  double getDistance(const Point& ) const;
  friend double getDistance(const Point& ,const Point& );//3 当声明了友元函数相当于声明了这个函数，无需再次声明
};
//2 double getDistance(const Point& ,const Point& ); 
class Triangle{
private:
  Point p1,p2,p3;
public:
  Triangle(const Point &p1,const Point &p2,const Point& p3);
  double getArea() const;
  double getPerimeter() const;
};

int main(){
  cout<<"TEST1:\n";
  Point p1(3,4);
  Point p2(5,2);
  double distance = getDistance(p1,p2);
  cout<<"Distance:"<<distance<<endl;
  
  cout<<"\nTEST1:\n";
  Point p11(0,0),p22(0,3),p33(4,0);
  Triangle t(p11,p22,p33);
  cout<<"Area:"<<t.getArea()<<endl;
  cout<<"Perimeter:"<<t.getPerimeter()<<endl;
  return 0;
}

Point::Point(double newX=0,double newY=0):x(newX),y(newY){}
Point::Point(const Point& p):x(p.x),y(p.y){}
Point::~Point(){}
void Point::setValue(double newX,double newY){
  x = newX;
  y = newY;
}
double Point::getX() const{return x;}
double Point::getY() const{return y;}
/*1 成员函数
double Point::getDistance(const Point& p) const{
  return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));  
}*/
/*2 普通函数
double getDistance(const Point& p1,const Point& p2){
  return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));    
}*/
/*3 友元函数 */
double getDistance(const Point& p1,const Point& p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));  
}

Triangle::Triangle(const Point &p1,const Point &p2,const Point& p3):p1(p1),p2(p2),p3(p3){}
double Triangle::getArea() const{
  double a=getDistance(p1,p2),b=getDistance(p1,p3),c=getDistance(p2,p3);
  double p=(a+b+c)/2;
  return sqrt(p*(p-a)*(p-b)*(p-c));// Heron
}
double Triangle::getPerimeter() const{
  return (getDistance(p1,p2)+getDistance(p1,p3)+getDistance(p2,p3));
}