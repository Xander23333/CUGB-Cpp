#include<iostream>
using namespace std;
class Person{
public:
  Person(){cout<<"Person Instruct!\n";}
  ~Person(){cout<<"Person Destruct!\n";}
};
class Teacher:public Person{
public:
  Teacher(){cout<<"Teacher Instruct!\n";}
  ~Teacher(){cout<<"Teacher Destruct!\n";}
};
class Student:public Person{
public:
  Student(){cout<<"Student Instruct!\n";}
  ~Student(){cout<<"Student Destruct!\n";}
};

int main(){
  Student s;Teacher t;
  return 0;
}