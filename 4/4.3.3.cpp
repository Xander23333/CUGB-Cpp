#include<iostream>
//#include<string>
#include<cstring>
using std::ostream;
using std::cout;using std::endl;

class MyString{
public:
  MyString(char *s){
    str = new char[strlen(s)+1];
    strcpy(str,s);
  }
  MyString(){
    str = nullptr;
  }
  MyString(const MyString& s);
  MyString(MyString&& s);
  ~MyString();
  MyString& operator = (const MyString& s);
  MyString& operator = (MyString&& s);
  int size()const;
  MyString operator+(const MyString& s) const ;
  char& operator[](int index);
  const char& operator[](int index) const;
friend ostream& operator<<(ostream&,const MyString&) ;

private:
  char *str;
};

int main(){
  MyString s((char*)"Hello");
  cout<<s<<endl;
  MyString s2 = s+(char*)"World";
  //s2 = "World"+s; error!
  cout<<s2<<endl;
  s2[5] = 'A';
  cout<<"Index 5:"<<s2[5]<<endl;

  const MyString s4=s2;
 // s4[5] = 'q';error!

  MyString s3(std::move(s2));
  cout<<s3<<endl;
 // cout<<s2<<endl;
  return 0;
}


MyString::MyString(const MyString& s){
  this->str = new char[s.size()+1];
  strcpy(this->str,s.str);
}
/;'
'
MyString::MyString(MyString&& s):str(s.str){
  s.str = NULL;
}
MyString::~MyString(){
  delete[] str;
}
MyString& MyString::operator = (const MyString& s){
  delete[] this->str;
  this->str = new char[s.size()+1];
  strcpy(this->str,s.str);
}
MyString& MyString::operator = (MyString&& s){
  this->str = s.str;
  s.str=NULL;
}
int MyString::size()const{
  return strlen(this->str);//this is so stupid!!
}
MyString MyString::operator+(const MyString& s) const {
  int l_size=this->size(),r_size=s.size();
  char *tmp = new char[ l_size + r_size + 1 ];
  strcpy(tmp,this->str);
  strcpy(tmp+l_size,s.str);
  return tmp;
}
char& MyString::operator[](int index)  {
  if (index>this->size()) {
    cout<<"error:Invalid index\n";
  }
  return *(str+index);
}
const char& MyString::operator[](int index) const{
//const func != func const 
// const func means return a const type. e.g. const referrence means the return object's value cannot be changed 
// func const (only meaningful as a member function) means this func is a const member func which can not change (*this)'s value
  if (index>this->size()) {
    cout<<"error:Invalid index\n";
  }  
  return *(str+index);
}
// The meaning of writing these two version nearly kills me.... finally I find its meaning in C++primer.
// And then I find it has appealed in PPT already in which class I skipped.....
ostream& operator<<(ostream& out,const MyString& s){
  out<<s.str;
  return out;
}