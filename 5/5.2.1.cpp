#include <iostream>
#include<cmath>
using namespace std;

class Point{
public:
    Point(double newX=0, double newY=0);
    Point(const Point& p);
    virtual ~Point();
    void setValue(double newX, double newY);
    double getX( ) const;
    double getY() const;
    double getDistance( const Point& p2) const;
private:
    double x, y;
};

class Point3D : public Point{
public:
    Point3D(double newX=0, double newY=0, double newZ=0);
    Point3D(const Point& p);
    double getZ() const;
    double getDistance( const Point3D& p)const;//override not, but hide
private:
    double z;
};

int main(){
    cout<<"TEST1:\n";
    Point p1(3, 4), p2(5,3);
    Point3D p1_3D(3,4,6);
    Point3D p2_3D(2,6,9);
    double dis=p1.getDistance(p2); //计算二维点 p1 和 p2 的距离
    cout<<"Distance between p1 and p2: "<<dis<<endl;
    dis=p1_3D.getDistance(p2_3D); //计算 3 维点 p1_3D 和 p2_3D 的距离
    cout<<"Distance between p1_3D and p2_3D: "<<dis<<endl;
    dis=p1.getDistance(p2_3D); //计算 p1 和 p2_3D 的距离
    cout<<"Distance between p1 and p2_3D: "<<dis<<endl;
    dis=p1_3D.getDistance(p2); //计算点 p1_3D 和 p2 的距离
    cout<<"Distance between p1_3D and p2: "<<dis<<endl;
    return 0;
}
Point::Point(double newX,double newY):x(newX),y(newY){}
Point::Point(const Point& p):x(p.x),y(p.y){}
Point::~Point(){}
void Point::setValue(double newX,double newY){
  x = newX;
  y = newY;
}
double Point::getX() const{return x;}
double Point::getY() const{return y;}
double Point::getDistance(const Point& p2)const{
  return sqrt((this->x-p2.x)*(this->x-p2.x)+(this->y-p2.y)*(this->y-p2.y));
}

Point3D::Point3D(const Point& p): Point(p), z(0) {}
Point3D::Point3D(double newX, double newY, double newZ):Point(newX,newY),z(newZ){}
double Point3D::getZ() const{return z;}
double Point3D::getDistance( const Point3D& p2)const{
  return sqrt(Point::getDistance(p2)+(this->z-p2.z)*(this->z-p2.z));
}
