#include<iostream>
using namespace std;
// when I haven't initialize list, the para send to it but not initialize it
class Point{
private:
  int a,b;
public:
  Point():a{0},b{0}{printf("a= %d b= %d Point default construct!\n",a,b);}
  Point(int a):a(a),b(0){printf("a= %d b= %d Point 1 para construct!\n",a,b);}
  Point(int a,int b):a(a),b(b){printf("a= %d b= %d Point 2 para construct!\n",a,b);}
  Point(const Point& p):a(p.a),b(p.b){printf("a= %d b= %d Point copy construct!\n",a,b);}
  ~Point(){printf("a= %d b= %d Point destruct!\n",a,b);}
  Point operator + (const Point& x)const{
    return Point(x.a+a,x.b+b);
  }
};
class Test{
private:
  Point a,b;
public:
  Test(){cout<<"Test default construct1\n";}
  Test(const Point& a):a{a}{cout<<"Test 1 para construct!\n";}
  Test(const Point& a,const Point& b):a{a},b{b}{cout<<"Test 2 para construct!\n";}
  Test(const Test& t):a{t.a},b{t.b}{cout<<"Test copy construct!\n";}
  Test(int x):a{x}{cout<<"Test int 1 para construct!\n";}
  ~Test(){cout<<"Test destruct!\n";}
};
/*
Point& fun(const Point& x){//wrong!!
  return x;
}*/
Point fun(const Point& x,const Point& y){//wrong!!
  return x+y;
}
int main(){
  Point p1(1),p2(1,2),p3;
  printf("the 1th sentence over!\n\n");
  p3=4;//1 para cons a temperory Point, assign p3, and dest. the temp.   
  Point p4=4;//1 para cons.
  printf("the 2ed sentence over!\n\n");
  Test t1(p1,p2),t2(p1),t3,t4;
  
  printf("the 3rd sentence over!\n\n");
  t3 = p1;//this is so diao?!!
  Test t6=p1;

  printf("the 4th sentence over!\n\n");
  t4=6;
  Test t5=6;
  delete &t5;//this sentence can destruct t5p
  printf("the 5th sentence over!\n\n");

  t4=t1;
  Test t7=t1;
  printf("the 6th sentence over!\n\n");

  Point x,z;
  x = fun(x,z);// 1.X(x) 2.Return(x) 3.X dest. 4.x=Return 5.Return dest.
  printf("the 7th sentence over!\n\n");

  Point y=fun(x,z);// 1.X(x) 2.Return(X)-->y(X) 3.X dest.    !!the complier is optimated!
  printf("the 8th sentence over!\n\n");
  //what fuck?????
}
