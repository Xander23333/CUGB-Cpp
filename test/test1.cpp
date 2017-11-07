#include<iostream>

//using namespace std;

class Time{
private:
  int h,m;
  void normalizeTime();
public:
  Time();
  Time(int h,int m);
  Time(int minutes);
  void setTime(int h,int m);
  void output() const;
  int getHour() const;
  int getMinute() const;
  int getTotalMinutes() const;
  Time getTimeSpan(const Time &t);
};



int main(){
  
  printf("TEST1:\n");
  Time t1(9,20),t2(11,35);
  Time t3=t1.getTimeSpan(t2);
  t3.output();
  
  return 0;
}

Time::Time():h(0),m(0){
    std::cout<<"default Construct!\n";
}
Time::Time(int h,int m):h(h),m(m){
  normalizeTime();
  std::cout<<"hour,minute Construct!\n";
}
Time::Time(int minutes):h(0),m(minutes){
  normalizeTime();
  std::cout<<"minutes Construct!\n";
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
void Time::output() const{
  printf("%02d:%02d\n",h,m);
}
int Time::getHour()const{
  return h;
}
int Time::getMinute()const{
  return m;
}
int Time::getTotalMinutes()const{
  return h*60+m;
}
Time Time::getTimeSpan(const Time &t){
  Time t1(abs(getTotalMinutes()-t.getTotalMinutes()));
  return t1;
}
