#include<iostream>
using namespace std;
class ExceptionBase
{
public:
    ExceptionBase(){}
    ~ExceptionBase(){}
    virtual void showReason()
    {
        cout<<"Base Exception!\n";
    }
};
class PushOnFull:public ExceptionBase
{
public:
    virtual void showReason()
    {
        cout<<"Error! Full!\n";
    }
};
class PopOnEmpty:public ExceptionBase
{
public:
    virtual void showReason()
    {
        cout<<"Error! Empty\n";
    }
};
template<typename T>
class Stack
{
private:
    T *pData;
    int stackSize;
    int top=-1;
public:
    Stack(int s=100);
    ~Stack();
    void push(const T &data);
    T pop();
    bool isEmpty();
    bool isFull();
};
template<typename T>
Stack<T>::Stack(int s)
{
    stackSize=s;
    pData=new T[s];
}
template<typename T>
Stack<T>::~Stack()
{
    delete [] pData;
}
template<typename T>
void Stack<T>::push(const T &data)
{
    if(isFull())
    {
        cout<<"Stack is full\n";
        throw PushOnFull();
    }
    ++top;
    pData[top]=data;
}
template<typename T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Stack is empty!\n";
        throw PopOnEmpty();
    }
    T t=pData[top];
    --top;
    return t; 
}
template<typename T>
bool Stack<T>::isEmpty()
{
    return top==-1;
}
template<typename T>
bool Stack<T>::isFull()
{
    return top==stackSize-1;
}
int main()
{
    int array[10]={1,3,2,4};
    Stack<int>s(4);
    cout<<endl;
    try
    {
        for(int i=0;i<3;++i)
        {
            s.push(array[i]);
        }
        while(!s.isEmpty())
        {
            cout<<s.pop()<<' ';
        }
        for(int i=0;i<10;++i)
        {
            s.push(array[i]);
        }
    }
    catch(ExceptionBase &e)
    {
        e.showReason();
    }
    return 0;
}