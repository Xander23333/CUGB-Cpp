#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*****************************************
//所有容器适用
for_each(b,e,p)
使用for_each()算法遍历数据
使用for_each()和函数对象修改数据
使用for_each()的返回值
*****************************************/

/*************************************************************************************
std::for_each                   所有排序容器适用                           algorithm
--------------------------------------------------------------------------------------
template <class InputIterator, class Function>
   Function for_each (InputIterator first, InputIterator last, Function f);

//eg：
template<class InputIterator, class Function>
  Function for_each(InputIterator first, InputIterator last, Function f)
  {
    for ( ; first!=last; ++first ) f(*first);
    return f;
  }
*************************************************************************************/
void myfunction (int i)
{
    cout << " " << i;
}
struct myclass
{
    void operator() (int i)
    {
        cout << " " << i;
    }
} myobject;

class MeanVlaue
{
public:
    MeanVlaue():num(0),sum(0){}
    void operator() (int elem)
    {
        num++;
        sum+=elem;
    }
    double value()
    {
        return static_cast<double>(sum)/static_cast<double>(num);
    }
    operator double()//重载的好处，简洁！
    {
        return static_cast<double>(sum)/static_cast<double>(num);
    }
private:
    long num;
    long sum;
};

template<typename T1>
auto add(T1 &a)->decltype(a+10){
  return a+=10;
}

template<class T>
class AddValue
{
public:
    AddValue(const T& v):theValue(v){}
    void operator() (T& elem)const
    {
        elem+=theValue;
    }
private:
    T theValue;
};

int main()
{
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    cout << "myvector contains:";
    for_each (myvector.begin(), myvector.end(), myfunction);

    // or:
    cout << "\nmyvector contains:";
    for_each (myvector.begin(), myvector.end(), myobject);

    cout << endl;

    MeanVlaue mv=for_each(myvector.begin(),myvector.end(),MeanVlaue());
    cout<<"MeanValue:"<<mv.value()<<endl;

    for_each(myvector.begin(), myvector.end(), add<int>);//参数可以自己改，eg：*(myvector.begin())
    for_each (myvector.begin(), myvector.end(), myobject);
    cout << endl;

    double mv2=for_each(myvector.begin(),myvector.end(),MeanVlaue());
    cout<<"MeanValue:"<<mv2<<endl;

    return 0;
}
