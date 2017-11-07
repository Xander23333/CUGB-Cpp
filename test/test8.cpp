// Person.h
#include<iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;

class Person {
  string name;
  int id;

public:
  Person(int id=0, string name="");
  ~Person();
  //拷贝构造函数
  Person(const Person &person);
  //赋值
  Person &operator=(const Person &person);
  //移动构造函数
  Person(Person &&person);
  //移动赋值运算符
  Person &operator=(Person &&person);
 
  Person copyPerson();

  void setId(int id) { this->id = id; }
  void setName(string Name) { this->name = Name; }

  void desc();
};
// Person.cpp


Person::Person(int id, string name):id(id), name(name) {
  cout<<"default!\n";
}

//拷贝构造函数
Person::Person(const Person &person) {
  cout << "copy constructor!" << endl;
  this->id = person.id;
  this->name = person.name;
}
//赋值
Person &Person::operator=(const Person &person) {
  cout << "operator= " << endl;
  //防止自身对自身赋值，这里可能会存在潜在的bug，如果这里我们分配内存来存储数据，那么我们
  //在赋值运算符中药释放this指针中数据指针成员指向的堆空间，如果这里我们不进行自赋值检查将会
  //导致自身的数据指针成员指向的内存被释放结果可能就不是我们所预期的那样子了。
  if (this == &person) {
    return *this;
  }

  this->id = person.id;
  this->name = person.name;

  return *this;
}
//移动构造函数
Person::Person(Person &&person) {
  cout << "move constructor!" << endl;
  this->id = person.id;
  this->name = person.name;
  //把移动操作的源对象简单的置为所谓空值（根据自己的应用场景决定）
  person.id = -1;
  person.name = "";
}
Person::~Person(){
  cout<<"Destruct!\n";
}
//移动赋值运算符
Person &Person::operator=(Person &&person) {
  cout << "move operator=" << endl;
  //这里防止自移动，下面要把移动源对象的数据域简单的置为空值，
  //如果源对象就是本身那么最后移动后自己的值被清空了。
  if (this == &person) {
    return *this;
  }
  this->id = person.id;
  this->name = person.name;

  person.id = -1;
  person.name = "";

  return *this;
}

void Person::desc() {
  cout << "id:" << id << endl;
  cout << "name:" << name << endl;
  cout << "-------------------------------------------" << endl;
}

Person Person::copyPerson() {
  Person p(this->id, name);
  cout<<"the func over!\n";
  return p;
}
// main.cpp


int main() {
  Person p1;
  Person p2;

  p1.setId(1);
  p1.setName("lucy");
  p2.setId(2);
  p2.setName("Tom");

  p2 = p1; // p2之前已经被初始化过
  Person p3 = p2; // p3未初始化过，这里通过p2来初始化p3，调用拷贝构造函数
  Person p4(p2); // p4未初始化过，同时这里根据传递的参数也可以判断出调用拷贝构造函数
  
  printf("the 1th sentence over!\n\n");
  Person p5 = p2.copyPerson(); //不调用移动构造函数; g++ 7.1.0 is optimately not use this!!
  
  printf("the 2ed sentence over!\n\n");
  p5 = p2.copyPerson();        //调用移动赋值运算符

  printf("the 3rd sentence over!\n\n");

  Person p6 = Person();
  printf("the 4th sentence over!\n\n");
  return 0;
}