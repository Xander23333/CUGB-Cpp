#include<iostream>
#include<iomanip>
//using namespace std;
using std::cout;using std::endl;
//unqualified-id is the error  "operator" name lack

class Time{
  friend std::ostream& operator<< (std::ostream& out,const Time& t);    
public:
  Time();
  Time(int h,int m);
  Time(int minutes);
  void setTime(int h,int m);
//  void output() const;
  int getHour() const;
  int getMinute() const;
  int getTotalMinutes() const;
  Time operator - (const Time&) const;
//  Time getTimeSpan(const Time &t) const;
private:
  int h,m;
  void normalizeTime();
};

class ParkingCard{
  friend std::ostream& operator << (std::ostream&, const ParkingCard&); 
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
};

int main(){
  
  printf("TEST1:\n");
  Time t1(9,20),t2(11,35),t3;
  t3=t2-t1;
  cout<<t3<<endl;
  printf("\nTEST2:\n");
  ParkingCard card(5);
  card.setParkingTime(Time(9,20));
  card.setLeavingTime(Time(11,35));
  std::cout<<"Expenses:"<<card.getTotalExpenses()<<std::endl;
  std::cout<<"Detailed info:\n";
  cout<<card;
  
  return 0;
}


std::ostream& operator <<(std::ostream& out,const Time& t){
  out<<std::setfill('0');
  out<<std::setw(2)<<t.h<<":"<<std::setw(2)<<t.m;//setw is temperary
  return out;
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
int Time::getHour()const{
  return h;
}
int Time::getMinute()const{
  return m;
}
int Time::getTotalMinutes()const{
  return h*60+m;
}
Time Time::operator - (const Time& t)const{
  return Time(getTotalMinutes()-t.getTotalMinutes());
}

std::ostream& operator <<(std::ostream& out, const ParkingCard& p){
  out <<"parkingTime = "<<p.parkingTime<<endl
      <<"leavingTime = "<<p.leavingTime<<endl;
  out <<std::fixed<<std::setprecision(2);
  out <<"rate = "<<p.rate<<endl;
  out <<"total expenses = "<<p.getTotalExpenses()<<endl;
}
void ParkingCard::setParkingTime(const Time &time){
  parkingTime.setTime(time.getHour(),time.getMinute());
}
void ParkingCard::setLeavingTime(const Time &time){
  leavingTime.setTime(time.getHour(),time.getMinute());
}
double ParkingCard::getTotalExpenses() const{
  Time Span = leavingTime - parkingTime;
  double ValidHour = Span.getHour(),ValidMinute = Span.getMinute();
  if (ValidMinute!=0){
    if (ValidMinute<30) ValidHour+=0.5;
    else ValidHour+=1;
  }
  return rate*ValidHour;
}