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
  Time getTimeSpan(const Time &t) const;
  friend void ParkingCard::setParkingTime(const Time&);
  friend void ParkingCard::setLeavingTime(const Time&);
};


class ParkingCard{
private:
  double rate;
  Time parkingTime;
  Time leavingTime;
public:
  ParkingCard(double newRate):rate(newRate){}
  void setRate(double newRate){rate = newRate;}
  double getRate() const{return rate;}
  void setParkingTime(const Time &Time);
  void setLeavingTime(const Time &Time);
  double getTotalExpenses() const;
  void output() const;
};

int main(){
  
  printf("TEST1:\n");
  Time t1(9,20),t2(11,35),t3;
  t3=t1.getTimeSpan(t2);
  t3.output();
  printf("\nTEST2:\n");
  ParkingCard card(5);
  card.setParkingTime(Time(9,20));
  card.setLeavingTime(Time(11,35));
  std::cout<<"Expenses:"<<card.getTotalExpenses()<<std::endl;
  std::cout<<"Detailed info:\n";
  card.output();
  
  return 0;
}

Time::Time():h(0),m(0){}
Time::Time(int h,int m):h(h),m(m){
  normalizeTime();
}
Time::Time(int minutes):h(0),m(minutes){
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
Time Time::getTimeSpan(const Time &t) const{
  return Time(abs(getTotalMinutes()-t.getTotalMinutes()));
}


void ParkingCard::setParkingTime(const Time &time){
  parkingTime.setTime(time.h,time.m);
}
void ParkingCard::setLeavingTime(const Time &time){
  leavingTime.setTime(time.h,time.m);
}
double ParkingCard::getTotalExpenses() const{
  int ValidMinute = (leavingTime.getTimeSpan(parkingTime))
                    .getTotalMinutes();
  double ValidHour = ValidMinute/60;
  ValidMinute %= 60;
  if (ValidMinute > 0){
    if (ValidMinute < 30) ValidHour += 0.5;
    else ValidHour += 1;
  }
  return rate*ValidHour;
}
void ParkingCard::output() const{
  printf("parkingTime = ");
  parkingTime.output();
  printf("leavingTime = ");
  leavingTime.output();
  printf("rate = %.2lf\ntotal expenses = %.2lf\n",rate,getTotalExpenses());
}