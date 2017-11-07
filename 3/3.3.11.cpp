#include<iostream>
using namespace std;

class Test{
private:
  int a;
public:
  Test(){cout<<"Default Construct!\n";}
  Test(int x):a(x){cout<<"a = "<<a<<" Construct!\n";}
  Test(const Test& t){
    a=t.a;
    cout<<"a = "<<a<<" Copy cinstructor!\n";
  }
  Test(Test&& t){
    a=t.a;
    cout<<"a = "<<a<<" move copy constructor!\n";
  }
  ~Test(){
    cout<<"a = "<<a<<" Destruct!\n";
  }
  Test operator + (const Test& x)const{
    return Test(a+x.a);
  }
  Test operator * (const Test& x)const {
    return Test(a*x.a);
  } 
  Test& operator=(Test&& t){
    cout << "move operator=" << endl;
    //这里防止自移动，下面要把移动源对象的数据域简单的置为空值，
    //如果源对象就是本身那么最后移动后自己的值被清空了。
    if (this == &t){
        return *this;
    }
    this->a = t.a;
    
    t.a = 0;
    
    return *this;
  }
};
Test fun(){
  return Test(2);
}
int main(){
  Test t2 = (fun());
  printf("the 1 sentence over!\n\n");
  Test t3 = {fun()};
  printf("the 2 sentence over!\n\n");
  Test t4 {(t2+t3*t3+t2)*t3};
  // even there is temperory rvalue
  // only t3*t3,t2+t3*t3,t2+t3*t3+t2 are building temporary value, 
  // when (t2+t3*t3+t2)*t3 it construct directly, not copy a temporary value=(t2+t3*t3+t2)*t3
  // why not move ? how can I use move implicitly???
  // 
  printf("the 3 sentence over!\n\n");
  
  Test t5 {12*12+1};
  printf("the 4 sentence over!\n\n");
  return 0;
}