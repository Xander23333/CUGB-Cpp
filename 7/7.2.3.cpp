#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
class Student{
private:
  string name;
  string specialty;//专业
  long id;// 学号
  double creditPoint; //学分积点
public:
  Student(string n,string s,long i,double c)
  :name(n),specialty(s),id(i),creditPoint(c){}
  void setCreditPoint(double c){creditPoint=c;}
  double getCreditPoint()const{return creditPoint;}
  string getName()const{return name;}
  long getId()const{return id;}
  string getSpecialty()const{return specialty;}
  friend ostream& operator<<(ostream& out,const Student& s);
};
ostream& operator<<(ostream& out,const Student& s){
  cout<<"Name:"<<s.name<<endl;
  cout<<" Id:"<<s.id<<endl;
  cout<<" Specialty:"<<s.specialty<<endl;
  cout<<" CreditPoint:"<<s.creditPoint<<endl;
}


class StudentManage{
public:
  enum SortType{BY_NAME,BY_ID,BY_SPECIALTY,BY_CRDITPOINT};
  StudentManage()=default;
  void addStudent();
  void removeStudent();
  void setSortType(SortType st);
  void findStudent();
  int size()const{ return students.size();}
  friend ostream& operator<<(ostream& out,const StudentManage& sm);
private:
  map<long,int> idmap;  
  vector<Student> students;
  SortType sortType=BY_ID;
};void StudentManage::setSortType (SortType st){
  /*if (choice>3 || choice<0) {
    cout<<"Illigal!\n";
    return ;
  }  
  SortType st=(SortType)choice;
  cout<<st<<endl;*/
//function+lambda......666
  function<bool(const Student&,const Student&)> f;
  switch(st){
  case BY_ID: f=[](const Student& s1,const Student& s2)
  {return s1.getName()<s2.getName();};break;
  case BY_NAME:f=[](const Student& s1,const Student& s2)
  {return s1.getId()<s2.getId();};break;
  case BY_SPECIALTY:f=[](const Student& s1,const Student& s2)
  {return s1.getSpecialty()<s2.getSpecialty();};break;
  case BY_CRDITPOINT:f=[](const Student& s1,const Student& s2)
  {return s1.getCreditPoint()<s2.getCreditPoint();};break;
  }
  sort(students.begin(),students.end(),f);
}

void StudentManage::addStudent(){
  string n,s;long i;double c;
//  cout<<"Please enter the name, speciality, id ,credit point of the student:\n";
  cin>>n>>s>>i>>c;
  if (idmap.count(i)){
    cout<<"This id has existed!\n";
    return ;
  }
  else{
    idmap[i]++;
    students.push_back(Student(n,s,i,c));
    setSortType(sortType);
  }
}
void StudentManage::removeStudent(){
  cout<<"Please enter the student's id you want to remove:\n";
  long x;cin>>x;
  if (!idmap.count(x)){
    cout<<"There is no such a student!\n";
    return ;
  }
  for(auto i=students.begin();i!=students.end();++i){
    if( (*i).getId()==x ) {
      idmap.erase(x);
      students.erase(i);
      cout<<"OK!This student is removed!\n";
      return ;
    }
  }
}
void StudentManage::findStudent(){
  cout<<"Please enter a name or an id:\n";
  string n;cin>>n;
  long i;
  if (n[0]<='9' && n[0]>='0'){
    stringstream ss;ss<<n;ss>>i;
    for_each(students.begin(),students.end(),[i](Student& x){if(x.getId()==i) cout<<x<<endl;});
  } 
  else {
    for_each(students.begin(),students.end(),[&n](Student& x){if(x.getName()==n) cout<<x<<endl;});
  }
}

ostream& operator<<(ostream& out,const StudentManage& sm){
  for(auto& e:sm.students) out<<e<<endl;
  return out;
}
int main(){
/*  cout<<"Test1:\n";
  vector<Student> vec{
  {"zhang","Computer",11001,4.2},
  {"wang","Computer",11002,3.8},
  {"Li","English",12001,4.1},
  {"Tang","English",12002,3.9},
  {"Qian","Computer",11003,4.0},
  {"Song","Geology",10001,4.1}
  };
  for(auto e: vec) 
  cout<<e;
*/
  cout<<"Test2:\n";
  StudentManage sm;
  
  cout<<"Welcome to the Student Management System!\nBut can "
      <<"I must say the our teacher has less creativity in teaching...\n"
      <<"In two continuous semeters this project always is the hardest task...\n"
      <<"I only look foward there will be some intersting task in the 14-15th week.\n\n";
 

  cout<<"sort type(0-name,1-id,2-specialty,3-creditpoint):\n";
  int choice;
  cin>>choice;
  sm.setSortType (static_cast<StudentManage::SortType>(choice));

  cout<<"\nPlease enter the student number:\n";
  int n;cin>>n;

    cout<<"Please enter the name, speciality, id ,credit point of the student:\n";
    while(n--) sm.addStudent();
  cout<<sm;

  int command;
  while(1){  
    cout<<"Please enter command, 1-add,2-find,3-remove,0-exit:\n";
    cin>>command;
    if (command==0) break;
    switch(command){
      case 1:sm.addStudent();break;
      case 2:sm.findStudent();break;
      case 3:sm.removeStudent();break;
    }
   // cout<<endl<<"Now:\n";
   // cout<<sm;
  }
  cout<<"Syytem is shot down!\n";
  return 0;
}