#include<iostream>
using std::cout;using std::endl;using std::cin;
template <typename T>
class Stack{
public:
  Stack(int size=100);
  ~Stack();
  void push(T data);
  T pop();
  bool isEmpty();
  bool isFull();
private:
  T *pData;
  int stackSize;
  int top=-1;
};
template <typename T>
Stack<T>::Stack(int size){
  pData=new T[size];
}
template <typename T>
Stack<T>::~Stack(){
  delete[] pData;
}
template <typename T>
void Stack<T>::push(T data){
  if(isFull()){
    cout<<"Stack is full!\n";
    exit(0);
  }
  top++;
  //cout<<top<<endl;
  pData[top]=data;
}
template <typename T>
T Stack<T>::pop(){
  if(isEmpty()){
    cout<<"Stack is empty!\n";
    exit(0);
  }
  T temp=pData[top];
  top--;
  
 // cout<<top<<endl;
  return temp;
}
template <typename T>
bool Stack<T>::isEmpty(){
  return top==-1;
}
template <typename T>
bool Stack<T>::isFull(){
  return top==stackSize-1;
}

int main(){
  int array[10]={1,3,2,4};
  Stack<int> s(4);
  for(int i=0;i<4;++i) s.push(array[i]);
  while(!s.isEmpty()) 
    cout<<s.pop()<<" ";
  for(int i=0;i<10;++i) s.push(array[i]);
  cout<<endl;

  return 0;
}