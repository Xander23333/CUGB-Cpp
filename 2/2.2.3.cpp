#include<iostream>

using namespace std;

class Time{
private:
  int h,m;
  void normalizeTime();
public:
  Time();
  Time(int h,int m);
  void setTime(int h,int m);
  void output();
  int getHour();
  int getMinute();
  int getTotalMinutes();
};

Time::Time():h(0),m(0){}
Time::Time(int h,int m):h(h),m(m){
  normalizeTime();
}
void Time::normalizeTime(){
  h+=(m/60);
  h%=24;
  m%=60;
}
void Time::setTime(int h,int m){
  this->h = h;this->m = m;
  normalizeTime();
}
void Time::output(){
  printf("%02d:%02d\n",h,m);
}
int Time::getHour(){
  return h;
}
int Time::getMinute(){
  return m;
}
int Time::getTotalMinutes(){
  return h*60+m;
}

int main(){
  Time t1(12,75);
  t1.output();
  t1.setTime(8,65);
  t1.output();
  cout<<"t1 Hour: "<<t1.getHour()<<endl;
  cout<<"t1 Minute: "<<t1.getMinute()<<endl;
  cout<<"t1 TotalMinutes: "<<t1.getTotalMinutes()<<endl;
  return 0;
}